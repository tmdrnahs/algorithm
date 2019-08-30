// 문제 설명
// <그림 1>과 같이 정사각형 모양의 지도가 있다. 1은 집이 있는 곳을, 0은 집이 없는 곳을 나타낸다.
// 철수는 이 지도를 가지고 연결된 집들의 모임인 단지를 정의하고, 단지에 번호를 붙이려 한다. 여기서 연결되었다는 것은 어떤 집이 좌우, 혹은 아래위로 다른 집이 있는 경우를 말한다. 대각선상에 집이 있는 경우는 연결된 것이 아니다. <그림 2>는 <그림 1>을 단지별로 번호를 붙인 것이다.
// 지도를 입력하여 단지수를 출력하고, 각 단지에 속하는 집의 수를 오름차순으로 정렬하여 출력하는 프로그램을 작성하시오.
// 입력 설명
// 첫 번째 줄에는 지도의 크기 N(정사각형이므로 가로와 세로의 크기는 같으며 5≤N≤25)이 입력되고, 그 다음 N줄에는 각각 N개의 자료(0혹은 1)가 입력된다.
// 출력 설명
// 첫 번째 줄에는 총 단지수를 출력하시오. 그리고 각 단지 내 집의 수를 오름차순으로 정렬하여 한 줄에 하나씩 출력하시오.
// 입력 예시
// 7
// 0110100
// 0110101
// 1110101
// 0000111
// 0100000
// 0111110
// 0111000
// 출력 예시
// 3
// 7
// 8
// 9

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
 
#define MAX_N (25)
 
int N;
int map[MAX_N+2][MAX_N+2];
 
int cnt_ff;
 
int cnt_group;
int cnt_apt[MAX_N*MAX_N/2+1];
 
int comp(const void*p1,const void*p2)
{
    return *(int*)p1 - *(int*)p2;
}
 
void Input_Data(void)
{
    int r,c;
    scanf("%d",&N);
    for(r=1;r<=N;r++)
    {
        for(c=1;c<=N;c++)
        {
            scanf("%1d",&map[r][c]);
        }
    }
}
 
void Flood_Fill(int r,int c)
{
    static int dr[] = {0,0,1,-1};
    static int dc[] = {1,-1,0,0};
 
    int i;
    int nr,nc;
 
    cnt_ff++;
    map[r][c] = 0;
 
    for(i=0;i<4;i++)
    {
        nr = r + dr[i];
        nc = c + dc[i];
 
        if(map[nr][nc] == 1) Flood_Fill(nr,nc);
    }
}
 
void Get_Cnt_Group(void)
{
    int r,c;
 
    for(r=1;r<=N;r++)
    {
        for(c=1;c<=N;c++)
        {
            if(map[r][c] == 1)
            {
                cnt_ff = 0;
                Flood_Fill(r,c);
                cnt_apt[cnt_group++] = cnt_ff;
            }
        }
    }
}

int main(void)
{
    int i;
    Input_Data();
     
    Get_Cnt_Group();
 
    printf("%d\n",cnt_group);
    qsort(cnt_apt,cnt_group,sizeof(cnt_apt[0]),comp);
     
    for(i=0;i<cnt_group;i++)
    {
        printf("%d\n",cnt_apt[i]);
    }

    return 0;
}