/* 수행시간 측정 프로그램
방법1. clock()
방법2. time()
*/

#include <stdio.h>
#include <time.h>

int main(void){
    clock_t start, finish; //typedef long clock_t (long을 typedef한 것)
    double duration;
    int i, x;
    start=clock();
    //수행시간 측정 시작
    for (i=0; i<1000000000; i++)
        x=i*5;
    //수행시간 측정 끝
    finish=clock();
    duration=(double) (finish-start)/CLOCKS_PER_SEC; //CLOCKS_PER_SEC로 나눠줘야 초단위로 나옴
    printf("%.2f 초입니다.\n", duration);

    return 0;
}