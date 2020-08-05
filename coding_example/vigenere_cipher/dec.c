#include <stdio.h>
#include <stdlib.h>
#define len 12


int dec(){

  FILE *keyfile, *pfile, *cfile;
  int i;
  unsigned char ch1, ch2;


  keyfile = fopen("key.txt", "r");
  pfile = fopen("ptext2.txt", "w");
  cfile = fopen("ctext.txt", "r");

  if ( keyfile == NULL || pfile == NULL || cfile == NULL){
    printf("error in opening files");
    return -1;
  }

  for (i = 0; i<len; i++)
  {
    fscanf(keyfile, "%2hhX", &ch1);
    fscanf(cfile, "%2hhX",&ch2);
    fprintf(pfile, "%c", (char)ch1 ^ ch2);
  }
  fclose(keyfile);
  fclose(pfile);
  fclose(cfile);
  return 0;
}


int main()
{
  dec();
}
