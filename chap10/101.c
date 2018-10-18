#include <stdio.h>
#include <stdlib.h>

void PrintArray(int Ary[], int index){
    int i;
    printf("Array:{ ");
    for(i=0;i<index;i++){
        printf("%d ",Ary[i]);
    }
    printf("}\n");
}

void merge(int A[], int B[], int lastA, int lastB){

    int indexA = lastA-1;
    int indexB = lastB-1;
    int indexMerged = lastA + lastB - 1;

    while(indexB >=0){
        if(indexA >= 0 && A[indexA]>B[indexB]){
            A[indexMerged] = A[indexA];
            indexA--;
        }else{
            A[indexMerged] = B[indexB];
            indexB--;
        }
        indexMerged--;
    }
}

int main(void){

    int i;

    int A[] = {1,2,3,5,7,11,13,17,19,23};
    int B[] = {1,2,3,5,8,13,21,34,55,89};

    int lastA = sizeof(A)/sizeof(A[0]);
    int lastB = sizeof(B)/sizeof(B[0]);
    int lastMerged = lastA+lastB;

    int *newA = (int *)malloc(sizeof(int)*lastMerged); //配列の確保
    if (newA == NULL) exit(0);
    for(i=0;i<lastA;i++){
        newA[i] = A[i];
    }

    PrintArray(newA,lastA);
    merge(newA,B,lastA,lastB);

    PrintArray(newA,lastMerged);
    
    free(newA);
    return 0;
}

