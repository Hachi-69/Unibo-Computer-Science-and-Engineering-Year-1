#include <stdio.h>
#define gV 5
int main () {
//    int vettore [gV];
//    int min = 99999;
//    for (int i=0; i<gV; i++){
//        scanf("%d",&vettore[i]);
//        if (vettore[i] < min){
//            min = vettore[i];
//        }
//
//    }
//
//    printf("il numero piu piccolo e: %d \n", min);

    int vettore [gV];
    int temp = 0;
    for (int i=0; i<gV; i++){
        scanf("%d",&vettore[i]);
    }

    for (int i = 0; i < gV-1; i++) {
        for (int j = 0; j < gV-1-i; j++) {
            if (vettore[j] > vettore[j + 1]) {
                temp = vettore[j];
                vettore[j] = vettore[j + 1];
                vettore[j + 1] = temp;
            }
        }
    }

//    for (int i = 0; i < gV-1; i++) {
//        for (int j = 0; j < gV-1-i; j++) {
//            if(vettore[j+1]<vettore[j]){
//                temp = vettore[j];
//                vettore[j]=vettore[j+1];
//                vettore[j+1]=temp;
//            }
//        }
//    }




    printf("Array ordinato in ordine crescente: ");
    for (int i = 0; i < gV; i++) {
        printf("%d ", vettore[i]);
    }
}
