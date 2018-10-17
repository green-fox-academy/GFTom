#include "stm32f7xx.h"
#include "stm32746g_discovery.h"
#include <string.h>

UART_HandleTypeDef uart_handle;			// UART INIT
GPIO_InitTypeDef led_green;					// LED INIT
GPIO_InitTypeDef led_red;					// LED INIT
GPIO_InitTypeDef blue_button;
TIM_HandleTypeDef tim_2;				//timer1 typdef
TIM_OC_InitTypeDef sConfig;

//#undef __GNUC__
#ifdef __GNUC__

#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif /* __GNUC__ */

static void SystemClock_Config(void);
static void Error_Handler(void);
static void MPU_Config(void);
static void CPU_CACHE_Enable(void);

volatile int state = 0;
volatile int tim2_state = 0;
volatile int button_press_counter = 0;
volatile int ignore_first_interrupt = 0;


void button_init() {
	__HAL_RCC_GPIOI_CLK_ENABLE();

	blue_button.Pin = GPIO_PIN_11;
	blue_button.Pull = GPIO_NOPULL;
	blue_button.Speed = GPIO_SPEED_FAST;
	blue_button.Mode = GPIO_MODE_IT_RISING;

	HAL_GPIO_Init(GPIOI, &blue_button);
}

void led_red_init() {
	__HAL_RCC_GPIOF_CLK_ENABLE();

	led_red.Pin = GPIO_PIN_10;
	led_red.Mode = GPIO_MODE_OUTPUT_PP;
	led_red.Pull = GPIO_PULLDOWN;
	led_red.Speed = GPIO_SPEED_HIGH;

	HAL_GPIO_Init(GPIOF, &led_red);
}


void led_green_init() {
	__HAL_RCC_GPIOF_CLK_ENABLE();

	led_green.Pin = GPIO_PIN_9;
	led_green.Mode = GPIO_MODE_OUTPUT_PP;
	led_green.Pull = GPIO_PULLDOWN;
	led_green.Speed = GPIO_SPEED_HIGH;

	HAL_GPIO_Init(GPIOF, &led_green);
}

void timer_init() {
	__HAL_RCC_GPIOI_CLK_ENABLE();
	__HAL_RCC_TIM2_CLK_ENABLE();

	tim_2.Instance = TIM2;
	tim_2.Init.Period = 9999;
	tim_2.Init.Prescaler = 32400;
	tim_2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	tim_2.Init.CounterMode = TIM_COUNTERMODE_UP;

	HAL_TIM_Base_Init(&tim_2);
	HAL_TIM_Base_Start_IT(&tim_2);
}


int main(void) {

	MPU_Config();
	CPU_CACHE_Enable();
	HAL_Init();
	SystemClock_Config();

	uart_handle.Init.BaudRate = 115200;
	uart_handle.Init.WordLength = UART_WORDLENGTH_8B;
	uart_handle.Init.StopBits = UART_STOPBITS_1;
	uart_handle.Init.Parity = UART_PARITY_NONE;
	uart_handle.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	uart_handle.Init.Mode = UART_MODE_TX_RX;

	BSP_COM_Init(COM1, &uart_handle);
	BSP_LED_Init(LED_GREEN);

	button_init();
	timer_init();
	led_red_init();
	led_green_init();

	HAL_NVIC_SetPriority(EXTI15_10_IRQn, 0x0F, 0x00);
	HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);

	HAL_NVIC_SetPriority(TIM2_IRQn, 0x0F, 0x00);
	HAL_NVIC_EnableIRQ(TIM2_IRQn);

	printf("pedestrian_crossing\r\n");

	while (1) {
	}

}   // end of main   {}

// ******************************timer inicializalas

void TIM2_IRQHandler() {
	HAL_TIM_IRQHandler(&tim_2);
}


void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {

	if (ignore_first_interrupt == 0) {
		ignore_first_interrupt++;
	} else if (tim2_state == 0 && button_press_counter == 0 ) {
		HAL_TIM_Base_Stop_IT(&tim_2);
		TIM2->ARR = 9999;
		__HAL_TIM_SET_COUNTER(&tim_2, 0);
		HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, GPIO_PIN_RESET);
		printf("Changed to green, you can come across.\r\n");
		HAL_TIM_Base_Start_IT(&tim_2);
		tim2_state = 1;
	} else if (tim2_state == 1 && button_press_counter == 0) {
		HAL_TIM_Base_Stop_IT(&tim_2);
		TIM2->ARR = 23331;
		__HAL_TIM_SET_COUNTER(&tim_2, 0);
		HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, GPIO_PIN_SET);
		printf("Changed to red, please wait 7 seconds\r\n");
		HAL_TIM_Base_Start_IT(&tim_2);
		tim2_state = 0;
	} else if ( tim2_state == 0 && button_press_counter != 0) {
		HAL_TIM_Base_Stop_IT(&tim_2);
		TIM2->ARR = 3333;
		__HAL_TIM_SET_COUNTER(&tim_2, 0);
		HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, GPIO_PIN_SET);
		printf("Changed to green, you can come across.\r\n");
		HAL_TIM_Base_Start_IT(&tim_2);
		tim2_state = 0;
		button_press_counter = 0;
	}
}

// ******************************
// ******************************button interrupt inicializalas
void EXTI15_10_IRQHandler() {
	HAL_GPIO_EXTI_IRQHandler(blue_button.Pin);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
	printf("Intention to come accross, wait 1 second. Changed to green, you can come across.\r\n");
	HAL_TIM_Base_Stop_IT(&tim_2);
	TIM2->ARR = 3333;
	__HAL_TIM_SET_COUNTER(&tim_2, 0);
	HAL_TIM_Base_Start_IT(&tim_2);
	button_press_counter++;
}

// ******************************

PUTCHAR_PROTOTYPE {

	HAL_UART_Transmit(&uart_handle, (uint8_t *) &ch, 1, 0xFFFF);

	return ch;
}

static void SystemClock_Config(void) {
	RCC_ClkInitTypeDef RCC_ClkInitStruct;
	RCC_OscInitTypeDef RCC_OscInitStruct;

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

	if (HAL_PWREx_EnableOverDrive() != HAL_OK) {
		Error_Handler();
	}

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

static void Error_Handler(void) {

	while (1) {
	}
}

static void MPU_Config(void) {
	MPU_Region_InitTypeDef MPU_InitStruct;

	HAL_MPU_Disable();

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
	HAL_MPU_Enable(MPU_PRIVILEGED_DEFAULT);
}

static void CPU_CACHE_Enable(void) {
	SCB_EnableICache();
	SCB_EnableDCache();
}

#ifdef  USE_FULL_ASSERT

void assert_failed(uint8_t* file, uint32_t line)
{

	while (1)
	{
	}
}
#endif
