#include <stdio.h>
#include <stdlib.h>
#define MSIZE 25

void arr_print( const int* a, int n){ 
    int i, j;
    for (i = 0; i < n; i++){
        j = 0;
        for (j; j < n; j++){
            printf("%3d ", *(a+MSIZE*i + j) );
        }
        printf("\n");
    }
}

void fill( int (*a)[MSIZE], int size){
    int r0 = 0;                                // границы рамки
    int r1 = size;
    int i;                                     // строка
    int j;                                     // столбец
    int k = 1;                                 // значние, присваиваемое элементу массива 
    
    while(size>0){
        i = r0;                                // верх рамки
        j = r0;
        for (j; j < r1; j++){
            a[i][j] = k;
            k++;
        }
        j--;                                   // правый бок рамки
        i++;
        for (i; i < r1; i++){
            a[i][j] = k;
            k++;
        }
        j--;                                   // низ рамки
        i--;
        for (j; j >= r0 ; j--){
            a[i][j] = k;
            k++;
        }
        j++;                                   // левый бок рамки
        i--;
        for (i; i >= r0+1; i--){
            a[i][j] = k;
            k++;
        }
        
        r0++;                                  // уменьшаем рамку
        r1--;
        size-=2;
    }
}

int main(){
    int n;
    int a[MSIZE][MSIZE];
    printf("Print integer (<=%d) ", MSIZE);
    scanf("%d",&n);
    if (n > MSIZE) { n = MSIZE; }
    
    //заполняем матрицу по "рамкам"
    int size = n;
    int r0 = 0;                                //границы рамки
    int r1 = size;
    int i;                                     // строка
    int j;                                     // столбец
    int k = 1;                                 // значние, присваиваемое элементу массива 
    
    while(size>0){
        i = r0;                                // верх рамки
        j = r0;
        for (j; j < r1; j++){
            a[i][j] = k;
            k++;
        }
        j--;                                   // правый бок рамки
        i++;
        for (i; i < r1; i++){
            a[i][j] = k;
            k++;
        }
        j--;                                   // низ рамки
        i--;
        for (j; j >= r0 ; j--){
            a[i][j] = k;
            k++;
        }
        j++;                                   // левый бок рамки
        i--;
        for (i; i >= r0+1; i--){
            a[i][j] = k;
            k++;
        }
        
        r0++;
        r1--;
        size-=2;
    }
    printf("Filling in main()\n");
    arr_print(a,n);
    
    fill(a, n-1); //на единицу меньше размер, для проверки
    printf("Filling in fill()\n");
    arr_print(a,n-1);

}
