// 임의의 난수 생성: 로또 복권
#include <stdio.h>
#include <stdlib.h>	// srand, rand
#include <time.h>	// time

int main(void)
{
	int	temp;

	// seed 있는 랜덤발생 함수, 초기의 seed 는 1이다.
	srand((unsigned int)time(NULL));

	printf("##### 로또 복권 생성 ##### \n\n");
	for (int i = 1; i <= 6; ++i) {
		// 0 ~ RAND_MAX 사이에서 임의의 난수를 생성하여 반환
		temp = rand() % 45 + 1;		// 최댓값과 최솟값
		printf("%02d ", temp );
	}
	printf("\n");
	return 0;
}
