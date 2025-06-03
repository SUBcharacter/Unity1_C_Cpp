#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdarg.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

void Process(int* number)
{
	printf("Process �Լ� ȣ���.\n\n");
	printf("���� ���� : %d\n", *number);
	*number += 30;
	printf("���� ��ȯ ��\n\n");

}

void Stat(int health, const char* name)
{
	printf("�г��� : %s\n\n", name);
	printf("ü�� : %d/100\n\n\n", health);
}

void Switching1(int a, int b)
{
	printf("��ȯ �� ���� | a = %d, b = %d\n\n", a, b);
	int temp = b;
	b = a;
	a = temp;

	printf("��ȯ �� ���� | a = %d, b = %d\n\n\n", a, b);

}

void Switching2(int* a, int* b)
{
	int temp = *b;  // �Ű����� b�� ���� �ּҸ� �������� ���� temp�� ����

	*b = *a;  // �Ű����� a�� ������ ���� �Ű����� b�� ������ ������ ����
	*a = temp; // �Ű����� a�� ������ ���� temp(b�� ������ ��)�� ���� ����
}

void Recursion(int count)
{
	if (count <= 0)
	{
		return;
	}


	printf("Recursion\n\n");
	Recursion(--count);
}

inline void Collision()
{
	printf("Collision");
}

void Average(int count, ...)
{
	va_list numbers;
	va_start(numbers, count);

	double total = 0;

	for (int i = 0; i < count; i++)
	{
		double value = va_arg(numbers, int);
		printf("value's value : %lf\n\n", value);
		total += value;
	}

	printf("��� : %.1lf\n", total / count);

	va_end(numbers);
}

void Provide()
{
	printf("Provide\n");
}

void main()
{
#pragma region �Լ�

	// �ϳ��� Ư���� ������ �۾��� �����ϱ� ����
	// ���������� ����� �ڵ��� ����
	// �Լ��� ���α׷��� ���� ���� �� �Լ� ȣ�� ��ġ����
	// �ش� �Լ��� �̵���Ų ��, �۾��� �����ϰ�
	// �ٽ� ���� ��ġ�� ���ƿ��� ����
	//int testing = 10;
	//printf("testing : %d\n",testing);
	//
	//Process(&testing);
	//
	//printf("testing : %d\n",testing);
#pragma endregion

#pragma region �Ű�����

	// �Լ��� ���ǿ��� ���޹����μ��� �Լ� ���η�
	// �����ϱ� ���� ����ϴ� ����
	//�Ű� ������ �Լ� ���ο����������� �̷������,
	// �������� �Ź� ������ ������ �� ����

	//int health = 80;
	//char* name = "Goblin";
	//
	//Stat(health, name);
	//Stat(90, "Orc");
	//Stat(100, "Fenrir");

#pragma endregion

#pragma region �μ�

	// �Լ��� ȣ��� �� �Ű� ������ ������ ���޵Ǵ� ��
	// �μ��� ��� ���� �����ϴ� �μ��� ���� ���޹޴� �Ű� ������ �ڷ����� ���� ��ġ�ؾ� ��

	//Switching1(30, 10);
	//
	//int x = 100;
	//int y = 50;
	//
	//printf("��ȯ �� ���� : x = %d, y = %d\n\n", x, y); // ��ȯ �� ���ڸ� ���
	//
	//Switching2(&x, &y);  // �Ű� ������ x�� y�� �ּҰ��� ����
	//
	//printf("��ȯ �� ���� : x = %d, y = %d\n\n", x, y); // ��ȯ �� ���ڸ� ���
#pragma endregion

#pragma region ����Լ�
	// � �Լ����� �ڽ��� �ٽ� ȣ���Ͽ� �۾��� �����ϴ� �Լ�

	//Recursion(5);

#pragma endregion

#pragma region �ζ��� �Լ�

	// �Լ��� ȣ���ϴ� ����Լ��� ȣ��Ǵ� ��ġ����
	// �Լ��� �ڵ带 �����Ͽ� �����ϴ� ����� �Լ�

	// �ζ��� �Լ��� �Լ��� ȣ���ϴ� ������ �����Ƿ�
	// ó���ӵ��� ��������, �ζ��� �Լ��� ���� ����ϰ� �Ǹ� �Լ��� �ڵ尡
	// ����Ǿ� ���� ������ ũ�Ⱑ Ŀ���� �ȴ�

	//Collision();

#pragma endregion

#pragma region �����μ����

	// �����Ǿ� �ִ� �Ű� ���� �ܿ� ������ �������� ����
	// �μ��� �߰��� ���� �� �ִ� �μ�
	//int array[5];
	//printf("���� 5�� �Է�\n\n");
	//for (int i = 0; i < 5; i++)
	//{
	//	scanf_s("%d", &array[i]);
	//}
	//
	//Average(5, array[0], array[1], array[2], array[3], array[4]);
#pragma endregion

#pragma region �Լ� ������

	// �Լ��� �ּ� ���� �����ϰ� ����ų �� �ִ� ������ ����
	//void (*prov)();
	//prov = Provide;
	//
	//prov();
#pragma endregion


}

