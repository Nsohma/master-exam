//This is Science Tokyo master exam 2025 [3](1)~(6)
#include <stdio.h>

int count_shortest_path1(int w, int h){
    if (w==0 || h==0){
        return 1;
    }
    return count_shortest_path1(w, h-1) + count_shortest_path1(w-1, h);
}

int count_shortest_path2(int w, int h){
    int a[100][100];
    for (int i=0; i<=h; i++)  a[i][0] = 1;
    for (int i=0; i<=w; i++)  a[0][i] = 1;
    for (int i=1; i<=h; i++){
        for (int j=1; j<=w; j++){
        if (i == 8 && j == 7) a[i][j] = 0;
        else a[i][j] = a[i][j-1] + a[i-1][j];
        }
    }
    return a[h][w]; //attention to the order of h and w
}



int main(void){
    printf("1  w:%d, h:%d, ans:%d\n", 2, 2, count_shortest_path1(2, 2));
    printf("1  w:%d, h:%d, ans:%d\n", 6, 5, count_shortest_path1(6, 5));
    printf("2  w:%d, h:%d, ans:%d\n", 2, 2, count_shortest_path2(2, 2));
    printf("2  w:%d, h:%d, ans:%d\n", 6, 5, count_shortest_path2(5, 6));
    printf("if stop (8, 7)  w:%d, h:%d, ans:%d\n", 17, 13, count_shortest_path2(17, 13));
    return 0;
}


