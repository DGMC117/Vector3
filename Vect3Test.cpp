#include "Vect3.h"

#include <iostream>
#include <cassert>

using namespace std;

int main() {

	{ // Default constructor
		Vec3<double> v;
		assert(0 == v.getXValue());
		assert(0 == v.getYValue());
		assert(0 == v.getZValue());
	}

	{ // Components constructor
		Vec3<double> v(1, 2, 3);
		assert(1 == v.getXValue());
		assert(2 == v.getYValue());
		assert(3 == v.getZValue());
	}

	{ // Copy constructor
		Vec3<double> v1(1, 2, 3);
		Vec3<double> v2(v1);
		assert(1 == v2.getXValue());
		assert(2 == v2.getYValue());
		assert(3 == v2.getZValue());
	}

	{ // Dot product
		Vec3<double> v1(2, 2, 2);
		Vec3<double> v2(1, 2, 3);
		assert(12 == v1.dotProduct(v2));
	}

	{ // Get magnitude
		Vec3<double> v(-1, 0, 0);
		assert(1 == v.getMagnitude());
	}

	{ // Normalize
		Vec3<double> v1(4, 0, 0);
		Vec3<double> v2 = v1.normalize();
		assert(1 == v2.getXValue());
		assert(0 == v2.getYValue());
		assert(0 == v2.getZValue());
	}

	{ // Distance to
		Vec3<double> v1(1, 0, 0);
		Vec3<double> v2(1, 2, 0);
		assert(2 == v1.distanceTo(v2));
	}

	{ // Cross product
		Vec3<double> v1(2, 3, 4);
		Vec3<double> v2(5, 6, 7);
		Vec3<double> v3 = v1.crossProduct(v2);
		assert(-3 == v3.getXValue());
		assert(6 == v3.getYValue());
		assert(-3 == v3.getZValue());
	}

	cout << __FILE__ << " passed" << endl;
}