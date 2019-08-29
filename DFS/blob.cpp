// 문제 설명
// 해마다 열리는 꿀꿀이 올림피아드에는 여러 종목들이 있는데, 요즘에는 꿀꿀이들의 교양을 겨루는 ‘미술관람 대회’가 인기를 끌고 있다. 이 대회는 사회자가 빨강, 초록, 파랑으로 이루어진 N × N 픽셀의 그림을 보여주면 그 그림에 포함된 영역의 수를 빠르고 정확하게 맞추는 것이 목표이다. 동일한 색깔이 네 방향(상, 하, 좌, 우) 중 한 곳이라도 연결되어 있으면 하나의 영역으로 간주한다.
// 예를 들어, 아래 그림은 각각 2, 1, 1개의 빨간색, 초록색, 파란색 영역이 있어 총 4개의 영역이 있다.
// 한편, 꿀꿀이들의 절반 정도는 선천적인 유전자 때문에 적록색맹이라서 빨간색과 초록색을 구별하지 못한다. 따라서 사회자는 일반 대회와 적록색맹용 대회를 따로 만들어서 대회를 진행하려고 한다. 사회자를 도와 영역의 수를 구하는 프로그램을 작성하여라.
// 입력 설명
// 첫 번째 줄에는 그림의 크기 N이 주어진다. (1 ≤ N ≤ 100)
// 두 번째 줄부터 N개의 줄에는 각 픽셀의 색깔이 'R'(빨강), 'G'(초록), 'B'(파랑) 중 하나로 주어진다.
// 출력 설명
// 일반 꿀꿀이와 적록색맹 꿀꿀이가 보는 영역의 수를 출력한다.
// 입력 예시
// 5
// RRRBB
// GGBBB
// BBBRR
// BBRRR
// RRRRR
// 출력 예시
// 4 3

#define _CRT_SECURE_NO_WARNINGS
 
#include <stdio.h>
 
#define MAX_N (100)
 
int N;
char map[MAX_N+2][MAX_N+2];
int chk[MAX_N+2][MAX_N+2];
 
void Input_Data(void)
{
    int r,c;
    scanf("%d",&N);
    for(r=1;r<=N;r++)
    {
        for(c=1;c<=N;c++)
        {
            scanf(" %c",&map[r][c]);
        }
    }
}
 
void Flood_Fill(int r,int c)
{
    int i;
    static int dr[] = {0,0,1,-1};
    static int dc[] = {1,-1,0,0};
    int nr,nc;
    chk[r][c] = 1;
    for(i=0;i<4;i++)
    {
        nr = r + dr[i];
        nc = c + dc[i];
        if(chk[nr][nc] == 0 && map[r][c] == map[nr][nc])
            Flood_Fill(nr,nc);
    }
}
 
int Get_Cnt_Group(void)
{
    int r,c;
    int cnt_group = 0;
    for(r=1;r<=N;r++)
    {
        for(c=1;c<=N;c++)
        {
            if(chk[r][c] == 1) continue;
            Flood_Fill(r,c);
            cnt_group++;
        }
    }
    return cnt_group;
}
 
void Init_For_RG_Pig(void)
{
    int r,c;
    for(r=1;r<=N;r++)
    {
        for(c=1;c<=N;c++)
        {
            chk[r][c] = 0;
            if(map[r][c] == 'R') map[r][c] = 'G';
        }
    }
}
 
int main(void)
{
    int i,cnt_normal,cnt_rg;
    Input_Data();
 
    cnt_normal = Get_Cnt_Group();
     
    Init_For_RG_Pig();
    cnt_rg = Get_Cnt_Group();
 
    printf("%d %d\n",cnt_normal,cnt_rg);
 
    return 0;
}