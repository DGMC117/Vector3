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

	cout << __FILE__ << " passed" << endl;
}