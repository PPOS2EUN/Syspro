#include <stdio.h>

int main(int argc, char *argv[])
{
	FILE *fp;
	int c;
	if (argc < 3)
		fp = stdin; 
	else if(argv[1] == 0)
		fp = fopen(argv[2],"w");
	else if(argv[1] == 1)
		fp = fopen(argv[2], "a");

	c = getc(fp); 

	while (c != EOF) { 
		putc(c, stdout); 
		c = getc(fp); 
	}
	fclose(fp);
	return 0;
}
