#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_SIZE 32

int max(int,int);
int longestCommonSubsequence(char *, char *, int, int);

int main() {
    int m, n;
    char text1[MAX_SIZE], text2[MAX_SIZE];
    printf("Enter 1st string (max length 30): ");
    fgets(text1,MAX_SIZE,stdin);
    printf("Enter 2nd string (max length 30): ");
    fgets(text2,MAX_SIZE,stdin);
    m = strlen(text1), n = strlen(text2);
    if(text1[m-1] == '\n') {
        text1[m-1] = '\0';
        m--;
    }
    if(text2[n-1] == '\n') {
        text2[n-1] = '\0';
        n--;
    }
    printf("Length of longest common subsequence of two strings: %d",longestCommonSubsequence(text1,text2,m,n));
    return 0;
}

int max(int a, int b) {
    if(a > b) return a;
    return b;
}
int longestCommonSubsequence(char *text1, char *text2, int m, int n) {
    if(m < n) {
        return longestCommonSubsequence(text2,text1,n,m);
    }
    int tab[m+1][n+1];
    for(int i=0; i<=m; i++) {
        for(int j=0; j<=n; j++) {
            if(i == 0 || j == 0) {
                tab[i][j] = 0;
            }else if(text1[i-1] == text2[j-1]) {
                tab[i][j] = tab[i-1][j-1] + 1;
            } else {
                tab[i][j] = max(tab[i-1][j],tab[i][j-1]);
            }
        }
    }
    return tab[m][n];
}