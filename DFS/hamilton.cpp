// 문제 설명
// 문제를 잘 풀기로 소문난 도경이는 모든 올림피아드 대회에 참가하고 싶어 했다.
// 대회에 참가하여 상이란 상은 다 타고 싶은 마음이었지만, 한 가지 걸리는 것이 있었다.
// 문제는 올림피아드 대회가 모두 해외에서 열리는 관계로 비행기 값이 굉장히 많이 들어간다는 것이다.
// 결국에는 집으로 다시 돌아와야 하는데, 모든 대회에 1번씩만 참가하고 집으로 돌아오는 경비를 가장 최소화하고 싶다.
// 도경이는 이것을 해결하지 못하면, 대회에 참가하기가 어렵게 된다. 
// 대회는 참가하기만 하면 언제든지 알고리즘 문제를 풀 수 있기 때문에 경기를 계산하는 것 이외의 사항은 고려하지 않아도 된다.
// 입력 설명
// 첫 줄은 참가하는 대회의 수 N(1≤N≤12)을 입력 받는다. 이때, 출발지(집)는 1번으로 한다.
// 둘째 줄은 N*N 크기의 대회 개최지와 개최지를 이동하는 항공료(0≤항공료<100)가 나온다. 
// 각 항공료는 한 칸의 공백으로 구분된다. 만약에 개최지에서 개최지로 이동할 수 있는 항공로가 없다면 항공료의 값을 0으로 표시한다.
// 출력 설명
// 집에서 출발하여 전체 대회를 모두 참가하고 돌아올 때, 최소의 항공료를 출력한다.
// 입력 예시
// 5 
// 0 14 4 10 20 
// 14 0 7 8 7 
// 4 5 0 7 16 
// 11 7 9 0 2 
// 18 7 17 4 0 
// 출력 예시
// 30
// 부가정보
// 예제의 비용 (경로)
// 10 (1->4)
// + 2 (4->5)
// + 7 (5->2)
// + 7 (2->3)
// + 4 (3->1)
// = 30

#include <stdio.h>

#define MAX_N (12)

int N; // 대회의 수 1~12
int cost[MAX_N+1][MAX_N+1]; // 비용 인접 행렬

int chk[MAX_N+1];
int sol = 0x7fffffff;

void InputData(void)
{
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            scanf("%d", &cost[i][j]);
        }
    }
}

void Hamilton(int city, int sum, int cnt) // 출발 도시, 여행 경비, 방문한 도시
{
    if (cnt == N-1) // 각 도시를 다 방문한 경우 1번 도시로 돌아가야 함
    {
        if (cost[city][1] != 0 && sol > sum + cost[city][1]) // 각 도시에서 출발지로 가는 경로가 있고, 그 비용이 sol보다 작으면
            sol = sum + cost[city][1]; // 1번으로 돌아가는 비용을 총 비용에 더해줌

        return;
    }

    for (int i = 2; i <= N; i++) // 1번 도시 포함하지 않기로 했기 떄문에 2부터 시작
    {
        if (chk[i]) continue; // 가려는 도시에 방문한 적 있는가
        if (cost[city][i] == 0) continue; // 경로가 있는가?
        if (sol <= sum + cost[city][i]) continue;
        chk[i] = 1;
        Hamilton(i, sum + cost[city][i], cnt+1);
        chk[i] = 0; // Hamilton 순환 끝났을 때(종료 조건 못만났을 때), 배열 index 초기화
    }
}

int main(void)
{
    InputData();
    Hamilton(1, 0, 0);
    printf("%d\n", sol);
    
    return 0;
}