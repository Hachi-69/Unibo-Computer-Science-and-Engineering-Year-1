
/********************************************************************************
 *                                                                              *
 *                   Architetture dei sistemi di Elaborazione                   *
 *                                                                              *
 ********************************************************************************

 Elaborato 3
 Descrizione:	Data una sequenza di bit, restituire la lunghezza minima e
				massima	delle sotto-sequenze di bit a 0.

 ********************************************************************************/

#include <stdio.h>

void main()
{
	// Input
	unsigned char vet[] = { 0xBC,0xFF,0x01 };	// Sequenza di bit
	unsigned short int len = 18;				// Lunghezza (in bit) della sequenza

	// Output
	short int minLung;		// Lunghezza minima sotto-sequenza di 0
	short int maxLung;		// Lunghezza massima sotto-sequenza di 0

	__asm
	{

	}

	// Stampa su video
	printf("Lunghezza minima delle sotto-sequenze di 0: %d\n", minLung);
	printf("Lunghezza massima delle sotto-sequenze di 0: %d\n", maxLung);
}
