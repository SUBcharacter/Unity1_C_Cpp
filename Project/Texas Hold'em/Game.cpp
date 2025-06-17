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

void Game::FirstBet()
{
	cout << "[�۽�Ʈ ����]" << endl << endl;



}

void Game::Round()
{
	int round = 0;
	while (dealer.GetMoney()>0)
	{
		round++;

		cout << round << " ����" << endl << endl;

		StartNewRound();

		ShowGameState();

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
