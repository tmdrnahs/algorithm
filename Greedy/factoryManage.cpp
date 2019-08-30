// 4 5
// 88 200
// 89 400
// 97 300
// 91 500

// 126900

#include <stdio.h>

int N; //일
int S; //보관비용
int C[50010]; //가격
int Y[50010]; //용량

void Input_Data(void){
	int i;
	scanf("%d %d", &N, &S);
	for(i=0 ; i<N ; i++){
		scanf("%d %d", &C[i], &Y[i]);
	}
}

long long GetTotalCost(void)
{
    int min = 5000; // 부품 1개의 최고 가격
    long long sum = 0;
    
    for (int day=0; day<N; day++)
    {
        min += S; // 부품 가격 + 보관 기간으로만 계산 (불필요한 for문 제거를 위한 최적화 ex. n 일차때 1~n일차까지의 구매 비용을 구하려고 하는 for문)
        if (min > C[day]) min = C[day];
        sum += min*Y[day];
    }

    return sum;
}

int main(void){
	long long ans = -1;
	Input_Data();		// 입력 함수
	
	// TODO : 코드를 작성하세요
	ans = GetTotalCost();
	
	
	
	printf("%lld\n", ans);		// 정답 출력
	return 0;
}
