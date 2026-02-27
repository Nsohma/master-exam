#include <stdio.h>

int lcs(char s1[], char s2[], int s1_len, int s2_len);
int Levenshtein(char s1[], char s2[], int s1_len, int s2_len);

int main(void){
    char s1[5];
    char s2[5];
    //s1[0] = 'A', s1[1] = 'B', s1[2] = 'D', s1[3] = 'C', s1[4] = 'A';
    //s2[0] = 'A', s2[1] = 'C', s2[2] = 'B', s2[3] = 'D', s2[4] = 'C';
    s1[0] = 'A', s1[1] = 'B', s1[2] = 'C', s1[3] = 'D';
    s2[0] = 'A', s2[1] = 'D', s2[2] = 'B', s2[3] = 'C';
    printf("lcs : %d\n", lcs(s1, s2, 4, 4));

    s1[0] = 'A', s1[1] = 'B', s1[2] = 'C', s1[3] = 'D', s1[4] = 'E';
    s2[0] = 'A', s2[1] = 'C', s2[2] = 'D', s2[3] = 'F', s2[4] = 'B';
    printf("Levenshtein : %d\n", Levenshtein(s1, s2, 5, 5));

    s1[0] = 'A', s1[1] = 'B', s1[2] = 'C', s1[3] = 'D', s1[4] = 'E';
    s2[0] = 'C', s2[1] = 'E', s2[2] = 'A', s2[3] = 'D', s2[4] = 'B';
    printf("Levenshtein : %d\n", Levenshtein(s1, s2, 5, 5));
}

int lcs(char s1[], char s2[], int s1_len, int s2_len){
    int i, j, k, mat[6][6];
    for (int i=0; i<s1_len+1; i++){
        mat[i][0] = 0;
    }
    for (int i=0; i<s2_len+1; i++){
        mat[0][i] = 0;
    }
    k = 0;
    //for (int i=0; i<s1_len; i++){
    //    for (int j=0; j<s2_len; j++){
    //        if (s1[i] == s2[j]){
    //            mat[i+1][j+1] = mat[i][j]+1;
    //            if (mat[i+1][j+1] > k){
    //                k = mat[i+1][j+1];
    //            }
    //        }else{
    //                mat[i+1][j+1] = 0;
    //        }
    //    }
    //}

    //for文の中で int i=0 や int j=0 とすると、for文の中でのみ
    //有効なスコープとなる
    for (i=0; i<s1_len; i++){
        for (j=0; j<s2_len; j++){
            if (s1[i] == s2[j]){
                mat[i+1][j+1] = mat[i+1][j]+1;
            } else if (mat[i][j+1] > mat[i+1][j]){
                mat[i+1][j+1] = mat[i][j+1];
            }else {
                mat[i+1][j+1] = mat[i+1][j];
            }
        }
    }

    return mat[i][j];
}

int Levenshtein(char s1[], char s2[], int s1_len, int s2_len){
    int i, j, r, mat[6][6];
    for (i=0; i<s1_len+1; i++){
        mat[i][0] = i*2;
    }
    for (j=0; j<s2_len+1; j++){
        mat[0][j] = j*2;
    }
    for (i=0; i<s1_len; i++){
        for (j=0; j<s2_len; j++){
            if (s1[i] == s2[j]){
                r = 0;
            }else{
                r = 3;
            }
            if (mat[i][j] + r < mat[i][j+1] + 2 &&
                mat[i][j] + r < mat[i+1][j] + 2){
                mat[i+1][j+1] = mat[i][j] +r;
            }else if (mat[i][j+1] +2 < mat[i+1][j] + 2){
                mat[i+1][j+1] = mat[i][j+1] + 2;
            }else{
                mat[i+1][j+1] = mat[i+1][j] + 2;
            }
        }
    }

    for (int t=0; t<s1_len+1; t++){
        for (int u=0; u<s2_len+1; u++){
            printf("mat[%d][%d]: %d ", t, u, mat[t][u]);
        }
        puts("");
    }

    return mat[i][j];
}


