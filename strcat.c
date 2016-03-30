#include <stdio.h>
#define MAX 100

int getstr1(char *, int );
void strcat1(char *, char *);

int main(void)
{
	int i;
	char str1[MAX];
	char str2[MAX];

	printf("give me first string:\n");
	while (getstr1(str1, MAX) != 0)
		;
	printf("\ngive me second string:\n");
	while (getstr1(str2, MAX) != 0)
		;
	strcat1(str1, str2);
	printf("\nresult string is:\n");
		while (str1[i++] != '\0')
			printf("%c", str1[i]);
	//for (i = 0; i < 5; i++)
	//	printf("%s", str1[i]);
	return 0;
}

int getstr1(char *str, int lim)
{
		
	char *start = str;
	for (; (*str  = getchar()) != '\n' && (start + lim * sizeof(char) - str) > 0; str++)
		;
	*str = '\0';
	return 0;
}

void strcat1(char *s, char *t)
{
	while (*s != '\0')
		s++;
	while (*s++ = *t++)
		;
}	
