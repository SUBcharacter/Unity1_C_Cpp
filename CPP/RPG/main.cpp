#include "Title.h"

void main()
{
	while (true)
	{
		system('cls');

		cout << "1_ ���� ����" << endl << endl;
		cout << "2_ ���� ����" << endl << endl;

		int input = 0;

		cin >> input;

		if (input == 1)
		{

		}
		else if (input == 2)
		{
			cout << "������ ���� �մϴ�. (Y/N)" << endl << endl;

			int input = _getch();

			if (input == 'Y' || input == 'y')
			{
				return;
			}
			else if (input == 'N' || input == 'n')
			{
				continue;
			}
			else
			{
				cout << "�߸� �� �Է��Դϴ�. �ٽ� �õ��� �ֽʽÿ�." << endl << endl;
				_getch();
			}
		}
	}

	
}