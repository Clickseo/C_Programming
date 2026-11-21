// 피보나치 수열(Fibonacci Sequence)
#include <stdio.h>

// 함수 원형 선언
int  Fibo(int  num);

int main(void)
{
	int	num;

	printf("### 피보나치 수열 구하기 ### \n\n");
	printf("몇 번째 수열까지 출력할까요: ");
	scanf_s("%d", &num);			// scanf ("%d", &num);

	for (int i=1; i<=num; ++i) {
		if (i % 5) {
      printf("%8d", Fibo(i) );
    }
		else {
      printf("%8d\n", Fibo(i) );
	}
	printf("\n");
	return 0;
}

// 피보나치 수열: 재귀적 용법
int  Fibo(int  num) {
	// 재귀 함수: 탈출 조건
	if (num == 1 || num == 2) {
		return 1;
  }
	return Fibo(num - 1) + Fibo(num - 2);	//  O(2^n)
}
