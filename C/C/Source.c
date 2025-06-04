#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdarg.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef struct 
{
	char grade;
	int health;
	double attack;

	// ����ü�� ũ��� ����ü�� �����ϴ� ��� �߿��� ũ�Ⱑ
	// ���� ū �ڷ����� ����� �ǵ��� �����Ѵ�
}Card;

typedef struct
{
	double x;
	double y;
}Point;

typedef struct
{
	int data;
	struct Node* nextptr;

}Node;

typedef struct
{
	int HP;
	int MP;
	int DF;
}Player;

int main()
{
#pragma region ����ü

	// ���� ���� ������ �ϳ��� �������� ����ȭ �� ����
	// �ϳ��� ��ü�� �����ϴ� ��
	// ����ü�� �����ϱ� ���� ����ü�� �޸� ������ �������� �����Ƿ�,
	// ����ü ���ο� �ִ� �����͸� �ʱ�ȭ �� �� ����
	// ����ü�� �� ����� ����ü ���𿡼� ��Ÿ���� ������� �ʱ�ȭ �ؾ���
	// ������ ���ʿ��� ������

	//Card attacker = { 'S', 5, 6 };
	//
	//printf("ī�� ����\n\n");
	//printf("ī�� ��� : %c\n", attacker.grade);
	//printf("ī�� ü�� : %d\n", attacker.health);
	//printf("ī�� ���ݷ� : %.0lf\n", attacker.attack);


#pragma endregion

#pragma region ����Ʈ �е�

	// ��� ������ �޸𸮿��� CPU�� ���� �� �� ����
	// ���� �� �ֵ��� �����Ϸ��� ���������� ��Ͽ� ���߾� ����Ʈ�� �е����ִ� ����ȭ �۾�
	// ����ü ũ���� ��� ��� ������ ������ ���� �޸� ũ�Ⱑ
	// �ٸ��� ������ �� ������, ����ü ũ�⸦ �����ϴ� ���´�
	// �⺻ �ڷ������θ� �����ȴ�

	//printf("Card ����ü�� ũ�� : %d", sizeof(Card));

#pragma endregion

#pragma region �� �� ������ �Ÿ�

	//srand((unsigned int)time(NULL)); // ���� �õ�
	//int count = 0;
	//
	//for (int i = 0; i < 30; i++)
	//{
	//	system("cls");
	//
	//	Point player = { rand() % 10, rand() % 10 }; // �÷��̾� ���� ��ǥ ����
	//	Point enemy = { rand() % 10, rand() % 10 }; // �� ���� ��ǥ ����
	//
	//	// �Ÿ� ���
	//	double distance = sqrt(pow(fabs(player.x - enemy.x), 2) + pow(fabs(player.y - enemy.y), 2));
	//
	//	// ���� ǥ��
	//	printf("�÷��̾� ��ǥ : (%.0lf, %.0lf)\n\n", player.x, player.y);
	//	printf("�� ��ǥ : (%.0lf, %.0lf)\n\n", enemy.x, enemy.y);
	//	printf("������ �Ÿ� : %.2lf\n\n", distance);
	//
	//	// ���� ���� �Ǵ�
	//	if (distance > 3)
	//	{
	//		printf("���� �Ұ�\n");
	//	}
	//	else
	//	{
	//		count++;
	//		printf("���� ����\n");
	//	}
	//	_getch();
	//}
	//
	//printf("���� Ƚ�� : %d\n", count);
#pragma endregion

#pragma region �ڱ� ���� ����ü

	// �ڱ� �ڽŰ� ���� Ÿ���� �����͸� ����� �����ϰ� �ִ� ����ü

	//Node* node1 = malloc(sizeof(Node));
	//node1->data = 30;
	//node1->nextptr = NULL;
	//
	//Node* node2 = malloc(sizeof(Node));
	//node2->data = node1->data * 2;
	//node1->nextptr = node2;
	//node2->nextptr = NULL;
	//
	//Node* node3 = malloc(sizeof(Node));
	//node3->data = node2->data * 2;
	//node2->nextptr = node3;
	//node3->nextptr = NULL;
	//
	//Node* head = node1;
	//
	//while (head!= NULL)
	//{
	//	printf("data : %d\n\n", head->data);
	//	head = head->nextptr;
	//}
	//
	//free(node1);
	//node1 = NULL;
	//free(node2);
	//node2 = NULL;
	//free(node3);
	//node3 = NULL;

	//Node node1 = {10,NULL};
	//Node node2 = {20,NULL};
	//Node node3 = {30,NULL};
	//
	//node1.nextptr = &node2;
	//node2.nextptr = &node3;
	//node3.nextptr = NULL;
	//
	//Node* currentNode = &node1;
	//
	//while (currentNode != NULL)
	//{
	//	printf("Node �� : %d\n\n", currentNode->data);
	//	currentNode = currentNode->nextptr;
	//}

	//---------------------------------------------------

	// typedef�� ����
	// ���� �ڷ����� �� �̸��� ������ �ִ� Ű����
		
	typedef unsigned int UI;

	UI testing;

	printf("typedef UI testing : %d\n\n\n", 255);
	
	// ����ü�� �Բ� ���� ����ü�� �̸��� struct���� ������ �� �� �ִ�.
	// Ex.
	// typedef struct
	//{
	//	int HP;
	//	int MP;
	//	int DF;
	//}Player;
	
	Player player = { 100, 50, 30 };
	
	printf("�÷��̾� ����\n\n");
	printf("ü�� : %d\n\n",player.HP);
	printf("���� : %d\n\n",player.MP);
	printf("���� : %d\n\n",player.DF);

	// ������ ������ �ܼ�ȭ �ؼ� �ڵ� �������� �÷��ְ�, �ڵ� �ۼ������� ���Ǽ��� ���� �� �ִ�.

#pragma endregion


	return 0;
}