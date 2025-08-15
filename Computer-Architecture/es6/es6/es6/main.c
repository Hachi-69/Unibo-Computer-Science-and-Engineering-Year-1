#include <stdio.h>

void main() {
	unsigned char Vettore[] = { 3,7,3,7,5 };
	unsigned int Lung = sizeof(Vettore) / sizeof(Vettore[0]);
	int Ris; //0 pari 1 dispari

	__asm {
		XOR EAX,EAX //SOMMA
	l5:
		MOV EBX, Vettore[Lung-1] //VAL
	l3:
		CMP EBX,0
		JE l1
		TEST EBX, 1
		JZ l2
		INC EAX
	l2:
		SHR EBX,1
		JMP l3

	l1:
		DEC Lung
		CMP Lung,0
		JZ l4
		JMP l5
	l4:	
		AND EAX,1
		MOV Ris,EAX
	}

	printf("Ris=%d\n", Ris);
}