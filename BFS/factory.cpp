#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

 

#define MAX_N (100)

#define MAX_Q (MAX_N*100)

int N, M;//공장 수, 도로 정보 수

int A[5000], B[5000], D[5000];//공장 A, 공장 B, 거리 D

 

int mat[MAX_N+1][MAX_N+1];

 

int chk[MAX_N+1];

 

int queue[MAX_Q];

int wp, rp;

 

#define Enqueue(X) (queue[wp++] = (X))

#define Dequeue(X) ((X) = queue[rp++])

#define QueueIsNotEmpty (wp > rp)

 

void InputData()
{
	int i;
	scanf("%d %d", &N, &M);
	for (i = 0; i < M; i++) {
		scanf("%d %d %d", &A[i], &B[i], &D[i]);	
		mat[A[i]][B[i]] = mat[B[i]][A[i]] = D[i];
	}
}

void Init_BFS(void)

{

	int i;

	wp = rp = 0;

	for (i = 1; i <= N; i++) chk[i] = 0x7fffffff;

}

 

int BFS(int s)

{

	int sol = 0;

	int i;

	int pres_n, next_n;

	Enqueue(s);

	chk[s] = 0;

	while (QueueIsNotEmpty)

	{

		Dequeue(pres_n);

		for (next_n=1; next_n <=N; next_n++)

		{

			if (mat[pres_n][next_n] == 0) continue;

			if (chk[next_n] <= chk[pres_n] + mat[pres_n][next_n]) continue;

			Enqueue(next_n);

			chk[next_n] = chk[pres_n] + mat[pres_n][next_n];

		}

	}

	

	for (i=1;i<=N;i++)

	{

		if (sol < chk[i]) sol = chk[i];

	}

	return sol;

}

 

int Get_Solution(void)

{

	int sol = 0x7fffffff;

	int ret;

	int i;

 

	for (i=1;i<=N;i++)

	{

		Init_BFS();

		ret = BFS(i);

		if (sol > ret) sol = ret;

	}

	return sol;

}

 

int main() 

{

	int ans = -1;

	InputData();//	입력 함수

 

	//	코드를 작성하세요

	ans = Get_Solution();

 

	printf("%d\n", ans);//	정답 출력

	return 0;

}