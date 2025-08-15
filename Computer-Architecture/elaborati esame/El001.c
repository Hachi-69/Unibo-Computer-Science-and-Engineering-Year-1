/********************************************************************************
 *                                                                              *
 *                   Architetture dei sistemi di Elaborazione                   *
 *                                                                              *
 ********************************************************************************

 Elaborato 1
 Descrizione:	Cifrare/decifrare il testo data la parola chiave. Nel testo cifrato
				il codice ASCII di ogni carattere è aumentato del codice ASCII del
				corrispondente carattere nella parola chiave sovrapposta (e ripetuta
				se necessario) al testo.

 ********************************************************************************/

#include <stdio.h>

void main()
{
	// Input
	char testo[] = "Questo e' un elaborato di ARC";
	char chiave[] = "Architetture";
	char decifra = 0; // 0 = cifra; 1 = decifra

	// Output
	char risultato[1024];

	__asm
	{

	}

	// Stampa su video
	printf("Risultato: |%s|\n", risultato);
	{ // N.B. Nella stringa precedente alcuni caratteri possono non essere stampabili: 
	  //    crea anche una stringa con tutti i caratteri come codici ascii esadecimali
		char* t = risultato;
		while (*t)
		{
			printf("\\x%02X", (unsigned char)(*t++));
		}
	}
}


