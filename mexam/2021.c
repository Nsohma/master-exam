#include <stdio.h>

void func1(int a[], int i, int j);
void func2(int a[], int m);
void func3(int a[], int m);
void swap(int a[], int i, int j);


int main(void){
    int a[10];
    for (int i=0; i<10; i++){
        a[i] = 10-i;
    }
    func3(a, 10);
    for (int i=0; i<10; i++){
        printf("a[%d]:%d ", i, a[i]);
    }
}

void swap(int a[], int i, int j){
    int k;
    k = a[i]; a[i] = a[j]; a[j] = k;
}

void func1(int a[], int i, int j){
    int k;
    while ((k = 2*i+1) <= j){
        if (2*i+2 <= j && a[k] < a[k+1]){
            k++;
        }
        if (a[k] <= a[i]){
            break;
        }
        swap(a, i, k);
        i = k;
    }
}

void func2(int a[], int m){
    int i;
    for (i = m/2-1; i> -1; i--){
        func1(a, i, m-1);
    }
}

void func3(int a[], int m){
    func2(a, m);
    while (m > 1){
        swap(a, 0, m-1);
        func1(a, 0, m-2);
        m--;
    }
}
