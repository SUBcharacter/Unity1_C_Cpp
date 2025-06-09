#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdarg.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>

void Shuffle(int list[], int size)
{
	srand((unsigned int)time(NULL));
	int temp = 0;

	for (int i = 0; i < size; i++)
	{
		int value = rand() % 10;
		temp = list[value];
		list[value] = list[i];
		list[i] = temp;
	}
}

void Explanation()
{
	system("cls");

	printf("�� �� �� �� !                 ��ŵ�Ϸ��� s�� ��������.\n\n");
	char skip = _getch();
	if (skip == 's')
		return;

	printf("��ǻ�Ͱ� ������ �ִ� ����(1 ~ 50)�� ���߸� �Ǵ� �����Դϴ�.\n\n");
	skip = _getch();
	if (skip == 's')
		return;

	printf("�÷��̾ ���ڸ� �Է��ϸ� ���ڸ� ���� ���ڰ� ������ �������� �˷��ݴϴ�.\n\n");
	skip = _getch();
	if (skip == 's')
		return;

	printf("�� 5���� ��ȸ �ȿ� ������ ���ϸ� �й��ϰ� �˴ϴ�.\n\n");
	skip = _getch();
	if (skip == 's')
		return;

	printf("�غ� �Ǽ̴ٸ� �ƹ� Ű�� �����ʽÿ�....");
	_getch();
}

void LifeDisplay(int life)
{
	printf("������ : ");
	for (int i = 0; i < life; i++)
	{
		printf("��");
	}
	printf("\n\n");
}

void Play()
{
	srand((unsigned int)time(NULL));

	int randomNumber = rand() % 50 + 1;
	int life = 10;

	Explanation();

	while (true)
	{
		int inputNumber = 0;

		system("cls");

		LifeDisplay(life);
		printf("���ڸ� �Է����ּ���! : ");

		scanf("%d", &inputNumber);

		if (inputNumber == 1099464864)
		{
			printf("����� ��� : %d\n\n", randomNumber);
			printf("����Ϸ��� �ƹ�Ű �Է�\n\n");
			_getch();
			continue;
		}

		if (inputNumber == randomNumber)
		{
			system("cls");
			printf("���ڸ� ���߼̽��ϴ�!\n\n\n");
			printf("V I C T O R Y !!\n\n\n");
			printf("Ÿ��Ʋ�� ���ư��ϴ�.\n");
			_getch();
			return;
		}
		else if (inputNumber > randomNumber && inputNumber <= 50)
		{
			system("cls");
			life--;
			printf("Ʋ���̽��ϴ�..... �̰ͺ��� ���� �����Դϴ�...\n\n");
			printf("���� ��ȸ : %d\n\n", life);
		}
		else if (inputNumber < randomNumber && inputNumber <= 50)
		{
			system("cls");
			life--;
			printf("Ʋ���̽��ϴ�..... �̰ͺ��� ū �����Դϴ�...\n\n");
			printf("���� ��ȸ : %d\n\n", life);
		}
		else
		{
			printf("������ ��� �����Դϴ�. 1 ~ 50 ������ ���ڸ� �Է��� �ֽʽÿ�.\n\n");
			_getch();
			continue;
		}

		if (life <= 0)
		{
			system("cls");
			printf("�ƽ����ϴ�... ��ȸ�� ��� ���� �ϼ̽��ϴ�...\n\n");
			printf("���� ���ڴ� : %d �����ϴ�...\n\n\n", randomNumber);
			printf("D E F E A T...\n\n\n");

			printf("Ÿ��Ʋ�� ���ư��ϴ�.\n");
			_getch();
			return;
		}
		printf("����Ͻ÷��� �ƹ�Ű�� �����ʽÿ�.....\n\n");
		_getch();
	}
}

void Title()
{
	while (true)
	{
		system("cls");
		printf("1_ ���� ����\n\n\n");
		printf("2_ ���� ����\n\n\n");

		char input = _getch();

		if (input == '1')
		{
			Play();
		}
		else if (input == '2')
		{
			return;
		}
		else
		{
			printf("�߸� �� �Է��Դϴ�. �ٽ� �õ� �Ͻʽÿ�.\n\n");
			_getch();
		}
	}
}

typedef enum
{
	// ����ÿ��� ���������� �����
	// ���� ������ ���Ҽ� ����(0~)
	// ������ �Ҵ��� ��� �Ҵ� �� ���ں��� 1�� �ö�
	BOW,
	GUN,
	KNIFE = 3,
	SWORD,
	HAMMER

}WeaponCategory;

int main()
{
#pragma region �ǻ� ����

	// rand() : 0 ~ 32767 ������ ������ ���� ��ȯ�ϴ� �Լ�
	// time(NULL) : 1970�� 1�� 1�� (00 : 00 : 00) UTC ���Ŀ� ���� ��(Second)�� ��ȯ�ϴ� �Լ�
	// srand(seed) : ���� �������� �õ带 �����ϴ� �Լ�

	//srand((unsigned int)time(NULL));
	//int count = 0;
	//
	//for (int i = 0; i < 10000; i++)
	//{
	//	int value = rand() % 100+1;
	//	
	//
	//	if (value > 75)
	//	{
	//		printf("value : %d ��÷!\n", value);
	//		count++;
	//	}
	//	else
	//	{
	//		printf("value : %d\n", value);
	//	}
	//	
	//}
	//
	//printf("25%% Ȯ�� 10000ȸ �������� ��÷ Ƚ�� : %d/10000", count);

#pragma endregion

#pragma region ���� �Լ�

	//srand((unsigned int)time(NULL));
	//
	//int list[15] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
	//
	//int size = sizeof(list) / sizeof(int);
	//
	//int numberTemp = 0;
	//Shuffle(list, size);
	//printf("�ʵ� �� :");
	//for (int i = 0; i < 5; i++)
	//{
	//	int numValue = rand() % 15;
	//	int symbolValue = rand() % 4 + 1;
	//
	//	switch (symbolValue)
	//	{
	//	case 1: printf("��"); break;
	//	case 2: printf("��"); break;
	//	case 3: printf("��"); break;
	//	case 4: printf("��"); break;
	//	}
	//	
	//	switch (list[numValue])
	//	{
	//	case 1: printf("A "); break;
	//	case 13: printf("J "); break;
	//	case 14: printf("Q "); break;
	//	case 15: printf("K "); break;
	//	default: printf("%d ", list[numValue]); break;
	//	}
	//}
	//printf("\n\n\n");
	//
	//printf("�� �� :");
	//
	//for (int i = 0; i < 2; i++)
	//{
	//	int numValue = rand() % 15;
	//	int symbolValue = rand() % 4 + 1;
	//	switch (symbolValue)
	//	{
	//	case 1: printf("��"); break;
	//	case 2: printf("��"); break;
	//	case 3: printf("��"); break;
	//	case 4: printf("��"); break;
	//	}
	//	
	//	switch (list[numValue])
	//	{
	//	case 1: printf("A "); break;
	//	case 13: printf("J "); break;
	//	case 14: printf("Q "); break;
	//	case 15: printf("K "); break;
	//	default: printf("%d ", list[numValue]); break;
	//	}
	//}

#pragma endregion

#pragma region Up & Down Game

	//Title();


#pragma endregion

#pragma region ������

	// ������ : ���� ���õ� ������� �̸� �ٿ� ���� �ڷ���
	// ��ü�� �ڵ峢���� ������ �������־� ���������� �������� ����

	//WeaponCategory weapon = BOW;
	//
	//for (int i = 0; i < 6; i++)
	//{
	//	switch (weapon)
	//	{
	//	case BOW:printf("���� ���� : Ȱ\n\n"); break;
	//	case GUN:printf("���� ���� : ��\n\n"); break;
	//	case KNIFE:printf("���� ���� : ������\n\n"); break;
	//	case SWORD:printf("���� ���� : ��\n\n"); break;
	//	case HAMMER:printf("���� ���� : �ظ�\n\n"); break;
	//	default:
	//		printf("����\n\n");
	//		break;
	//	}
	//	weapon++;
	//}
#pragma endregion

}