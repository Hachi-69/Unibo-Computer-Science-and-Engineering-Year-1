#include <stdio.h>

void main() {
	unsigned int Num = 65537;
	unsigned int Ris = NULL;

	__asm {
		MOV EAX, 0 // RIS<-0
		MOV EBX, Num

		CMP EBX, 0
		JE l1

		l3:
			MOV ECX, EBX
			AND ECX, 1
			CMP ECX, 1
			JE l2
			SHR EBX,1
			JMP l3

		l2:
			CMP EBX,1
			JE l4
			JMP l1

		l4:
			MOV EAX, 1

		l1:
			MOV Ris,EAX
	}

	printf("Ris=%d\n", Ris);
}