#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdarg.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

#pragma region ���� ����

int x = 0;

void SetStage(int up)
{
	printf("x�� ��ȯ\n\n");
	x += up;
	x--;
	x *= up;
}
#pragma endregion

void Increase()
{
	static int score = 0;

	score++;
	printf("%d\n\n", score);
}

int main()
{
#pragma region �޸� ����

	// �޸� ���� : ���� �ּ� ~ ���� �ּ�
	// ���� : CODE, DATA, BSS, HEAP, STACK

#pragma region CODE ����

	// ���α׷��� �����ϱ� ���� �ʿ��� �ڵ尡 ����Ǵ� ��������
	// �Լ��� �ּҿ� ����� ����Ǵ� �޸� ����
	// CODE : �Լ��� �ּ� ����

#pragma endregion

#pragma region DATA ����

	// ���α׷��� ���۰� �Բ� �޸𸮿� ����Ǹ�,
	// ���α׷��� ����� �� �޸𸮰� �����ǰ�,
	// �ʱ�ȭ�� �̷���� ���� ������ ���� ������ ����Ǵ� �޸� ����
	// DATA : �ʱ�ȭ�� �̷���� ���� ���� ����, Read Only

#pragma endregion

#pragma region BSS ����

	// ���α׷��� ����� �� �ʱ�ȭ�� �̷������ ���� ���� ������
	// ���� ������ ����Ǵ� �޸� ����
	// BSS : �ʱ�ȭ�� �̷������ ���� ���� ���� ����
#pragma endregion

#pragma region STACK ����

	// ���α׷��� �ڵ����� ����ϴ� �ӽ� �޸� ��������
	// �Լ� ȣ�� �� �����Ǵ� ���� ������ �Ű� ������ ����Ǵ� �޸� ����
	// STACK : ���� ����, �Ű� ����
#pragma endregion

#pragma region HEAP ����

	// ����ڰ� ���� �޸� ������ �������ִ� �޸� �����̸�,
	// ������� �۴� ��� ����ڰ� ���� �޸𸮸� �����ؾ� �Ǵ� �޸� ����
	// HEAP : ����ڰ� ���� �Ҵ��ϴ� �޸� ����, malloc���� �Ҵ��� ����
#pragma endregion

#pragma endregion

#pragma region ������ ����


#pragma region ���� ����

	// �Լ� ���ο��� ����� ������ �Լ� ���ο����� ������ �� ������,
	// �Լ��� ����Ǿ��� �� �޸𸮿��� ������� Ư¡�� ������ �ִ� ����
	// ���� ������ ����� ���ÿ� �ʱ�ȭ���� ������,
	// ���� �޸� ��ġ�� �����ߴ� ���� ������ �ȴ�.

	//int x = 10;
	//{ 
	//	int x = 20;
	//	printf("x�� �ּ� : %p\n\n", x);
	//	printf("x�� �� : %d\n\n\n", x);
	//}
	//printf("x�� �ּ� : %p\n\n", x);
	//printf("x�� �� : %d\n\n", x);

#pragma endregion

#pragma region ���� ����

	// �Լ� �ܺο��� ����� ������ ���α׷��� ����� ��
	// �޸𸮿� �ö󰡰� �Ǹ�, ���α׷��� ���� �Ǹ� �޸𸮿��� �����Ǵ� ����

	// ���� ������ ����� ���ÿ� �ʱ�ȭ�� �Ǿ� ���� ������
	// �ڵ����� �ʱ�ȭ �ȴ�

	//printf("x�� �� : %d\n\n", x);
	//SetStage(200);
	//printf("x�� �� : %d\n\n", x);
	//
	//printf("x�� �ּ� : %p", x);

#pragma endregion

#pragma region ���� ����

	// ���α׷��� ����Ǵ� ���� �޸𸮿� �����ϸ�,
	// ����� ���� �������� ������ ������ Ư¡�� ������ �ִ� ����
	// ���� ������ �� �ѹ��� �ʱ�ȭ�� �̷������

	Increase();
	Increase();
	Increase();

#pragma endregion


#pragma endregion


	return 0;
}

