#include <stdio.h>

void main() {
	unsigned short num1 = 4;
	unsigned short num2 = 3;
	unsigned int prodotto;

	__asm {
		XOR EDX, EDX
		XOR AX, AX
		XOR CX, CX
		MOV AX, num1
		MOV CX, num2
		l1: 
		ADD DX,AX
	    LOOP l1
		MOV prodotto, EDX
	}

	printf("prodotto = %u\n", prodotto);
}