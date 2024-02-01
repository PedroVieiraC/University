#include <stdio.h>

void hexad(int num){
    char ae[6] = {'A', 'B', 'C', 'D', 'E', 'F'};
    
    if(num > 15){
        hexad(num/16);
    }
    if(num%16 >9){
        printf("%c",ae[(num%16)-10]);
    }
    else
    printf("%i", num % 16);
}

int main()
{

    int num;
    scanf("%i", &num);
    
    hexad(num);
    
    printf("\n");
    
    return 0;
}