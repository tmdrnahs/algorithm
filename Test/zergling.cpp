// 문제 설명
// 승훈이는 심심한 시간에 스타크래프트(Starcraft) 게임을 하며 놀고 있었다. 스타크래프트유닛중 하나인 저글링을 한 곳에 몰아세운 뒤, 방사능 오염 공격으로 없애보려고 했다.
// 그런데 좀 더 재미있게 게임을 하기 위해서 게임을 개조하여 방사능 오면 공격을 가하면 방사능은 1초마다 이웃한 저글링에 오염된다.
// 그리고 방사능에 오염된 저글링은 3초 후에 죽게 된다.
// 예를 들어 아래 왼쪽그림과 같이 모여 있는 저글링 중에 빨간 동그라미 표시를 한 저글링에게 방사능 오염공격을 가하면, 총 9초 후에 저글링들이 죽게 된다.
// 아래 오른쪽에 있는 그림의 숫자들은 각 저글링들이 죽는 시간이다.
// 저글링을 모아놓은 지도의 크기와 지도상에 저글링들이 놓여 있는 격자 위치가 주어질 때, 총 몇 초 만에 저글링들을 모두 없앨 수 있는지 알아보는 프로그램을 작성하시오. 
// 입력 설명
// 첫째 줄은 지도의 가로 세로 크기가 주어진다. 지도는 격자 구조로 이루어져 있으며 크기는 100×100칸을 넘지 않는다.
// 둘째 줄부터는 지도상에 저글링들이 놓여있는 상황이 주어진다. 1은 저글링이 있는 곳의 표시이고 0은 없는 곳이다.
// 마지막 줄에는 방사능오염을 가하는 위치가 가로 세로 위치로 주어진다.
// 출력 설명
// 죽을 수 있는 저글링들이 모두 죽을 때까지 몇 초가 걸리는지 첫 번째 줄에 출력하고 둘째 줄에는 죽지 않고 남아 있게 되는 저글링의 수를 출력하시오.
// 입력 예시
// 7 8
// 0010000
// 0011000
// 0001100
// 1011111
// 1111011
// 0011100
// 0011100
// 0001000
// 3 5
// 출력 예시
// 9
// 0

#include <stdio.h>

#define MAX_N 100

int W, H; // 지도 크기
int X, Y;
int map[MAX_N+1][MAX_N+1];
int aliveZergling = 0;

void InputData(void)
{
    scanf("%d %d", &W, &H);
    for (int i = 1; i <= H; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            scanf("%1d", &map[i][j]);
            
            if (map[i][j])
                aliveZergling++;
        }
    }
    scanf("%d %d", &X, &Y);
}

void PrintData(void)
{
    printf("==MapData==\n");
    for (int i = 1; i <= H; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }
    printf("startingPoing: (%d, %d)\n", X, Y);
    printf("aliveZergling: %d\n", aliveZergling);
}

int sol = 0;

void BFS(int stage, int x, int y)
{
    if (x < 1 || y < 1 || MAX_N < x || MAX_N < y) return;
    if (map[x][y] == 0 || map[x][y] == 5) return;
    sol = stage;
    map[x][y] = 5;
    aliveZergling--;
    if (aliveZergling == 0) return;

    BFS(stage+1, x+1, y);
    BFS(stage+1, x, y+1);
    BFS(stage+1, x-1, y);
    BFS(stage+1, x, y-1);
}

int main(void)
{
    InputData();
    BFS(3, X, Y);
    printf("%d %d", sol, aliveZergling);

    return 0;
}