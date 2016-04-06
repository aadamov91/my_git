#include <stdio.h>
#include <stdlib.h>
#define NUMBER '0'
#define MAXVAL 100

int sp = 0;

double val[MAXVAL];

void push(double f);
double pop(void);

main(int argc, char *argv[])
{
	double op2;
	while (--argc > 0 ){
		switch ((*++argv)[0]) {
			case '0' ... '9':
				push(atof(*argv));
				break;
			case '+':
				push(pop() + pop());
				break;
			case '*':
				push(pop() * pop());
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '/':

				op2 = pop();
				push(pop() / op2);
				break;
			default:
				printf("error: unknown command:%s\n", argv[0]);
				break;
			}
		}
	printf("\t%.8g\n", pop());
	return 0;
}	
		
void push(double f)
{
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("stack if full cant push %g\n", f);
}

double pop(void)
{
	if (sp > 0)
		return val[--sp];
	else {
		printf("stack empty\n");
	return 0.0;
		}		
}		
