#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_N (100000)

int M; // 사냥꾼
int N; // 동물
int L; // 사거리

typedef struct {
    int x;
    int y;
} TARGET;

TARGET target[MAX_N];
int hunter[MAX_N];

void InputData(void)
{
    scanf("%d %d %d", &M, &N, &L);
    for (int i=0; i<M; i++)
        scanf("%d", &hunter[i]);
    for (int i=0; i<N; i++)
        scanf("%d %d", &target[i].x, &target[i].y);
}

void DummyData(void)
{
    M = 4;
    N = 8;
    L = 4;
    hunter[0] = 6;
    hunter[1] = 1;
    hunter[2] = 4;
    hunter[3] = 9;
    target[0].x = 7;
    target[0].y = 2;
    target[1].x = 3;
    target[1].y = 3;
    target[2].x = 4;
    target[2].y = 5; 
    target[3].x = 5;
    target[3].y = 1;
    target[4].x = 2;
    target[4].y = 2;
    target[5].x = 1;
    target[5].y = 4;
    target[6].x = 8;
    target[6].y = 4;
    target[7].x = 9;
    target[7].y = 4;
}


void PrintData(void)
{
    printf("hunter: ");
    for (int i=0; i<M; i++)
        printf("%d ", hunter[i]);
    printf("\ntarget: ");
    for (int i=0; i<N; i++)
        printf("target[%d](%d,%d) ", i, target[i].x, target[i].y);
    printf("\n");
}

void GetTarget(void)
{
    int sum = 0;

    //PrintData();
    for (int i=0; i<N; i++)
    {
        if (target[i].y > L)
            continue;

        for (int j=0; j<M; j++)
        {
            int distance = abs(target[i].x - hunter[j]) + target[i].y;
            if (distance > L)
                continue;

            sum++;
            break;
        }
    }

    printf("%d\n", sum);
}

int main(void)
{
    // InputData();
    DummyData();
    GetTarget();
    
    return 0;
}