#include <stdio.h>
#include <stdlib.h>
#include "library.h"

int main(int argc, char* argv[])
{
	struct library rec;
	FILE *fp;
	if (argc != 2) {
		exit(1);
	}

	fp = fopen(argv[1], "wb");
	printf("%-3s %-3s %-3s %-3s %-3s %-3s\n", "id", "bookname", "author", "year", "numofborrow", "borrow");
	while (scanf("%d %s %s %d %d %s", &rec.id, rec.bookname, rec.author, &rec.year, &rec.numofborrow, rec.borrow) == 6)
		fwrite(&rec, sizeof(rec), 1, fp);
	fclose(fp);
	exit(0);
}
