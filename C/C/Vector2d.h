#pragma once

class Vector2d {
protected :
	double x;
	double y;
};

class Vector3d :public Vector2d {
public :
	Vector3d(double _x = 0, double _y = 0, double _z = 0);

protected :
	double z;
};