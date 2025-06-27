#include "PlayManager.h"

void Title()
{
	HideCursor();
	while (true)
	{
		system("cls");
		GotoXY(75, 6);
		cout << R"(
			
		      _    _       _     _   _ _   _     _    _       _     _ _                _ 
		     | |  | |     | |   | | (_) | | |   | |  | |     | |   | ( )              | |
		     | |__| | ___ | | __| |  _| |_| |   | |__| | ___ | | __| |/  ___ _ __ ___ | |
		     |  __  |/ _ \| |/ _` | | | __| |   |  __  |/ _ \| |/ _` |  / _ \ '_ ` _ \| |
		     | |  | | (_) | | (_| | | | |_|_|   | |  | | (_) | | (_| | |  __/ | | | | |_|
		     |_|  |_|\___/|_|\__,_| |_|\__(_)   |_|  |_|\___/|_|\__,_|  \___|_| |_| |_(_)
		                                                                                 
                                                                             

		)";
		GotoXY(50, 18);
		cout << "1_ ���� ����\n\n";
		GotoXY(50, 20);
		cout << "2_ ���� ����\n\n";

		GotoXY(50, 22);
		int input;
		input = _getch();

		if (input == '1')
		{
			Play();
		}
		else if(input == '2')
		{
			cout << "������ �����մϱ�? (Y/N)\n\n";
			int yesOrNo;
			yesOrNo = _getch();

			if (yesOrNo == 'y' || yesOrNo == 'Y')
			{
				return;
			}
			else if (yesOrNo == 'n' || yesOrNo == 'N')
			{
				continue;
			}
			else
			{
				cout << "�߸��� �Է��Դϴ�. �ٽ� �õ� �Ͻʽÿ�.\n\n";
				_getch();
			}
		}
		else
		{
			cout << "�߸��� �Է��Դϴ�. �ٽ� �õ� �Ͻʽÿ�.\n\n";
			_getch();
		}
	}
}

void Play()
{
	GameDescription();
	srand((unsigned int)time(NULL));
	Deck deck;
	Card init(CLOVER, TWO);
	Player player;
	Player dealer("����", 20000);

	DifficultySet(player);

	Game gameManager(player, dealer);

	ShowCursor();
	gameManager.Round();
}

void GameDescription()
{
	system("cls");
	int input;
	GotoXY(40, 6);
	cout << "Hold it! Hold'em�� ���� �� ȯ���մϴ�.                (1���� ������ ��ŵ)\n\n";
	input = _getch();
	if (input == '1') return;
	GotoXY(30, 8);
	cout << "Hold it! Hold'em�� �ػ罺 Ȧ�� ��Ģ�� ������ ��Ŀ ���� �Դϴ�.\n\n";
	input = _getch();
	if (input == '1') return;
	GotoXY(35, 10);
	cout << "�¸� ������ ������ �Ļ��Ű�� ������ ���� �˴ϴ�.\n\n";
	input = _getch();
	if (input == '1') return;
	GotoXY(40, 12);
	cout << "���̵��� ���� �����ڱ��� �����˴ϴ�.\n\n";
	input = _getch();
	if (input == '1') return;
	GotoXY(40, 14);
	cout << "����� ���� ���� �غ��ñ� �ٶ��ϴ�.\n\n";
	_getch();
	

}

void DifficultySet(Player& p)
{
	while (true)
	{
		system("cls");
		GotoXY(75, 4);
		cout << R"(
				         __                                __          __ 
				   _____/ /_____ _____ ____     ________  / /__  _____/ /_
				  / ___/ __/ __ `/ __ `/ _ \   / ___/ _ \/ / _ \/ ___/ __/
				 (__  ) /_/ /_/ / /_/ /  __/  (__  )  __/ /  __/ /__/ /_  
				/____/\__/\__,_/\__, /\___/  /____/\___/_/\___/\___/\__/  
				               /____/                                     
)";
		GotoXY(40, 14);
		cout << "���̵��� ������ �ֽʽÿ�.\n\n\n";
		GotoXY(40, 17);
		cout << "1_ ���(���� | �����ڱ� : 10000)\n\n";
		GotoXY(40, 19);
		cout << "2_ �Ϲ���(���� | �����ڱ� : 5000)\n\n";
		GotoXY(40, 21);
		cout << "3_ �ѷ�(����� | �����ڱ� : 2000)\n\n";


		int input = 0;
		GotoXY(40, 22);
		input = _getch();

		if (input == '1')
		{
			GotoXY(40, 25);
			cout << "��� ���̵��� �����ϼ̽��ϴ�. ����Ͻðڽ��ϱ�? (Y/N)\n\n";
			int easy = _getch();
			
			if (easy == 'y' || easy == 'Y')
			{
				p.ChangeMoney(10000);
				return;
			}
			else if (easy == 'n' || easy == 'N')
			{
				continue;
			}
			else
			{
				cout << "�߸��� �Է��Դϴ�. �ٽ� �õ��Ͻʽÿ�.\n\n";
				_getch();
			}
		}
		else if (input == '2')
		{
			GotoXY(40, 25);
			cout << "�Ϲ��� ���̵��� �����ϼ̽��ϴ�. ����Ͻðڽ��ϱ�? (Y/N)\n\n";
			int normal = _getch();
		
			if (normal == 'y' || normal == 'Y')
			{
				p.ChangeMoney(5000);
				return;
			}
			else if (normal == 'n' || normal == 'N')
			{
				continue;
			}
			else
			{
				cout << "�߸��� �Է��Դϴ�. �ٽ� �õ��Ͻʽÿ�.\n\n";
				_getch();
			}
		}
		else if (input == '3')
		{
			GotoXY(40, 25);
			cout << "�ѷ� ���̵��� �����ϼ̽��ϴ�. ����Ͻðڽ��ϱ�? (Y/N)\n\n";
			int hard = _getch();
			if (hard == 'y' || hard == 'Y')
			{
				p.ChangeMoney(2000);
				return;
			}
			else if (hard == 'n' || hard == 'N')
			{
				continue;
			}
			else
			{
				cout << "�߸��� �Է��Դϴ�. �ٽ� �õ��Ͻʽÿ�.\n\n";
				_getch();
			}
		}
		else
		{
			cout << "�߸��� �Է��Դϴ�. �ٽ� �õ��Ͻʽÿ�.\n\n";
			_getch();
		}
	}
}

