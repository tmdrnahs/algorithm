#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_N (30000)
 
int N;
int num[MAX_N];
int tmp[MAX_N];
 
void Input_Data(void)
{
    int i;
    scanf("%d", &N);
    for (i=0;i<N;i++)
    {
        scanf("%d", &num[i]);
    }
}
 
void Print(void)
{
    int i;
    for (i=0;i<N;i++)
    {
        printf("%d ", num[i]);
    }
}

int comp(const void* p1, const void* p2)
{
    return *(int*)p1 - *(int*)p2;
}
 
 
int main(void)
{
    Input_Data();

    // Call Sorting
    qsort(num, N, sizeof(num[0]), comp);
    Print();
 
    return 0;
}