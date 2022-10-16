#include <stdio.h>
#include <ctype.h>

#define SIZE 50

char stack[SIZE];
int top = -1; /* Global declarations */

void push(char elem)
{ /* Function for PUSH operation */
	stack[++top] = elem;
}

char pop()
{ /* Function for POP operation */
	return (stack[top--]);
}

int pr(char symbol)
{ /* Function for precedence */

	if (symbol == '^') /* exponent operator, highest precedence*/
	{
		return (3);
	}
	else if (symbol == '*' || symbol == '/')
	{
		return (2);
	}
	else if (symbol == '+' || symbol == '-') /* lowest precedence */
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
/* Main Program */
void main()
{
	char infix[50], postfix[50], ch, elem;
	int i = 0, k = 0;
	printf("Enter Infix Expression : ");
	scanf("%s", infix);
	push('#');
	while ((ch = infix[i++]) != '\0')
	{
		if (ch == '(')
			push(ch);
		else if (isalnum(ch))
			postfix[k++] = ch;
		else if (ch == ')')
		{
			while (stack[top] != '(')
				postfix[k++] = pop();
			elem = pop(); /* Remove ( */
		}
		else
		{ /* Operatore */
			while (pr(stack[top]) >= pr(ch))
				postfix[k++] = pop();
			push(ch);
		}
	}
	while (stack[top] != '#') /* Pop from stack till empty */
		postfix[k++] = pop();
	postfix[k] = '\0'; /* Make postfix as valid string */
	printf("\nPostfix Expression =  %s\n", postfix);
}