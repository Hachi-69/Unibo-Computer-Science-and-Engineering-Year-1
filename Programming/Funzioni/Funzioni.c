#include <stdio.h>


int main(){

    int a[]={3,3,3};

    for (int i=0; i<3; i++){
        printf("%d",a[i]);
    }
    printf("\n\n");

    *a = elabora(a);

    for (int i=0; i<3; i++){
        printf("%d",a[i]);
    }
    return 0;
}

int elabora(int a[]){

    a[3] = (int*)malloc(3 * sizeof(int));
    if  (a==NULL)
        exit(1);

    for (int i=0; i<3; i++){
        a[i]=9;
    }
    return *a;
}
