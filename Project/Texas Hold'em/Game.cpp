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

	player.AddCard(deck.DrawCard());
	dealer.AddCard(deck.DrawCard());
	player.AddCard(deck.DrawCard());
	dealer.AddCard(deck.DrawCard());

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
			cout << playerCard[i].GetCard() << "  ";
		}
		cout << "\n\n";
	}
	else
		return;
}

void Game::EvalueateHand(Player& p, const vector<Card>& cards)
{
	map<Number, int> numberCount;
	map<Mark, vector<Number>> markCount;
	
	for (const Card& c : cards)
	{
		numberCount[c.GetNumber()]++;

	}
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
