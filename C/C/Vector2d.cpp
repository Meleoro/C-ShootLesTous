#include "Vector2d.h"

Vector2d Vector2d::operator+() {
	return Vector2d(x + v.x, y + v.y);
}