/*
	파일 복사: 텍스트 파일
		파일명: FileCopy(text).c
			파일명: data.txt >> copy.txt
*/

#include <stdio.h>
#include <stdlib.h>		// exit
int main(void)
{
	FILE	*fpIn = NULL;
	// fpIn = fopen("data.txt", "r");
	fopen_s(&fpIn, "data.txt", "r");
	if (fpIn == NULL) {
		printf("%s 파일 개방 실패!!! \n", "data.txt");
		exit(1);
	}

	FILE	*fpOut = NULL;
	// fpOut = fopen("copy.txt", "w");
	fopen_s(&fpOut, "copy.txt", "w");
	if (fpOut == NULL) {
		printf("%s 파일 개방 실패!!! \n", "copy.txt");
		fclose(fpIn);
		exit(1);
	}

	int	ch;
	printf("파일 복사중... \n\n");
	while ((ch = fgetc(fpIn)) != EOF)
		fputc(ch, fpOut);
	fclose(fpIn);
	fclose(fpOut);
	printf("복사 완료!!! \n");
	return 0;
}
