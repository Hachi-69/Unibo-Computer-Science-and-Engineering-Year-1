#include <stdio.h>

int main(){
    char lettera;
    int numero;
    FILE *fp;

    fp = fopen("c:/documenti/miofile.txt","r");

    if(fp == NULL){
        printf("errore");
        exit(1);
    }

    fscanf(fp,"%c",&lettera);
    fscanf(fp,"%d",&numero);

    lettera = getc(fp);
    lettera = fgetc(fp);

    if(lettera == EOF)
        // end of file

    stringa = fgets(buffer,n,fp);

    fclose(fp);

    fp = fopen("c:/documenti/miofile.txt","w");

    if(fp == NULL)
        exit(1);

    fprintf(fp,"Questa è una lettera: %c, Questo è un numero: %d",lettera,numero);

    fclose(fp);
}
