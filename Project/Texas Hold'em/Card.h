#pragma once	
#include "UsingLibrary.h"
class Card
{
private:
	Mark mark;
	Number number;
	bool isFromHand = false;

	string SetMarkString()
	{
		switch (mark)
		{
		case SPADE: return "��";
		case DIAMOND: return "��";
		case HEART: return "��";
		case CLOVER: return "��";
		}
	}

	string SetNumberString()
	{
		switch (number)
		{
		case TWO: return "2";
		case THREE: return "3";
		case FOUR: return "4";
		case FIVE: return "5";
		case SIX: return "6";
		case SEVEN: return "7";
		case EIGHT: return "8";
		case NINE: return "9";
		case TEN: return "10";
		case J: return "J";
		case Q: return "Q";
		case K: return "K";
		case A: return "A";
		}
	}
public:
	
	Card() : mark(CLOVER), number(TWO) {}
	Card(Mark m, Number n,bool fromHand = false) : mark(m), number(n),isFromHand(fromHand)
	{

	}

	Mark GetMark() { return mark; }

	Number GetNumber() { return number; }

	

	string GetMarkString()
	{
		return SetMarkString();
	}
	string GetNumberString()
	{
		return SetNumberString();
	}

	string GetCardString();
	
	void SetFH(bool type) { isFromHand = type; }
	void PrintCard(int x, int y);
	bool FromHand() const { return isFromHand; }

	bool operator<(const Card& otherCard) const;
	bool operator==(const Card& otherCard) const;

	static bool CompareNumber1(Card& a, Card& b);
	static bool CompareNumber2(Card& a, Card& b);
};

