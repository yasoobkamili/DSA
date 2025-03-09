// Tower of Hanoi
// CSE-23-46
#include <stdio.h>
void TOH(int height, int a, int b, int c)
{
    if (height > 0)
    {
        TOH(height - 1, a, c, b);
        printf("(%d-%d)\n", a, c);
        TOH(height - 1, b, a, c);
    }
}
int main()
{
    TOH(4, 1, 2, 3);
}
