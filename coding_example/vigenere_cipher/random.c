#include <stdio.h>
#include <stdlib.h>
#define len 12


int rand(){

  FILE *randfile, *outfile;
  int i;
  unsigned char next;

  randfile = fopen("/dev/random", "r");
  outfile = fopen("key.txt", "w");

  if ( randfile == NULL || outfile == NULL){
    printf("error in opening files");
    return -1;
  }

  for (i = 0; i<len; i++)
  {
    fscanf(randfile, "%c", &next);
    fprintf(outfile, "%02X",next);
  }
  fclose(randfile);
  fclose(outfile);

  return 0;
}


int main()
{
  rand();
}
