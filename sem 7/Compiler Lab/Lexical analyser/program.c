#include <string.h>
#include <ctype.h>
#include <stdio.h>

void main()
{
    FILE *f;
    char c, str[10];
    int n = 0, i = 0;
    printf("Enter the c program\n");
    f = fopen("input.txt", "w");
    while ((c = getchar()) != EOF)
    {
        putc(c, f);
    }
    fclose(f);
    f = fopen("input.txt", "r");
    while ((c = getc(f)) != EOF)
    {
        if (isdigit(c))
        {
            n = c - 48;
            c = getc(f);
            while (isdigit(c))
            {
                n = n * 10 + (c - 48);
                c = getc(f);
            }
            printf("\n%d is a number ", n);
            ungetc(c, f);
        }
        else if (isalpha(c))
        {
            str[i++] = c;
            c = getc(f);
            while (isdigit(c) || isalpha(c) || c == '_' || c == '$')
            {
                str[i++] = c;
                c = getc(f);
            }
            str[i++] = '\0';
            if (strcmp("auto", str) == 0 || strcmp("break", str) == 0 ||
                strcmp("case", str) == 0 || strcmp("char", str) == 0 ||
                strcmp("const", str) == 0 || strcmp("continue", str) == 0 || strcmp("default", str) == 0 || strcmp("do", str) == 0 || strcmp("double", str) == 0 || strcmp("else", str) == 0 || strcmp("enum", str) == 0 || strcmp("extern", str) == 0 || strcmp("float", str) == 0 || strcmp("for", str) == 0 || strcmp("goto", str) == 0 || strcmp("if", str) == 0 || strcmp("int", str) == 0 || strcmp("long", str) == 0 || strcmp("register", str) == 0 || strcmp("return", str) == 0 || strcmp("short", str) == 0 || strcmp("signed", str) == 0 || strcmp("sizeof", str) == 0 || strcmp("static", str) == 0 || strcmp("struct", str) == 0 || strcmp("switch", str) == 0 || strcmp("typedef", str) == 0 || strcmp("union", str) == 0 || strcmp("unsigned", str) == 0 || strcmp("void", str) == 0 || strcmp("volatile", str) == 0 || strcmp("while", str) == 0)
            {
                printf("\n%s is a keyword", str);
            }
            else
            {
                printf("\n%s is a identifier", str);
            }
            ungetc(c, f);
            i = 0;
        }
        else if (c == ' ' || c == '\t' || c == '\n')
        {
            continue;
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '-' || c == '=' || c == '>' || c == '<' || c == '!' || c == '&' || c == '|' || c == '^')
        {
            str[i++] = c;
            c = getc(f);
            while (c == '+' || c == '-' || c == '*' || c == '/' || c == '-' || c == '=' || c == '>' || c == '<' || c == '!' || c == '&' || c == '|' || c == '^')
            {
                str[i++] = c;
                c = getc(f);
            }
            str[i++] = '\0';
            if (strcmp("+", str) == 0 || strcmp("-", str) == 0 || strcmp("*", str) == 0 || strcmp("/", str) == 0 || strcmp("%", str) == 0 || strcmp("=", str) == 0 || strcmp("!", str) == 0 || strcmp("&", str) == 0 || strcmp("|", str) == 0 ||
                strcmp("^", str) == 0 || strcmp(">", str) == 0 || strcmp("<", str) == 0 || strcmp("+=", str) == 0 || strcmp("-=", str) == 0 || strcmp("*=", str) == 0 || strcmp("/=", str) == 0 || strcmp(" =", str) == 0 || strcmp("==", str) == 0 ||
                strcmp("!=", str) == 0 || strcmp(">=", str) == 0 ||
                strcmp("<=", str) == 0 || strcmp("&&", str) == 0 ||
                strcmp("||", str) == 0 || strcmp("<<", str) == 0 ||
                strcmp(">>", str) == 0 || strcmp("++", str) == 0 ||
                strcmp("--", str) == 0)
            {
                printf("\n%s is a operator", str);
            }
            else if (strcmp("//", str) == 0)
            {
            	while ((c = getc(f)) != '\n')
            	{
            		printf("%c", c);
            		continue;
            	}
            }
            else if (strcmp("/*", str) == 0)
            {
            	while (1)
            	{
            		c = getc(f);
            		if (c == '*')
            			if ((c = getc(f)) == '/')
            				break;
            	}
                c = getc(f);
            }
            else
            {
                printf("\n%s is a invalid operator", str);
            }
            ungetc(c, f);
    		i = 0;
        }
        else
        {
    		printf("\n%c is a special symbol", c);
        }
    }
    printf("\n");
    fclose(f);
}
