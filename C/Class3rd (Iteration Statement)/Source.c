#include <stdio.h>

void main()
{
#pragma region ���� ������ ����

	//int plus = 0;
	//int minus = 0;
	//long long multi = 1;
	//long long divid = 10000000000000;
	//
	//for (int i = 1; i <= 10; i++)
	//{
	//	system("cls");
	//
	//	printf("���� ������ (10ȸ �ݺ� ����)\n\n\n");
	//	printf("+= �� ��� : %d\n\n", plus);
	//	printf("-= �� ��� : %d\n\n", minus);
	//	printf("*= �� ��� : %lld\n\n", multi);
	//	printf("/= �� ��� : %lld\n\n", divid);
	//
	//	plus += i;
	//	minus -= i;
	//	multi *= i;
	//	divid /= i;
	//
	//	Sleep(200);
	//}

#pragma endregion

#pragma region �ݺ���

	// ���α׷� ������ Ư���� �۾��� �ݺ������� �����ϴ� ��ɹ�

	// for, while ��

	// for(�ʱ��;���ǽ�;������){�ݺ��� �ڵ�}

	// while(����){�ݺ��� �ڵ�}

#pragma region ���� ������

	// �ǿ����ڸ� �ϳ��� ������Ű�ų� ���ҽ�ų ��
	// ����ϴ� ������

	/*
	* ������ ++, --
	* ��ġ�� ���� ���ݾ� �ٸ�
	*/

#pragma region ���� ���� ������

	// ������ ���� ������Ų �Ŀ� ������ �����ϴ� ������

	//int a = 0;
	//int b = ++a;
	//
	//printf("a:%d b:%d\n\n", a, b);
	//
	//b = --a;
	//
	//printf("a:%d b:%d\n\n", a, b);

	/*
	* ���� ����
	* - a�� 0 �Ҵ�
	* - a�� 1 ���� ��Ų �� b�� �Ҵ�
	* - ��� a�� b �Ѵ� 1�� �Ҵ�
	*/

#pragma endregion

#pragma region ���� ���� ������

	// ������ ������ ���� ������ ���� ������Ű�� ������.

	//int x = 0;
	//int y = x++;
	//
	//printf("x : %d  y : %d\n\n", x, y);
	//
	//y = x--;
	//
	//printf("x : %d  y : %d", x, y);

	/*
	* ���� ����
	* - x�� 0�� �Ҵ�
	* - y�� x�� �Ҵ� ��, x�� 1����
	* - x�� 1, y�� 0�� �Ҵ��
	*/

#pragma endregion


#pragma endregion

#pragma region for��

	// �ʱ���� �����Ͽ� ���ǽ��� ����� ���� Ư���� �� ��ŭ �ݺ��ϴ� �ݺ���
	// �ݺ����� �����ϴ� ������ �ʱ�ȭ -> ���� �˻� -> ���� -> ����

	//for (int i = 0; i < 10; i++)
	//{
	//	printf("������.");
	//	Sleep(500);
	//	system("cls");
	//	printf("������..");
	//	Sleep(500);
	//	system("cls");
	//	printf("������...");
	//	Sleep(500);
	//	system("cls");
	//	printf("������....");
	//	Sleep(500);
	//	system("cls");
	//	printf("������...");
	//	Sleep(500);
	//	system("cls");
	//	printf("������..");
	//	Sleep(500);
	//	system("cls");
	//	printf("������.");
	//	Sleep(500);
	//	system("cls");
	//}

#pragma endregion

#pragma region while ��

// Ư�� ������ ������ ������ ����ؼ� �־��� ��ɹ��� �����ϴ� �ݺ���
// �ݺ����� ���������� �����ϸ鼭 ���� �б⸦ ������ �Ǹ�
// ��� ������ �����帧�� ���� �̸� �����Ѵ�
//int a = 0;
//while (a< 300)
//{
//	system("cls");
//	a += 20;
//	printf("���� a�� �� : %d", a);
//	Sleep(250);
//}

#pragma endregion

#pragma region do while ��

// ���ǰ� ������� �ѹ��� �۾��� ������ ����
// ���ǿ� ���� ��ɹ��� �����ϴ� �ݺ���
// �ݺ����� ��� �̸� �����ؼ� �����ϴ� ������ ������,
// ������ Ʋ�ȴٸ� ���� �ݺ��� ���� ���� �б⸸ �ٽ� �˻��Ͽ� ó��

int a = 0;

do
{
	system("cls");
	a += 20;
	printf("���� : a�� 3000�� �ʰ� �ϱ� ������ �ݺ�\n");
	printf("���� a�� �� : %d\n\n", a);
	Sleep(100);

} while (a<3000);

printf("�ݺ� ����");

#pragma endregion

#pragma region nested for ��

//char �迭[10][10];
//
//for (int i = 0; i < 10; i++)
//{
//	for (int j = 0; j < 10; j++)
//	{
//		�迭[i][j] = 'A'+i;
//	}
//}
//
//for (int i = 0; i < 10; i++)
//{
//	for (int j = 0; j < 10; j++)
//	{
//		printf("%c", �迭[i][j]);
//	}
//	printf("\n");
//}

#pragma endregion

#pragma endregion


}