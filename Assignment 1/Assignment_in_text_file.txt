#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

enum level { freshman = 1, sophomore, junior, senior };  // 학년
struct student {		// 학생 정보를 저장할 구조체 모양
	char name[20];		// 이름
	enum level year;	// 학년
	int score;			// 점수
	struct student* next;	// 다른 학생을 가리킬 포인터
};
typedef struct student STUDENT;	// 닉네임 정의

// 학생들의 정보를 담는다.
STUDENT * buildClass(STUDENT* list)  {
  list = (STUDENT*)malloc(sizeof(STUDENT));
  STUDENT* curr = list;
  char name[20];
  enum level year;
  int score;
  
  printf("학생 정보 (이름 학년 점수): ");
  scanf("%s %d %d", name, &year, &score);
  while(year != 0){
    strcpy(curr->name, name);
    curr->year = year;
    curr->score = score;
    scanf("%s %d %d", name, &year, &score);

    if(year == 0 && score == 0)
        break;

    curr->next = (STUDENT*)malloc(sizeof(STUDENT));
    curr = curr->next;
  }
  return list;
}

void printClass(STUDENT* list) {
  STUDENT* p = list;
  printf("\n** 학생 리스트 출력 **\n");
  while(p != NULL){
	
    printf("%s: %d학년, %d점\n", p->name, p->year, p->score);
    p = p->next;
  }
}
	

void printStudent(STUDENT* list, char* p) {
  STUDENT* curr = list;

  //printf("\nprintStudent\n");
  while(strcmp(curr->name, p) != 0 && curr != NULL){
    curr = curr->next;
  }
  
  if(curr == NULL)
    printf("없음");
  printf("\n%s : %d학년, %d점\n\n", curr->name, curr->year, curr->score);
}

	

void findStudents(STUDENT* list, int low, int high) {
  STUDENT* curr = list;
  printf("*** %d점과 %d점 사이의 학생 정보 ***\n",low, high);
  while(curr != NULL){
    if(curr->score >=low && curr->score <=high)
      printf("%s : %d학년, %d점\n", curr->name, curr->year, curr->score);
    curr = curr->next;
  }
}
	

void printFour(STUDENT* list) {
  int i = 0;
  STUDENT* curr = list;
  printf("\n*** 4 학생들의 이름 ***\n");

  for(i = 0; i < 4; i++){
    printf("%s\n", curr->name);
    curr = curr->next;
  }
}	


int main() {

	STUDENT* list = NULL;
	list = buildClass(list);
	printClass(list);
	printStudent(list, "윤이화");
	findStudents(list, 70, 80);
	printFour(list);

	return 0;

}



