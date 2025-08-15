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
    unsigned int livello = 8;		// livello massimo del triangolo di tartaglia da generare

    // Output
    unsigned int triangolo[1024];	// risultato: il vettore contiene i numeri del 
    // triangolo dal livello 0 al più alto richiesto

    unsigned int i;
    unsigned int k = 0;

    __asm {
        xor eax, eax; eax = livello corrente
        xor ebx, ebx; ebx = indice globale in triangolo[](k)

        mov     dword ptr[triangolo + ebx * 4], 1; triangolo[0] = 1
        inc     ebx

        prossimo_livello :
        cmp     eax, livello
            jg      fine

            inc     eax; livello++

            ; triangolo[ebx] = 1 (primo valore del nuovo livello)
            mov     dword ptr[triangolo + ebx * 4], 1
            inc     ebx

            mov     ecx, eax; ecx = elementi interni = livello - 1
            dec     ecx
            cmp     ecx, 0
            jle     scrivi_ultimo

            ; calcola base livello precedente = eax * (eax - 1) / 2
            mov     edx, eax
            dec     edx
            imul    edx, eax
            shr     edx, 1; edx = base del livello precedente

            ; i = 0
            xor eax, eax; eax = i(riusiamo EAX come contatore locale)

            loop_interni:
        ; calcola offset = edx + eax
            mov     esi, edx
            add     esi, eax
            mov     edi, dword ptr[triangolo + esi * 4]; triangolo[base + i]

            inc     esi
            mov     edx, dword ptr[triangolo + esi * 4]; triangolo[base + i + 1]

            add     edi, edx
            mov     dword ptr[triangolo + ebx * 4], edi

            inc     ebx
            inc     eax
            loop    loop_interni

            scrivi_ultimo :
        mov     dword ptr[triangolo + ebx * 4], 1
            inc     ebx
            jmp     prossimo_livello

            fine :
        mov     k, ebx
    }



    // Stampa su video
    printf("Triangolo di Tartaglia fino al livello %d\n", livello);
    for (i = 0; i <= livello; i++)
    {
        unsigned int j;
        for (j = 0; j <= i; j++)
            printf("%d ", triangolo[k++]);
        printf("\n");
    }
}


