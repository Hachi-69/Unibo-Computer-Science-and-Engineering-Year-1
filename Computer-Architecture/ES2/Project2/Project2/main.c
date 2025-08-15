#include <stdio.h>

void main() {
	unsigned int num = 10;
	unsigned int radice;

	__asm {
		MOV EAX, num
		MOV EBX, radice
		XOR EBX, EBX
		MOV EDX, 1

		l2:

		SUB EAX,EDX
		CMP EAX,0

		JS l1

		INC EBX
		INC EDX
		INC EDX

		JMP l2

		l1:
		MOV radice,EBX
	}

	printf("Radice: %d\n",radice);
}