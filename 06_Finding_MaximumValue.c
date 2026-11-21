// 최댓값 구하기
#include <stdio.h>
#include <stdlib.h>                                  // __max, __min
// #define  __max(a,  b)  (((a) > (b)) ? (a) : (b))  // 매크로 함수
// #define  __min(a,  b)  (((a) < (b)) ? (a) : (b))  // 매크로 함수

int main(void)
{
	int	a, b, c, d, max;

	printf("4 개의 정수 입력: ");
	scanf_s("%d %d %d %d", &a, &b, &c, &d);
	// scanf("%d %d %d %d", &a, &b, &c, &d);

	/*
		if (a > b)	max = a;
		else		max = b;
		if (c > max)	max = c;
		if (d > max)	max = d;
	*/

	max = __max(a, b);
	max = __max(c, max);
	max = __max(d, max);

	printf("최대값: %d \n", max);
	return 0;
}
