/**
 ******************************************************************************
 * @file    main.c
 * @author  Ac6
 * @version V1.0
 * @date    01-December-2013
 * @brief   Default main function.
 ******************************************************************************
 */
#include "stm32f7xx.h"
#include "stm32746g_discovery.h"
#include <string.h>

UART_HandleTypeDef uart_handle;			// UART INIT
GPIO_InitTypeDef led_green;					// LED INIT
GPIO_InitTypeDef led_red;					// LED INIT
GPIO_InitTypeDef blue_button;
GPIO_InitTypeDef led_green_2;
TIM_HandleTypeDef tim_2;				//timer1 typdef
TIM_HandleTypeDef tim_pwm;
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

volatile int state = 0;  // global valtozo
volatile int tim2_state = 0;
volatile int button_press_counter = 0;
volatile int ignore_first_interrupt = 0;
volatile int led_counter = 0;
volatile int info_printer = 0;

void button_init() {
	__HAL_RCC_GPIOI_CLK_ENABLE()
	;         			// enable the GPIOI clock

	blue_button.Pin = GPIO_PIN_11;             		// the pin is the 11
	blue_button.Pull = GPIO_NOPULL;
	blue_button.Speed = GPIO_SPEED_FAST;       		// port speed to fast
	blue_button.Mode = GPIO_MODE_IT_RISING;

	HAL_GPIO_Init(GPIOI, &blue_button);          	// call the HAL init
}

void led_init() {
	__HAL_RCC_GPIOA_CLK_ENABLE()
	;   		 		// we need to enable the GPIOA port's clock first

	led_red.Pin = GPIO_PIN_15;            				// this is about PIN 0
	led_red.Mode = GPIO_MODE_OUTPUT_PP; // Configure as output with push-up-down enabled
	led_red.Pull = GPIO_PULLDOWN;    // the push-up-down should work as pulldown
	led_red.Speed = GPIO_SPEED_HIGH;     		// we need a high-speed output

	HAL_GPIO_Init(GPIOA, &led_red); // initialize the pin on GPIOA port with HAL
}

void led_green_init() {
	__HAL_RCC_GPIOB_CLK_ENABLE();		// we need to enable the GPIOA port's clock first

	led_green.Pin = GPIO_PIN_4;			// this is about PIN 0
	led_green.Mode = GPIO_MODE_AF_PP; 	// pwm push pull
	led_green.Pull = GPIO_PULLDOWN;  	// the push-up-down should work as pulldown
	led_green.Speed = GPIO_SPEED_HIGH;	// we need a high-speed output
	led_green.Alternate = GPIO_AF2_TIM3;

	HAL_GPIO_Init(GPIOB, &led_green); // initialize the pin on GPIOA port with HAL
}

void led_green_2_init() {
	__HAL_RCC_GPIOF_CLK_ENABLE();   		 		// we need to enable the GPIOA port's clock first

	led_green_2.Pin = GPIO_PIN_9;            			// this is about PIN 0
	led_green_2.Mode = GPIO_MODE_OUTPUT_PP; // Configure as output with push-up-down enabled
	led_green_2.Pull = GPIO_PULLDOWN; // the push-up-down should work as pulldown
	led_green_2.Speed = GPIO_SPEED_HIGH;     	// we need a high-speed output

	HAL_GPIO_Init(GPIOF, &led_green_2); // initialize the pin on GPIOA port with HAL
}

void timer_init() {
	__HAL_RCC_GPIOI_CLK_ENABLE();
	__HAL_RCC_TIM2_CLK_ENABLE();

	tim_2.Instance = TIM2;
	tim_2.Init.Period = 16665;    //108000000 / 32400 = ... * X sec
	tim_2.Init.Prescaler = 32400;
	tim_2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	tim_2.Init.CounterMode = TIM_COUNTERMODE_UP;

	HAL_TIM_Base_Init(&tim_2);
	HAL_TIM_Base_Start_IT(&tim_2);
}


void timer_init_pwn() {
	__HAL_RCC_GPIOI_CLK_ENABLE();
	__HAL_RCC_TIM3_CLK_ENABLE();

	tim_pwm.Instance = TIM3;
	tim_pwm.Init.Period = 100;    //108000000 / 32400 = ... * X sec
	tim_pwm.Init.Prescaler = 1;
	tim_pwm.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	tim_pwm.Init.CounterMode = TIM_COUNTERMODE_UP;

	HAL_TIM_Base_Init(&tim_pwm);

	HAL_TIM_Base_Start(&tim_pwm); //it is a little bit weird, but you have to call it too, before starting PWM

	HAL_TIM_PWM_Init(&tim_pwm);

	sConfig.OCMode = TIM_OCMODE_PWM1;
	sConfig.Pulse = 10;

	HAL_TIM_PWM_ConfigChannel(&tim_pwm, &sConfig, TIM_CHANNEL_1);

//	HAL_TIM_PWM_Start(&tim_pwm, TIM_CHANNEL_1);
}

int main(void) {

	MPU_Config();
	CPU_CACHE_Enable();
	HAL_Init();
	SystemClock_Config();

	uart_handle.Init.BaudRate = 115200;                     // UART STRUCT
	uart_handle.Init.WordLength = UART_WORDLENGTH_8B;
	uart_handle.Init.StopBits = UART_STOPBITS_1;
	uart_handle.Init.Parity = UART_PARITY_NONE;
	uart_handle.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	uart_handle.Init.Mode = UART_MODE_TX_RX;

	BSP_COM_Init(COM1, &uart_handle);                       // BSP INIT
	BSP_LED_Init(LED_GREEN);                                // LED BSP INIT

	timer_init();
	timer_init_pwn();
	led_init();
	led_green_init();
	button_init();
	led_green_2_init();

	HAL_NVIC_SetPriority(EXTI15_10_IRQn, 0x0F, 0x00);
	HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);

	HAL_NVIC_SetPriority(TIM2_IRQn, 0x0F, 0x00);
	HAL_NVIC_EnableIRQ(TIM2_IRQn);

	printf("***button press counter\r\n***");   // print to hercules with uart

	while (1) {
	}

}   // end of main   {}

// ******************************timer inicializalas

void TIM2_IRQHandler() {
	HAL_TIM_IRQHandler(&tim_2);
}

void TIM3_IRQHandler() {
	HAL_TIM_IRQHandler(&tim_pwm);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {

	if (ignore_first_interrupt == 0) {
		ignore_first_interrupt++;
	} else if (tim2_state == 0 && led_counter < button_press_counter) {
		if(info_printer == 0) {
			printf("You pressed the button %d times\r\n", button_press_counter);
			printf("Program is in blinking state, wait for %d sec\r\n", button_press_counter * 3);
		info_printer++;
		}
		HAL_TIM_Base_Stop_IT(&tim_2);
		TIM2->ARR = 1111;
		__HAL_TIM_SET_COUNTER(&tim_2, 0); // visszaállítja a timer-t nullara
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_SET);
	    HAL_TIM_PWM_Start(&tim_pwm, TIM_CHANNEL_1);
		HAL_TIM_Base_Start_IT(&tim_2);
		led_counter++;
		tim2_state = 1;
	} else if (tim2_state == 1 && led_counter < button_press_counter) {
		HAL_TIM_Base_Stop_IT(&tim_2);
		TIM2->ARR = 2222;
		__HAL_TIM_SET_COUNTER(&tim_2, 0); // visszaállítja a timer-t nullara
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_RESET);
	    HAL_TIM_PWM_Stop(&tim_pwm, TIM_CHANNEL_1);
		HAL_TIM_Base_Start_IT(&tim_2);
		tim2_state = 0;
	} else if (led_counter == button_press_counter) {
		printf("timer off, program stop\r\n");
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_RESET);
	    HAL_TIM_PWM_Stop(&tim_pwm, TIM_CHANNEL_1);
		HAL_TIM_Base_Stop_IT(&tim_2);
		HAL_TIM_Base_DeInit(&tim_2);
	}
}

// ******************************
// ******************************button interrupt inicializalas
void EXTI15_10_IRQHandler() {
	HAL_GPIO_EXTI_IRQHandler(blue_button.Pin);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
	printf("Button is pressed and released\n");

	HAL_TIM_Base_Stop_IT(&tim_2);
	__HAL_TIM_SET_COUNTER(&tim_2, 0);  // visszaállítja a timer-t nullara
	button_press_counter++;
	HAL_TIM_Base_Start_IT(&tim_2);

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
