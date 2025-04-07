#include <stdio.h>
#include <string.h>

int complexity = 0;

void computeLPSArray(char *pattern, int M, int *lps)
{
    int length = 0;
    lps[0] = 0;
    int i = 1;

    while (i < M)
    {
        complexity++;
        if (pattern[i] == pattern[length])
        {
            length++;
            lps[i] = length;
            i++;
        }
        else
        {
            if (length != 0)
            {
                length = lps[length - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMPSearch(char *pattern, char *text)
{
    int N = strlen(text);
    int M = strlen(pattern);

    int lps[M];
    computeLPSArray(pattern, M, lps);

    int i = 0;
    int j = 0;

    while (i < N)
    {
        complexity++;
        if (pattern[j] == text[i])
        {
            i++;
            j++;
        }

        if (j == M)
        {
            printf("Pattern found at index %d\n", i - j);
            j = lps[j - 1];
        }
        else if (i < N && pattern[j] != text[i])
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i++;
            }
        }
    }
}

int main()
{
    char text[100], pattern[100];

    printf("Enter the text (single word): ");
    scanf("%s", text);

    printf("Enter the pattern (single word): ");
    scanf("%s", pattern);

    KMPSearch(pattern, text);

    printf("Time Complexity: O(N + M) %d\n", complexity);
    return 0;
}
