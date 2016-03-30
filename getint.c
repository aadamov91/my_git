#include <stdio.h>
#include <ctype.h>
#define MAX 100
#define BUFS 100

main()
{
	int n, i;
	int array[MAX];
	int getint (int *);

	for (n = 0; n < MAX && getint(&array[n]) != EOF; n++)
		printf ("array%d is %d\n", n,  array[n]);

	for (i = 0; i < n; i++)
		printf ("%d", array[i]);
	printf("\nend\n");
	return 0;
}

int getch(void);
void ungetch (int );

char buf[BUFS];
int bufp = 0;


int getint(int *pn)
{
	int c, sign;
	
	
	while (isspace(c = getch()))
	;

	if (!isdigit(c) && c != EOF && c != '+' && c != '-'){
		ungetch(c);
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-')
		c = getch();
	for (*pn = 0; isdigit(c); c = getch())
		*pn =10 *  *pn + (c - '0');
	*pn *= sign;
	if (c != EOF)
		ungetch(c);
	return c;
}

int getch(void)
{
	
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
	if (bufp >= BUFS)
		printf("ungetch error buf is over\n");
	else 
		buf[bufp++] = c;
}
