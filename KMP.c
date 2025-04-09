#include <stdio.h>
#include <string.h>

// Function to create the LPS (Longest Prefix Suffix) array
void buildLPS(char pattern[], int m, int lps[]) {
    int len = 0;   // Length of the previous longest prefix suffix
    lps[0] = 0;    // lps[0] is always 0

    int i = 1;
    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];  // Try the previous prefix
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// Function to search the pattern in the text
void KMPsearch(char text[], char pattern[]) {
    int n = strlen(text);
    int m = strlen(pattern);

    int lps[m];
    buildLPS(pattern, m, lps);

    int i = 0; // index for text
    int j = 0; // index for pattern

    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == m) {
            printf("Pattern found at index %d\n", i - j + 1);  // 1-based index
            j = lps[j - 1];  // Continue checking for more matches
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
}

// Main function
int main() {
    char text[] = "ABABABABABABABAB";
    char pattern[] = "ABAB";

    KMPsearch(text, pattern);

    return 0;
}
