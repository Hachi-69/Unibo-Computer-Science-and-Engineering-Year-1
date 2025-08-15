#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *file;
    int counter = 0;
    char ch;

    // Apri il file in modalità lettura
    file = fopen("nomefile.txt", "r");
    if (file == NULL) {
        printf("Errore nell'aprire il file.\n");
        return 1;
    }

    // Leggi i caratteri uno alla volta
    while ((ch = fgetc(file)) != EOF) {
        // Controlla se il carattere è alfanumerico
        if (isalnum(ch)) {
            counter++;
        }
    }

    // Chiudi il file
    fclose(file);

    // Stampa il numero di caratteri alfanumerici
    printf("Numero di caratteri alfanumerici: %d\n", counter);
    return 0;
}
