#include <stdio.h>
#define MAX_DEGREE 101 // 다항식의 최대차수 +1

typedef struct { //이름 안써도 됨
    int degree; //차수
    float coef[MAX_DEGREE]; //차수의 계수
} polynomial; //다항식 구조체 선언

//다항식 A와 B를 더한 결과를 반환한다

polynomial poly_add1(polynomial A, polynomial B) //poly_add1()이라는 함수 정의, polynomial은 반환값이라 앞에 붙임
    {
        polynomial C;
        int Apos=0, Bpos=0, Cpos=0; //각 배열의 인덱스 [0]이런거 (배열 위치를 알기 위해)

        //차수 따라가려고
        int degree_a=A.degree; //A최고차항 차수 저장
        int degree_b=B.degree; //B최고차항 차수 저장

        C.degree=(A.degree>B.degree)? A.degree:B.degree; //A가 더 크면 A차수, B가 더 크면 B차수

        while (Apos <= A.degree && Bpos <= B.degree){ //최고차수보다 이하일때까지 루프 돌겠다

            if (degree_a > degree_b) {//A차수>B차수
                C.coef[Cpos]=A.coef[Apos]; //다음칸으로 옮김
                Cpos++;
                Apos++;
                degree_a--;
            }

            else if (degree_a == degree_b) {//A차수==B차수
                C.coef[Cpos]=A.coef[Apos] + B.coef[Bpos];
                degree_a--;
                degree_b--;
                Cpos++;
                Apos++;
                Bpos++;
            }

           else { // B차수 > A차수
                C.coef[Cpos++]=B.coef[Bpos++];
                degree_b--;
                Cpos++;
                Bpos++;
            }
        return C;
    }
    }

void print_poly(polynomial p){
    int i;
    for (i =p.degree; i>0 ; i--) //항 출력
        printf("%3.1fx^%d +", p.coef[p.degree - i], i);

    printf("%3.1f\n", p.coef[p.degree]);//없는 마지막 항 출력
}

int main(void){
    polynomial a={5, {3,6,0,0,0,10}};
    polynomial b={4, {7,0,5,0,1}};
    polynomial c;

    print_poly(a);
    print_poly(b);
    c=poly_add1(a,b);
    printf("----------\n");
    print_poly(c);

    return 0;
}