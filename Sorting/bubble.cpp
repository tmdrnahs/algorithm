#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
 
#define MAX_N (5000)
 
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

void BubbleSort()
{
    int temp;

    for (int i=0; i<N-1; i++)
    {
        for (int j=0; j<N-1-i; j++)
        {
            if (num[j] > num[j+1])
            {
                temp = num[j];
                num[j] = num[j+1];
                num[j+1] = temp;
            }
        }
    }
}
 
 
int main(void)
{
    Input_Data();

    // Call Sorting
    BubbleSort();
    Print();
 
    return 0;
}