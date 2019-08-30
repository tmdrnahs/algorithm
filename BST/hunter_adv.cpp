// 문제 설명
// KOI 사냥터에는 N 마리의 동물들이 각각 특정한 위치에 살고 있다. 사냥터에 온 사냥꾼은 일직선상에 위치한 M 개의 사대(총을 쏘는 장소)에서만 사격이 가능하다. 편의상, 일직선을 x-축이라 가정하고, 사대의 위치 x1, x2, ... xM 은 x-좌표 값이라고 하자. 각 동물이 사는 위치는 (a1, b1), (a2, b2), ..., (aN, bN) 과 같이 x, y-좌표 값으로 표시하자. 동물의 위치를 나타내는 모든 좌표 값은 양의 정수이다.
// 사냥꾼이 가지고 있는 총의 사정거리가 L 이라고 하면, 사냥꾼은 한 사대에서 거리가 L 보다 작거나 같은 위치의 동물들을 잡을 수 있다고 한다. 단, 사대의 위치 xi와 동물의 위치 (aj,bj) 간의 거리는 |xi-aj| + bj 로 계산한다.
// 예를 들어, 아래의 그림과 같은 사냥터를 생각해보자. (사대는 작은 사각형으로, 동물의 위치는 작은 원으로 표시되어 있다.) 사정거리 L이 4라고하면, 점선으로 표시된 영역은 왼쪽에서 세 번째 사대에서 사냥이 가능한 영역이다.
// 사대의 위치와 동물들의 위치가 주어졌을 때, 잡을 수 있는 동물의 수를 출력하는 프로그램을 작성하시오.
// 입력 설명
// 입력의 첫 줄에는 사대의 수 M(1≤M≤100,000) 동물의 수 N(1≤N≤100,000), 사정거리 L(1≤L≤1,000,000,000)이 빈칸을 사이에 두고 주어진다. 두 번째 줄에는 사대의 위치를 나타내는 M개의 x-좌표 값이 빈칸을 사이에 두고 양의 정수로 주어진다. 이후 N 개의 각 줄에는 각 동물의 사는 위치를 나타내는 좌표 값이 x-좌표 값, y-좌표 값의 순서로 빈칸을 사이에 두고 양의 정수로 주어진다. 사대의 위치가 겹치는 경우는 없으며, 동물들의 위치가 겹치는 경우도 없다. 모든 좌표 값은 1,000,000,000 보다 작거나 같은 양의 정수이다.
// 출력 설명
// 출력은 단 한 줄이며, 잡을 수 있는 동물의 수를 음수가 아닌 정수로 출력한다.
// 입력 예시
// 4 8 4
// 6 1 4 9 
// 7 2
// 3 3
// 4 5
// 5 1
// 2 2
// 1 4
// 8 4
// 9 4
// 출력 예시
// 6
#define _CRT_SECURE_NO_WARNINGS
 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
#define MAX_M (100000)
#define MAX_N (100000)
 
typedef struct
{
    int x;
    int y;
}ANIMAL;
 
int M, N, L;
int shoot[MAX_M];
ANIMAL animal[MAX_N];
 
int comp(const void* p1, const void* p2) 
{
    return *(int*)p1 - *(int*)p2;
}
 
void Input_Data(void)
{
    int i;
    scanf("%d %d %d", &M, &N, &L);
    for (i=0;i<M;i++)
    {
        scanf("%d", &shoot[i]);
    }
    for (i = 0; i < N; i++)
    {
        scanf("%d %d", &animal[i].x, &animal[i].y);
    }
}
 
 
int Binary_Search_Upper(int s,int e,int d)
{
    int m,sol = -1;
 
    while(s<=e)
    {
        m = (s+e)/2;
        if(shoot[m] <= d)
        {
            sol = m;
            s = m+1;
        }
        else e = m -1;
    }
    return sol;
}
 
int Binary_Search_Lower(int s,int e,int d)
{
    int m,sol = -1;
 
    while(s<=e)
    {
        m = (s+e)/2;
        if(shoot[m] >= d)
        {
            sol = m;
            e = m-1;
        }
        else s = m+1;
    }
    return sol;
}
 
int Get_Distance(int idx_animal,int idx_shoot)
{
    return animal[idx_animal].y + abs(animal[idx_animal].x - shoot[idx_shoot]);
}
 
int Get_Solution(void)
{
    int i,ret,cnt = 0;
    qsort(shoot,M,sizeof(shoot[0]),comp);
    for(i=0;i<N;i++)
    {
        ret = Binary_Search_Upper(0,M-1,animal[i].x);
        if(ret != -1 && Get_Distance(i,ret) <= L)
        {
            cnt++;
            continue;
        }
         
        ret = Binary_Search_Lower(0,M-1,animal[i].x);
        if(ret != -1 && Get_Distance(i,ret) <= L)
        {
            cnt++;
            continue;
        }
    }
    return cnt;
}
int main(void)
{
    Input_Data();
 
    printf("%d\n", Get_Solution());
 
    return 0;
}