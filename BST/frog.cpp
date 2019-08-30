
// 문제 설명
// 개구리가 연못 위에서 놀고 있다. 개구리는 N개의 연 잎 들을 이용해서 이리저리 뛰어 놀고 있다.
 
// 개구리가 뛰는 장면을 보던 철수는 개구리가 도약을 하는 경우가 얼마나 있는지 궁금해졌다. 여기서 도약은 아래 조건을 만족하는 경우를 말한다.
 
// 1. 개구리가 뛴 거리가 이전에 뛴 거리 이상 뛰지만 그 2배보다 멀리 뛰지는 않는다.
// 2. 개구리는 오른쪽으로만 뛴다.
// 3. 개구리는 두 번만 뛴다.
// 4. 위 세 가지 조건을 만족한다면 어느 곳에서든 시작할 수 있다.
 
// 허나, 연 잎 들이 너무 많기 때문에 가능한 횟수가 매우 많아질 것 같다고 생각한 철수는, 개구리가 오른쪽으로 도약하는 경우가 얼마나 되는지 구해달라고 했다. 철수를 위해 프로그램을 짜주자.
// 입력 설명
// 첫 번째 줄에는 연 잎의 수 N(3 ≤ N ≤ 1,000)이 주어진다.
// 두 번째 줄부터 N개의 줄에는 각 연 잎의 좌표가 주어진다. 모든 좌표는 0 이상 108 이하이다.
 
// 출력 설명
// 개구리가 오른쪽으로 도약하는 경우의 수를 출력한다.
 
// 입력 예시
// 5
// 3
// 1
// 10
// 7
// 4
// 출력 예시
// 4
// 부가정보
// 개구리가 오른쪽으로 도약하는 경우는 다음 4가지뿐이다.
// (1, 3, 7), (1, 4, 7), (4, 7, 10), (1, 4, 10)

#include <stdio.h>
#include <stdlib.h>

#define MAX_N (200000)

int N;
int array[MAX_N];

void printArray(void)
{
    for (int i = 0; i < N; i++)
        printf("%d ", array[i]);
}

void InputData(void)
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &array[i]);
    }
}

int BinarySearchLower(int s, int e, int d)
{
    int m;
    int sol = -1;

    while (s<=e)
    {
        m = (s+e)/2;
        if (array[m] >= d)          // m이 d 이상이면
        {
            sol = m;                // m을 후보로 저장
            e = m-1;
        }
        else s = m+1;
    }

    return sol;
}

int BinarySearchUpper(int s, int e, int d)
{
    int m;
    int sol = -1;

    while (s<=e)
    {
        m = (s+e)/2;
        if (array[m] <= d)          // m이 d 이하이면
        {
            sol = m;                // m을 후보로 저장
            s = m+1;
        }
        else e = m-1;
    }

    return sol;
}

void FrogJum()
{
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = i+1; j < N; j++)
        {
            int jump = array[j] - array[i];
            int ds = array[j] + jump;
            int de = array[j] + jump*2;

            int lower = BinarySearchLower(j+1, N-1, ds);
            if (lower == -1)
                continue;
            int upper = BinarySearchUpper(lower, N-1, de);
            if (upper == -1)
                continue;

            count += upper - lower + 1;
        }
    }

    printf("%d", count);
}

int comp(const void* p1, const void* p2)
{
    return *(int*)p1 - *(int*)p2;
}

int main(void)
{
    InputData();
    qsort(array, N, sizeof(array[0]), comp);
    FrogJum();
    //printArray();
    return 0;
}