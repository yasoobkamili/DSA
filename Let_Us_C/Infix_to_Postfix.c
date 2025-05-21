// infix to postfix conversion
// CSE-23-46
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
char stack[MAX];
int top = -1;
void push(char c)
{
    if (top > MAX)
    {
        printf("stack overflow\n");
        return;
    }
    top++;
    stack[top] = c;
}
char pop()
{
    if (top == -1)
    {
        printf("stack is empty\n");
        return '\0';
    }
    return stack[top--];
}
char peek()
{
    if (top == -1)
        return '\0';
    return stack[top];
}
int is_al_num(char c)
{
    if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
    {
        return 1;
    }
    return 0;
}
int is_operator(char c)
{
    if (c == '^' || c == '*' || c == '/' || c == '+' || c == '-')
    {
        return 1;
    }
    return 0;
}
int precedence(char c)
{
    if (c == '+' || c == '-')
    {
        return 1;
    }
    else if (c == '*' || c == '/')
    {
        return 2;
    }
    else if (c == '^')
    {
        return 3;
    }
    return 0;
}
void infix_to_postfix(char infix[], char postfix[])
{
    int i, j = 0;
    for (i = 0; infix[i] != '\0'; i++)
    {
        char c = infix[i];

        // c is operand
        if (is_al_num(c))
        {
            postfix[j] = c;
            j++;
        }
        // c is (
        else if (c == '(')
        {
            push(c);
        }
        // c is )
        else if (c == ')')
        {
            while (top != -1 && peek() != '(')
            {
                postfix[j++] = pop(); // pops top element of stack and appends them to postfix also ')' was never pushed to stack therefore will not be appended to postfix
            }
            pop(); // pops '(' from stack
        }
        // c is operator
        else if (is_operator(c))
        {
            while (top != -1 && precedence(peek()) >= precedence(c))
            {
                postfix[j++] = pop(); // before pushing operator to stack , if precedence of operator is less than of peek than pop that and append to postfix
            }
            push(c);
        }
    }
    while (top != -1)
    {
        postfix[j++] = pop(); // ppops remaining element from stack and appends to postfix
    }
    postfix[j] = '\0';
}
int main()
{
    char infix[MAX], postfix[MAX];
    printf("enter infix string:");
    scanf("%s", infix);
    infix_to_postfix(infix, postfix);
    printf("Postfix is %s\n", postfix);
}
