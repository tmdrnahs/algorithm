#include <stdio.h>
#include <stdlib.h>

#define MAX_N (5000)

int N;
int package[MAX_N];

void InputData(void)
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &package[i]);
    }
}

void PrintData(void)
{
    for (int i = 0; i < N; i++)
        printf("%d ", package[i]);

    printf("\n");
}

int compare(const void* p1, const void* p2)
{
    return *(int*)p1 - *(int*)p2;
}

void Packing(void)
{
    int sum = 0;
    qsort(package, N, sizeof(package[0]), compare);
    // 기존과 다른 점은 quick sort 한번만 진행하고
    // 누적 값을 계속 insert 해줌
    for (int i = 0; i < N-1; i++)
    {
        package[i+1] = package[i] + package[i+1];
        sum += package[i+1];

        int temp = package[i+1];
        // 현재 index를 기준으로 다음 원소와 비교하며 swap 진행
        int j;
        for (j = i+1; j < N-1; j++)
        {
            if (temp > package[j+1])
                package[j] = package[j+1];
            else break;
        }
        package[j] = temp;
    }

    printf("%d", sum);
}

int main(void)
{
    InputData();
    Packing();
    
    return 0;
}