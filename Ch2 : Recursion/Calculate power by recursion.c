#include <stdio.h>
double power(double x, int n){
    if (n==0){
        return 1;
    }
    else if (n%2==0) //짝수
    {
        return power(x*x,n/2);
    }
    else{ //홀수
        return x*power(x*x, (n-1)/2);
    }
}


int main(void){
    int power_sol=power(2,9);
    printf("%d", power_sol);
    return 0;
}
//반으로 줄어들어가는 이런 경우 O(logn)이 됨