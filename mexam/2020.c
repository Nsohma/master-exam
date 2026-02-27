#include <stdio.h>
//mergesort 

int mergesort(int a[], int begin, int end, int w[]);

int main(void){
    int a[5] = {3, 5, 1, 4, 2}, w[5];
    int count = mergesort(a, 0, 4, w);
    printf("%d\n", count);
    return 0;
}

int mergesort(int a[], int begin, int end, int w[]){
    int mid = (begin + end) / 2;
    int i = begin, j = mid + 1, k, c = 0;

    printf("(%d, %d)\n", begin, end);
    if (begin < end){
        c += mergesort(a, begin, mid, w);
        c += mergesort(a, mid+1, end, w);

        for (k = begin; k <= end; ++k){
            if (mid < i){
                w[k] = a[j++];
            } else if (end < j){
                w[k] = a[i++];
            }
            else{
                ++c;
                if (a[i] < a[j]){
                    w[k] = a[i++];
                } else{
                    w[k] = a[j++];
                }
            }
        }
        for (k = begin; k <= end; ++k){
            a[k] = w[k];
        }
    }
    return c;
}
