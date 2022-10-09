#include <stdio.h>
#include <stdlib.h> // exit() 사용을 위해 추가
#define MAX_TERMS 101

struct { //이름 없어도 괜찮음
    float coef; //계수
    int expon;  //차수
} terms[MAX_TERMS]={{8,3}, {7,1}, {1,0}, {10,3}, {3,2}, {1,0}}; //이렇게 구조체배열로 정의할수도 & 초기화

int avail=6; //전역변수, terms[]배열의 비어있는 첫째 요소의 인덱스 (0,1,2,3,4,5까지 찼으니까 6부터 가능하다 이 뜻)

//정수 2개를 비교하여 크기 정보를 반환하는 함수
char compare(int a, int b){
    if (a>b) return '>';
    else if (a==b) return '=';
    else return '<';
}

//새로운 항을 다항식에 추가하는 함수
void attach(float coef, int expon) {
    if (avail>=MAX_TERMS) {
        fprintf(stderr,"항의 개수가 너무 많음\n"); //file print로 에러메시지 화면에 즉시 출력
        exit(1); // 프로그램을 즉시 종료시키고 OS에게 1이라는 값을 전달하여 에러 상황을 알림
    }
    else {
        terms[avail].coef = coef;
        terms[avail].expon = expon;
    }
}

//C=A+B
poly_add2(int As, int Ae, int Bs, int Be, int* Cs, int* Ce) {
    float tempcoef;
    *Cs=avail;
    while (As <= Ae && Bs <= Be)
        switch (compare(terms[As].expon, terms[Bs].expon)){
            case '>':  //A의 차수 > B의 차수
                attach(terms[As].coef, terms[As].expon);
                As++;
                break;
            case '=':  //A의 차수 == B의 차수
                tempcoef=terms[As].coef + terms[Bs].coef;
                if (tempcoef)
                    attach(tempcoef, terms[As].expon);
                As++;
                Bs++;
                break;

            case '<':  //A의 차수 < B의 차수
                attach(terms[Bs].coef, terms[Bs].expon);
                Bs++;
                break;
        }
        // A의 나머지 항들을 이동함
        for (; As<= Ae; As++)
            attach(terms[As].coef, terms[As].expon);
        
        //B의 나머지 항들을 이동함
        for (; Bs<=Be;Bs++)
            attach(terms[Bs].coef, terms[Bs].expon);
        *Ce=avail-1;
}

void print_poly(int s, int e){
    for (int i=s; i<e; i++)
        printf("%3.1fx^%d\n", terms[e].coef, terms[e].expon);
}

int main(void){
    int As=0, Ae=2, Bs=3, Be=5, Cs, Ce;
    poly_add2(As, Ae, Bs,Be, &Cs, &Ce);
    print_poly(As, Ae);
    print_poly(Bs,Be);
    printf("----------\n");
    print_poly(Cs,Ce);

    return 0;
}
