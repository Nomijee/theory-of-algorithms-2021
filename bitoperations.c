#include <stdio.h>

int main(int argc, char *argv[]) {
    
   //int i= 241;

   int i= 0xF1; //11110001
   printf("Hex: %X\n", i);
   printf("Decimal: %d\n", i);
   printf("Print size of int: %d\n", sizeof(i));
   printf("Print size of char: %d\n", sizeof(char));
   printf("Print size of char: %d\n", sizeof(int));
   
   char c = 41;
   printf("c in char is : %c\n", c);
   printf("c in char is : %d\n", c);

   
   int j = 1000000000;
   printf("j in char is : %d\n", j);
   printf("j in char is : %c\n", j);
   printf("j in int from char is : %d\n", (int) (char) j);
    
    return 0;
}
