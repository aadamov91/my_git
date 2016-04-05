#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int getline1(char *line, int max);

main(int argc, char *argv[])
{
	char line[MAXLINE];
	long lineno = 0;
	int inc = 0;
	int c, except = 0, number = 0, found = 0;

	while (--argc > 0 && (*++argv)[0] == '-')
		while (c = *++argv[0])
			switch (c){
			case 'x':
				except = 1;
				break;
			case 'n':
				number = 1;
				break;
			default:
				printf("error illegal option %c\n", c);
				argc = 0;
				found = -1;
				break;
			}
	if (argc != 1)
		printf("error using find pattern\n");
	else
		while(getline1(line, MAXLINE) > 0){
			lineno++;
			inc++;
			if ((strstr(line, *argv) != NULL) != except){
				if (number)
					printf("%ld:", lineno);
				printf("%s\nfuck you%d\n", line, inc);
				found++;
			}
		}
	return found;
}

int getline1(char *line, int max){
	 char *c = line;
	int s;
	for (;(s = getchar()) != EOF && s != '\n'; *line++)
		*line = s;
	if (s =='\n') {
		*line = s;
		*line++;
	}
	*line ='\0';
	return line - c;
}
