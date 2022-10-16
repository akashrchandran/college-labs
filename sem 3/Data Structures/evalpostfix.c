#include <stdio.h>
#include <ctype.h>  // isdigit, isalpha, isalnum, functions
#include <stdlib.h> //just to use exit function
#define SIZE 10
int a[10];
int top = 0;
void push(int item)
{
    if (top >= SIZE - 1)
    {
        ;//Don't alert even if stack is full
    }
    else
    {
        top = top + 1;
        a[top] = item;
    }
}

int pop()
{
    int item;
    if (top < 0)
    {
        ;//Don't alert even if stack is full
    }
    else
    {
        item = a[top];
        top = top - 1;
        return item;
    }
}

char readSymbol(char e[])
{
    static int i; // used static variable to keep track of the index of the array
    return (e[i++]);
}

int evalPostfix(char E[])
{
    int d, y, x, r, value, i = 0;
    char item;
    for (i = 0; E[i]; ++i) // iterating through the exxpression
    {
        item = readSymbol(E);
        if (isdigit(item))
        {
            d = (int)item - '0'; // type casting to get the perfect value
            push(d);
        }
        else
        {
            y = pop();
            x = pop();
            switch (item)
            {
                case '+':
                    r = x + y;
                    break;
    
                case '-':
                    r = x - y;
                    break;
    
                case '*':
                    r = x * y;
                    break;
    
                case '/':
                    r = x / y;
                    break;
    
                default:
                    printf("\n Invalid expression, Exiting...\n");
                    exit(0); // Exiting the program
            }
        }
    }
    
    return (r);
}

void main()
{
    int i;
    char E[25];
    // char E[] = "231*+9-3+12/45*";  Testing expression answer = 20
    printf("Enter the postfix expression: ");
    scanf("%s", E); //should have used looped to read chars
    printf("Postfix evaluation: %d\n", evalPostfix(E));
}