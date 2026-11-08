//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//
//int main(void) {
//	FILE* sourceFile, * destFile;
//	double item;
//	int input_status;
//
//	sourceFile = fopen("source.txt", "r");
//	destFile = fopen("destination.txt", "w");
//
//	input_status = fscanf(sourceFile, "%lf", &item);
//	while (input_status == 1) {
//		fprintf(destFile, "%.2f\n", item);
//		input_status = fscanf(sourceFile, "%lf", &item);
//	}
//	fclose(sourceFile);
//	fclose(destFile);
//	return 0;
//}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(int argc, int* argv[])
{
    FILE* fp;
    void filecopy(FILE*, FILE*);
    char* prog = argv[0];

    if (argc == 1) {
        filecopy(stdin, stdout);
    }
    else {
        while (--argc > 0) {
            if ((fp = fopen(*++argv, "r")) == NULL) {
                fprintf(stderr, "%s: can't open %s\n", prog, *argv);
                exit(1);
            }
            else {
                filecopy(fp, stdout);
                fclose(fp);
            }
            if (ferror(stdout)) {
                fprintf(stderr, "%s: error writing stdout\n", prog);
                exit(2);
            }
        }
        exit(0);
    }
}

void filecopy(FILE* ifp, FILE* ofp) {
    int c;

    while ((c = getc(ifp)) != EOF)
        putc(c, ofp);
}