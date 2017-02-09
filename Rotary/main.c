#ifndef F_CPU
#define F_CPU 8000000UL // 8 MHz clock speed
#endif

#include <avr/io.h>
#include <util/delay.h>

#include <lcd.h>

int main(void)
{
  DDRB = 0xFF; //Nakes PORTC as Output
 lcd_init(LCD_DISP_ON_CURSOR);



  while(1) //infinite loop
  {
    lcd_clrscr();             /* clear screen of lcd */
    lcd_home();               /* bring cursor to 0,0 */
    lcd_puts("AAN");        /* type something random */
    PORTB = 0xFF; //Turns ON All LEDs
    _delay_ms(600); //1 second delay
    lcd_clrscr();             /* clear screen of lcd */
    lcd_home();               /* bring cursor to 0,0 */
    lcd_puts("UIT");        /* type something random */
    PORTB= 0x00; //Turns OFF All LEDs
    _delay_ms(350); //1 second delay
    lcd_gotoxy(0,1);          /* go to 2nd row 1st col */
    lcd_puts("display test");  /* type something random */
    _delay_ms(250);            /* wait 50ms */
  }
}
