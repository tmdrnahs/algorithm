#include <stdio.h>

#define MAX_N (10000)
#define MAX_Q (MAX_N+1) // +1은 Circular queue에서 마지막 공간을 사용하지 않을 것이기 때문에 해준다.

int N;
int queue[MAX_N];
int wp = 0, rp = 0;

int EnQueue(int data)
{
	if((wp+1)%MAX_Q == rp) return 0;
	queue[wp] = data;
    wp = (wp+1)%MAX_Q;
	return 1;
}

int DeQueue(int *p)
{
	if(wp == rp) return 0;
	*p = queue[rp];
    rp = (rp+1)%MAX_Q;
	return 1;
}

int main(void)
{
	int cmd,data;
	int i;
	scanf("%d",&N);

	for(i=0;i<N;i++)
	{
		scanf("%d",&cmd);
		switch(cmd)
		{
		case 1: // Push
			scanf("%d",&data);
			EnQueue(data);
			break;
		case 0: // Pop
			if(DeQueue(&data))
			{
				printf("%d\n",data);
			}
			else printf("E\n");
			break;
		case 2: // Count
            if (wp >= rp) printf("%d\n", wp-rp);
            else if (rp > wp) printf("%d\n", MAX_Q-(rp-wp));
			break;
		}
	}

	return 0;
}