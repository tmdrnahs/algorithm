// 문제 설명
// 배열에 오름차순으로 N개의 숫자가 저장되어 있다.
// M개의 탐색할 숫자가 주어질 때, 각 숫자가 배열에 몇 개씩 저장되어 있는지 출력하는 프로그램을 작성하시오.
// 입력 설명
// 첫째 줄에 N 이 입력된다. (1≤N≤200,000)
// 둘째 줄에 배열에 저장 되어있는 N개의 숫자가 순서대로 공백으로 구분되어 입력된다.
// 셋째 줄에 M 이 입력된다. (1≤M≤200,000)
// 넷째 줄에 M개의 탐색할 숫자가 순서대로 공백으로 구분되어 입력된다.
// (이 숫자는 정렬 되어있지 않다)
// 출력 설명
// 입력 넷째 줄에서 주어진 탐색할 숫자의 배열 내 저장된 개수를 차례대로 출력한다.
// 입력 예시
// 10
// 1 1 1 6 9 11 13 17 19 20 
// 2
// 1 9 
// 출력 예시
// 3 1 

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
  
#define MAX_N (200000)
  
int N;
int num[MAX_N + 1];
  
void Input_Data(void)
{
    int i;
    scanf("%d", &N);
    for (i = 1; i <= N; i++)
    {
        scanf("%d", &num[i]);
    }
}
  
int Binary_Search_Lower(int s,int e,int d)
{
    int m;
    int sol = -1;
 
    while(s<=e)
    {
        m = (s+e)/2;
        if(num[m] == d)
        {
            sol = m;
            e = m -1;
        }
        else if(num[m]>d) e = m-1;
        else s = m+1;
    }
    return sol;
}
 
int Binary_Search_Upper(int s,int e,int d)
{
    int m;
    int sol = -1;
 
    while(s<=e)
    {
        m = (s+e)/2;
        if(num[m] == d)
        {
            sol = m;
            s = m + 1;
        }
        else if(num[m]>d) e = m-1;
        else s = m+1;
    }
    return sol;
}
  
int main(void)
{
    int i, T, d,lower,upper ;
    Input_Data();
  
    scanf("%d", &T);
    for (i = 0; i < T; i++)
    {
        scanf("%d", &d);
 
        lower = Binary_Search_Lower(1,N,d);
        if(lower == -1)
        {
            printf("0 ");       
        }
        else
        {
            upper = Binary_Search_Upper(lower,N,d);
            printf("%d ",upper - lower + 1);
        }
    }
    return 0;
}