#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

void main()
{
#pragma region �迭

	// ���� �ڷ����� ������� �̷���� ���� ����
	// �迭�� ��� ù ��° ���Ҵ� 0���� ����	

	//int array[1000];
	//int count = sizeof(array) / sizeof(int);
	//printf("�迭�� ũ�� : %d\n\n", count);
	//
	//for (int i = 1; i <= count; i++)
	//{
	//	array[i-1] = 10 * i;
	//	printf("���� x-%d : %d\n", i, array[i-1]);
	//}
	
	// �迭�� ���ϴ� ���ҿ� ���ϴ� ���� ������ �� ������,
	// �迭�� ũ��� ������ �Ǵ� �������� ������ �޸� ������ ������ �ȴ�

	//int list[5] = { 1, 2, 3, 4, 5 };
	//
	//int* pointer = list;
	//printf("list[0] : %d\n", list[0]);
	//printf("list[0] address : %p\n", pointer);
	//*pointer = 99;
	//
	//printf("list[0] : %d\n\n", list[0]);
	//
	//
	//printf("list[1] : %d\n", list[1]);
	//printf("list[1] address : %p\n", pointer+1);
	//pointer++;
	//*pointer = 100;
	//
	//printf("list[1] : %d\n", list[1]);

	// �迭�� ũ��� ������ �� ������, �ʱ�ȭ ��Ͽ��� ������ ��ҿ� ���� �迭�� ũ�Ⱑ ������

	//float container[ ] = { 10.5f,20.8f,35.6f,31.4f };
	

#pragma endregion

#pragma region ���ڿ�

	// �������� �޸� ������ ����� ���� ������ ����
	// ���ڿ��� ��� �����͸� �̿��Ͽ�
	// ���ڿ� ����� ����Ű���� �� �� ������,
	// ���ڿ� ����� ������ ������ �б� ���� ������ ����Ǳ� ������,
	// ���ڿ��� ���� ������ �� ����

	//const char* Title = "Call of Duty : Modern Warfare";
	//printf("%s\n", Title);

	// ���ڿ��� ���鵵 �Բ� �޸� ������ �����Ͽ� ũ�Ⱑ �����Ǹ�,
	// �������� ���ڿ��� ���� �˷��ִ� ���� ���ڰ� ���Եȴ�

	//Title = "Battle Field";
	
	//printf("%s\n", Title);

	// ���ڿ��� �����ϰ� �Ǹ� �� �������� ��ȿ�� ���ڱ��� �޸� ������ ����ȴ�

	//char name[] = "Bob Robert";
	//char* const name2 = "Bob Robert";
	//printf("%s\n", name);
	//
	//name[0] = 'J';
	//name[1] = 'i';
	//name[2] = 'm';
	//
	//printf("%s\n", name);

#pragma endregion

#pragma region ����

	/*
	* �ƽ�Ű �ڵ�, �����ڵ� ���� �� Ȱ��
	*/

	// �ƽ�Ű�ڵ�(American Standard Code for Information Interchange)
	// �̱�������ȯǥ�غ�ȣ
	// �پ��� ���ڵ��� 0~127������ ���ڷ� ǥ���� �� �ְ� ���� ��
	// C���� ���ڸ� ǥ���� �� �ַ� ���ȴ�.
	// Ex.

	int character = 'A';

	printf("�ƽ�Ű �ڵ� ���� : %d\n", character);
	printf("�ƽ�Ű �ڵ� ���� : %c\n", character);

	// ǥ���Ǵ°� ����������, ���ڿ͵� ������ �� �ִ�.
	// Ex.
	
	character += 1;
	printf("�ƽ�Ű �ڵ� ���� : %d\n", character);
	printf("�ƽ�Ű �ڵ� ���� : %c\n", character);
	//---------------------------------------------------------

	// �����ڵ�
	// ������ ��� ���ڸ� �ϰ��ǰ� ǥ���� �� �ֵ��� ����� ��� ǥ��
	// C������ �ַ� ������ ������ ����� �� �ִ� ����� �ִ�.
	// Ex.
	
	printf("�����ڵ�(A) : \u0041");

#pragma endregion


}