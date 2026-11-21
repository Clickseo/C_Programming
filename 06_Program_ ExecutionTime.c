// 프로그램 수행 시간
#include <stdio.h>
#include <time.h>	// clock_t, CLK_TCK, clock 함수

int main(void)
{
	// typedef	long	clock_t; 	// 프로세스 실행 시간 유형
	clock_t		start, end;
	double		time;

	// clock 함수: 프로그램 시작 후의 경과한 clock tick(1초에 18.2만큼 증가)를 반환
	start = clock();
	for(int i=0; i<30000000; i++);
	end = clock();

	// #define CLOCKS_PER_SEC	1000
	// #define CLK_TCK		CLOCKS_PER_SEC
	time = (double)(end - start) / CLK_TCK;
	printf("수행 시간: %lf \n", time );
	
	return 0;
}
