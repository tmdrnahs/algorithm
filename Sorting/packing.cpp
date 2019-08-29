// 문제 설명
// 사탕 공장에서는 요구에 따라 다양한 개수의 사탕을 담고 있는 포장을 하고 있다. 어느 날 갑자기 대형 이벤트가 생겨서 공장에 있는 모든 사탕들을 풀어서 하나로 포장 해야 한다.
// A, B, C 3개의 사탕 포장이 있을 때 이 포장들을 한번에 하나로 합칠 수는 없고, 한번에 2개씩만 합칠 수 있다. 예를 들면 A와 B를 먼저 합친 후 C를 다시 합치거나 A와 C를 먼저 합치고 B를 합치기, 혹은 B와 C를 먼저 합치고 A를 합칠 수 있다.
// 사탕 포장을 풀었다가 다시 합치는 순서는 매우 중요한데, 그 이유는 그 순서에 따라 전체 비용이 달라지기 때문이다.
// 사탕 포장 A와 B에 각각 a개와 b개의 사탕이 들어있다고 할 때 이 둘을 합치는 비용은 a + b라고 한다. 그러므로 A와 B를 먼저 합치고 C를 합치는 경우 그 전체 비용은 a + b + a + b + c이며, B와 C를 먼저 합치고 A를 합치는 비용은 b + c + b + c + a 이므로 그 둘은 서로 같지 않을 수 있다.
// 예를 들어, 각각 2, 2, 5개가 포장되어 있다면 A(2)와 B(2)를 합치는 비용은 4. 합쳐진 것(4)과 C(5)를 합치는 비용은 9로 총 13이 최소비용이다.
// 현재 공장에 포장되어 있는 포장 개수 N과 각각 포장에 들어있는 사탕의 개수 ni가 주어질 때, 이들을 하나로 합치는데 들어가는 비용의 최소(C)를 구하라.
// 입력 설명
// 첫 번째 줄에는 포장 개수 N(1<=N<=5000)이 주어진다.
// 두 번째 줄에는 포장에 들어있는 사탕의 개수 ni(1<=ni<=100)가 주어진다.
// 출력 설명
// 최소 비용을 출력한다.
// 입력 예시
// 3
// 2 2 5
// 출력 예시
// 13

#include <stdio.h>
#include <stdlib.h>

#define MAX_N (5000)

int N;
int package[MAX_N];

void InputData(void)
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &package[i]);
    }
}

void PrintData(void)
{
    for (int i = 0; i < N; i++)
        printf("%d ", package[i]);

    printf("\n");
}

int compare(const void* p1, const void* p2)
{
    return *(int*)p1 - *(int*)p2;
}

void Packing(void)
{
    int sum = 0;
    for (int i = 0; i < N-1; i++)
    {
        qsort(package+i, N-1, sizeof(package[0]), compare);
        package[i+1] = package[i] + package[i+1];
        sum += package[i+1];
    }

    printf("%d", sum);
}

int main(void)
{
    InputData();
    Packing();
    
    return 0;
}