#include <stdio.h>
#include <string.h>

struct studentTag{ //학생 구조체 선언
    char name[10];
    int age;
    double gpa;
}; //구조체는 뒤에 ;가 필요함

int main(void){
    struct studentTag s1;
    strcpy(s1.name,"kim");
    return 0;
}