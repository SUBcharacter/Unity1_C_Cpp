#pragma once
#include <iostream>

using namespace std;

class Packet
{
private:
	int number;

public:
	Packet() { cout << "��Ŷ ����" << endl; }

	void SetNumber(int a);
	void GetNumber();

	void Receive(unique_ptr<Packet>&& ptr);

	~Packet() { cout << "��Ŷ �Ҹ�" << endl; }


};

