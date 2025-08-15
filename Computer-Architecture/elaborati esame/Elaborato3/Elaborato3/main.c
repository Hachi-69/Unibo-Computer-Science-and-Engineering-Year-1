/********************************************************************************
 *                                                                              *
 *                   Architetture dei sistemi di Elaborazione                   *
 *                                                                              *
 ********************************************************************************

 Elaborato 3
 Descrizione: Data una sequenza di bit, restituire la lunghezza minima e
              massima delle sotto-sequenze di bit a 0.

 ********************************************************************************/

#include <stdio.h>

void main()
{
    // Input
    unsigned char vet[] = { 0x43,0x00,0xFE }; // Sequenza di bit
    unsigned short int len = 18;               // Lunghezza (in bit) della sequenza

    // Output
    short int minLung; // Lunghezza minima sotto-sequenza di 0
    short int maxLung; // Lunghezza massima sotto-sequenza di 0

    __asm {
        xor eax, eax           // Inizializza EAX come indice del bit (bit index)
        xor ebx, ebx           // Inizializza EBX per contare gli zeri consecutivi
        xor ecx, ecx           // Azzeramento precauzionale
        mov word ptr[minLung], -1  // Valori iniziali: -1 indica nessun valore ancora rilevato
        mov word ptr[maxLung], -1

    analizza:
        movzx edx, len         // Carica in EDX la lunghezza totale della sequenza (in bit)
        cmp eax, edx
        jae  fine              // Se l’indice ha superato la lunghezza, termina

        // Estrae il byte corrente dal vettore in base all'indice del bit
        mov edi, eax
        shr edi, 3             // Calcola l'indice del byte: eax / 8
        mov bl, byte ptr[vet + edi]

        mov edi, eax           // Salva l’indice del bit per dopo (verrà usato in avanza)

        // Calcola la posizione del bit all'interno del byte corrente (modulo 8)
        mov cl, al
        and cl, 7

        // Estrae il bit specifico usando una maschera (1 << cl) & byte
        mov dh, 1
        shl dh, cl
        and dh, bl

        test dh, dh
        jne chiudi_seq         // Se il bit è 1, termina la sequenza di zeri

        // Se il bit è 0, incrementa il contatore e passa al bit successivo
        inc bh                 // bh = numero zeri consecutivi
        inc eax
        jmp analizza

    chiudi_seq:
        cmp bh, 0
        je avanza             // Se nessuno zero è stato contato, salta

        mov edi, eax          // Salva la posizione corrente del bit

        // Gestione massimo
        mov esi,ebx
        mov ax, word ptr[maxLung]
        cmp ax, -1
        je set_max
        mov bl, bh
        xor bh, bh
        cmp bx, ax
        jle skip_max
    set_max:
        mov ebx, esi
        mov bl, bh
        xor bh, bh
        mov word ptr[maxLung], bx
    skip_max:

        // Gestione minimo
        mov ax, word ptr[minLung]
        cmp ax, -1
        je set_min
        cmp bx, ax
        jge skip_min
    set_min:
        mov word ptr[minLung], bx
    skip_min:

        xor ebx, ebx           // Reset del contatore dopo sequenza chiusa

    avanza:
        mov eax, edi           // Ripristina posizione bit dopo interruzione sequenza
        inc eax
        jmp analizza           // Continua analisi

    fine:
        // Alla fine del ciclo, controlla se l'ultima sequenza era di zeri e aggiorna max/min
        mov bl, bh
        xor bh, bh
        cmp bx, 0
        je end                 // Se non ci sono zeri, termina

        // aggiorno max finale se necessario
        mov ax, word ptr[maxLung]
        cmp ax, -1
        je upd_f_max
        cmp bx, ax
        jge upd_f_max
        jmp min
    upd_f_max:
        mov word ptr[maxLung], bx

    min:
        // aggiorno min finale se necessario
        mov ax, word ptr[minLung]
        cmp ax, -1
        je upd_f_min
        cmp bx, ax
        jle upd_f_min
        jmp end
    upd_f_min:
        mov word ptr[minLung], bx
end:
    }
    
    // Stampa su video
    printf("Lunghezza minima delle sotto-sequenze di 0: %d\n", minLung);
    printf("Lunghezza massima delle sotto-sequenze di 0: %d\n", maxLung);
}