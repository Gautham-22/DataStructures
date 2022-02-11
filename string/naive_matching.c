// Naive Algorithm for string matching

#include<stdio.h>
#include<string.h>

int match(char *str, char *pattern) {
    int m = strlen(str), n = strlen(pattern);
    if(n > m) return -1;
    
    int temp;
    for(int i=0; i<m; i++) {
        // each iteration checks whether pattern is in string starting from index i
        int j=0, temp = i;
        while(j<n && str[temp]==pattern[j]) {
            temp++;
            j++;
        }
        if(j == n) return temp - n;
    }
    return -1;
}
// time complexity - O(mn)

int main() {
    char str[] = {'a','b','a','b', 'c', 'a','b', 'c', 'a', 'b', 'a', 'b','a', 'b', 'd', '\0'};
    char pattern[] = {'a', 'b','a', 'b', 'd', '\0'};
    int res = match(str,pattern);
    if(res == -1) {
        printf("Pattern not found in the string.\n");
    } else {
        printf("Pattern is found, starting at index %d of string.\n",res);
    }
    return 0;
}