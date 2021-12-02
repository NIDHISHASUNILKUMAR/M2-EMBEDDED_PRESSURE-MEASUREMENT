# Introduction:

In hospital operating theatres, semiconductor manufacturing facilities, computer data centers and biochemical research laboratories, it is necessary to ensure either a slightly higher or lower air pressure to prevent a contaminated atmosphere leaking outside or a clean atmosphere becoming contaminated from outside air.So inorder to have an idea over our surrounding pressure'pressure measurement' is important.

# Features:

* Detects the room pressure and displays value of pressure on the display.
* Simple circuit design and easy to. Understand.
* Obtaining accurate and meaningful data is important in determining the quality and consistency of the product. For these reasons, accurate sensors are absolutely critical in obtaining this information.

# 4W'S and 1H:

## What:

It gives an awareness over the pressure in which we are residing .

## Why:

 Pressure measuring instruments are used to measure the pressure of liquids or gases to maintain the quality standards of the products, for safety concerns of the units, to avoid explosions, to maintain the efficient working of machinery as well as controlling pressure is important for the longevity of the machinery.
 
 ## Where:
 
 *Used in automotive industry, engine control, weather stations etc.
 
 *Hospital operating theatres, semiconductor manufacturing facilities, computer data centers and biochemical research laboratories. 
 
 ## Who:
 
It does not require the manual involvement to detect. So anyone who needs can use this.
 
 ## How:
 
  A sensor which is the main part of this project and it is the one which detects and displays the value.
  
 # Swot Analysis:

 ## Strength: 
 
 It's strength is compact in size and accuracy in displaying the correct pressure.

## Weakness:

Since we are using tiny electronic component we have to be careful.

## Opportunity:

We should create an opportunity to make our product used by everyone by providing an awareness over the adverse effects of over the pressure and importance of surveiling the pressure.

## Threat:

Most of the people know about this features but we need to prove the importance of this device in each and every embedded projects to get aware.

# REQUIREMENTS:

## High level requirements:

SL.NO    | High level requirements | Description | Status 
---------|-------------------------|-------------|-------
1|HLR1|ATMEGA328|Done
2|HLR2|Sensor|Done
3|HLR3|LCD Display|Done

## Low level requirements:

SL.NO    | High level requirements | Description | Status 
---------|-------------------------|-------------|-------
1|LR1|Simulide|Done
2|LR2|Avr Gcc compiler	|Done
3|LR3|Buzzer|Done


# Design:

## Flowchart:

![pressureflowchart1](https://user-images.githubusercontent.com/94303567/144361198-b1947fb5-e149-4285-a5c2-3732ebb26735.jpg)

## Block diagram:

![pressure block diagram](https://user-images.githubusercontent.com/94303567/144361362-ff3585c7-f65f-41c9-a63d-98f9c762ff43.jpg)

The internal block diagram of MPX4115A pressure sensor is shown below. It has three pins +5 volt input pin, ground pin and output pin and we measure the output voltage from this pin and convert it back in pressure using the formula.

![MPX4115A PRESSURE SENSOR](https://user-images.githubusercontent.com/94303567/144296632-8e76413f-7139-4d1f-9c48-6f4ec30a43f3.jpg)

# Implementation:

// LCD module connections

sbit LCD_RS at LATC0_bit;

sbit LCD_EN at LATC1_bit;

sbit LCD_D4 at LATC2_bit;

sbit LCD_D5 at LATC3_bit;

sbit LCD_D6 at LATC4_bit;

sbit LCD_D7 at LATC5_bit;

sbit LCD_RS_Direction at TRISC0_bit;

sbit LCD_EN_Direction at TRISC1_bit;

sbit LCD_D4_Direction at TRISC2_bit;

sbit LCD_D5_Direction at TRISC3_bit;

sbit LCD_D6_Direction at TRISC4_bit;

sbit LCD_D7_Direction at TRISC5_bit;

// End LCD module connections


unsigned int ADCResult=0;

float pressure;

unsigned char txt[15];


void main() {

 OSCCON=0x66; //Configure to use 8MHz internal oscillator.
 
 
 ANSELC=0X00;
 
 ANSELA=0XFF;
 
 TRISA.RA0 = 1; // Configure RA0 pin as input

ADC_Init(); // Initialize ADC

Lcd_Init(); // Initialize LCD

 Lcd_Cmd(_LCD_CLEAR); // Clear display
 
 Lcd_Cmd(_LCD_CURSOR_OFF); // Cursor off

Lcd_Out(1, 1, "microcontrollers"); // Display "StudentCompanion"

 Lcd_Out(2, 1, "lab.com"); // Display "barometer"
 Delay_ms(2000); // 2 Second delay
 
 Lcd_Cmd(_LCD_CLEAR); // Clear display

do {
 ADCResult = ADC_Read(0);
 
 pressure = (ADCResult*5.0)/1023;
 
 pressure = (pressure + 0.475)/0.0475;
 
 FloatToStr(pressure, txt);
 
 Lcd_Out(1, 1, "P = ");
 
 Lcd_Out_Cp(txt);
 
 Lcd_Out_Cp("KPa");

} while(1);

}


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

# Test plan and output:

SL.NO    | High level requirements | Description | Status 
---------|-------------------------|-------------|-------
1|HLR1|ATMEGA328|Done
2|HLR2|Sensor|Done
3|HLR3|LCD Display|Done

## Low level requirements:

SL.NO    | High level requirements | Description | Status 
---------|-------------------------|-------------|-------
1|LR1|Simulide|Done
2|LR2|Avr Gcc compiler	|Done
3|LR3|Buzzer|Done







