//queue using array
#include <stdio.h>

#define MAX 5
int start = -1, end = -1, currSize = 0;
int q[MAX];

void push(int value);
void pop();

void push(int value)
{
    if (currSize == MAX)
    {
        printf("no more space to push\n");
        return;
    }
    if (currSize == 0)
    {
        start = 0;
        end = 0;
    }
    else
    {
        end = (end + 1) % MAX;
    }
    q[end] = value;
    printf("Pushed %d\n", value);
    currSize++;
}
void pop()
{
    if (currSize == 0)
    {
        printf("nothing to pop\n");
        return;
    }
    printf("Popped %d\n", q[start]);
    if (currSize == 1)
    {
        start = -1, end = -1;
    }
    else
    {
        start = (start + 1) % MAX;
    }
    currSize--;
}
void front()
{
    if (currSize == 0)
    {
        printf("nothing here!\n");
        return;
    }
    printf("front is %d\n", q[start]);
}
int main()
{
    push(9);
    push(8);
    push(4);
    push(5);
    pop();
    pop();
    pop();
    front();
}
