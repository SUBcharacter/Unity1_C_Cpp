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
	 
	//int packet = 10;
	//int* pointer = &packet;
	//
	//printf("packet�� �ּ� : %p\n", &packet);
	//printf("packetptr�� �ּ� : %p\n\n", pointer);
	//printf("packet�� �� : %d\n", packet);
	//printf("packetptr ������ �� : %d\n\n", *pointer);
	
	// ������ ������ �ڽ��� �޸� ������ ������ ������
	// ������ ������ ������ ���� �ּҸ� �����ϰ� �Ǹ�,
	// �ش� ������ ���� �ּҸ� ����Ű�� �ȴ�

	//*pointer = 99;
	//
	//printf("*packetptr = 99; ����\n\n");
	//printf("packet�� �� : %d\n", packet);
	//printf("packetptr ������ �� : %d\n\n\n\n", *pointer);

	// ������ ������ �����Ͱ� ����Ű�� �޸� ������ �ڷ�����
	// �� �� �����Ƿ�, �����Ͱ� ����Ű�� �޸��� �ڷ����� ���� ���־�� ��.

	// ������ ������ ũ��� �߾� ó�� ��ġ�� �� ���� ó���� �� �ִ� ũ��� ��������,
	// �� ���� ó���� �� �ִ� ũ��� � ü���� ���� ũ�Ⱑ �����ȴ�.

	//printf("packetptr ������ ũ�� : %u\n", sizeof(packetptr));

	//int storage=0;
	//pointer = &storage;
	//
	//printf("packetptr = &storage; ����\n\n");
	//printf("storage�� �� : %d\n", storage);
	//printf("packetptr ������ �� : %d\n\n", *pointer);
	//*pointer = 20;
	//printf("*packetptr = 20; ����\n\n");
	//printf("storage�� �ּ� : %p\n", &storage);
	//printf("packetptr�� �ּ� : %p\n\n", pointer);
	//printf("storage�� �� : %d\n", storage);
	//printf("packetptr ������ �� : %d\n", *pointer);

#pragma endregion

#pragma region ��� ���� ������

	// �����Ͱ� ����Ű�� �ּҿ� ����Ǿ� �ִ� ����
	// ������ �� ������ �����Ǿ� �ִ� ������

	// ��� ���� ������
	// 
	//int height = 10;
	//int width = 20;
	//const int* pointer = &height;
	//
	//printf("height �� : %d\n", height);
	//printf("height �ּҰ� : %d\n\n", &height);
	//
	//printf("width �� : %d\n", width);
	//printf("width �ּҰ� : %d\n\n", &width);
	//
	//printf("�������� �� : %p\n", pointer);
	//printf("������ ������ �� : %d\n\n", *pointer);
	//
	//pointer = &width;
	//printf("pointer �ּ� ��ü\n\n");
	//printf("�������� �� : %p\n", pointer);
	//printf("������ ������ �� : %d\n", *pointer);


#pragma endregion

#pragma region ������ ���

	// ������ ������ ����Ű�� �ִ� �ּ� ���� ���� �� �� ������ �����Ǿ� �ִ� ������

	//int some= 10;
	//int day = 30;
	//int* const pointer = &some;
	//
	//printf("some �� : %d\n", some);
	//printf("some �ּҰ� : %p\n\n", &some);
	//
	//printf("day �� : %d\n", day);
	//printf("day �ּҰ� : %p\n\n", &day);
	//
	//printf("pointer �� : %p\n", pointer);
	//printf("pointer ������ �� : %d\n\n", *pointer);
	//
	//*pointer = day;
	//
	//printf("pointer ������ �� ����\n\n");
	//printf("pointer �� : %p\n", pointer);
	//printf("pointer ������ �� : %d\n\n" ,*pointer);
	//
	//printf("day �� : %d\n", day);
	//printf("day �ּҰ� : %p\n\n", &day);

#pragma endregion

#pragma region ���� ������

// �ڷ����� �������� ���� ���·� ��� �ڷ����� ������ �� �ִ� ������
int integer = 10;
float realnum = 15.8f;
char yob ='A';

void * pointer = &yob;

printf("pointer �� : %p\n", pointer);
printf("pointer ������ �� : %c\n\n", *(char*)pointer);

*(char*)pointer = 'B';

printf("pointer �� : %p\n", pointer);
printf("pointer ������ �� : %c\n\n", *(char*)pointer);

pointer = &integer;

printf("pointer �� : %p\n", pointer);
printf("pointer ������ �� : %d\n\n", *(int*)pointer);

*(int*)pointer = 50;

printf("pointer �� : %p\n", pointer);
printf("pointer ������ �� : %d\n\n", *(int*)pointer);

pointer = &realnum;

printf("pointer �� : %p\n", pointer);
printf("pointer ������ �� : %f\n\n", *(float*)pointer);

*(float*)pointer = 30.5f;

printf("pointer �� : %p\n", pointer);
printf("pointer ������ �� : %f\n\n", *(float*)pointer);

printf("integer �� : %d\n\n", integer);
printf("realnum �� : %f\n\n", realnum);
printf("yob �� : %c\n\n", yob);

// ���� �����ʹ� �޸� �ּҿ� �����ؼ� ���� ���� �� �� �����Ƿ�
// ���� �����Ͱ� ����Ű�� ������ �ڷ������� ��ȯ���־�� ��

#pragma endregion

	//�������� �ּ� ���� �ش� �����Ͱ� ����� �޸��� ���� �ּҸ� �ǹ���
#pragma endregion

}