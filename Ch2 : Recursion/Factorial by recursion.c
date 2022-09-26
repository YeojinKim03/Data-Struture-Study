#include <stdio.h>
int factorial(int n) //fatorial 정의한 함수
{
    if(n<1) {
        return 1;}

    else {
        return (n*factorial(n-1));
    }
}
int main(void){
    int a=factorial(3); //3이라고 임의로 대입
    printf("%d",a);
    
    return 0;
}