#pragma once
#include "UsingLibrary.h"
#include "Deck.h"


class Player
{
protected:
	string name;
	HandRank handRank;
	int money;
	vector<Card> hand;
public:
	Player();
	Player(string name, int money) : name(name), money(money) {}
	string SetName();
	void SetMoney(int seedMoney);

	string GetName() const { return name; }
	int GetMoney() const { return money; }
	const vector<Card>& GetHand() const { return hand; }
	
	void AddCard(Card card);
	void ClearHand();
	void ShowHand();
	void ChangeMoney(int chip);
	void SetHR(HandRank hr);
	HandRank GetHR() const { return handRank; }
};

