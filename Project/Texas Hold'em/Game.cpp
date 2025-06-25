#include "Game.h"

int Game::Input()
{
	int input = 0;

	while (true)
	{
		cin >> input;
		if (input < 1 || input >3)
		{
			cout << "�߸��� �Է��Դϴ�. �ٽ� �õ� �Ͻʽÿ�.\n\n";
			_getch();
		}
		else
			break;
	}


	return input;
}

void Game::StartNewRound()
{
	pot = 0;
	communityCard.clear();
	player.ClearHand();
	dealer.ClearHand();

	deck.ShuffleDeck();

	player.AddCard(deck.DrawCard(true));
	dealer.AddCard(deck.DrawCard(true));
	player.AddCard(deck.DrawCard(true));
	dealer.AddCard(deck.DrawCard(true));

	PlayerCard();
}

void Game::DealCommunityCard(int count)
{
	deck.DrawCard();
	for (int i = 0; i < count; i++)
	{
		communityCard.push_back(deck.DrawCard());
	}
	PlayerCard();
}

void Game::ShowCommunityCard()
{
	cout << "Ŀ�´�Ƽ ī��" << endl << endl;
	for (int i = 0; i < communityCard.size(); i++)
	{
		cout << communityCard[i].GetCardString() << "  ";
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
	ShowPlayerCard();
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
		isAllin = true;
	}
	else
	{
		bettingChip = chip;
	}

	p.ChangeMoney(-bettingChip);
	pot += bettingChip;
	
	
}

void Game::FirstBet()
{
	cout << "[��ŸƮ ����]" << endl << endl;

	BetFromPlayer(player, entry / 2);
	BetFromPlayer(dealer, entry);
	cout << "�÷��̾��� ����" << endl;
	cout << "1_ ������  2_ ��  3_ ����" << endl << endl;
	int choice = 0;

	choice = Input();

	if (choice == 1) // ������
	{
		actPlayer = RAISE;
		cout << "������ �ݾ��� �Է��� �ֽʽÿ�. ���� ������ : " << player.GetMoney() << endl << endl;

		int raise = 0;
		cin >> raise;
		bettingPlayer = raise + entry;
		cout << player.GetName()+ " " << raise << " ������ | -" << raise + (entry / 2) << endl << endl;
		BetFromPlayer(player, raise + (entry / 2));
	}
	else if (choice == 2) // ��
	{
		actPlayer = CALL;
		BetFromPlayer(player, entry / 2);
		cout << player.GetName() << " �� | -" << entry / 2 << endl << endl;
	}
	else if (choice == 3) // ����
	{
		actPlayer = DIE;
		cout << player.GetName() << " ����" << endl << endl;
	}

	DealerDecision(actPlayer,entry);

	cout << "���� ���þ� : " << pot << endl << endl;
	cout << "----------------------------------------------------------------" << endl << endl << endl;

}

void Game::DefaultBet()
{

	if(isAllin)
	{
		return;
	}

	bettingDealer = 0;
	bettingPlayer = 0;

	cout << "[���� Ÿ��]" << endl << endl;

	cout << "�÷��̾��� ����" << endl;
	cout << "1_ ������  2_ üũ  3_ ����" << endl << endl;

	int choice = 0;

	choice = Input();

	if (choice == 1) // ������
	{
		actPlayer = RAISE;
		cout << "������ �ݾ��� �Է��� �ֽʽÿ�. ���� ������ : " << player.GetMoney() << endl << endl;

		int raise = 0;
		cin >> raise;
		bettingPlayer = raise;
		cout << player.GetName() + " " << raise << " ������ | -" << raise << endl << endl;
		BetFromPlayer(player, raise);
	}
	else if (choice == 2) // üũ
	{
		actPlayer = CHECK;
		cout << player.GetName() << " üũ! ����� õõ�� �����غ���� �߽��ϴ�. \n\n";
	}
	else if (choice == 3) // ����
	{
		actPlayer = DIE;
		cout << player.GetName() << " ����" << endl << endl;
	}

	DealerDecision(actPlayer);
		
	cout << "���� ���þ� : " << pot << endl << endl;
	cout << "----------------------------------------------------------------" << endl << endl << endl;
}

void Game::DealerDecision(Acting actPlayer, int entry)
{
	if (actPlayer == DIE)
	{
		return;
	}

	cout << "���� ������ ...." << endl << endl << endl;

	Sleep(1000);

	int dealerChoice = (rand() % 2) + 1;
	switch (actPlayer)
	{
	case RAISE:
		if (dealerChoice == 1) // ��
		{
			actDealer = CALL;
			BetFromPlayer(dealer, bettingPlayer - entry);// raise �ݾ� ��ŭ �� ����
			cout << "���� ��! �� �ݾ� : " << bettingPlayer - entry << endl << endl;
		}
		else if (dealerChoice == 2) // ����
		{
			actDealer = DIE;
			return;
		}
		break;
	case CALL :
		if (dealerChoice == 1) // üũ
		{
			actDealer = CHECK;
			cout << "���� üũ!" << endl << endl;
		}
		else if (dealerChoice == 2) // ����
		{
			actDealer = DIE;
			return;
		}
		break;
	case CHECK:
		actDealer = CHECK;
		cout << "���� üũ!\n\n";
		break;
	}
}

bool Game::DecisionCheck()
{
	if (actPlayer == DIE)
	{
		dealer.ChangeMoney(pot);
		cout << player.GetName() << " ����.... ������ ����� �����մϴ�.\n\n";
	}
	else if(actDealer == DIE)
	{
		player.ChangeMoney(pot);
		cout << "���� ����! ����� �����մϴ�!  ��� : " << pot << endl << endl;
	}
	else
	{
		actPlayer = DEFAULT;
		actDealer = DEFAULT;
		return false;
	}

	actPlayer = DEFAULT;
	actDealer = DEFAULT;
	cout << "���� ����� �Ѿ�ϴ�.\n\n" << endl;
	_getch();

	return true;
}

void Game::PlayerCard()
{
	// �ʱ�ȭ
	playerCard.clear();
	dealerCard.clear();

	// �ڵ� ����
	playerCard.insert(playerCard.end(), player.GetHand().begin(), player.GetHand().end());
	dealerCard.insert(dealerCard.end(), player.GetHand().begin(), player.GetHand().end());

	// Ŀ�´�Ƽ ī�� ����
	playerCard.insert(playerCard.end(), communityCard.begin(), communityCard.end());
	dealerCard.insert(dealerCard.end(), communityCard.begin(), communityCard.end());

	// �迭 ����
	sort(playerCard.begin(), playerCard.end());
	sort(dealerCard.begin(), dealerCard.end());

}

void Game::ShowPlayerCard()
{
	if (!playerCard.empty())
	{
		cout << "������ ī���\n\n";
		for (int i = 0; i < playerCard.size(); i++)
		{
			cout << playerCard[i].GetCardString() << "  ";
		}
		cout << "\n\n";
	}
	else
		return;
}

void Game::EvaluateCard(Player& p, vector<Card> playerCard)
{
#pragma region ���� ī��
	{
		for (auto& card : playerCard)
		{
			if (card.FromHand())
			{
				p.SetHR(HIGHCARD);
				p.SetHC(card);
			}
		}
	}
#pragma endregion

#pragma region �� ��� & �� ���

	{
		map<Number, vector<Card>> numMap;

		for (auto& card : playerCard)
		{
			numMap[card.GetNumber()].push_back(card);
		}

		int pairCount = 0;
		vector<Number> pairNum;
		for (auto& [num, cards] : numMap)
		{
			if (cards.size() == 2)
			{
				pairNum.push_back(num);
			}
		}
		sort(pairNum.begin(), pairNum.end());
		
		if (!pairNum.empty())
		{
			pairCount = pairNum.size();
		
			if (pairCount == 1)
			{
				p.SetHR(ONEPAIR);
		
				vector<Card> pairCard =numMap[pairNum[0]];
				
				sort(pairCard.begin(), pairCard.end());
				
				vector<Card> handPairCard;
				
				for (auto& card : pairCard)
				{
					if (card.FromHand())
					{
						handPairCard.push_back(card);
					}
				}

				if (!handPairCard.empty())
				{
					sort(handPairCard.begin(), handPairCard.end());
					p.SetHC(handPairCard.back());
				}
				else
				{
					p.SetHC(pairCard.back());
				}
			}
			else if (pairCount >= 2)
			{
				p.SetHR(TWOPAIR);

				vector<Card> pairCards;

				for (int i = pairNum.size()-2; i < pairNum.size(); i++)
				{
					Number num = pairNum[i];
					
					vector<Card> handPairCard;
					vector<Card> pairCard;
					for (auto& card : numMap[num])
					{
						pairCard.push_back(card);
					}
					sort(pairCard.begin(), pairCard.end());
					for (auto& card : pairCard)
					{
						if (card.FromHand())
						{
							handPairCard.push_back(card);
						}
					}
					if (!handPairCard.empty())
					{
						sort(handPairCard.begin(), handPairCard.end());
						pairCards.push_back(handPairCard.back());
					}
					else
					{
						pairCards.push_back(pairCard.back());
					}
				}
				p.SetHC(pairCards);
			}
		}

	}

#pragma endregion

#pragma region Ʈ����

	{
		map<Number, vector<Card>> numMap;

		for (auto& card : playerCard)
		{
			numMap[card.GetNumber()].push_back(card);
		}

		vector<Number> triNum;
		for (auto& [num, card] : numMap)
		{
			if (card.size() == 3)
			{
				triNum.push_back(num);
			}
		}

		if (triNum.size() == 1)
		{
			p.SetHR(TRIPLE);

			vector<Card> triCards;

			for (auto& num : triNum)
			{
				for (auto& card : numMap[num])
				{
					triCards.push_back(card);
				}
			}
			vector<Card> handCard;
			for (auto& card : triCards)
			{
				if (card.FromHand())
				{
					handCard.push_back(card);
				}
			}
			if (!handCard.empty())
			{
				sort(handCard.begin(), handCard.end());
				p.SetHC(handCard.back());
			}
			else
			{
				sort(triCards.begin(), triCards.end());
				p.SetHC(triCards.back());
			}
		}
	}

#pragma endregion


#pragma region ��Ʈ����Ʈ
	{
		int combo = 1;

		for (int i = 1; i < playerCard.size(); i++)
		{

			if (playerCard[i].GetNumber() == playerCard[i - 1].GetNumber())
			{
				continue;
			}

			if (playerCard[i].GetNumber() == playerCard[i - 1].GetNumber() + 1)
			{
				combo++;
				p.SetHC(playerCard[i-1]);
				if (combo >= 5)
				{
					p.SetHR(STRAIGHT);
				}
			}
			else
			{
				combo = 1;
				p.ClearHC();
			}
		}
	}
#pragma endregion

#pragma region �÷���
	{
		map<Mark, vector<Card>> markMap;

		for (int i = 0; i < playerCard.size(); i++)
		{
			markMap[playerCard[i].GetMark()].push_back(playerCard[i]);
		}

		for (auto& [mark, cards] : markMap)
		{
			if (cards.size() >= 5)
			{
				sort(cards.begin(), cards.end());
				p.SetHR(FLUSH);
				p.SetHC(cards.back());
				break;
			}
		}
	}
#pragma endregion



#pragma region ��Ʈ����Ʈ �÷���

	{
		map<Mark, vector<Card>> markMap;

		for (int i = 0; i < playerCard.size(); i++)
		{
			markMap[playerCard[i].GetMark()].push_back(playerCard[i]);
		}

		for (auto& [mark, cards] : markMap)
		{
			if (cards.size() < 5)
				continue;

			sort(cards.begin(), cards.end());

			int combo = 1;

			for (int i = 1; i < cards.size(); i++)
			{
				if (cards[i].GetNumber() == cards[i - 1].GetNumber())
				{
					continue;
				}

				if (cards[i].GetNumber() == cards[i - 1].GetNumber() + 1)
				{
					combo++;
					if (combo >= 5)
					{
						p.SetHR(STRAIGHTFLUSH);
						p.SetHC(cards[i]);
						
					}
				}
				else
				{
					combo = 1;
				}
			}
		}
	}

#pragma endregion

#pragma region ��Ƽ��

	{
		map<Mark, vector<Card>> markMap;

		for (int i = 0; i < playerCard.size(); i++)
		{
			markMap[playerCard[i].GetMark()].push_back(playerCard[i]);
		}

		for (auto& [mark, cards] : markMap)
		{
			if (cards.size() < 5)
			{
				continue;
			}

			sort(cards.begin(), cards.end());

			vector<Number> royalNum = { TEN,J,Q,K,A };

			int combo = 0;

			for (auto& c : cards)
			{
				if (c.GetNumber() == royalNum[combo])
				{
					combo++;
				}
				else if (c.GetNumber() > royalNum[combo])
					break;

				if (combo == 5)
				{
					p.SetHR(ROYALSTRAIGHTFLUSH);
					p.SetHC(Card(mark, A, true));
					break;
				}

				if (combo == 5)
					break;
			}
		}
	}

#pragma endregion



}



void Game::Round()
{
	

	int round = 0;
	while (dealer.GetMoney()>0) // ���� ������ Ȯ��
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

		// 1�� ����
		FirstBet();

#pragma region Decision Check
		if (DecisionCheck()) continue;
#pragma endregion

		_getch();
		

		DealCommunityCard(3);

		ShowGameState();

		// ���� Ȯ��

		// 2�� ����
		DefaultBet();

#pragma region Decision Check
		if (DecisionCheck()) continue;
#pragma endregion

		_getch();

		DealCommunityCard(1);
		
		ShowGameState();

		// ���� Ȯ��
		
		// 3�� ����
		DefaultBet();

#pragma region Decision Check
		if (DecisionCheck()) continue;
#pragma endregion

		_getch();

		DealCommunityCard(1);
		
		ShowGameState();

		// ���� Ȯ��

		// ��Ʈ ����
		DefaultBet();

#pragma region Decision Check
		if (DecisionCheck()) continue;
#pragma endregion

		_getch();
		
		// ��ٿ�

		ShowGameState(true);
		
		// ���� Ȯ��

		_getch();

		// ��� ����



		// ���� ������ Ȯ�� 
	}
	

}
