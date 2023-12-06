#include <stdio.h>
#include "library.h"

int main(int argc, char* argv[])
{
	struct library rec;
	FILE *fp;
	if (argc != 2) {
		return 1;
	}
	if ((fp = fopen(argv[1], "rb")) == NULL ) {
		return 2;
	}

	int num;
	printf("--bookquery\n");
	printf("0: list of all books, 1: list of available books ) ");
	scanf("%d",&num);

	if(num == 0){
		while(fread(&rec, sizeof(rec), 1, fp) > 0)
			if(rec.id != 0)
				printf("%d %3s %3s %d %d %3s\n", rec.id, rec.bookname, rec.author, rec.year, rec.numofborrow, rec.borrow);
	}
	else if (num == 1){
		while(fread(&rec, sizeof(rec), 1, fp) > 0)
			if(rec.id != 0 && (rec.borrow == "True"))
				printf("%d %3s %3s %d %d %3s\n", rec.id, rec.bookname, rec.author, rec.year, rec.numofborrow, rec.borrow);
	}	
	
	fclose(fp);
	return 0;
}
