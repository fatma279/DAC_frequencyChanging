/*  Author  : fatma                          */
/*  Date    : 19 December 2021                  */
/*  version : V1                             */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "DAC_interface.h"
#include "DAC_private.h"
#include "DAC_config.h"

#include <song.h>



volatile u16 flag1=0;
volatile u16 flag2=0;
//volatile u16 flag3=0;
//volatile u16 flag4=0;

void DAC_voidInit(void)
{
	   MGPIO_voidSetPinDirection(GPIOA, PIN8, OUTPUT_SPEED_2MHZ_PP);
	   MGPIO_voidSetPinDirection(GPIOA, PIN9, OUTPUT_SPEED_2MHZ_PP);
	   MGPIO_voidSetPinDirection(GPIOA, PIN10, OUTPUT_SPEED_2MHZ_PP);
	   MGPIO_voidSetPinDirection(GPIOA, PIN11, OUTPUT_SPEED_2MHZ_PP);
	   MGPIO_voidSetPinDirection(GPIOA, PIN12, OUTPUT_SPEED_2MHZ_PP);
	   MGPIO_voidSetPinDirection(GPIOA, PIN15, OUTPUT_SPEED_2MHZ_PP);
	   MGPIO_voidSetPinDirection(GPIOC, PIN13, OUTPUT_SPEED_2MHZ_PP);
	   MGPIO_voidSetPinDirection(GPIOC, PIN14, OUTPUT_SPEED_2MHZ_PP);


}


void voidSetDAC_Man(void)
{

	u8 Local_u8BIT;


	if(flag1<50620)
	{
		for(int iteration=0; iteration<8; iteration++)
		{
			/* Get bit value */
			Local_u8BIT = GET_BIT(adele_raw[flag1],iteration);

			/*Set value in desire pin */
			MGPIO_voidSetPinValue(PIN_DATA[iteration][0],PIN_DATA[iteration][1], Local_u8BIT);
		}
	}

	flag1 ++;

}


void voidSetDAC_Woman(void)
{

	u8 Local_u8BIT;

	if(flag2 < 50620)
	{
		for(int iteration=0; iteration<8; iteration++)
		{
			/* Get bit value */
			Local_u8BIT = GET_BIT(adele_raw[flag2],iteration);

			/*Set value in desire pin */
			MGPIO_voidSetPinValue(PIN_DATA[iteration][0],PIN_DATA[iteration][1], Local_u8BIT);
		}
	}

	flag2 ++;
}


