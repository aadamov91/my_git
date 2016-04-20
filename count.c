#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

void countwords(FILE *file);
void countfreq(FILE *file);
void countcharfreq(FILE *file);

int main(int argc, char *argv[])
{
	FILE *fp;
	int n;
	char ch;
	char flag;
	if (argc < 2)	//check there is something to open
	{
		printf("no file to open\n");
		exit(1);
	}

	fp = fopen(argv[1], "r");
        if (fp == NULL) //check we can open it
        {
                printf("error can not open file %s\n", argv[1]);
                exit(1);
        }

	if (argc == 3 && *argv[2] == '-') //check there is a key if not will just count chars in file
	{
		
		flag = (argv[2][1]);
		switch (flag)
		{
			case 'w' : 
				countwords(fp); // just count words
				break;
			case 'f' :
				countfreq(fp); //count average chars in word
				break;
			case 'c' :
				countcharfreq(fp); // count char frequancy
				break;
			case 'h' :
				printf("type file name and -w for word count\n -c for character frequancy \n -f for average characters in word count\n");
				exit(1);
			default :
				fprintf(stderr, "unknown command %s\n", argv[2][1]); //if wrong flag
				exit(1);	
		}
	}
	else if (argc != 2) // check there is one file to open and do the counting
	{
		fprintf(stderr, "error usage %s type -help for help\n", argv[0]);
		exit(1);
	}
	
	rewind(fp);
	while ((ch = getc(fp)) != EOF) //counting chars till EOF
	{
		n++;
	}

	printf("file %s has %d characters in it\n", argv[1], n);
	return 0;
	
}

void countwords(FILE *file)
{
	int n_words = 0;
	bool inword;
	char c;
	inword = false;
	while ((c = getc(file)) != EOF) //read file
	{
		if (!isspace(c) && !inword) // start of word
		{
			inword = true;
			n_words++;
		}
		if (isspace(c) && inword) // end of word
		{
			inword = false;
		}
	}
	printf("number of words in file is %d\n ", n_words);
}

void countfreq(FILE *file)
{
        int n_words = 0;
	int n_chars = 0;
        bool inword;
        char c;
	float average;
        inword = false;
        while ((c = getc(file)) != EOF)
        {
		n_chars++;
                if (!isspace(c) && !inword)
                {
                        inword = true;
                        n_words++;
                }
                if (isspace(c) && inword)
                {
                        inword = false;
                }
        }
        printf("number of average characters in word in file  is %.2f\n ", (average = n_chars / n_words));
}
void countcharfreq(FILE *file)
{
	int count_char = 0;
	int count[26] = {0};
	int i;
	char c;
	float freq;
	while ((c = getc(file)) != EOF)
	{
		
		if (isalpha(c)) // check c is a letter
		{
			count_char++;		
			count[c - 'a']++; //match a letter to a array
		}
	}

	for (i = 0; i < 26; i++)
	{
		if (count[i] != 0 ) // dont display if letter not met in file
		{	
			freq = count[i] / count_char;
			printf("number of chars is %d freq of %c in file is %.2e and it appears %d times\n", count_char, i + 'a', freq, count[i]);
		}
	}
}
