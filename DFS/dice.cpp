// 문제 설명
// 주사위를 던진 횟수 N과 출력형식 M을 입력 받아서 M의 값에 따라 각각 아래와 같이 출력하는 프로그램을 작성하시오.
// M = 1 : 주사위를 N번 던져서 나올 수 있는 모든 경우
// M = 2 : 주사위를 N번 던져서 중복이 되는 경우를 제외하고 나올 수 있는 모든 경우
// M = 3 : 주사위를 N번 던져서 모두 다른 수가 나올 수 있는 모든 경우
// * 중복의 예
// 1 1 2 와 중복 : 1 2 1, 2 1 1
// 1 2 3 과 중복 : 1 3 2, 2 1 3, 2 3 1, 3 1 2
// 입력 설명
// 첫 줄에 주사위를 던진 횟수 N(2≤N≤5)과 출력모양 M(1≤M≤3)이 들어온다.
// 출력 설명
// 주사위를 던진 횟수 N에 대한 출력모양을 출력한다.
// 작은 숫자부터 출력한다.
// 입력 예시
// 3 1
// 출력 예시
// 1 1 1
// 1 1 2
// 1 1 3
// 1 1 4
// 1 1 5
// 1 1 6
// 1 2 1
// …
// 6 6 6
// 힌트
// M = 1, 모든 경우의 수
// M = 2 일 때, 재귀함수에 현재 선택한 번호를 넘겨줌으로써 선택하지 않도록 파라미터 전개 조합(combination)
// M = 3 일 때, 중복된 숫자를 선택한 적이 있는가에 대한 정보를 배열 하나를 만들어서 저장해 놓음 ex) arr[i] == 1; 인 경우 i를 선택한 적 있는 것으로 간주. 순열
#define _CRT_SECURE_NO_WARNINGS
 
#include <stdio.h>
 
int N,M;
 
#define MAX_N (5)
int select[MAX_N+1] ;
int chk[7];
 
void Dice1(int n)
{
    int i;
 
    if(n > N) 
    {
        for(i=1;i<=N;i++) printf("%d ",select[i]);
        printf("\n");
        return;
    }
 
    for(i=1;i<=6;i++)
    {
        select[n] = i;
        Dice1(n+1); 
    }
}
 
void Dice2( int n,int s)
{
    int i;
    if(n > N)
    {
        for(i=1;i<=N;i++) printf("%d ",select[i]);
        printf("\n");
        return;
    }
 
    for(i=s;i<=6;i++)
    {
        select[n] = i;
        Dice2(n+1,i);
    }
}
 
void Dice3(int n)
{
    int i;
 
    if(n>N)
    {
        for(i=1;i<=N;i++) printf("%d ",select[i]);
        printf("\n");
        return;
    }
 
    for(i=1;i<=6;i++)
    {
        if(chk[i] == 1) continue;
        select[n] = i;
        chk[i] = 1; 
        Dice3(n+1);
        chk[i] = 0;
    }
}
 
int main(void)
{
    scanf("%d %d",&N,&M);
    switch(M)
    {
    case 1:
        // void Dice1(int n)
        Dice1(1);
        break;
    case 2:
        ///Dice2( int n,int s)
        Dice2(1,1);
        break;
    case 3:
        Dice3(1);
        break;
    }
}