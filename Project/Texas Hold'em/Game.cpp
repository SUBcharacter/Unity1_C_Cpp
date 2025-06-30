#include "Game.h"

int Game::Input()
{
	ShowCursor();
	string input;
	int choice = 0;
	int x = 28 + player.GetName().length();
	while (true)
	{
		GotoXY(x, 21);
		getline(cin, input);
		

		if (!input.empty())
		{
			choice = stoi(input);
			if (choice < 1 || choice >3)
			{
				GotoXY(x, 22);
				cout << "�߸��� �Է��Դϴ�. �ٽ� �õ� �Ͻʽÿ�.\n\n";
				_getch();
				GotoXY(x, 21);
				cout << "       ";
				cout << "                                               ";

			}
			else
				break;
		}
	}
	

	GotoXY(x, 21);
	cout << "       ";
	HideCursor();
	return choice;
}

void Game::StartNewRound()
{
	pot = 0;
	isAllin = false;
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
}

void Game::ShowCommunityCard()
{
	int x = 10;
	for (int i = 0; i < communityCard.size(); i++)
	{
		
		communityCard[i].PrintCard(x,8);
		x += 8;
	}
	
}

void Game::ShowGameState(int round, bool showDown)
{
	system("cls");
	GotoXY(0, 0);
	cout << round << " ����" << endl << endl;
	GotoXY(90, 0);
	cout << "[����]"; 
	GotoXY(97, 0);
	cout << "������ : " << dealer.GetMoney();
	if (showDown)
	{
		GotoXY(85, 2);
		dealer.ShowHand(85, 2);
	}
	else
	{
		GotoXY(85, 3);
		cout << "(�����)" << endl << endl << endl;
	}
	
	GotoXY(27, 7);
	cout << "[Ŀ�´�Ƽ ī��]  " << endl << endl;
	if (communityCard.empty())
	{
		GotoXY(28, 12);
		cout << "(ī�� ���� ��)" << endl << endl << endl;
	}
	else
	{
		ShowCommunityCard();
	}
	
	GotoXY(0, 19);
	cout << "[" << player.GetName() << "]  ������ : " << player.GetMoney();
	
	player.ShowHand(3,22);
	
}

void Game::ShowHand()
{
	GotoXY(80, 13);
	dealer.ShowHighRank();
	GotoXY(80, 16);
	player.ShowHighRank();
}

bool Game::CheckPlayerMoney(Player& pd)
{
	if (pd.GetMoney() <= 0)
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
		GotoXY(80, 9);
		cout << "������ ���� ���� �����ϼ̽��ϴ�.";
		GotoXY(80, 10);
		cout << "�ڵ����� ���� ó���˴ϴ�.";
		GotoXY(80, 11);
		cout <<"���� �ݾ� : " << bettingChip;
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
	GotoXY(80, 7);
	cout << "[��ŸƮ ����]" << endl << endl;
	int x = 28 + player.GetName().length();
	BetFromPlayer(player, entry / 2);
	BetFromPlayer(dealer, entry);
	GotoXY(x, 19);
	cout << "�÷��̾��� ����";
	GotoXY(x, 20);
	cout << "1_ ������  2_ ��  3_ ����" << endl << endl;
	
	int choice = 0;

	choice = Input();

	if (choice == 1) // ������
	{
		ShowCursor();
		actPlayer = RAISE;
		GotoXY(x, 23);
		cout << "������ �ݾ��� �Է��� �ֽʽÿ�. ���� ������ : " << player.GetMoney() << endl << endl;
		string input;
		int raise = 0;
		while (true)
		{
			GotoXY(x, 24);
			raise = 0;
			getline(cin, input);

			if (input.empty())
				continue;

			raise = stoi(input);
			break;
		}
		HideCursor();
		bettingPlayer = raise + entry;
		GotoXY(x, 23);
		cout << "                                                                ";
		GotoXY(x, 24);
		cout << "                             ";
		GotoXY(x, 19);
		cout << "                                  ";
		GotoXY(x, 20);
		cout << "                                  ";
		GotoXY(80, 9);
		cout << player.GetName()+ " " << raise << " ������ | -" << raise + (entry / 2) << endl << endl;
		BetFromPlayer(player, raise + (entry / 2));
	}
	else if (choice == 2) // ��
	{
		actPlayer = CALL;
		BetFromPlayer(player, entry / 2);
		GotoXY(x, 19);
		cout << "                                  ";
		GotoXY(x, 20);
		cout << "                                  ";
		GotoXY(80, 9);
		cout << player.GetName() << " �� | -" << entry / 2 << endl << endl;
	}
	else if (choice == 3) // ����
	{
		actPlayer = DIE;
		GotoXY(x, 19);
		cout << "                                  ";
		GotoXY(x, 20);
		cout << "                                  ";
		GotoXY(80, 9);
		cout << player.GetName() << " ����" << endl << endl;
	}

	DealerDecision(actPlayer,entry);
	GotoXY(80, 17);
	cout << "���� ���þ� : " << pot << endl << endl;
	
	
}

void Game::DefaultBet()
{

	if(isAllin)
	{
		return;
	}

	bettingDealer = 0;
	bettingPlayer = 0;

	int x = 28 + player.GetName().length();
	GotoXY(80, 7);
	cout << "[���� Ÿ��]" << endl << endl;
	GotoXY(x, 19);
	cout << "�÷��̾��� ����" << endl;
	GotoXY(x, 20);
	cout << "1_ ������  2_ üũ  3_ ����" << endl << endl;
	GotoXY(x, 21);
	int choice = 0;

	choice = Input();

	if (choice == 1) // ������
	{
		GotoXY(x, 23);
		actPlayer = RAISE;
		cout << "������ �ݾ��� �Է��� �ֽʽÿ�. ���� ������ : " << player.GetMoney() << endl << endl;
		GotoXY(x, 24);
		int raise = 0;
		string input;
		ShowCursor();
		while (true)
		{
			GotoXY(x, 24);
			raise = 0;
			getline(cin, input);

			if (input.empty())
				continue;

			raise = stoi(input);
			break;
		}
		HideCursor();
		GotoXY(x, 23);
		cout << "                                                                ";
		GotoXY(x, 24);
		cout << "                   ";
		GotoXY(x, 19);
		cout << "                                  ";
		GotoXY(x, 20);
		cout << "                                  ";
		bettingPlayer = raise;
		GotoXY(80, 9);
		cout << player.GetName() + " " << raise << " ������ | -" << raise << endl << endl;
		BetFromPlayer(player, raise);
	}
	else if (choice == 2) // üũ
	{
		GotoXY(x, 19);
		cout << "                                  ";
		GotoXY(x, 20);
		cout << "                                  ";
		GotoXY(80, 9);
		actPlayer = CHECK;
		cout << player.GetName() << " üũ!";
	}
	else if (choice == 3) // ����
	{
		GotoXY(x, 19);
		cout << "                                  ";
		GotoXY(x, 20);
		cout << "                                  ";
		GotoXY(80, 9);
		actPlayer = DIE;
		cout << player.GetName() << " ����" << endl << endl;
	}

	DealerDecision(actPlayer);
	GotoXY(80, 17);
	cout << "���� ���þ� : " << pot << endl << endl;
	
}

void Game::DealerDecision(Acting actPlayer, int entry)
{
	if (actPlayer == DIE)
	{
		return;
	}
	GotoXY(80, 13);
	cout << "���� ������ ...." << endl << endl << endl;

	Sleep(2500);

	GotoXY(80, 13);
	cout << "                           ";
	int dealerChoice = (rand() % 100) + 1;
	switch (actPlayer)
	{
	case RAISE:
		if (dealerChoice >= 30) // ��
		{
			actDealer = CALL;
			BetFromPlayer(dealer, bettingPlayer - entry);// raise �ݾ� ��ŭ �� ����
			GotoXY(80, 13);
			cout << "���� ��! �� �ݾ� : " << bettingPlayer - entry << endl << endl;
		}
		else if (dealerChoice < 30) // ����
		{
			actDealer = DIE;
			return;
		}
		break;
	case CALL :
		if (dealerChoice >= 30) // üũ
		{
			actDealer = CHECK;
			GotoXY(80, 13);
			cout << "���� üũ!" << endl << endl;
		}
		else if (dealerChoice < 30) // ����
		{
			actDealer = DIE;
			return;
		}
		break;
	case CHECK:
		actDealer = CHECK;
		GotoXY(80, 13);
		cout << "���� üũ!\n\n";
		break;
	}
}

bool Game::DecisionCheck()
{
	if (actPlayer == DIE)
	{
		dealer.ChangeMoney(pot);
		GotoXY(80, 9);
		cout << player.GetName() << " ����.... ������ ����� �����մϴ�.\n\n";
	}
	else if(actDealer == DIE)
	{
		player.ChangeMoney(pot);
		GotoXY(80, 13);
		cout << "���� ����! ����� �����մϴ�!";
		GotoXY(80, 14);
		cout << "���: " << pot;
	}
	else
	{
		actPlayer = DEFAULT;
		actDealer = DEFAULT;
		return false;
	}

	actPlayer = DEFAULT;
	actDealer = DEFAULT;
	GotoXY(80, 16);
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
	dealerCard.insert(dealerCard.end(), dealer.GetHand().begin(), dealer.GetHand().end());

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

void Game::Rewarding(Player& p, Player& d)
{
	int y = 18;
	GotoXY(80, y);
	if (p.GetHR() > d.GetHR())
	{
		if (p.GetHR() == ROYALSTRAIGHTFLUSH)
		{
			cout << "���ϵ帳�ϴ�! �ξ� ��Ʈ����Ʈ �÷��� �޼�!";
			GotoXY(80, y+1);
			cout << "���: " << pot;
			p.ChangeMoney(pot);
		}
		else
		{
			cout << p.GetName() << "�� �¸� �Ͽ����ϴ�!";
			GotoXY(80, y + 1);
			cout << "��� : " << pot;
			p.ChangeMoney(pot);
			
		}
		
	}
	else if (p.GetHR() < d.GetHR())
	{
		if (d.GetHR() == ROYALSTRAIGHTFLUSH)
		{
			cout << "�̷�... ������ �ξ� ��Ʈ����Ʈ �÷����� �޼��߽��ϴ�...";
			GotoXY(80, y + 1);
			cout << "���� ��� : " << pot;
			d.ChangeMoney(pot);
		}
		else
		{
			cout << "������ �¸� �Ͽ����ϴ�...";
			GotoXY(80, y + 1);
			cout << "���� ��� : " << pot;
			d.ChangeMoney(pot);
		}
	}
	else if (p.GetHR() == d.GetHR())
	{
		switch (p.GetHR())
		{
		case HIGHCARD:
			for (int i = p.GetHC().size()-1;i >= 0 ;i--)
			{
				if (Card::CompareNumber1(p.GetHC()[i], d.GetHC()[i]))
				{
					cout << p.GetName() << "�� ����ī��! �¸� �Ͽ����ϴ�!";
					GotoXY(80, y + 1);
					cout << "��� : " << pot;
					p.ChangeMoney(pot);
					return;
					
				}
				else if (Card::CompareNumber2(p.GetHC()[i], d.GetHC()[i]))
				{
					cout << "������ ����ī��.... �ƽ����ϴ�....";
					GotoXY(80, y + 1);
					cout << "���� ��� : " << pot;
					d.ChangeMoney(pot);
					return;
				}
				else
					continue;
			}
			cout << "���ø� ��! �ǵ��� ���� �����ϴ�.";
			GotoXY(80, y + 1);
			cout << "��� : " << pot / 2;
			p.ChangeMoney(pot / 2);
			d.ChangeMoney(pot / 2);

			break;

		case ONEPAIR:
			if (Card::CompareNumber1(p.GetHC()[0], d.GetHC()[0]))
			{
				cout << p.GetName() << "�� �¸� �Ͽ����ϴ�!";
				GotoXY(80, y + 1);
				cout << "��� : " << pot;
				p.ChangeMoney(pot);
				
			}
			else if (Card::CompareNumber2(p.GetHC()[0], d.GetHC()[0]))
			{
				cout << "������ �¸� �Ͽ����ϴ�...";
				GotoXY(80, y + 1);
				cout << "���� ��� : " << pot;
				d.ChangeMoney(pot);
			}
			else
			{
				for (int i = 3; i >= 1; i--)
				{
					if (Card::CompareNumber1(p.GetHC()[i], d.GetHC()[i]))
					{
						cout << p.GetName() << "�� ����ī��! �¸� �Ͽ����ϴ�!";
						GotoXY(80, y + 1);
						cout << "��� : " << pot;
						p.ChangeMoney(pot);
						return;
					}
					else if (Card::CompareNumber2(p.GetHC()[i], d.GetHC()[i]))
					{
						cout << "������ ����ī��.... �ƽ����ϴ�...";
						GotoXY(80, y + 1);
						cout<< "���� ��� : " << pot;
						d.ChangeMoney(pot);
						return;
					}
					else
						continue;
				}
				cout << "���ø� ��! �ǵ��� ���� �����ϴ�."; 
				GotoXY(80, y + 1);
				cout<< "��� : " << pot / 2;
				p.ChangeMoney(pot / 2);
				d.ChangeMoney(pot / 2);
				break;
			}
			break;

		case TWOPAIR:
			if (Card::CompareNumber1(p.GetHC()[0], d.GetHC()[0]))
			{
				cout << p.GetName() << "�� �¸� �Ͽ����ϴ�!";
				GotoXY(80, 14);
				cout << "��� : " << pot;
				p.ChangeMoney(pot);
				
			}
			else if (Card::CompareNumber2(p.GetHC()[0], d.GetHC()[0]))
			{
				cout << "������ �¸� �Ͽ����ϴ�..";
				GotoXY(80, y + 1);
				cout<< "���� ��� : " << pot;
				d.ChangeMoney(pot);
			}
			else
			{
				if (Card::CompareNumber1(p.GetHC()[1], d.GetHC()[1]))
				{
					cout << p.GetName() << "�� �¸� �Ͽ����ϴ�!";
					GotoXY(80, y + 1);
					cout << "���: " << pot;
					p.ChangeMoney(pot);
					
				}
				else if (Card::CompareNumber2(p.GetHC()[1], d.GetHC()[1]))
				{
					cout << "������ �¸� �Ͽ����ϴ�...";
					GotoXY(80, y + 1);
					cout << "���� ��� : " << pot;
					d.ChangeMoney(pot);
				}
				else
				{
					if (Card::CompareNumber1(p.GetHC()[2], d.GetHC()[2]))
					{
						cout << p.GetName() << "�� ����ī��! �¸� �Ͽ����ϴ�!";
						GotoXY(80, y + 1);
						cout << "��� : " << pot;
						p.ChangeMoney(pot);
					}
					else if (Card::CompareNumber2(p.GetHC()[2], d.GetHC()[2]))
					{
						cout << "������ ����ī��... �¸� �Ͽ����ϴ�..";
						GotoXY(80, y + 1);
						cout << "���� ��� : " << pot;
						d.ChangeMoney(pot);
					}
					else
					{
						cout << "���ø� ��! �ǵ��� ���� �����ϴ�.";
						GotoXY(80, y + 1);
						cout << "��� : " << pot / 2;
						p.ChangeMoney(pot / 2);
						d.ChangeMoney(pot / 2);
					}
				}
			}
			break;
		case TRIPLE:
			if (Card::CompareNumber1(p.GetHC()[0], d.GetHC()[0]))
			{
				cout << p.GetName() << "�� �¸� �Ͽ����ϴ�!";
				GotoXY(80, y + 1);
				cout << "��� : " << pot << endl << endl << endl;
				p.ChangeMoney(pot);
			}
			else if (Card::CompareNumber2(p.GetHC()[0], d.GetHC()[0]))
			{
				cout << "������ �¸� �Ͽ����ϴ�...";
				GotoXY(80, y + 1);
				cout << "���� ��� : " << pot << endl << endl << endl;
				d.ChangeMoney(pot);
			}
			else
			{
				for (int i = 2; i >= 1; i--)
				{
					if (Card::CompareNumber1(p.GetHC()[i], d.GetHC()[i]))
					{
						cout << p.GetName() << "�� ����ī��! �¸� �Ͽ����ϴ�";
						GotoXY(80, y + 1);
						cout << "��� : " << pot << endl << endl << endl;
						p.ChangeMoney(pot);
						return;
					}
					else if (Card::CompareNumber2(p.GetHC()[i], d.GetHC()[i]))
					{
						cout << "������ ����ī��.... �ƽ����ϴ�...."; 
						GotoXY(80, y + 1);
						cout << "���� ��� : " << pot << endl << endl << endl;
						d.ChangeMoney(pot);
						return;
					}
					else
						continue;
				}
				cout << "���ø� ��! �ǵ��� ���� �����ϴ�";
				GotoXY(80, y + 1);
				cout << "��� : " << pot / 2 << endl << endl << endl;
				p.ChangeMoney(pot / 2);
				d.ChangeMoney(pot / 2);
			}
			break;
		case STRAIGHT:
			if (Card::CompareNumber1(p.GetHC()[4], d.GetHC()[4]))
			{
				cout << p.GetName() << "�� �¸� �Ͽ����ϴ�!"; 
				GotoXY(80, y + 1);
				cout << "��� : " << pot << endl << endl << endl;
				p.ChangeMoney(pot);
			}
			else if (Card::CompareNumber2(p.GetHC()[4], d.GetHC()[4]))
			{
				cout << "������ �¸� �Ͽ����ϴ�...";
				GotoXY(80, y + 1);
				cout << "���� ��� : " << pot << endl << endl << endl;
				d.ChangeMoney(pot);
			}
			else
			{
				cout << "���ø� ��! �ǵ��� ���� �����ϴ�";
				GotoXY(80, y + 1);
				cout << "��� : " << pot / 2 << endl << endl << endl;
				p.ChangeMoney(pot / 2);
				d.ChangeMoney(pot / 2);
			}
			break;
		case FLUSH:
			for (int i = 4; i >= 0; i--)
			{
				if (Card::CompareNumber1(p.GetHC()[i], d.GetHC()[i]))
				{
					cout << p.GetName() << "�� �¸� �Ͽ����ϴ�!";
					GotoXY(80, y + 1);
					cout << "��� : " << pot << endl << endl << endl;
					p.ChangeMoney(pot);
					return;
				}
				else if (Card::CompareNumber2(p.GetHC()[i], d.GetHC()[i]))
				{
					cout << "������ �¸� �Ͽ����ϴ�..";
					GotoXY(80, y + 1);
					cout << "���� ��� : " << pot << endl << endl << endl;
					d.ChangeMoney(pot);
					return;
				}
				else
					continue;
			}
			cout << "���ø� ��! �ǵ��� ���� �����ϴ�.";
			GotoXY(80, y + 1);
			cout << "��� : " << pot / 2 << endl << endl << endl;
			p.ChangeMoney(pot / 2);
			d.ChangeMoney(pot / 2);
			break;
		case FULLHOUSE:
			if (Card::CompareNumber1(p.GetHC()[0], d.GetHC()[0]))
			{
				cout << p.GetName() << "�� �¸� �Ͽ����ϴ�!";
				GotoXY(80, y + 1);
				cout << "��� : " << pot << endl << endl << endl;
				p.ChangeMoney(pot);
			}
			else if (Card::CompareNumber2(p.GetHC()[0], d.GetHC()[0]))
			{
				cout << "������ �¸� �Ͽ����ϴ�...";
				GotoXY(80, y + 1);
				cout << "���� ��� : " << pot << endl << endl << endl;
				d.ChangeMoney(pot);
			}
			else
			{
				if (Card::CompareNumber1(p.GetHC()[1], d.GetHC()[1]))
				{
					cout << p.GetName() << "�� �¸� �Ͽ����ϴ�!";
					GotoXY(80, y + 1);
					cout << "��� : " << pot << endl << endl << endl;
					p.ChangeMoney(pot);
				}
				else if (Card::CompareNumber2(p.GetHC()[1], d.GetHC()[1]))
				{
					cout << "������ �¸� �Ͽ����ϴ�...";
					GotoXY(80, y + 1);
					cout << "���� ��� : " << pot << endl << endl << endl;
					d.ChangeMoney(pot);
				}
				else
				{
					cout << "���ø� ��! �ǵ��� ���� �����ϴ�.";
					GotoXY(80, y + 1);
					cout << "��� : " << pot / 2 << endl << endl << endl;
					p.ChangeMoney(pot / 2);
					d.ChangeMoney(pot / 2);
				}
			}
			break;
		case FOURCARD:
			if (Card::CompareNumber1(p.GetHC()[0], d.GetHC()[0]))
			{
				cout << p.GetName() << "�� �¸� �Ͽ����ϴ�!";
				GotoXY(80, y + 1);
				cout << "��� : " << pot << endl << endl << endl;
				p.ChangeMoney(pot);
			}
			else if (Card::CompareNumber2(p.GetHC()[0], d.GetHC()[0]))
			{
				cout << "������ �¸� �Ͽ����ϴ�...";
				GotoXY(80, y + 1);
				cout << "���� ��� : " << pot << endl << endl << endl;
				d.ChangeMoney(pot);
			}
			else
			{
				if (Card::CompareNumber1(p.GetHC()[1], d.GetHC()[1]))
				{
					cout << p.GetName() << "�� �¸� �Ͽ����ϴ�!";
					GotoXY(80, y + 1);
					cout << "��� : " << pot << endl << endl << endl;
					p.ChangeMoney(pot);
				}
				else if (Card::CompareNumber2(p.GetHC()[1], d.GetHC()[1]))
				{
					cout << "������ �¸� �Ͽ����ϴ�...";
					GotoXY(80, y + 1);
					cout << "���� ��� : " << pot << endl << endl << endl;
					d.ChangeMoney(pot);
				}
				else
				{
					cout << "���ø� ��! �ǵ��� ���� �����ϴ�.";
					GotoXY(80, y + 1);
					cout << "��� : " << pot / 2 << endl << endl << endl;
					p.ChangeMoney(pot / 2);
					d.ChangeMoney(pot / 2);
				}
			}
			break;
		case STRAIGHTFLUSH:
			if (Card::CompareNumber1(p.GetHC()[4], d.GetHC()[4]))
			{
				cout << p.GetName() << "�� �¸� �Ͽ����ϴ�!";
				GotoXY(80, y + 1);
				cout << "��� : " << pot << endl << endl << endl;
				p.ChangeMoney(pot);
			}
			else if (Card::CompareNumber2(p.GetHC()[4], d.GetHC()[4]))
			{
				cout << "������ �¸� �Ͽ����ϴ�...";
				GotoXY(80, y + 1);
				cout << "���� ��� : " << pot << endl << endl << endl;
				d.ChangeMoney(pot);
			}
			else
			{
				cout << "���ø� ��! �ǵ��� ���� �����ϴ�.";
				GotoXY(80, y + 1);
				cout << "��� : " << pot / 2 << endl << endl << endl;
				p.ChangeMoney(pot / 2);
				d.ChangeMoney(pot / 2);
			}
			break;
		}
		return;
	}
}

void Game::Round()
{
	
	int round = 0;
	while (true)
	{
		system("cls");
		// �� �÷��̾��� ��ȭ Ȯ��
		if (CheckPlayerMoney(player))
		{
			GotoXY(75,5);
			cout << R"(
		          ,--,     .--.           ,---.         .---..-.   .-.,---.  ,---.    
		        .' .'     / /\ \ |\    /| | .-'        / .-. )\ \ / / | .-'  | .-.\   
		        |  |  __ / /__\ \|(\  / | | `-.        | | |(_)\ V /  | `-.  | `-'/   
		        \  \ ( _)|  __  |(_)\/  | | .-'        | | | |  ) /   | .-'  |   (    
		         \  `-) )| |  |)|| \  / | |  `--.      \ `-' / (_)    |  `--.| |\ \   
		         )\____/ |_|  (_)| |\/| | /( __.'       )---'         /( __.'|_| \)\  
		        (__)             '-'  '-'(__)          (_)           (__)        (__) 
)";
			GotoXY(40, 14);
			cout << "���� ����! �÷��̾ �Ļ��߽��ϴ�...." << endl << endl;
			isPlayerDie = true;
			_getch();
			return;
		}
		else if (CheckPlayerMoney(dealer))
		{
			GotoXY(75, 5);
			cout << R"(
	      _  _   ____    ____  __    ______ .___________.  ______   .______     ____    ____   _  _   
	    _| || |_ \   \  /   / |  |  /      ||           | /  __  \  |   _  \    \   \  /   / _| || |_ 
	   |_  __  _| \   \/   /  |  | |  ,----'`---|  |----`|  |  |  | |  |_)  |    \   \/   / |_  __  _|
	    _| || |_   \      /   |  | |  |         |  |     |  |  |  | |      /      \_    _/   _| || |_ 
	   |_  __  _|   \    /    |  | |  `----.    |  |     |  `--'  | |  |\  \----.   |  |    |_  __  _|
	     |_||_|      \__/     |__|  \______|    |__|      \______/  | _| `._____|   |__|      |_||_|                                                                                             
)";
			GotoXY(30, 15);
			cout << "�����մϴ�! ������ �Ļ� ��Ű�̽��ϴ�. �� ��� : " << player.GetMoney() << endl << endl;
			isDealerDie = true;
			_getch();
			return;
		}

		round++;
		

		StartNewRound();

		ShowGameState(round);

		// 1�� ����
		FirstBet();

#pragma region Decision Check
		if (DecisionCheck()) continue;
#pragma endregion

		_getch();
		

		DealCommunityCard(3);

		ShowGameState(round);

		// ���� Ȯ��

		// 2�� ����
		DefaultBet();

#pragma region Decision Check
		if (DecisionCheck()) continue;
#pragma endregion

		_getch();

		DealCommunityCard(1);
		
		ShowGameState(round);

		// ���� Ȯ��
		
		// 3�� ����
		DefaultBet();

#pragma region Decision Check
		if (DecisionCheck()) continue;
#pragma endregion

		_getch();

		DealCommunityCard(1);
		
		ShowGameState(round);

		// ���� Ȯ��

		// ��Ʈ ����
		DefaultBet();

#pragma region Decision Check
		if (DecisionCheck()) continue;
#pragma endregion

		_getch();
		
		// ��ٿ�

		ShowGameState(true,round);
		
		_getch();

		
		// ���� Ȯ��

		PlayerCard();
		EvaluateCard(player, playerCard);
		EvaluateCard(dealer, dealerCard);

		ShowHand();

		// ��� ����
		Rewarding(player, dealer);
		_getch();


		
	}
	

}
