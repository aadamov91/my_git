#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFSIZE 4096
#define SLEN 81
void append(FILE *source, FILE *dest);
char * s_gets(char * st, int n);

int main(int argc,char **argv)
{
	FILE *fa, *fs;
	int files = 0;
	int ch;
	if (argv[1] == "help"){
		printf("append usage: type in destination file and source file\n");
		exit(0);
		}
	if (argc != 3){
		fprintf(stderr,"wrong usage:type help for usage %s\n", argv[0]);
		exit(1);
		}
	
	if ((fa = fopen(argv[1], "a+")) == NULL)
	{
		fprintf(stderr, "cant open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	if (setvbuf(fa, NULL, _IOFBF, BUFSIZE) != 0)
	{
		fputs("cant create buffer\n", stderr);
		exit(EXIT_FAILURE);
	}

	if ((fs = fopen(argv[2], "r")) == NULL)
	{
		fprintf(stderr, "cant open file for read %s", argv[2]);
		exit(EXIT_FAILURE);
	}
	if (setvbuf(fs, NULL, _IOFBF, BUFSIZE) != 0)
	{
		fputs("cant create in buffer\n", stderr);
		exit(EXIT_FAILURE);
	}
	append(fs, fa);
	if (ferror(fs) != 0)
		fprintf(stderr, "Error in reading file %s.\n", argv[2]);
	if (ferror(fa)!= 0)
		fprintf(stderr, "Error in writing file %s\n", argv[1]);
	fclose(fs);
	files++;
	printf("append done, result for %s:\n\n", argv[1]);
	while ((ch = getc(fa)) != EOF)
		putchar(ch);
	puts("DONE\n");
	fclose(fa);

	return 0;


}

void append (FILE *source, FILE *dest)
{
	size_t bytes;
	static char temp[BUFSIZE];

	while ((bytes = fread(temp, sizeof(char), BUFSIZE, source)) > 0)
		fwrite(temp, sizeof(char), bytes, dest);
}	

char *s_gets(char *st, int n)
{
	char *ret_val;
	char *find;

	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		find = strchr(st, '\n');
		if (find)
			*find = '\0';
		else 
			while (getchar() != '\n')
				continue;
	}
	return ret_val;
}
