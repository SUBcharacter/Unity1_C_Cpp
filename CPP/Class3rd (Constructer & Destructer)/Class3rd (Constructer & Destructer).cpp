﻿#include <iostream>
#define SIZE 5
using namespace std;

class Unit
{
private:
	int health;
	int defence;
public:
	Unit()
	{
		health = 40;
		defence = 0;

		cout << "Created Unit" << endl;
	}

	void Stats()
	{
		cout << "체력 : " << health << endl;
		cout << "방어력 : " << defence << endl;
	}

	~Unit()
	{
		cout << "Destroyed" << endl;
	}
};

class Item
{
private:
	char grade;
	int* price = new int[SIZE];
public:
	Item()
	{
		grade = 'A';
		for (int i = 0; i < SIZE; i++)
		{
			price[i] = (i + 1) * 100;
		}
	}

	Item(Item& clone)
	{
		grade = clone.grade;
		price = new int[SIZE];
		for (int i = 0; i < SIZE; i++)
		{
			price[i] = clone.price[i];
		}

	}

	void ShowInfo()
	{
		cout << grade << endl;
		for (int i = 0; i < SIZE; i++)
		{
			cout << "price[" << i << "] : " << price[i] << endl;
		}

	}

	~Item()
	{
		delete[] price;

	}
};

void Position(int x, int y, int z = 30)
{
	cout << "Coordinate (x, y, z) : (" << x << ", " << y << ", " << z << ")" << endl;
}

int main()
{
#pragma region 생성자

	// 클래스의 인스턴스가 생성되는 시점에서 자동으로 호출되는 특수한 멤버 함수
	// 생성자의 경우 객체가 생성될 때 단 한 번만 호출되며,
	// 생성자는 반환형이 존재하지 않기 때문에 생성자가 호출되기 전에는
	// 객체에 대한 메모리는 할당하지 않는다
	//Unit unit;
	//unit.Stats();

#pragma endregion

#pragma region 소멸자

	// 객체가 소멸될 때 자동으로 실행되는 클래스의 멤버 함수
	// 소멸자는 객체가 메모리에서 해제될 때 단 한 번만 호출되며
	// 소멸자에는 매개 변수를 생성하여 사용할 수 없다

	//Unit* marine = new Unit;
	//
	//marine->Stats();
	//delete marine;

#pragma endregion

#pragma region 복사 생성자

	// 같은 객체를 복사하여 생성시킬 때 호출되는 생성자
	// 복사 생성자를 정의하지 않고, 객체를 복사하게 되면
	// 기본 복사 생성자가 호출되기 때문에 얕은 복사로 객체가 복사된다
	//Item item1;
	//Item item2(item1);
	//item1.ShowInfo();
	//item2.ShowInfo();

#pragma endregion

#pragma region 얕은 복사

	// 객체를 복사할 때 주소 값을 복사하여 같은 메모리 공간을 가리키게 하는 복사
	// 얕은 복사의 경우 같은 객체가 서로 같은 메모리 공간을 참조하고 있기 때문에
	// 하나의 객체로 값을 변경하게 되면 서로 참조된 객체도 함께 영향을 받는다

	//int* pointer1 = new int;
	//int* pointer2 = pointer1;
	//
	//*pointer2 = 20;
	//
	//cout << "pointer1 : " << *pointer1 << endl;
	//cout << "pointer2 : " << *pointer2 << endl;
	//
	//*pointer1 = 10;
	//
	//cout << "pointer1 : " << *pointer1 << endl;
	//cout << "pointer2 : " << *pointer2 << endl;
	//
	//delete pointer2;

#pragma endregion

#pragma region 깊은 복사

	// 객체를 복사할 때, 참조 값이 아닌 객체 자체를 새로 복사하여
	// 서로 다른 메모리를 생성하는 복사

	//Item item1;
	//Item item2(item1);
	//
	//item1.ShowInfo();
	//item2.ShowInfo();

#pragma endregion

#pragma region 기본 매개 변수

	// 함수의 매개 변수에 값이 전달되지 않을 때
	// 미리 값을 설정해놓는 매개 변수

	// 기본 매개 변수를 지정하려면 오른쪽에서 부터 값을 지정해야 함

	Position(30, 30);

#pragma endregion


	return 0;
}


