#include <iostream>
using namespace std;

namespace Module
{
	float time = 5.12412f;

	void Function()
	{
		cout << "Module Function" << endl;
	}
}

namespace Library
{
	const char* manual = "";
	void Function()
	{
		cout << "Library Function" << endl;
	}
}

using namespace Library;
using namespace Module;

int data = 20;

int main()
{
#pragma region ��Ʈ��

	// �ð��� �帧�� ���� ���������� �߻��ϴ� �������� �帧
	// ��Ʈ���� �ü���� ���� �����Ǹ�,
	// ��Ʈ�� ��ü�� ���۶�� �ӽ� �޸� ������ ����

	int series = 5;

	//cout << series << " Stream" << endl;
	//cout << "Program ���α׷�" << endl;
	//int count = 0;
	//cin >> count;
	//for (int i = 1; i <= count; i++)
	//{
	//	
	//	cout << "PlayStation " << i << endl << endl;
	//}
#pragma endregion

#pragma region ���� ���� ������

	// ���� �������� ���Ǵ� �ĺ��ڸ� �����ϴµ� ���Ǵ� ������
	// ���� ���� �����ڴ� ���� ������ ���� �̸��� ���� ������ ����Ǿ�����
	// ���� ����� ������ ����� ������ �̸��� ����ϴ� ���� ��Ģ�� ������
	// ���� ������ ȣ����� ����

	//int data = 10;
	//
	//cout << "Data ���� : " << data << endl;
	//cout << "Data ���� : " << ::data << endl;
#pragma endregion

#pragma region �̸� ����

	// �Ӽ��� ������ �� �ֵ��� ��ȿ ������ �����ϴ� ����
	//Module::Function();
	//Library::Function();
	//manual = "�Ŵ���";
	//cout << manual << endl;
	//cout << Module::time << endl;
#pragma endregion

#pragma region ���� �Ҵ�

	//int* pointer = new int;
	//*pointer = 100;
	//
	//cout << "pointer : " << *pointer << endl;
	//cout << "pointer : " << pointer << endl;
	//
	//delete pointer;
	//pointer = nullptr;

#pragma region ���� �迭

	//pointer = new int[5];
	//
	//for (int i = 0; i < 5; i++)
	//{
	//	pointer[i] = (i + 1) * 10;
	//	cout << "pointer[" << i << "] : " << pointer[i] << endl;
	//}
	//
	//delete[] pointer;
	//pointer = nullptr;

#pragma endregion


#pragma endregion

#pragma region ������ ����Ʈ

	// ������ ����Ʈ : ���� �ڵ�� �Ѿ����, ���� �ڵ��� �ൿ���� �޸𸮿� ������ �ݿ��Ǵ� ����
	// ���� : ';', ',', '&&,||', '?:', �Լ��� ����

	int a = 1;

	a = a + 3 - 5 + 10; // <- ���� �ݷ��� �������� �ڵ尡 ����(������ ����Ʈ)

	cout << "a�� �� : " << a << endl;
	a = 1;
	a = a++ + 3 - 5 + 10; // ������ ����Ʈ ���� ���� �ι� �ٲ�(���ǵ��� ���� �ൿ)
	// a++�� ���� �����ϴ��� ��Ȯ���� �ʾ� � ���� ���� ���� ���� �Ұ�

	cout << "a�� �� : " << a << endl;

	// ������ ������ �ڵ尡 ������������ ������ ���� ����, �������� ������ ����

#pragma endregion



}


