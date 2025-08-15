/********************************************************************************
*                                                                              *
*                   Computer Architecture Systems                             *
*                                                                              *
********************************************************************************

Assignment 2  
Description: Given the maximum requested level as input, return the corresponding
             Pascal's Triangle by storing the various levels consecutively
             inside a one-dimensional array.

********************************************************************************/

#include <stdio.h>

void main()
{
	// Input
	unsigned int livello = 8;		// maximum level of Pascal's triangle to generate

	// Output
	unsigned int triangolo[1024];	// result: the array contains the numbers of
	// the triangle from level 0 to the highest requested level

	unsigned int i;
	unsigned int k = 0;

    __asm {
        xor ebx, ebx            // EBX = row = 0
        xor ecx, ecx            // ECX = position k
        xor edx, edx            // EDX = index in the triangolo[] array
        xor eax, eax            // holds the current coefficient C(n, k)
        xor edi, edi            // EDI = C(n, k-1) (previous coefficient)
        mov esi, livello        // ESI = maximum level
        inc esi                 // ESI = number of rows = level + 1

        // clear the triangolo[] array
        mov ecx, 1024           // ECX = number of elements to clear

    zero_loop:
        mov[triangolo + ebx * 4], eax  // triangolo[idx] = 0
        inc ebx                        // idx++
        loop zero_loop                 // ECX--, if not zero go back to zero_loop
        xor ebx, ebx
        xor eax, eax

    ciclo_righe :
        mov ecx, 0              // position k = 0
        mov eax, 1              // first coefficient always 1

        mov triangolo[edx * 4], eax // store the first coefficient in triangolo[]
        inc edx                // increment index in triangolo[]

    ciclo_colonne :
        cmp ecx, ebx            // if k >= row, end of row
        jge  fine_riga          // otherwise, compute coefficient C(n, k)

        // Compute next coefficient:
        // C(n,k) = C(n,k-1) * (n - k + 1) / k
        // previous C is in eax
        mov edi, eax            // store C(n,k-1) in EDI

        // compute (n - k + 1)
        mov eax, ebx            // eax = n
        sub eax, ecx            // eax = n - k

        mov esi, edx
        xor edx, edx            // EDX = 0 (for mul)        

        mul edi                 // EAX = EAX * EDI → EAX = C(n,k-1) * (n - k + 1)

        xor edx, edx
        mov edx, esi            // EDX = index in triangolo[]

        // divide by k
        inc ecx                 // k++
        mov edi, ecx            // edi = k

        mov esi, edx
        xor edx, edx            // EDX = 0 (for div)

        div edi                 // eax = result / k

        xor edx, edx
        mov edx, esi            // EDX = index in triangolo[]

        mov triangolo[edx * 4], eax // store the current coefficient in triangolo[]
        inc edx
        jmp ciclo_colonne

        fine_riga :
            dec ecx
            inc ebx                 // row++
            mov esi, livello        // ESI = maximum level
            inc esi                 // ESI = number of rows = level + 1
            cmp ebx, esi           // if row < level+1, continue
            jne ciclo_righe
    }

	// Print to screen
	printf("Pascal's Triangle up to level %d\n", livello);
	for (i = 0; i <= livello; i++)
	{
		unsigned int j;
		for (j = 0; j <= i; j++)
			printf("%d ", triangolo[k++]);
		printf("\n");
	}
}
