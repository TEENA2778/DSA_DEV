#include <stdio.h>
#include <string.h>

int lps[100]; // Assuming a maximum size for the lps array

void kmpsearch(char *pat, char *txt) {
    int lenp = strlen(pat);
    int lent = strlen(txt);
    int i = 0;
    int j = 0;
    
    while (i < lent && j < lenp) {
        if (txt[i] == pat[j]) {
            i = i + 1;
            j = j + 1;
        } else {
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }

        if (j == lenp) {
            printf("pat found at %d ", i - j);
            j = lps[j - 1];
        }
    }
}

void computelps(char *pat) {
    int len = 0;
    lps[0] = 0;
    int i = 1;
    int M = strlen(pat);

    while (i < M) {
        if (pat[len] == pat[i]) {
            lps[i] = len + 1;
            len = len + 1;
            i = i + 1;
        } else {
            if (len != 0)
                len = lps[len - 1];
            else {
                lps[i] = 0;
                i = i + 1;
            }
        }
    }
}

int main() {
    char txt[] = "ABABDABACDABABCABAB";
    char pat[] = "ABABCABAB";

    computelps(pat);
    kmpsearch(pat, txt);

    return 0;
}
