#include <stdio.h>
int fib(int n)
{
    if (n==0){
        return 0;
    }
    if (n==1){
        return 1;
    }
    else {
        return (fib(n-1)+fib(n-2));
    }
}

int main(void){
    int sol=fib(5);
    printf("\n%d",sol);

    return 0;
}