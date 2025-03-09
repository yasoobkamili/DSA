// find all palindromic substrings of a given string
// CSE--23-46
#include <stdio.h>
#include <string.h>
int isPalindrome(char str[], int left, int right)
{
    int len = strlen(str);
    while (left < right)
    {
        if (str[left] != str[right])
        {
            return 0;
        }
        left++;
        right--;
    }
    return 1;
}
void palidromePartition(char str[])
{
    int i, j, k;
    int length = strlen(str);
    for (i = 0; i < length; i++)
    {
        for (j = i; j < length; j++)
        {
            if (isPalindrome(str, i, j))
            {
                for (k = i; k <= j; k++)
                {
                    printf("%c", str[k]);
                }
                printf("\n");
            }
        }
    }
}
int main()
{
    char str[] = "ababa";
    palidromePartition(str);
}
