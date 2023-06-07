#include <avr/io.h>
#include <util/delay.h>
#include <stdbool.h>

int main(void)
{
bool y;
bool a=0,b=0;
DDRB |=(1<<PINB5); // declaring 13 pin as output.
DDRD |=0b00000000; //declaring 2,3 pins as inputs.
PORTD |=0b00001100; //setting pull up for inputs.
 while(1){
 a=(PIND &(1<<PIND2))==(1<<PIND2);
 b=(PIND &(1<<PIND3))==(1<<PIND3);
 y=(!a)|(!b);
 if(y){
 PORTB = (1<<PB5);}
 else{
 PORTB = !(1<<PB5);}}
 return 0;
}
