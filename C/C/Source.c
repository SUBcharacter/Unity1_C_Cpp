#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include "Library.h"

#define SIZE 10

void main()
{
#pragma region �ּ� ������

	// ������ �ּ� ���� ��ȯ�ϴ� ������
	
	//int x = 10;
	//printf("%p", &x);

#pragma region scanf_s �Լ�

	// ǥ�� �Է� �Լ���, ���� ������ �����͸� �پ��� ���Ŀ� ���� �Է��ϴ� �Լ�
	// ǥ�� �Է� �Լ��� �����͸� �Է��ϰ� �Ǹ� ���ۿ� �����͸� �����Ͽ��ٰ� �Է��ϴ� ����
	// ���� ���� ������ ���α׷��� �����Ѵ�

	//int a = 0;
	//scanf_s("%d", &a);
	//printf("��°� : %d", a);

	// ǥ�� �Է� �Լ��� �Է��� ������ ������ ���� �۾����� �Ѿ� �� �� ����

#pragma endregion

#pragma region  ������

	// �޸��� �ּ� ���� ������ �� �ִ� ����
	 
	int packet = 10;
	int* packetptr = &packet;

	printf("�����ͷ� ǥ�� : %p\n", packetptr);
	printf("�����ͷ� ǥ�� : %p\n", &packet);
	printf("�����ͷ� ǥ�� : %d\n", *packetptr);
	
	// ������ ������ �ڽ��� �޸� ������ ������ ������
	// ������ ������ ������ ���� �ּҸ� �����ϰ� �Ǹ�,
	// �ش� ������ ���� �ּҸ� ����Ű�� �ȴ�
#pragma endregion

	//�������� �ּ� ���� �ش� �����Ͱ� ����� �޸��� ���� �ּҸ� �ǹ���
#pragma endregion

}