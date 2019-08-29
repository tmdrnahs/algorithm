// 물류창고
// 힌트
// 1. 각 물건의 갯수를 입력 시 미리 수집한다.
#include <stdio.h>

#define MAX_N (100000)

int N; // 제품 수
int M; // 제품 종류 2 ~ 9
int product[MAX_N+1];

// H1. index를 각 제품 종류로 정한다.
int cntProduct[10];
int chk[10]; // 해당 index의 물건을 정리한 적 있나?
int sol = 0x7fffffff;

void InputData(void)
{
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++)
    {
        scanf("%d", &product[i]);
    }
}

void PrintData(void)
{
    for (int i = 1; i <= N; i++)
    {
        printf("%d", product[i]);
    }
}

void Init(void)
{
    for (int i = 1; i <= N; i++)
    {
        cntProduct[product[i]]++;
    }
}

void DFS(int m, int s, int cnt)
{
    for (int i = 1; i <= M; i++)
    {
        if (chk[i]) continue;
        int move = GetMoveCount(m, s, id);
    }
}

int main(void)
{
    int ans = -1;
    InputData();
    PrintData();

    ans = sol;
    printf("%d", ans);
    return 0;
}