#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  // args inputfile outputfile 1 outputfile2
  if (argc < 4) {
    printf("Must give at least three arguments. (readfile,writefile "
           "1,writefile 2) \n");
    exit(1);
  }

  // open the files
  FILE *in = fopen(argv[1], "r");
  if (!in) {
    printf("Can't open %s for reading", argv[1]);
    exit(1);
  }

  FILE *out1 = fopen(argv[2], "w");
  if (!out1) {
    printf("Can't open %s for writing", argv[2]);
    exit(1);
  }

  FILE *out2 = fopen(argv[3], "w");
  if (!out2) {
    printf("Can't open %s for writing", argv[3]);
    exit(1);
  }

  char line[100];
  int shortLineCount = 0;
  int longLineCount = 0;

  // go through each line in input
  while (fgets(line, 100, in) != NULL) {
    // if line < 20 uppercase to file 1
    if (strlen(line) < 20) {
      for (int i = 0; line[i] != '\0'; i++) {
        line[i] = toupper(line[i]);
      }
      fprintf(out1, "%s", line);
      shortLineCount++;
    } else {

      // if line >= 20 lowercase to file 2
      for (int i = 0; line[i] != '\0'; i++) {
        line[i] = tolower(line[i]);
      }
      fprintf(out2, "%s", line);
      longLineCount++;
    }
  }
  // close the files
  fclose(in);
  fclose(out1);
  fclose(out2);

  printf("%d lines written to %s\n", shortLineCount, argv[2]);
  printf("%d lines written to %s\n", longLineCount, argv[3]);

  return 0;
}
