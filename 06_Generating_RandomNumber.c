// 임의의 난수 생성: 로또 복권
#include <stdio.h>
#include <stdlib.h>  // srand, rand
#include <time.h>    // time

int main(void)
{
	int a, b, c;

	// seed 있는 랜덤발생 함수, 초기의 seed 는 1이다.
	srand((unsigned int) time(NULL));

	// 0 ~ RAND_MAX 사이에서 임의의 난수를 생성하여 반환
	a = rand();
	b = rand();
	c = rand();

	printf("임의의 난수 생성: a = %d, b = %d, c = %d \n",	a, b, c );	
	return 0;
}
