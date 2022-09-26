#include <stdio.h>
double slow_power(double x, int n) //제곱하는 수, n제곱 입력
{
    int i;
    double result=1.0;
    for (i=0; i<n; i++)
    {
        result=result*x;
    }
    return result;
}

int main(void){
    double power=slow_power(2.0,3);
    printf("%g",power); //있는 그대로 출력
    return 0;
}