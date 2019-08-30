// 문제 설명
// 국가의 역할 중 하나는 여러 지방의 예산요청을 심사하여 국가의 예산을 분배하는 것이다.
// 국가예산의 총액은 미리 정해져 있어서 모든 예산요청을 배정해 주기는 어려울 수도 있다. 그래서 정해진 총액 이하에서 가능한 한 최대의 총 예산을 다음과 같은 방법으로 배정한다.
// (1) 모든 요청이 배정될 수 있는 경우에는 요청한 금액을 그대로 배정한다.
// (2) 모든 요청이 배정될 수 없는 경우에는 특정한 정수 상한액을 계산하여 그 이상인 예산요청에는 모두 상한액을 배정한다. 상한액 이하의 예산요청에 대해서는 요청한 금액을 그대로 배정한다.
// 예를 들어, 전체 국가예산이 485이고 4개 지방의 예산요청이 각각 120, 110, 140, 150이라고 하자. 이 경우, 상한액을 127로 잡으면, 위의 요청들에 대해서 각각 120, 110, 127, 127을 배정하고 그 합이 484로 가능한 최대가 된다.
// 여러 지방의 예산요청과 국가예산의 총액이 주어졌을 때, 위의 조건을 모두 만족하도록 예산을 배정하는 프로그램을 작성하시오.
// 입력 설명
// 첫째 줄에는 지방의 수를 의미하는 정수 N이 주어진다. N은 3 이상 10,000 이하이다.
// 다음 줄에는 각 지방의 예산요청을 표현하는 N개의 정수가 빈칸을 사이에 두고 주어진다. 이 값들은 모두 1 이상 100,000 이하이다.
// 그 다음 줄에는 총 예산을 나타내는 정수 M이 주어진다. M은 N이상 1,000,000,000 이하이다.
// 출력 설명
// 배정된 예산들 중 최대값인 정수를 출력한다.
// 입력 예시
// 4
// 120 110 140 150
// 485
// 출력 예시
// 127
// 부가정보
// [입력 예시 2]
// 5
// 70 80 30 40 100
// 450
// [출력 예시 2]
// 100
// 힌트 중간 값 정한다음에 BST로 탐색하면서 상한값 찾기
#include <stdio.h>
#include <math.h>

#define MAX_N (10000)
int N; // 지방 수
int M; // 총 예산

int request[MAX_N+1];
int requestSum;
int requestMax;

void InputData(void)
{
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
    {
        scanf(" %d", &request[i]);
    }
    scanf("%d", &M);
}

void PrintData(void)
{
    printf("--RequestList--\n");
    for (int i = 1; i <= N; i++)
    {
        printf("%d ", request[i]);
    }
    printf("\n");
}

int CheckRequest(void)
{
    for (int i = 1; i <= N; i++)
    {
        if (requestMax < request[i])
            requestMax = request[i];
        requestSum += request[i];
    }

    if (requestSum <= M)
        return 1;

    return 0;
}

int GetMax(void)
{
    int max = 0;

    if (CheckRequest())
        return requestMax;

    int average = M/N;
    int minus = M;
    int surplus = 0;

    for (int i = 1; i <= N; i++)
        minus -= request[i];

    for (int i = 1; i <= N; i++)
    {
        if (average - request[i] > 0)
            surplus += average - request[i];
    }

    int limit = abs(surplus + minus) / N;

    // 여기서 loop 돌리면서 찾기
    if ((average + limit + 1)*N <= M)
        max = average + limit + 1;
    else
        max = average + limit;


    return max;
}

int main(void)
{
    InputData();
    //PrintData();
    int sol = GetMax();
    printf("%d", sol);
    return 0;
}