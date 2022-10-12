#include <stdio.h>

struct Poly
{
	int coeff;
	int exp;
};


void readPoly(struct Poly a[], int n)
{	
	int i;
	for (i = 0; i < n; i++)
	{	
		struct Poly p;
		printf("Enter the coeff and exp of %d term\n", i+1);
		printf("Enter the coeff: ");
		scanf("%d", &p.coeff);
		printf("Enter the exp: ");
		scanf("%d", &p.exp);
		a[i] = p;
	}
}


void displayPoly(struct Poly a[], int n)
{	
	int i;
	for (i = 0; i < n; i++)
	{
		if(a[i].coeff > 0)
			printf("+%dX^%d", a[i].coeff, a[i].exp);
		else
			printf("-%dX^%d", a[i].coeff, a[i].exp);
	}
	printf("\n");
}

int addPoly(struct Poly a[], struct Poly b[], struct Poly c[],int n1, int n2)
{
	int i=0, j=0, k=0;
	while (i < n1 && j < n2)
	{
		if (a[i].exp > b[j].exp)
		{
			c[k].coeff = a[i].coeff;
			c[k].exp = a[i].exp;
			i++;
			k++;
		}
		else if (a[i].exp < b[j].exp)
		{
			c[k].coeff = b[j].coeff;
			c[k].exp = b[j].exp;
			j++;
			k++;
		}
		else
		{
			c[k].exp = a[i].exp;
			c[k].coeff = a[i].coeff + b[j].coeff;
			i++;
			j++;
			k++;
		}
	}

	while (i < n1)
	{
		c[k].coeff = a[i].coeff;
		c[k].exp = a[i].exp;
		i++;
		k++;
	}
	while (j < n2)
	{
		c[k].coeff = b[j].coeff;
		c[k].exp = b[j].exp;
		j++;
		k++;
	}
	return k;
}

int main()
{	
	int n1, n2;
	printf("Enter the no. of terms in first polynomial: ");
	scanf("%d", &n1);
	struct Poly a[n1];
	readPoly(a, n1);
	printf("first polynomial is: ");
	displayPoly(a, n1);
	printf("\nEnter the no. of terms in second polynomial: ");
	scanf("%d", &n2);
	struct Poly b[n2];
	readPoly(b, n2);
	printf("second polynomial is: ");
	displayPoly(b, n2);
	struct Poly c[n1 + n2];
	int n3 = addPoly(a, b, c, n1, n2);
	printf("\nThe result of addition is:\n\n");
	displayPoly(a, n1);
	displayPoly(a, n1);
	printf("--------------------------\n");
	displayPoly(c, n3);
	return 0;
}
