#include "Deck.h"

Deck::Deck()
{
	deckIndex = 0;
	deck.reserve(60);

	for (int i = CLOVER; i <= SPADE; i++)
	{
		for (int j = ACE; j <= KING; j++)
		{
			deck.push_back(Card((Rank)j, (Mark)i));
		}
	}
}

void Deck::ShuffleDeck()
{
	deckIndex = 0;

	random_device rd;
	mt19937 g(rd());

	shuffle(deck.begin(), deck.end(), g);
}

Card& Deck::Draw()
{
	if (deckIndex >= 52)
	{
		cout << "ī�� ����! ���� �ٽ� �����ϴ�." << endl;
		ShuffleDeck();
	}
	cout << "ī�带 �̽��ϴ�..." << endl;

	Sleep(200);

	return deck[deckIndex++];
}
