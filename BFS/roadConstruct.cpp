#include <stdio.h>

int N;//지도 크기
char map[110][110];//지도 정보

typedef struct
{
    int r;
    int c;
    int sum;
} TILE;

#define MAX_N (100)
#define MAX_Q (MAX_N*MAX_N*10)
TILE queue[MAX_Q];
int wp,rp;

#define Enqueue(X) (queue[wp++] = (X)) 
#define Dequeue(X) ((X) = queue[rp++])
#define QueueIsNotEmpty (wp > rp)

int chk[MAX_N][MAX_N];

void Input_Data(void){
	int i;
	scanf("%d", &N);
	for(i = 0 ; i < N ; i++){
		scanf("%s", map[i]);
        for (int j=0; j<N; j++)
        {
            map[i][j] -= '0';
            chk[i][j] = 0x7fffffff;
        }
	}
}

int BFS(void)
{
    int dr[] = {0,0,1,-1};
    int dc[] = {1,-1,0,0};
    TILE data, ndata;

    data.r = 0;
    data.c = 0;
    data.sum = map[0][0];
    Enqueue(data);
    chk[0][0] = data.sum;

    while (QueueIsNotEmpty)
    {
        Dequeue(data);

        if (data.sum != chk[data.r][data.c]) continue;

        for (int i = 0; i < 4; i++)
        {
            ndata.r = data.r + dr[i];
            ndata.c = data.c + dc[i];

            if (ndata.r < 0 || ndata.r >= N) continue;
            if (ndata.c < 0 || ndata.c >= N) continue;
            
            ndata.sum = data.sum + map[ndata.r][ndata.c];

            if (ndata.sum >= chk[ndata.r][ndata.c]) continue;

            Enqueue(ndata);
            chk[ndata.r][ndata.c] = ndata.sum;
        }
    }

    return chk[N-1][N-1];
}

int main(void){
	int ans = -1;
	Input_Data();		//	입력 함수
	
	//	코드를 작성하세요
	ans = BFS();
	printf("%d\n", ans);		//	정답 출력
	return 0;
}