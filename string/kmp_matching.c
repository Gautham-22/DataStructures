// KMP Algorithm for string matching

#include<stdio.h>
#include<string.h>

int match(char *str, char *pattern) {
    int m = strlen(str), n = strlen(pattern);
    if(n > m) return -1;
    
    // finding whether the starting part of pattern is repated somewhere inside pattern
    int pie[n], i;
    for(int j=0; j<n; j++) {
        pie[j] = -1;
    }
    for(int j=0; j<n-1; j++) {
        i = 0;
        while(i<n && j<n-1 && pattern[j+1] == pattern[i]) {
            pie[j+1] = i;
            j++; i++;
        }
    }

    // comparing
    int j=-1;
    for(i=0; i<m; ) {
        while(j == -1 && i<m && pattern[j+1] != str[i]) {
            i++;
        }
        while(i<m && j<n-1 && pattern[j+1] == str[i]) {
            j++; i++;
        }
        if(j == n-1) return i - n;
        while(j!=-1 && pattern[j+1] != str[i]) {
            j = pie[j];
        }
    }

    return -1;
}
// time complexity - O(m + n)

int main() {
    char str[] = {'a','b','a','b', 'c', 'a','b', 'c', 'a', 'b', 'a', 'b','a', 'b', 'd', '\0'};
    char pattern[] = {'a', 'b', 'a', 'b', '\0'};
    int res = match(str,pattern);
    if(res == -1) {
        printf("Pattern not found in the string.\n");
    } else {
        printf("Pattern is found, starting at index %d of string.\n",res);
    }
    return 0;
}