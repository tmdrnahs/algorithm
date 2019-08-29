// N명의 점수가 주어질 때 상위 3명의 ID를 출력하는 프로그램을 작성하시오.
// 입력 설명
// 첫 줄에 학생 수 N(4≤N≤30,000)이 주어진다.
// 둘째 줄에는 N개의 점수가 공백으로 구분되어 ID 순으로 주어진다. (각 점수는 0 이상 10억 이하)
// 맨 먼저 입력된 점수는 ID가 1인 학생의 점수이고, 이후부터 순서대로 ID가 1씩 증가한다.
// 출력 설명
// 점수가 가장 높은 학생의 ID 3개를 순서대로 출력한다.
// 만일 점수가 같은 경우는 ID가 작은 학생을 선택한다.
// 입력 예시
// 8
// 70 30 70 40 60 50 90 80 
// 출력 예시
// 7 8 1 

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_N (30000)
 
typedef struct
{
    int id;
    int score;
} STUDENT;

int N;
STUDENT student[MAX_N];

void Input_Data(void)
{
    int i;
    scanf("%d", &N);
    for (i=0;i<N;i++)
    {
        student[i].id = i+1;
        scanf("%d", &student[i].score);
    }
}


// 점수가 같으면 id가 작은 사람 우선
int comp(const void* p1, const void* p2)
{
    if (((STUDENT*)p2)->score == ((STUDENT*)p1)->score)
        return ((STUDENT*)p1)->id - ((STUDENT*)p2)->id;
    return ((STUDENT*)p2)->score - ((STUDENT*)p1)->score;
}

int main(void)
{
    Input_Data();

    // Call Sorting
    qsort(student, N, sizeof(student[0]), comp); 
    printf("%d %d %d\n",student[0].id,student[1].id,student[2].id);
    return 0;
}