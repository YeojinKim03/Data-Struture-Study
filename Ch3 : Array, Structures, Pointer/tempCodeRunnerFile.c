#include <stdio.h>
int main(void){
    int A[10]={1,2,3,4,5,6,7,8,9,10};
    int max=A[0]; //제일 앞에 것을 max라 가정
    for (int i=1;i<10;i++)
        if (A[i]>max)
            max=A[i];
    printf("최댓값=%d\n",max);

    return 0;
}