#pragma once
#include <iostream>
using namespace std;

class Consumable
{
protected:
public:
	string name;
	int count = 10;
	virtual void Use();

#pragma region �����Լ�

	// ���� �Լ� ���̺��� ����Ͽ� �Լ��� ȣ��Ǵ� �ð��� ��Ÿ�ӿ� �����ϸ�,
	// �� �� �̻��� ���� �Լ��� �����ϴ� Ŭ������ ���� �� ���� �Լ� �����Ͱ� �߰��ȴ�
	// �����Լ��� ���� �ð��� ���� Ŭ������ ���� ������ ���� Ŭ������ �����ǵ� �Լ��� ȣ���� �� �ִ�

#pragma endregion

};

