#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

void main()
{
#pragma region �ݺ��� ����

	//for (int i = 1; i <= 9; i++)
	//{
	//	for (int j = 1; j <= 9; j++)
	//	{
	//		int multi = i * j;
	//		printf("%d X %d = %d\n\n", i, j, multi);
	//	}
	//	printf("��������...(�ƹ�Ű �Է�)\n\n\n");
	//	_getch();
	//}

#pragma endregion

#pragma region ���ǹ�

	// � ������ �־��� �� �ش� ���ǿ� ���� ������ �����ϵ��� �����ϴ� ��ɹ�

#pragma region ���� ������

	// �� ���� �ǿ������� ���� ���Ͽ� �� ����� 0 �Ǵ�
	// 1�̶�� ������ ��Ÿ���� ������

	// > : ������ ���� �� ũ�ٸ�
	// < : �������� ���� �� ũ�ٸ�
	// >= : ������ ���� ũ�ų� ���ٸ�
	// <= : �������� ���� ũ�ų� ���ٸ�
	// == : ���� ���� ���ٸ�
	// != : ���� ���� �ٸ��ٸ�

	//int state1 = 11 > 10;
	//int state2 = 9 < 10;
	//int state3 = 11 >= 10;
	//int state4 = 9 <= 10;
	//int state5 = 10 == 10;
	//int state6 = 9 != 10;
	//
	//printf("%d", state1);
	//printf("%d", state2);
	//printf("%d", state3);
	//printf("%d", state4);
	//printf("%d", state5);
	//printf("%d", state6);

#pragma endregion

#pragma region if��

	// � Ư���� ������ ���Ͽ� ������ �´ٸ� ����Ǵ� ���ǹ�
	// if(���� ������ 1�ϋ� ����Ǹ�, 0�� �� ������� �ʴ´�

	//int a = _getch();
	//
	//if (a == '1')
	//{
	//	printf("1�� ������");
	//}
	//else if (a == '2')
	//{
	//	printf("2�� ������");
	//}
	//else
	//{
	//	printf("�߸��� �Է�");
	//}

#pragma endregion 

#pragma region else if ��

	// if������ ���� ���� ������ ���������� �˻��ϰ� ������ ����ϴ� ���ǹ�
	// else if���� ��� �������� ����� �� ������, if�� ���� ������ �ϳ��� �˻��ϴٰ�
	// ���� ���� ������ �´� �б�� ��

	//int x = _getch();
	//
	//if (x == 'q')
	//{
	//	printf("ù��° �޴�");
	//}
	//else if (x == 'w')
	//{
	//	printf("�ι�° �޴�");
	//}
	//else if (x == 'e')
	//{
	//	printf("������");
	//	return;
	//}



#pragma endregion

#pragma region else ��

	// if���� ������ ���� ���ǹ����� ��� ������ ���� ������ ����Ǵ� ���ǹ�
	// if���� ����� ��� ���ǹ��� ������ ���� �� ���� ���� �ִ� ���ǹ��� ����˴ϴ�.

//int number = 0;
//scanf("%d", &number);
//
//if (number > 0)
//{
//	printf("��� number�� �� : %d", number);
//}
//else if (number < 0)
//{
//	printf("���� number�� �� : %d", number);
//}
//else
//{
//	printf("number�� �� : %d", number);
//}

#pragma endregion

#pragma region �� ������

// �� �� �̻��� ������ �����ϰų� �ϳ��� ������ ������Ű�� ������

#pragma region And ������

//�ΰ��� ������ �´ٸ� ����Ǵ� ������

//srand((unsigned int)time(NULL));
//
//int count = 0;
//while (1)
//{
//	int sub1 = 30;
//	int sub2 = rand() % 31;
//	int sub3 = rand() % 50;
//	
//	if (sub1 == sub2 && sub3 == 40)
//	{
//		printf("���� �޼�\n");
//		printf("�õ� Ƚ�� : %d", count);
//		break;
//	}
//	else
//	{
//		printf("���� �̴޼�\n");
//	}
//	count++;
//}
#pragma endregion

#pragma region Or ������

// �� ���� ���� �� �ϳ��� �´ٸ� ����Ǵ� ������
// ���ǹ��� �� ǥ������ ���ϴ� ����,
// ����� �̹� Ȯ�����ٸ�, �� ������ �򰡸� ����

//srand((unsigned int)time(NULL));
//int count = 0;
//while (1)
//{
//	count++;
//	int sub1 = rand() % 50;
//	int sub2 = rand() % 50;
//	int sub3 = rand() % 50;
//
//	if (sub1 == sub2 || sub2 == sub3)
//	{
//		printf("���� �޼�\n");
//		printf("�õ� Ƚ�� : %d", count);
//		break;
//	}
//	else
//	{
//		printf("���� �̴޼�\n");
//	}
//	
//}

#pragma endregion

#pragma region Not ������

// �ϳ��� ������ ������Ű�� ������

//srand((unsigned int)time(NULL));
//int count = 0;
//
//while (1)
//{
//	int sub1 = rand() % 10;
//	int sub2 = rand() % 50;
//	count++;
//	if (!(sub1 < sub2))
//	{
//		printf("���� �޼�\n");
//		printf("sub1 : %d , sub2 : %d\n", sub1, sub2);
//		printf("�õ� Ƚ�� : %d", count);
//		break;
//	}
//	else
//	{
//		printf("���� �̴޼�\n");
//	}
//}


#pragma endregion

#pragma region ��и�

//while (1)
//{
//	system("cls");
//	printf("��ǥ�� �Է� :");
//	int x = 0;
//	int y = 0;
//
//	scanf_s("%d %d", &x, &y);
//
//	if (x > 0 && y > 0)
//	{
//		printf("��ǥ�� : (%d, %d)\n", x, y);
//		printf("�� 1 ��и�\n");
//	}
//	else if (x < 0 && y>0)
//	{
//		printf("��ǥ�� : (%d, %d)\n", x, y);
//		printf("�� 2 ��и�\n");
//	}
//	else if (x < 0 && y < 0)
//	{
//		printf("��ǥ�� : (%d, %d)\n", x, y);
//		printf("�� 3 ��и�\n");
//	}
//	else if (x > 0 && y < 0)
//	{
//		printf("��ǥ�� : (%d, %d)\n", x, y);
//		printf("�� 4 ��и�\n");
//	}
//	else if (x == 0 && y != 0)
//	{
//		printf("��ǥ�� : (%d, %d)\n", x, y);
//		printf("X ����\n");
//	}
//	else if (x != 0 && y == 0)
//	{
//		printf("��ǥ�� : (%d, %d)\n", x, y);
//		printf("Y ����\n");
//	}
//	else
//	{
//		printf("��ǥ�� : (%d, %d)\n", x, y);
//		printf("����\n");
//	}
//	_getch();
//}
#pragma endregion

#pragma endregion

#pragma region switch ��

// � ����� ���� �� ������� ����Ǵ� ��ɹ�
// switch������ ���ǽ����� �Ǽ��� ������ �Ǽ��� ����� ������ �� ����.

	int state;
	scanf_s("%d", &state);

	switch (state)
	{
	case 0: printf("Idle State"); break;
	case 1: printf("Attack State"); break;
	case 2: printf("Die State"); break;
	default: printf("Exception\n");  break;
	}
#pragma endregion

#pragma endregion
}