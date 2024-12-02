/*
	학생 적 처리: 구조체 변수
		파일명: score.c
			구조체: SCORE
*/

#include <stdio.h>

// 구조체 설계: SCORE(struct _score)
typedef struct _score {
	char	name[12];
	int	kor, eng, math, tot;
	float	ave;
} SCORE;

// 함수 원형 선언
void	input(SCORE *pScore);
void	output(SCORE *pScore);

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
void	input(SCORE *p) {
	printf("학생 성적을 입력 하세요. \n\n");
	printf("학생 이름: ");		gets_s(p->name, sizeof(pS->name));
	printf("국어 점수: ");		scanf_s("%d", &p->kor);
	printf("영어 점수: ");		scanf_s("%d", &p->eng);
	printf("수학 점수: ");		scanf_s("%d", &p->math);

	p->tot = p->kor + p->eng + p->math;
	p->ave = (float)p->tot / 3;
}

// 한 명의 학생 정보 출력
void	output(SCORE *p) {
	printf("\n\t ### 입력 정보 ### \n\n");
	printf("%10s %3d %3d %3d %5d %8.2f \n",
		p->name, p->kor, p->eng, p->math, p->tot, p->ave);
}
