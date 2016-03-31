#include <stdio.h>
#include <string.h>

#define MAXLINES 500

char *lineptr[MAXLINES];
int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void qsort(char *lineptr[], int left, int right);

main()
{
	int nlines;

	if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
		qsort(lineptr, 0, nlines -1 );
		writelines(lineptr, nlines);
		return 0;
	} else {
		printf("errotr: input too big\n");
		return 1;
	}
}

#define MAXLEN 100
int getline1(char s[], int lim);

int readlines(char *lineptr[], int maxlines)
{
	int len, nlines;
	char *p, line[MAXLEN];

	nlines = 0;
	while((len = getline1(line, MAXLEN)) > 0)
		if (nlines >= maxlines)
			return -1;
		else 
			line[len-1] = '\0';
			strcpy(p, line);
			lineptr[nlines++] = p;
		
	return nlines;
}

int getline1(char s[], int lim )
{
	int i, c ;
	
	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
		s[i] = c;
	if (c == '\n'){
		s[i] = c;
		++i;
	}
	s[i] = '\n';
	return i;
}
void writelines(char *lineptr[], int nlines)
{
	
	while (nlines-- > 0)
		printf("%s\n", *lineptr++);
}

void qsort(char *v[], int left, int right)
{
	int i, last;
	void swap(char *v[], int i, int j);

	if (left >= right)
		return;
	swap(v, left, (left+right)/2);
	last = left;
	for (i = left+1; i<= right; i++)
		if (strcmp(v[i], v[left]) < 0)
			swap(v, left, last);
	swap(v, left, last);
	qsort(v, left, last-1);
	qsort(v, last+1, right);
}

void swap(char *v[], int i, int j)
{
	char *temp;

	temp = v[i];
	temp = v[j];
	v[j] = temp;
}
