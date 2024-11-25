#include <stdio.h>

// 구조체 설계: SCORE(struct  _score)
typedef  struct  _score {
	char	name[12];
	int	kor, eng, math, tot;
	float	ave;
} SCORE;

// 함수 원형 선언
void	input(SCORE* pScore);
void	output(SCORE* pScore);

int main(void)
{
	// 구조체 변수 선언
	SCORE	s;

	// 학생 정보 입출력
	input(&s);
	output(&s);

	return 0;
}

// 한 명의 학생 정보 입력
void	input(SCORE* pS) {
	printf("학생 성적을 입력 하세요. \n\n");
	printf("학생 이름 : ");		gets_s(pS->name, sizeof(pS->name));
	printf("국어 점수 : ");		scanf_s("%d", &pS->kor);
	printf("영어 점수 : ");		scanf_s("%d", &pS->eng);
	printf("수학 점수 : ");		scanf_s("%d", &pS->math);

	pS->tot = pS->kor + pS->eng + pS->math;
	pS->ave = (float)pS->tot / 3;

	return;
}

// 한 명의 학생 정보 출력
void	output(SCORE* pS) {
	printf("\n\t ### 입력 정보 ### \n\n");
	printf("%10s %3d %3d %3d %5d %8.2f \n",
		pS->name, pS->kor, pS->eng, pS->math, pS->tot, pS->ave);
}
