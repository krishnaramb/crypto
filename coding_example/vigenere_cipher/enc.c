#include <stdio.h>
#include <stdlib.h>
#define len 12


int enc(){

  FILE *keyfile, *pfile, *cfile;
  int i;
  unsigned char ch1;
  char ch2;

  keyfile = fopen("key.txt", "r");
  pfile = fopen("ptext.txt", "r");
  cfile = fopen("ctext.txt", "w");

  if ( keyfile == NULL || pfile == NULL || cfile == NULL){
    printf("error in opening files");
    return -1;
  }

  for (i = 0; i<len; i++)
  {
    fscanf(keyfile, "%2hhX", &ch1);
    fscanf(pfile, "%c",&ch2);
    fprintf(cfile, "%02X",ch1 ^ ch2);
  }
  fclose(keyfile);
  fclose(pfile);
  fclose(cfile);
  return 0;
}


int main()
{
  enc();
}
