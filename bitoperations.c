#include <stdio.h>


void bin_print(unsigned int i){
    //numbers of bits in an integer.
    // an uni operator but i does loke like function
    int j = sizeof(unsigned int) * 8;

    //Temporary variable 
    int k;

    //loop over the no. of bits in i.left to right
     for (j-- ; j >= 0; j--) {
        //ternary operator as j++ or J-- above is uni operator  j>=0 is bi condition 
       //((1 << j) & i)if this is true  ?return true as 1: oterwise false as  0;
        k = ((1 << j) & i) ? 1 : 0;
        //print k
        printf("%d", k);

    }
}
//standard main signature
int main(int argc, char *argv[]) {

    //Set i to a literal value.
   unsigned int i= 0x0f0f0f0f;//0xffffffff;//2^32-1 is equal to 4294967295 or //  or //0b11111111111111111111111111111111; 
    //0xf1; or //241

    //what we are printing
    printf("Original:\t");
    //print i in binary
    bin_print(i);
    //End line 
    printf("\t%x\t%u\n\n", i, i);

      // 32.
    int j = sizeof(unsigned int) * 8;

    //bit shifting <<
  for (j--; j >= 0 ; j--) {
        // 1 shifted left j times.
        bin_print(1 << j); printf("\n");
        // i.
        bin_print(i); printf("\n");
        printf("-------------------------------- &\n");
        // (1 shifted left j times) bitwise logical and i.
  }   
    
    //for shell that every thing is ok
    return 0;
}
