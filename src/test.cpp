#include <stdio.h>
#include <string.h>

int main() {
  char numandnum[] = "109000000000000000000000000000000000000000000000000000000"
                     "000000000000000000000000000000000000000000+"
                     "999999999999999999999999999999999999999999999999999999999"
                     "999999999999999999999999999999999999999999999999999999999"
                     "999999999999999999999999999999999999999999";
  char first_num[256], second_num[256];
  int i, j;

  for (i = 0; numandnum[i] != '+'; i++)
    ;

  strncpy(first_num, numandnum, i);
  first_num[i] = '\0';

  strncpy(second_num, numandnum + i + 1, strlen(numandnum) - i - 1);
  second_num[strlen(numandnum) - i - 1] = '\0';

  printf("第一个整数： %s", first_num);
  printf("第二个整数： %s", second_num);

  return 0;
}