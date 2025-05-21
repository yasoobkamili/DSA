// stack implementation using array
// CSE-23-46
#include <stdio.h>
#define MAX 10
int top = -1;

void push(int);
int is_empty();
int is_full();
void pop();
void peek();
void height();

int is_empty()
{
    return (top == -1);
}
int is_full()
{
    return (top == (MAX - 1));
}
int st[MAX];

void push(int value)
{
    if (is_full())
    {
        printf("Stack Overflow!!\n");
        return;
    }
    top++;
    st[top] = value;
    printf("Pushed %d !!\n", value);
}

void pop()
{
    if (is_empty())
    {
        printf("nothing to pop!!\n");
        return;
    }
    printf("popped %d\n", st[top]);
    top--;
}
void peek()
{
    if (is_empty())
    {
        printf("stack is empty!!\n");
        return;
    }

    printf("Top element is: %d\n", st[top]);
    return;
}
void height()
{
    printf("height of stack is: %d\n", top + 1);
    return;
}
int main()
{
    printf("Top is at: %d\n", top);
    push(1);
    push(3);
    push(2);
    push(5);
    printf("Top is at: %d\n", top);
    peek();
    height();
    pop();
    printf("Top is at: %d\n", top);
    peek();
    height();
}
