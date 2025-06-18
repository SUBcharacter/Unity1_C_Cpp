#include "Game.h"

void Game::StartNewRound()
{
	communityCard.clear();
	player.ClearHand();
	dealer.ClearHand();

	deck.ShuffleDeck();

	player.AddCard(deck.DrawCard());
	dealer.AddCard(deck.DrawCard());
	player.AddCard(deck.DrawCard());
	dealer.AddCard(deck.DrawCard());
}

void Game::DealCommunityCard(int count)
{
	deck.DrawCard();
	for (int i = 0; i < count; i++)
	{
		communityCard.push_back(deck.DrawCard());
	}
}

void Game::ShowCommunityCard()
{
	cout << "Ŀ�´�Ƽ ī��" << endl << endl;
	for (int i = 0; i < communityCard.size(); i++)
	{
		cout << communityCard[i].GetCard() << "  ";
	}
	cout << endl << endl << endl;
}

void Game::ShowGameState(bool showDown)
{
	cout << "[����]  " << "������ : " << dealer.GetMoney() << endl << endl;
	if (showDown)
	{
		dealer.ShowHand();
	}
	else
	{
		cout << "(�����)" << endl << endl << endl;
	}
	

	cout << "[Ŀ�´�Ƽ ī��]  " << endl << endl;
	if (communityCard.empty())
	{
		cout << "(ī�� ���� ��)" << endl << endl << endl;
	}
	else
	{
		ShowCommunityCard();
	}
	

	cout << "[" << player.GetName() << "]  " << "������ : " << player.GetMoney() << endl << endl;
	player.ShowHand();
	cout << endl << "-----------------------------------------------------" << endl << endl;

}

bool Game::CheckPlayerMoney()
{
	if (player.GetMoney() <= 0)
	{
		return true;
	}

	return false;
}

void Game::BetFromPlayer(Player& p, int chip)
{
	int bettingChip = 0;
	
	if (chip >= p.GetMoney())
	{
		bettingChip = p.GetMoney();
		cout << "������ ���� ���� �����ϼ̽��ϴ�. �ڵ����� ���� ó���˴ϴ�. ���� �ݾ� : "<< bettingChip << endl << endl;
	}
	else
	{
		bettingChip = chip;
	}

	p.ChangeMoney(-bettingChip);
	pot += bettingChip;
	
	
}

bool Game::FirstBet()
{
	cout << "[��ŸƮ ����]" << endl << endl;

	BetFromPlayer(player, entry / 2);
	BetFromPlayer(dealer, entry);
	cout << "�÷��̾��� ����" << endl;
	cout << "1_ ������  2_ ��  3_ ����" << endl << endl;
	int choice = 0;

	cin >> choice;

	if (choice == 1) // ������
	{
		cout << "������ �ݾ��� �Է��� �ֽʽÿ�. ���� ������ : " << player.GetMoney() << endl << endl;

		int raise = 0;
		cin >> raise;
		bettingPlayer = raise + entry;
		cout << player.GetName()+ " " << raise << " ������ | -" << raise + (entry / 2) << endl << endl;
		BetFromPlayer(player, raise + (entry / 2));
	}
	else if (choice == 2) // ��
	{
		
		BetFromPlayer(player, entry / 2);
		cout << player.GetName() << " �� | -" << entry / 2 << endl << endl;
	}
	else if (choice == 3) // ����
	{
		cout << player.GetName() << " ����" << endl << endl;
		return true;
	}

	cout << "���� ������ ...." << endl << endl << endl;

	

	cout << "���� ���þ� : " << pot << endl << endl;
	cout << "----------------------------------------------------------------" << endl << endl << endl;

	return false;
}

bool Game::DefaultBet()
{
	cout << "[���� Ÿ��]" << endl << endl;

	cout << "�÷��̾��� ����" << endl;
	cout << "1_ ������  2_ ��  3_ ����" << endl << endl;

	int choice = 0;

	cin >> choice;




	return false;
}

void Game::DealerDecision()
{

}

void Game::Round()
{
	

	int round = 0;
	while (dealer.GetMoney()>0)
	{
		system("cls");

		if (CheckPlayerMoney())
		{
			cout << "���� ����! �÷��̾ �Ļ��߽��ϴ�...." << endl << endl;
			_getch();
			return;
		}

		round++;

		cout << round << " ����" << endl << endl;

		StartNewRound();

		ShowGameState();
		if (FirstBet())
		{
			cout << "�÷��̾��� ����, ���� ����� �Ѿ�ϴ�." << endl;
			_getch();
			continue;
		}
		_getch();
		// 1�� ����

		DealCommunityCard(3);

		ShowGameState();

		_getch();
		// ���� Ȯ��

		// 2�� ����

		DealCommunityCard(1);
		
		ShowGameState();

		_getch();
		// ���� Ȯ��

		// 3�� ����

		DealCommunityCard(1);
		
		ShowGameState();

		_getch();
		// ���� Ȯ��

		// ��Ʈ ����

		// ��ٿ�
		
		// ���� Ȯ��

		// ��� ����

		// ���� ������ Ȯ�� 
	}
	

}
