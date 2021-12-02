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

