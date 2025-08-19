#include <stdio.h>

int multi (float a, float b, float c) 
{
    printf("%.2f", a * b * c);
    return(0);
    
}

int main(){
    float x, y;
    x = 4.0;
    y = 4.0;
    multi(x, y, 2.0);
    return(0);

}