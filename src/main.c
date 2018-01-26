/*
  Dominik Leon Bieczyński
  Leon Instruments
  http://leon-instruments.blogspot.com

  Data: 24.01.2018
  Dostowanie do płytki eXtrinoXL FULL [Atmel AVR XMEGA128A3U]
  Paweł 'felixd' Wojciechowski
  Outsourcing IT - Konopnickiej.Com
  http://www.konopnickiej.com
 */

#define F_CPU 2000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "hd44780.h"

int main(void)
{

	// konfiguracja przycisku FLIP
	PORTE.DIRCLR = PIN5_bm;				 // pin E5 jako wejście
	PORTE.PIN5CTRL = PORT_OPC_PULLUP_gc; // podciągnięcie do zasilania

	// Inicjalizacja wyświetlacza
	LcdInit(); // inicjalizacja sterownika LCD
	// Lcd("   eXtrino XL   "); // wyświetlenie napisu
	Lcd("CPU: ");
	LcdDec(F_CPU);
	Lcd("Hz");
	Lcd2;					 // przejście do drugiej linii
	Lcd("Konopnickiej.Com"); // wyświetlenie napisu

	// zmienna służąca jako licznik
	uint8_t licznik = 0;

	while (1)
	{
		if (!(PORTE.IN & PIN5_bm))
		{					 // jeżeli przycisk FLIP jest wciśnięty
			licznik++;		 // zwiększ licznik o 1
			LcdClear();		 // wyczyśc wyświetlacz
			Lcd("Licznik:"); // wyświetlenie napisu
			Lcd2;			 // przejście do drugiej linii
			LcdDec(licznik); // wyświetlenie zmiennej liczbowej
			_delay_ms(100);  // czekanie 100ms
		}
	}
}
