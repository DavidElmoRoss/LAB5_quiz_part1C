/*
This program should count from 0-6 on the top line of the
LCD continously every 1.5 seconds

What one statement must you add to this code to make this happen
*/
#include "mbed.h"
#include "Grove_LCD_RGB_Backlight.h"

Ticker Carmine;

short counter=0;
char buf[4];

void count(void)
{
    counter++;
}

Grove_LCD_RGB_Backlight lcd(D14,D15);

int main(void)
{
    Carmine.attach(&count,2);                            // YOUR STATEMENT goes on THIS LINE
    lcd.clear();
    lcd.setRGB(0xFF,0x00,0x00);
    for(;;)
    {
        while(counter <=6)
        {
          lcd.locate(7,0);
          sprintf(buf,"%d",counter);
          lcd.print(buf);
        }
        counter=0;
    }
}

