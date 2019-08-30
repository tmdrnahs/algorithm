// 문제 설명
// 지방에서 서울에 관광 온 성수는 지하철 노선을 보고 깜짝 놀랐다. 노선이 엄청나게 복잡하기 때문이었다.
// 각 노선들이 서로 얽혀있어서 잘못하면 10분도 안 걸리는 거리를 1시간 동안 갈 수도 있는 상황이었다.
// 어쩔 수 없이 성수는 현재 숙소에서 관광할 목적지까지 가장 짧은 시간에 도착할 수 있는 경로와 시간을 표로 만들려고 한다.
// 단, 각 지하철역에서 관광지가 있고, 지하철을 갈아타는데 소요되는 시간은 없다고 가정한다.
// 입력 설명
// 첫 줄에 N(3<= N <= 100), M(1<= M <= N)을 입력 받는다. N은 지하철역의 수, M은 원하는 목적역의 번호를 입력 받는다.
// 둘째 줄부터 N개의 줄이 나오고, 각 줄에는 N개의 수 S가 입력된다.
// i번째 줄에서 j번째 수 Sij는 i번 역에서 j번 역까지 가는데 걸리는 시간이다. 1번 역이 숙소가 있는 역이고, Sij에서 i=j 일 때는 항상 0이다. (0<= S <=100)
// 출력 설명
// 목적 역까지 가는데 걸리는 최소 시간과 최소시간으로 가는 최단 경로를 출력한다.
// 입력 예시
// 5 5
// 0 2 2 5 9
// 2 0 3 4 8
// 2 3 0 7 6
// 5 4 7 0 5
// 9 5 6 5 0
// 출력 예시
// 8
// 1 3 5 
// 힌트
// 좌표 기반 BFS가 아니고 Node to Node 기반 가중치 BFS 예제이다.
#include <stdio.h>
 
#define MAX_N (100)
 
int N, M;
int mat[MAX_N+1][MAX_N+1];
 
typedef struct
{
    int n;
    int sum;
}QUEUE;
 
#define MAX_Q (MAX_N * 100)
QUEUE queue[MAX_Q];
int wp,rp;
 
#define Enqueue(X) (queue[wp++] = (X)) 
#define Dequeue(X) ((X) = queue[rp++])
#define QueueIsNotEmpty (wp > rp)
 
int chk[MAX_N+1];
int prev[MAX_N+1];
 
void Input_Data(void)
{
    int s,e;
    scanf("%d %d",&N,&M);
    for(s=1;s<=N;s++)
    {
        chk[s] = 0x7fffffff;
        for(e=1;e<=N;e++)
        {
            scanf("%d",&mat[s][e]);
        }
    }
}
 
int BFS(void)
{
    int i;
    QUEUE data,ndata;
 
    data.n = 1;
    data.sum = 0;
    Enqueue(data);
    chk[1] = 0;
 
    while(QueueIsNotEmpty)
    {
        Dequeue(data);
        if(data.sum != chk[data.n]) continue;
 
        for(i=1;i<=N;i++)
        {
            ndata.n = i;
            ndata.sum = data.sum + mat[data.n][ndata.n];
 
            if(chk[ndata.n] <= ndata.sum) continue;
 
            Enqueue(ndata);
            chk[ndata.n] = ndata.sum;
            prev[ndata.n] = data.n;
        }
    }
 
    return chk[M];
}
 
void Print_Path(int n)
{
    if(n == 0) return;
    Print_Path(prev[n]);
    printf("%d ",n);
}
 
 
int main(void)
{
    int ret;
    Input_Data();
 
    ret = BFS();
 
    printf("%d\n",ret);
 
    Print_Path(M);
 
    return 0;
}