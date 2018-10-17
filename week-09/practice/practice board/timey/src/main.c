/* Includes ------------------------------------------------------------------*/
#include "stm32f7xx_hal.h"
#include "stm32746g_discovery.h"
#include <string.h>

typedef enum button_state {
    PUSH,
    RELEASE
} button_state_t;

typedef enum program_state {
    IGNORE_FIRST_INTERRUPT,
    LED_TURN_ON,
    IGNORE_SECOND_INTERRUPT,
    LED_TURN_OFF
} program_state_t;


volatile button_state_t state = PUSH;
volatile program_state_t program_state = IGNORE_FIRST_INTERRUPT;
volatile uint32_t start = 0;
volatile uint32_t time = 0;

GPIO_InitTypeDef conf;
UART_HandleTypeDef uart_handle;
TIM_HandleTypeDef TimHandle;

#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)

static void SystemClock_Config(void);
static void Error_Handler(void);
static void MPU_Config(void);
static void CPU_CACHE_Enable(void);

void button_init()
{
    __HAL_RCC_GPIOI_CLK_ENABLE();         // enable the GPIOI clock

    conf.Pin = GPIO_PIN_11;               // the pin is the 11
    conf.Pull = GPIO_NOPULL;
    conf.Speed = GPIO_SPEED_FAST;         // port speed to fast
    conf.Mode = GPIO_MODE_IT_RISING_FALLING;

    HAL_GPIO_Init(GPIOI, &conf);          // call the HAL init

    HAL_NVIC_SetPriority(EXTI15_10_IRQn, 0x0F, 0x00);
    HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
}

void timer_init()
{
    __HAL_RCC_TIM2_CLK_ENABLE();

    TimHandle.Instance               = TIM2;
    TimHandle.Init.Period            = 4000;
    TimHandle.Init.Prescaler         = 54000;
    TimHandle.Init.ClockDivision     = TIM_CLOCKDIVISION_DIV1;
    TimHandle.Init.CounterMode       = TIM_COUNTERMODE_UP;
}

int main(void) {

	/* Configure the MPU attributes as Write Through */
	MPU_Config();

	/* Enable the CPU Cache */
	CPU_CACHE_Enable();

	HAL_Init();

	/* Configure the System clock to have a frequency of 216 MHz */
	SystemClock_Config();

	button_init();
	timer_init();

	BSP_LED_Init(LED_GREEN);

	uart_handle.Init.BaudRate = 115200;
	uart_handle.Init.WordLength = UART_WORDLENGTH_8B;
	uart_handle.Init.StopBits = UART_STOPBITS_1;
	uart_handle.Init.Parity = UART_PARITY_NONE;
	uart_handle.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	uart_handle.Init.Mode = UART_MODE_TX_RX;

	BSP_COM_Init(COM1, &uart_handle);


	printf("\n**********WELCOME in timey**********\r\n\n");


	while (1) {
	}
}

void EXTI15_10_IRQHandler()
{
    HAL_GPIO_EXTI_IRQHandler(conf.Pin);
}

void TIM2_IRQHandler()
{
    HAL_TIM_IRQHandler(&TimHandle);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
    switch(state)
    {
    case PUSH:
        start = HAL_GetTick();
        state = RELEASE;
        break;
    case RELEASE:
        time = HAL_GetTick() - start;
        state = PUSH;
        printf("MEASURED TIME IS: %lu ms\r\n", time);

        HAL_NVIC_SetPriority(TIM2_IRQn, 0x0F, 0x00);
        HAL_NVIC_EnableIRQ(TIM2_IRQn);

        HAL_TIM_Base_Init(&TimHandle);
        HAL_TIM_Base_Start_IT(&TimHandle);
        break;
    default:
        break;
        printf("hiba!!!!\r\n");
    }
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if(program_state == IGNORE_FIRST_INTERRUPT)
    {
        printf("ignore first interrupt\r\n");
        program_state = LED_TURN_ON;
        return;
    }
    else if(program_state == LED_TURN_ON)
    {
        BSP_LED_On(LED1);
        HAL_TIM_Base_Stop_IT(&TimHandle);
        HAL_TIM_Base_DeInit(&TimHandle);

        uint32_t prescaler = 54000;
        uint32_t period = ((SystemCoreClock / 2) / prescaler) * ((float)time / (float)1000);

        TimHandle.Instance               = TIM2;
        TimHandle.Init.Period            = period;
        TimHandle.Init.Prescaler         = prescaler;
        TimHandle.Init.ClockDivision     = TIM_CLOCKDIVISION_DIV1;
        TimHandle.Init.CounterMode       = TIM_COUNTERMODE_UP;

        HAL_TIM_Base_Init(&TimHandle);
        HAL_TIM_Base_Start_IT(&TimHandle);

        program_state = IGNORE_SECOND_INTERRUPT;

        printf("led turned on. Period: %lu\r\n", period);
    }
    else if(program_state == IGNORE_SECOND_INTERRUPT)
    {
        program_state = LED_TURN_OFF;
        return;
    }
    else if(program_state == LED_TURN_OFF)
    {
        BSP_LED_Off(LED1);
        printf("led turned off.\r\n");

        HAL_TIM_Base_Stop_IT(&TimHandle);
        HAL_TIM_Base_DeInit(&TimHandle);

        timer_init();
        program_state = IGNORE_FIRST_INTERRUPT;
    }
}

PUTCHAR_PROTOTYPE {
    HAL_UART_Transmit(&uart_handle, (uint8_t *) &ch, 1, 0xFFFF);
    return ch;
}


static void SystemClock_Config(void) {
	RCC_ClkInitTypeDef RCC_ClkInitStruct;
	RCC_OscInitTypeDef RCC_OscInitStruct;

	/* Enable HSE Oscillator and activate PLL with HSE as source */
	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
	RCC_OscInitStruct.HSEState = RCC_HSE_ON;
	RCC_OscInitStruct.HSIState = RCC_HSI_OFF;
	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
	RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
	RCC_OscInitStruct.PLL.PLLM = 25;
	RCC_OscInitStruct.PLL.PLLN = 432;
	RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
	RCC_OscInitStruct.PLL.PLLQ = 9;
	if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
		Error_Handler();
	}

	/* activate the OverDrive to reach the 216 Mhz Frequency */
	if (HAL_PWREx_EnableOverDrive() != HAL_OK) {
		Error_Handler();
	}

	/* Select PLL as system clock source and configure the HCLK, PCLK1 and PCLK2
	 clocks dividers */
	RCC_ClkInitStruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK
			| RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;
	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_7) != HAL_OK) {
		Error_Handler();
	}
}

/**
 * @brief  This function is executed in case of error occurrence.
 * @param  None
 * @retval None
 */
static void Error_Handler(void) {
	/* User may add here some code to deal with this error */
	while (1) {
	}
}

/**
 * @brief  Configure the MPU attributes as Write Through for SRAM1/2.
 * @note   The Base Address is 0x20010000 since this memory interface is the AXI.
 *         The Region Size is 256KB, it is related to SRAM1 and SRAM2  memory size.
 * @param  None
 * @retval None
 */
static void MPU_Config(void) {
	MPU_Region_InitTypeDef MPU_InitStruct;

	/* Disable the MPU */
	HAL_MPU_Disable();

	/* Configure the MPU attributes as WT for SRAM */
	MPU_InitStruct.Enable = MPU_REGION_ENABLE;
	MPU_InitStruct.BaseAddress = 0x20010000;
	MPU_InitStruct.Size = MPU_REGION_SIZE_256KB;
	MPU_InitStruct.AccessPermission = MPU_REGION_FULL_ACCESS;
	MPU_InitStruct.IsBufferable = MPU_ACCESS_NOT_BUFFERABLE;
	MPU_InitStruct.IsCacheable = MPU_ACCESS_CACHEABLE;
	MPU_InitStruct.IsShareable = MPU_ACCESS_SHAREABLE;
	MPU_InitStruct.Number = MPU_REGION_NUMBER0;
	MPU_InitStruct.TypeExtField = MPU_TEX_LEVEL0;
	MPU_InitStruct.SubRegionDisable = 0x00;
	MPU_InitStruct.DisableExec = MPU_INSTRUCTION_ACCESS_ENABLE;

	HAL_MPU_ConfigRegion(&MPU_InitStruct);

	/* Enable the MPU */
	HAL_MPU_Enable(MPU_PRIVILEGED_DEFAULT);
}

/**
 * @brief  CPU L1-Cache enable.
 * @param  None
 * @retval None
 */
static void CPU_CACHE_Enable(void) {
	/* Enable I-Cache */
	SCB_EnableICache();

	/* Enable D-Cache */
	SCB_EnableDCache();
}

#ifdef  USE_FULL_ASSERT

/**
 * @brief  Reports the name of the source file and the source line number
 *         where the assert_param error has occurred.
 * @param  file: pointer to the source file name
 * @param  line: assert_param error line source number
 * @retval None
 */
void assert_failed(uint8_t* file, uint32_t line)
{
	/* User can add his own implementation to report the file name and line number,
	 ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

	/* Infinite loop */
	while (1)
	{
	}
}
#endif

/**
 * @}
 */

/**
 * @}
 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
