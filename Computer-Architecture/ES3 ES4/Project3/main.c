#include <stdio.h>

void main() {
	char Stringa[] = "Questa è una stringa";
	int Lunghezza = sizeof(Stringa) - 1;
	char Carattere = 'è';
	int Posizione=NULL;

	__asm {
		MOV ECX, 0 // I<-0
		MOV EAX, Lunghezza
		MOV BL, Carattere

		l4:
		CMP ECX, EAX
		JAE l1
		JMP l2

		l1:
		MOV ECX, -1
		JMP l3

	    l2:
		MOV BH,Stringa[ECX]
		CMP BH,BL
		JE l3
		INC ECX
		JMP l4


		l3:
		MOV Posizione, ECX
	}

	printf("Posizione=%d\n", Posizione);
}