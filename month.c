#include <stdio.h>
#define MAX 4
static char daytab[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};
//static massive to calculate day of year



int getmonth(int *pn);
int day_of_year(int , int ,int );
int main()
{
	int i;
	int date[MAX];
	printf("give me a date in format dd.mm.yy:\n");
	for (i = 0; i < MAX && getmonth(&date[i]) != '\n'; i++)
			;
	//building a masive of type date[3] {13, 12, 1932}
		printf("day of year %d is %d", date[2], day_of_year(date[0], date[1], date[2]));

	return 0;
}	

int getmonth(int *pn)
{
	int c;
	*pn = 0;
	while ((c = getchar()) != '.' || c != '\n')
		*pn = 10 * *pn + (c - '0');
	//if c = '\n' we return  \n?
	return c;
}

int day_of_year(int d, int m, int y)
{
	int i, leap;
	char *p;
	leap = y%4 ==0 && y%100 != 0 || y%400 == 0;
	//check leap year
	p = &daytab[leap][1];
	for ( i = 1; i < m; i++){
		d += *p;
		p++;
		}	
	return d;
}			 	
