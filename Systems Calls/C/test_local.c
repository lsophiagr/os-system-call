#include <stdio.h>

int main(void) {
  char buf[256] = "((4+3)*3[2+2])";
  int i;
int countP = 0;
int countC = 0;

  for (i = 0; i < 256; ++i)
  {
    if (*(buf+i) == '(') {
      countP = countP + 1;
      }
    
    if (*(buf+i) == ')') {
      countP = countP - 1;
      }
    
    if (*(buf+i) == '[') {
      countC = countC + 1;
      }
    
    if (*(buf+i) == ']') {
      countC = countC - 1;
      }
  }

  if ((countP != 0) || (countC != 0)){
    printf("no esta balance");
    
  }  else {
    printf("esta balance");
  }
  
}