#include "Vector2.h"

Vector2::Vector2(int x, int y)
{
#pragma region this ������

	// �ڱ� �ڽ��� ����Ű�� ������

	this->x = x;
	this->y = y;

#pragma endregion

}

Vector2 Vector2::operator+(Vector2& other)
{
	return Vector2(x+other.x,y+other.y);
}
