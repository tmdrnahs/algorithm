// 문제 설명
// 미로탈출 로봇 대회를 개최하였다. 대회에 사용되는 미로는 가로(X), 세로(Y) 100이하의 크기이며, 상하좌우로 이동가능하며 미로를 한 칸 이동하는 데는 1초가 걸린다.
// 로봇이 출발점에서 도착점까지 가장 빨리 이동할 경우 걸리는 시간을 구하는 프로그램을 작성하시오.
// 입력 설명
// 첫 줄에 미로의 크기 X, Y(1≤X, Y≤100)가 주어진다.
// 둘째 줄에 출발점 x, y 좌표와 도착점 x, y 좌표가 공백으로 구분하여 주어진다.
// 셋째 줄부터 미로의 정보가 길은 0, 벽은 1로 공백이 없이 들어온다.
// 주의 사항으로, 좌표는 좌측상단이 가장 작은 위치이며 이 위치의 좌표는 (1,1)이다.
// 출력 설명
// 첫 줄에 출발점에서 도착점까지 가장 빠른 시간을 출력한다.
// 입력 예시
// 8 7
// 1 2 7 5
// 11111111
// 00000111
// 10110011
// 10111001
// 10111101
// 10000001
// 11111111
// 출력 예시
// 9
// 힌트
// 좌표간 가중치가 동일하다. 나중에 시도되는 경우는 좋지 않은 결과이기 떄문에 차단해준다.
#define _CRT_SECURE_NO_WARNINGS
 
#include <stdio.h>
 
#define MAX_RC (100)
 
int C,R;
int sc,sr,ec,er;
int map[MAX_RC+1][MAX_RC+1];
 
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
 
int chk[MAX_RC+1][MAX_RC+1];
 
void Input_Data(void)
{
    int r,c;
    scanf("%d %d",&C,&R);
    scanf("%d %d %d %d",&sc,&sr,&ec,&er);
    for(r=1;r<=R;r++)
    {
        for(c=1;c<=C;c++)
        {
            scanf("%1d",&map[r][c]);
        }
    }
}
 
int BFS(void)
{
    int i;
    QUEUE data,ndata;
    int dr[] = {-1,1, 0,0};
    int dc[] = { 0,0,-1,1};
    data.r = sr;
    data.c = sc;
    data.time = 0;
    Enqueue(data);
    chk[sr][sc] = 1;
 
    while(QueueIsNotEmpty)
    {
        Dequeue(data);
 
        for(i=0;i<4;i++)
        {
            ndata.r = data.r + dr[i];
            ndata.c = data.c + dc[i];
            ndata.time = data.time + 1;
            if(ndata.r<1 || ndata.r>R) continue;
            if(ndata.c<1 || ndata.c>C) continue;
 
            if(map[ndata.r][ndata.c] == 1) continue;
            if(chk[ndata.r][ndata.c] == 1) continue;
 
            if(ndata.r==er && ndata.c == ec) return ndata.time;
 
            Enqueue(ndata);
            chk[ndata.r][ndata.c] = 1;
        }
    }
    return -1;
}
 
 
 
int main(void)
{   
    Input_Data();
 
    printf("%d\n",BFS());
 
    return 0;
}
