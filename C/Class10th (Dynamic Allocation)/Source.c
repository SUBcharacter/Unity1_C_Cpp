#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdarg.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
#pragma region ���� �Ҵ�

	// ���α׷��� ���� �߿� �ʿ��� ��ŭ �޸𸮸� �Ҵ��ϴ� �۾�
	// ���� �Ҵ��� ���� �ð��� ���������� �޸��� ũ�⸦ �����ų �� ������,
	// �������� �޸��� ũ�⸦ �Ҵ��� �� ����Ʈ ������ ����
	//int x = 50, y = (x + 50) / 20;
	//int* name = malloc(sizeof(int));
	//*name = x+ y;
	//printf("%d", *name);
	//
	//free(name);

	//int* array = malloc(sizeof(int) * 3);
	//
	//for (int i = 1; i <= 3; i++)
	//{
	//	array[i-1] = i * 10;
	//}
	//
	//for (int i = 0; i < 3; i++)
	//{
	//	printf("Address of array[%d] : %p\n", i, &array[i]);
	//	printf("array[%d] : %d\n\n", i, array[i]);
	//}
	//
	//free(array);

#pragma region ����

	// UAF(Use After Free)
	// HEAP �������� malloc���� �Ҵ��� ������ free�� ������
	// �޸𸮸� �ٽ� �Ҵ��ϸ� ���� ������ ���� �Ǵ� ��.

	//int* uaf = malloc(sizeof(int));
	//
	//*uaf = 30;
	//
	//printf("uaf�� �� : %d, uaf�� �ּ� : %p\n\n", *uaf, uaf);
	//
	//free(uaf);
	//
	//uaf = malloc(sizeof(int));
	//
	//printf("uaf�� �ּ� : %p\n", uaf);

#pragma endregion


#pragma endregion

#pragma region ��� ������

	// �̹� ������ �޸� ������ ����Ű�� ������

	// int* dangleptr = malloc(sizeof(int));
	// 
	// *dangleptr = 30;
	// 
	// printf("�ּ� : %p, �� : %d\n\n", dangleptr, *dangleptr);
	// 
	// free(dangleptr);
	// dangleptr = NULL;

	// printf("�ּ� : %p, �� : %d\n\n", dangleptr, *dangleptr);

#pragma endregion

	return 0;
}