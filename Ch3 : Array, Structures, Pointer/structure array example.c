#include <stdio.h>
#include <string.h>
typedef struct studentTag { //학생 구조체 선언
    char name[10]; //학생 이름 저장할 문자 배열 
    int age;       //학생의 나이를 저장할 정수 변수 
    double gpa;    //평균 평점을 저장할 실수 변수 
} student; //student 라고 하겠다

int main(void){
    student s[2]={{"김이화",20,4.3}, {"최이화",21,3.7}}; //2개 한번에 선언
    for (int i=0;i<2;i++)
        printf("%s,%d,%.2f\n", s[i].name, s[i].age, s[i].gpa);
}