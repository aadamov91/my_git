#include <stdio.h>

int minus(int , int );
int add(int , int );
int ptrfunc(int (*functionptr)(int , int ), int , int );
int main(void)
{

	
	int sum;
	int sum1;
	int (*ptr)(int, int);
	ptr = &minus;
	sum = ptrfunc(ptr, 2, 3);
	printf("result of ptrfunc pointing to minus is %d\n", sum);

	ptr = &add;
	sum1 = ptrfunc(ptr, 4, 2);
	printf("result of ptrfunc pointing to add is %d\n", sum1);
	return 0;
}

int minus(int a, int b)
{
        return b - a;
}

int add(int m, int n)
{
        return m + n;
}

int ptrfunc(int (*functionptr)(int , int ), int j, int k)
{
        int res;
        res = (*functionptr)(j,k);
        return res;
}


