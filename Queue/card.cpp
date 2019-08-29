// 문제 설명
// N장의 카드로 구성 된 카드 덱(Deck)이 있다. 이 카드는 1번 카드가 가장 위에, N번 카드가 가장 아래쪽에 있는 형태로 놓여져 있다. 이제 이 카드를 아래의 규칙에 따라서 수행하면서 한 장씩 상대방에게 전달할 것이다.
 
// 1) 가장 아래 카드 번호를 2로 나눈 몫의 정수만큼 반복하여 제일 위에 올라와 있는 카드부터 한 장씩 순서대로 가장 밑으로 옮긴다.
// 2) 옮긴 후 가장 위에 올라와 있는 카드 한 장을 상대에게 넘긴다.
// 위 1)~2) 행동을 N-1번 수행하고 마지막에는 남은 카드 한 장을 넘긴다.
// 위 규칙대로 카드를 넘겼을 때, 상대방에게 넘긴 카드 번호를 넘긴 순서대로 출력하시오. 
// 입력 설명
// 첫 줄에 수식의 수의 갯수가 입력으로 주어진다. ( 1≤ N ≤100)
// 출력 설명
// 상대방에게 넘긴 카드 번호를 넘긴 순서대로 출력하시오.
// 입력 예시
// 4
// 출력 예시
// 3 1 2 4
#include <stdio.h>

#define MAX_N (100)
#define MAX_Q (MAX_N+1)

int N;
int queue[MAX_Q];
int wp = 0, rp = 0;

int Enqueue(int data)
{
	if((wp+1)%MAX_Q == rp) return 0;
	queue[wp] = data;
    wp = (wp+1)%MAX_Q;
	return 1;
}

int Dequeue(int *p)
{
	if(wp == rp) return 0;
	*p = queue[rp];
    rp = (rp+1)%MAX_Q;
	return 1;
}

void InitQueue(void)
{
    int i;
    for(int i=1; i<=N; i++)
    {
        Enqueue(i);
    }
}

void ShuffleQueue()
{
    int card;
    int lastCard = N;
    int repeat;

    for (int i=0; i<N; i++)
    {
        repeat = queue[(wp-1+MAX_Q)%MAX_Q]/2; // 음수 보정(원형 queue라서)
        for (int j=0; j<repeat; j++)
        {
            Dequeue(&card);
            Enqueue(card);
        }

        Dequeue(&card);
        printf("%d ", card);
    }
}

int main(void)
{
    scanf("%d", &N);
    
    InitQueue();
    ShuffleQueue();

    return 0;
}