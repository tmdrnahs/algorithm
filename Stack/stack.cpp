#include <stdio.h>

#define MAX_N (10000)

int N;
int stack[MAX_N];
int sp = 0;

int Push_Stack(int data)
{
	if(sp == MAX_N) return 0;
	stack[sp++] = data;
	return 1;
}

int Pop_Stack(int *p)
{
	if(sp == 0) return 0;
	*p = stack[--sp];
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
			Push_Stack(data);
			break;
		case 0: // Pop
			if(Pop_Stack(&data))
			{
				printf("%d\n",data);
			}
			else printf("E\n");
			break;
		case 2: // Count
			printf("%d\n",sp);
			break;
		}
	}

	return 0;
}