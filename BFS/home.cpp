// 문제 설명
// 농부 창호가 키우는 소들은 각자 자신의 목장에 얌전히 있다. 소가 없는 텅 빈 목장도 있다. 각각의 목장은 다른 목장들과 하나 혹은 더 많은 길로 연결이 되어 있다. 때때로 두 목장은 한 개 이상의 길로 연결되어 있을 수도 있으며, 적어도 한 개 이상의 목장들은 헛간으로 가는 길이 존재한다. 물론 소는 어떤 방향으로도 갈 수 있고, 모든 소들은 같은 속도로 걷게 된다.
// 목장들에는 ‘a’부터 ‘z’까지와, ‘A’부터 ‘Y’까지로 번호가 붙여져 있다. 소 한 마리는 대문자 알파벳이 번호 매겨진 목장에 있다. (목장 하나 당 소 한 마리 이다) 그리고 소가 없는 목장은 소문자로 번호가 매겨져 있다. 헛간은 그 헛간에 소가 있건 없건, ‘Z’로 번호가 매겨져 있다.
// 각각 목장과 목장, 혹은 목장과 헛간을 잇는 길의 거리가 주어질 때, 헛간으로 가장 먼저 올 수 있는 소와 그 거리를 구하는 프로그램을 작성하자.
// 입력 설명
// 첫 줄에 P(1≤P≤10,000)개의 길 들이 입력된다. 둘째 줄부터 P+1번째 줄까지, 한 줄에 두 문자와 숫자 하나가 입력 되는데, 이는 서로 연결 되는 두 목장(혹은 헛간)의 번호와, 그 길의 길이(1≤길이≤1,000)를 뜻한다. 번호가 소문자인 목장과 대문자인 목장은 따로 존재한다. 예를 들어 번호가 ‘e’인 목장과 ‘E’인 목장은 따로 존재하며, ‘e’는 소가 없는 목장이고, ‘E’는 소가 있는 목장이다. 또한 ‘z’는 소가 없는 목장으로, 헛간 ‘Z’와는 상관없는 다른 장소이다.
// 출력 설명
// 가장 먼저 헛간에 도달하는 소가 원래 있던 목장의 번호와, 그 소가 걷는 거리를 출력하라.
// 입력 예시
// 5
// A d 6
// B d 3
// C e 9
// d Z 8
// e Z 3
// 출력 예시
// B 11

// 힌트
// 목적지 Z에서 BFS를 돌려서 각 대문자 농장에 도착하는 모든 경우의 수를 구한 후 가장 작은 값 
// 각 노드간 여러 갈래의 길이 있을 때, 최단 거리를 구하는 문제 이므로 작은 값만 저장!! 중요!!
// 목적지가 있을 떄, 목적지에서 출발지로 가는 식으로 거꾸로 생각하보자
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
 
#define MAX_NODE (52)
 
int mat[MAX_NODE][MAX_NODE];
int chk[MAX_NODE];
 
#define MAX_Q (MAX_NODE * 100)
 
typedef struct
{
    int n;
    int dist;
}QUEUE;
 
QUEUE queue[MAX_Q];
int wp, rp;
 
#define Enqueue(X) (queue[wp++] = (X))
#define Dequeue(X) ((X) = queue[rp++])
#define QueueIsNotEmpty (wp > rp)
 
 
int Char_to_Num(char ch)
{
    if('a'<=ch && ch<='z') return ch-'a';
    else return ch-'A' + 26;
}
 
char Num_to_Char(int num)
{
    if(0<=num && num<=25) return num+'a';
    else return num-26+'A';
}
 
void Input_Data(void)
{
    int P;
    int p;
    char ch1,ch2;
    int n1,n2;
    int dist;
 
    scanf("%d",&P);
    for(p=0;p<P;p++)
    {
        scanf(" %c %c %d",&ch1,&ch2,&dist);
        n1 = Char_to_Num(ch1);
        n2 = Char_to_Num(ch2);
        if(mat[n1][n2] == 0 || (mat[n1][n2] > dist))
        {
            mat[n1][n2] = mat[n2][n1] = dist;
        }
    }
 
    for(p=0;p<MAX_NODE;p++) chk[p] = 0x7fffffff;
}
 
int BFS(void)
{
    int min_dist_node;
    QUEUE data,ndata;
    int n;
 
    data.n = Char_to_Num('Z');
    data.dist = 0;
    Enqueue(data);
    chk[data.n] = 0;
 
    while(QueueIsNotEmpty)
    {
        Dequeue(data);
        if(data.dist != chk[data.n]) continue;
 
        for(n=0;n<MAX_NODE;n++)
        {
            ndata.n = n;
            if(mat[data.n][ndata.n] == 0) continue;
            ndata.dist = data.dist + mat[data.n][ndata.n];
 
            if(chk[ndata.n] <= ndata.dist) continue;
 
            Enqueue(ndata);
            chk[ndata.n] = ndata.dist;
        }
    }
     
    min_dist_node = 26;
    for(n = 27;n<=50;n++)
    {
        if(chk[min_dist_node] > chk[n]) min_dist_node = n;
    }
    return min_dist_node;
}
 
 
 
int main(void)
{
    int node=0; 
    Input_Data();
 
    node = BFS();
 
    printf("%c %d\n",Num_to_Char(node),chk[node]);
 
    return 0;
}