#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *inputFile, *outputFile;
    int counter = 0;
    int vocali = 0;
    char ch;

    // Apri il file in modalità lettura
    inputFile = fopen("testo.txt", "r");
    outputFile = fopen("testoOutput.txt", "w");
    if (inputFile == NULL || outputFile == NULL) {
        printf("Errore nell'aprire il file.\n");
        return 1;
    }

    // Leggi i caratteri uno alla volta
    while ((ch = fgetc(inputFile)) != EOF) {
        // Controlla se il carattere è alfanumerico
        if (isalnum(ch)) {
            counter++;
        }

        if (!(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
              ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')) {
            fprintf(outputFile,"%c",ch);
            vocali++;
        }
    }

    printf("Numero di caratteri alfanumerici: %d\n", counter);
    printf("Numero di vocali: %d\n", vocali);

    // Chiudi il file
    fclose(inputFile);
    fclose(outputFile);

    outputFile = fopen("testoOutput.txt", "r");
    if (outputFile == NULL) {
        printf("Errore nell'aprire il file.\n");
        return 1;
    }

    char c;
    printf("\nContenuto di OutputFile\n");
    while ((c = fgetc(outputFile)) != EOF) {
        putchar(c);
    }
    printf("\n\n");
    return 0;
}
