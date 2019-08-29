// 문제 설명
// 철수의 토마토 농장에서는 토마토를 보관하는 큰 창고를 가지고 있다. 토마토는 아래의 그림과 같이 격자 모양 상자의 칸에 하나씩 넣어서 창고에 보관한다.
// 창고에 보관되는 토마토들 중에는 잘 익은 것도 있지만, 아직 익지 않은 토마토들도 있을 수 있다. 보관 후 하루가 지나면, 익은 토마토들의 인접한 곳에 있는 익지 않은 토마토들은 익은 토마토의 영향을 받아 익게 된다. 하나의 토마토의 인접한 곳은 왼쪽, 오른쪽, 앞, 뒤 네 방향에 있는 토마토를 의미한다. 대각선 방향에 있는 토마토들에게는 영향을 주지 못하며, 토마토가 혼자 저절로 익는 경우는 없다고 가정한다. 철수는 창고에 보관된 토마토들이 며칠이 지나면 다 익게 되는지, 그 최소 일수를 알고 싶어 한다.
// 토마토를 창고에 보관하는 격자모양의 상자들의 크기와 익은 토마토들과 익지 않은 토마토들의 정보가 주어졌을 때, 며칠이 지나면 토마토들이 모두 익는지, 그 최소 일수를 구하는 프로그램을 작성하라. 단, 상자의 일부 칸에는 토마토가 들어있지 않을 수도 있다.

// 입력 설명
// 첫 줄에는 상자의 크기를 나타내는 두 정수 M, N이 주어진다. M은 상자의 가로 칸의 수, N은 상자의 세로 칸의 수를 나타낸다. 단, 2≤M, N≤1,000 이다. 둘째 줄부터는 하나의 상자에 저장된 토마토들의 정보가 주어진다. 즉, 둘째 줄부터 N개의 줄에는 상자에 담긴 토마토의 정보가 주어진다. 하나의 줄에는 상자 가로줄에 들어있는 토마토의 상태가 M개의 정수로 주어진다. 정수 1은 익은 토마토, 정수 0은 익지 않은 토마토, 정수 -1은 토마토가 들어있지 않은 칸을 나타낸다.
// 출력 설명
// 여러분은 토마토가 모두 익을 때까지의 최소 날짜를 출력해야 한다. 만약, 저장될 때부터 모든 토마토가 익어있는 상태이면 0을 출력해야 하고, 토마토가 모두 익지는 못하는 상황이면 -1을 출력해야 한다.
// 입력 예시
// 6 4
// 0 0 0 0 0 0
// 0 0 0 0 0 0
// 0 0 0 0 0 0
// 0 0 0 0 0 1
// 출력 예시
// 8
// 힌트
// BFS의 초기 값에 익은 토마토(들)의 좌표 넣어준다.
// 좌표간 가중치가 동일하다. 나중에 시도되는 경우는 좋지 않은 결과이기 떄문에 차단해준다.
#define _CRT_SECURE_NO_WARNINGS
 
#include <stdio.h>
#include <math.h>

#define MAX_RC (1000)
 
int C,R;
int box[MAX_RC+1][MAX_RC+1];
 
typedef struct
{
    int r;
    int c;
    int time;
} QUEUE;
 
#define MAX_Q (MAX_RC * MAX_RC)
QUEUE queue[MAX_Q];
int wp,rp;
 
#define Enqueue(X) (queue[wp++] = (X)) 
#define Dequeue(X) ((X) = queue[rp++])
#define QueueIsNotEmpty (wp > rp)

int cnt_tomato;

void Input_Data(void)
{
    int r,c;
    QUEUE data;
    scanf("%d %d",&C,&R);
    for(r=1;r<=R;r++)
    {
        for(c=1;c<=C;c++)
        {
            scanf("%d",&box[r][c]);
            switch(box[r][c])
            {
            case 0:
                cnt_tomato++;
                break;
            case 1:
                data.r = r;
                data.c = c;
                data.time = 0;
                Enqueue(data);
                break;
            }
        }
    }
}

void PrintData(void)
{
    printf("===tomato===\n");
    for(int r=1;r<=R;r++)
    {
        for(int c=1;c<=C;c++)
        {
            printf("%d ",box[r][c]);
        }
        printf("\n");
    }
}
 
int BFS(void)
{
    int cnt = 0;
    int dr[] = {-1,1, 0,0};
    int dc[] = { 0,0,-1,1};
    QUEUE data,ndata;

    while(QueueIsNotEmpty)
    {
        Dequeue(data);
 
        for(int i=0;i<4;i++)
        {
            ndata.r = data.r + dr[i];
            ndata.c = data.c + dc[i];
            ndata.time = data.time + 1;

            if(ndata.r<1 || ndata.r>R) continue;
            if(ndata.c<1 || ndata.c>C) continue;
            if(abs(box[ndata.r][ndata.c]) == 1) continue;

            Enqueue(ndata);
            box[ndata.r][ndata.c] = 1;
            cnt_tomato--;
        }
    }

    return cnt_tomato ? -1 : data.time;
}
 
int main(void)
{   
    Input_Data();
    printf("%d\n",BFS());
    //PrintData();
    return 0;
}
