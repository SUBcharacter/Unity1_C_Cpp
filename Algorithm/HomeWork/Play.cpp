#include "Play.h"

void Play::DamageReport(Player& p, Card& c)
{
	int prevHP = p.getHealth();
	int damage = 0;
	switch (c.GetCardRank())
	{
	case ACE: damage = -20 * ((int)c.GetCardMark()); break;
	case KING: damage = -10 * ((int)c.GetCardMark()); break;
	case QUEEN: damage = -5 * ((int)c.GetCardMark()); break;
	case JACK: damage = -2 * ((int)c.GetCardMark()); break;
	default: break;
	}

	switch (c.GetCardRank())
	{
	case TEN: damage = 20; break;
	case NINE: damage = 15; break;
	case EIGHT: damage = 10; break;
	case SEVEN: damage = 5; break;
	default: break;
	}

	p.setHealth(p.getHealth() + damage);

	if (p.getHealth() > prevHP)
	{
		cout << "ü�� ȸ��!	:  " << damage << " ȸ��" << endl;
	}
	else if (p.getHealth() < prevHP)
	{
		cout << "���� �Ѵ�!	:  " << -damage << " ������" << endl;
	}
	else
	{
		cout << "�ƹ� �ϵ� �Ͼ�� �ʾҽ��ϴ�...." << endl;
	}

	if (p.getHealth() <= 0)
	{
		cout << "���� ü�� : " << 0 << endl << endl;
	}
	else
	{
		cout << "���� ü�� : " << p.getHealth() << endl << endl;
	}
	
	
}

void Play::CheckCard(Player& p, Card& card)
{
	cout << "ī�� Ȯ���� ...." << endl;

	Sleep(500);

	DamageReport(p, card);
}


bool Play::CheckSomeOneDied()
{
	if (you.getHealth() < 0)
	{
		cout << "�̸��� �ڱ��� ���ҽ��ϴ�... GAME OVER" << endl;
		_getch();
		return true;
	}
	else if (your_Friend.getHealth() < 0)
	{
		cout << "ģ���� �̸��� �ݰ��� �����Ƚ��ϴ٤����� GAME OVER" << endl;
		_getch();
		return true;
	}
	else
		return false;
}

void Play::start()
{
	deck.ShuffleDeck();

	while (!CheckSomeOneDied())
	{
		system("cls");

		cout << "����� ��!" << endl;
		// �÷��̾� ��
		
		// ��ο�
		// ī��Ȯ�� �� ������ ���
		CheckCard(you, deck.Draw());
		
		_getch();

		cout << "ģ���� ��!" << endl;
		// ��� ��

		// ��ο�
		// ī�� Ȯ�� �� ������ ���
		CheckCard(your_Friend, deck.Draw());

		_getch();
	}

}
