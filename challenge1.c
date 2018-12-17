//Problem        : Base Arithmetic
//Language       : C
//Compiled Using : GCC
//Version        : GCC 4.9.1
//Input for your program will be provided from STDIN
//Print out all output from your program to STDOUT
// Compile gcc -o challenge challenge.c 
// Will get 2 numbers in any base and convert them to uppercase 
// and to base 10 and add them
// Example B95 + 101101 = 1742

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int val(char c) 
{ 
    if (c >= 48 && c <= 57) 
        return (int)c - '0'; 
    else
        return (int)c - 'A' + 10; 
} 
  
// Function to convert a number from given base 'b' 
// to decimal 
int toDecimal(char *s, int base) 
{ 
    int len = strlen(s); 
    int power = 1; // Initialize power of base 
    int num = 0;
    int i = 0;// Initialize result 
    // Decimal equivalent is str[len-1]*1 + 
    // str[len-1]*base + str[len-1]*(base^2) + ... 
    for (i = len - 1; i >= 0; i--) 
    { 
        num += val(s[i]) * power; 
        power = power * base; 
    }
    return num; 
}

char findMax(char *s){
    int i = 0;
    char maxc = '0';
    for(i =0;i<strlen(s); i++){
        s[i] = toupper(s[i]);
        if(s[i] > maxc){
            maxc = s[i];
        }
    }
    return maxc;
}

int main() {
    char *s1,*s2;
    char max1,max2;
    int base1,base2, x_10, y_10, sum;
    s1 = malloc(10* sizeof(char));
    s2 = malloc(10* sizeof(char));
    printf("Please give me the 2 numbers:\n");
    scanf("%s %s", s1, s2);
    max1 = findMax(s1);
    max2 = findMax(s2);

    base1 = val(max1) + 1;
    base2 = val(max2) + 1;

    x_10 = toDecimal(s1, base1);
    y_10 = toDecimal(s2, base2);
    sum = x_10 + y_10;

    printf("%s is in base-%d.In base-10, its value is %d.\n", s1, base1, x_10);
    printf("%s is in base-%d.In base-10, its value is %d.\n", s2, base2, y_10);
    printf("%s + %s = %d\n", s1, s2, sum);
    free(s1);
    free(s2);
    return 0;
}


