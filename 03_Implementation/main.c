/**
 * @file main.c
 * @author your name (achyuthrudru1999@gamil.com)
 * @brief 
 * @version 0.1
 * @date 2021-09-16
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "activity1.h"
#include "activity2.h"
#include "activity3.h"

int main(void)
{
    uint16_t pressure;
        if(activity1_LED()==1) //Check if both the switches are pressed
        {
           
            TurnLED_ON();//Turn LED ON
            pressure=activity2_GetADC(); //Get the ADC value
            activity3_PWM(pressure); //PWM output based on pressure
		    activity3_USARTWrite(pressure); //To Serial monitor to print pressure
            

        }
        else  //in all other cases
        {
            TurnLED_OFF();//Turn LED OFF
		    _delay_ms(200);
        }

    }
    return 0;
}
