#include <stdio.h>

#define MAX_N (10000)
#define MAX_Q (MAX_N+1)

int N;//직원 수
int S;//시작 직원 번호
int M;

int queue[MAX_Q];
int wp = 0;
int rp = 0;

void InputData(){
	scanf("%d %d %d", &N, &S, &M);
}

int Enqueue(int data)
{
	if ((wp+1)%MAX_Q == rp) return 0;
	queue[wp] = data;
	wp = (wp+1)%MAX_Q;
	return 1;
}

int Dequeue(int *data)
{
	if (wp==rp) return 0;
	*data = queue[rp];
	rp = (rp+1)%MAX_Q;
	return 1;
}

void print(void)
{
	printf("PrintQueue: ");
	for (int i=rp; i<(rp+N)%MAX_Q; i++)
		printf("%d ", queue[i]);
	printf("\n");
}

void InitQueue()
{
	for (int i=0; i<N; i++)
		Enqueue((S+i-1)%N+1);

	print();
}

void PrintQueue(void) 
{
	for (int i=0; i<N; i++)
	{
		int data;
		for (int j=0; j<M-1; j++)
		{
			Dequeue(&data);
			Enqueue(data);
		}

		Dequeue(&data);
		printf("%d ", data);
	}
}

int main(){

	InputData();//	입력 함수

	//	코드를 작성하세요
	InitQueue();
	PrintQueue();

	return 0;
}