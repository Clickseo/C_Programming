/*
	회원 정보 처리: 중첩 구조체, 비트 필드 구조체
		파일명: person.c
			구조체: bitFieldDATE, PERSON
*/

#include <stdio.h>

/*
	typedef	 struct  _date {
		unsigned  int  year;
		unsigned  int  month;
		unsigned  int  day;
	} DATE;
*/

// 비트 필드 구조체 형식 정의
typedef  struct _bitFieldDATE {
	unsigned int  year: 16;		// 0 ~ 9999
	unsigned int  month: 4;		// 1 ~ 12
	unsigned int  day: 5;		// 1 ~ 31
	unsigned int : 7;		// Reserved	// Padding Bits
} bitFieldDATE;

// 구조체 설계: PERSON(struct  _person)
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

int main(void)
{
	// 구조체 변수
	PERSON		temp;

	printf("아 이 디: ");
	gets_s(temp.ID, sizeof(temp.ID));		// gets(temp.ID);

	printf("비밀번호: ");
	gets_s(temp.PASS, sizeof(temp.PASS));		// gets(temp.Name);

	printf("이    름: ");
	gets_s(temp.Name, sizeof(temp.Name));		// gets(temp.Name);

	printf("성별(예: 남자):  ");
	gets_s(temp.Gender, sizeof(temp.Gender));	// gets(temp.Gender);

	int	year, month, day;
	printf("생년월일(예: 2000 12 31) : ");
	scanf_s("%d %d %d%*c", &year, &month, &day);

	// 비트 필드 구조체 멤버에 입력 데이터 저장
	temp.Birthday.year = year;
	temp.Birthday.month = month;
	temp.Birthday.day = day;

	printf("연 락 처: ");
	gets_s(temp.Tel, sizeof(temp.Tel));		// gets(temp.Tel);

	printf("주    소: ");
	gets_s(temp.Addr, sizeof(temp.Addr));		// gets(temp.Addr);
	printf("\n##### 회원 정보 ##### \n\n");
	printf("아 이 디: %s \n", temp.ID);
	printf("패스워드: %s \n", temp.PASS);
	printf("이    름: %s \n", temp.Name);
	printf("성    별: %s \n", temp.Gender);
	printf("생년월일: %d년 %d월 %d일 \n",
		temp.Birthday.year, temp.Birthday.month, temp.Birthday.day);
	printf("연 락 처: %s \n", temp.Tel);
	printf("주    소: %s \n", temp.Addr);

	return 0;
}
