/*
	구조체 배열: 학생 정보와 성적 처리
		파일명: student.c

		1) 요구사항
		- 사용자로부터 3명의 학생 정보와 성적을 입력 받아 출력하는 프로그램을 작성하세요.
		- 한 명의 학생 정보와 성적을 저장하기 위한 데이터 구조를 설계하세요.
				회원 정보: 아이디, 비밀번호, 이름, 성별, 생년월일, 연락처, 주소
							단, 성별은 남자와 여자로 한글로 입력 처리하세요.
							또한 생년월일은 물리적인 크기가 4bytes 크기로 저장될 수 있도록 설계하여 처리하세요.
				학생 성적 정보: 국어, 영어, 수학, 총점, 평균

		- 학생 정보와 성적 입력: input
		- 학생 정보와 성적 출력: output
*/

#include <stdio.h>
#define arrMAXSIZE 3	// 학생 수

// 비트 필드 구조체 형식 정의
typedef  struct _bitFieldDATE {
	unsigned int  year : 16;	// 0 ~ 9999
	unsigned int  month : 4;	// 1 ~ 12
	unsigned int  day : 5;		// 1 ~ 31
	unsigned int : 7;		// Reserved	// Padding Bits
} bitFieldDATE;

// 구조체 설계: PERSON(struct _person)
typedef	 struct _person {
	// int		Birthday[12];	// 생년월일: 8자리(20001231)
	bitFieldDATE	Birthday;	// 생년월일
	char		Gender[8];	// 성별: 남자, 여자
	char		Name[12];	// 이름: 홍길동, 을지문덕
	char		ID[16];		// 계정
	char		PASS[16];	// 비밀번호
	char		Tel[16];	// 연락처: 010-1009-1004
	char		Addr[80];	// 주소
} PERSON;

// 구조체 설계: SCORE(struct _score)
typedef struct _score {
	int	kor, eng, math, tot;
	float	ave;
} SCORE;

// 구조체 설계: STUDENT(struct  _student)
typedef struct _student {
	PERSON		info;
	SCORE		score;
} STUDENT;

// 함수 원형 선언
void	input(STUDENT *pStudent, int num);
void	output(STUDENT *pStudent, int num);

int main(void)
{
	// 구조체 배열
	STUDENT	arr[arrMAXSIZE] = { 0 };

	// 학생 정보와 성적 입출력
	input(arr, arrMAXSIZE);		// p[i]	// 첨자 연산
	output(arr, arrMAXSIZE);	// p->	// 포인터 연산

	return 0;
}

// 학생 정보와 성적 점수 입력
void	input(STUDENT *p, int num) {
	for (int i = 0; i < num; ++i) {
		printf("\n%d번째 학생 정보를 입력하세요.\n", i + 1);
		printf("아 이 디: ");
		gets_s(p[i].info.ID, sizeof(p[i].info.ID));	// gets(pStudent[i].info.ID);
		
		printf("비밀번호: ");
		gets_s(p[i].info.PASS, sizeof(p[i].info.PASS)); // gets(pStudent[i].info.Name);

		printf("이    름: ");
		gets_s(p[i].info.Name, sizeof(p[i].info.Name)); // gets(pStudent[i].info.Name);

		printf("성별(예: 남자):  ");
		gets_s(p[i].info.Gender, sizeof(p[i].info.Gender));
		// gets(pStudent[i].info.Gender);

		// 비트 필드 구조체 멤버에 데이터 저장
		int	year, month, day;
		printf("생년월일(예: 2000 12 31) : ");
		scanf_s("%d %d %d%*c", &year, &month, &day);

		p[i].info.Birthday.year = year;
		p[i].info.Birthday.month = month;
		p[i].info.Birthday.day = day;

		printf("연 락 처: ");
		gets_s(p[i].info.Tel, sizeof(p[i].info.Tel)); // gets(pStudent[i].info.Tel);

		printf("주    소: ");
		gets_s(p[i].info.Addr, sizeof(p[i].info.Addr));	// gets(p[i].info.Addr);

		// 2) 학생 성적 점수 입력 처리
		printf("\n%d번째 학생 성적을 입력하세요.\n", i + 1);
		printf("국어 점수: ");
		scanf_s("%d", &p[i].score.kor);		// scanf("%d", &p[i].score.korkor);

		printf("영어 점수: ");
		scanf_s("%d", &p[i].score.eng);		// scanf("%d", &p[i].score.koreng);

		printf("수학 점수: ");
		scanf_s("%d%*c", &p[i].score.math);	// scanf("%d", &p[i].score.kormath);

		p[i].score.tot = p[i].score.kor + p[i].score.eng + p[i].score.math;
		p[i].score.ave = (float)p[i].score.tot / 3;
	}
}

// 학생 정보와 성적 점수 출력
void	output(STUDENT *p, int num) {
	for (int i = 0; i < num; ++i, ++p) {
		printf("\n##### 학생 정보와 성적 점수 결과 ##### \n");
		printf("아 이 디: %-10s / 패스워드: %-10s\n", p->info.ID, p->info.PASS);
		printf("이    름: %-10s / 성    별: %-6s / 생년월일: %4d년 %02d월 %02d일\n",
			p->info.Name, p->info.Gender,
			p->info.Birthday.year, p->info.Birthday.month, p->info.Birthday.day);

		printf("연 락 처: %-16s \n", p->info.Tel);
		printf("주    소: %-80s \n", p->info.Addr);

		printf("성적정보: 국어(%03d), 영어(%03d), 수학(%03d), 총점(%03d), 평균(%5.1f) \n",
			p->score.kor, p->score.eng, p->score.math, p->score.tot, p->score.ave);
	}
}
