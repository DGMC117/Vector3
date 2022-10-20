#ifndef _Vec3_
#define _Vec3_

#include <cmath>

template <class T>
class Vec3 {

private:
	T x;
	T y;
	T z;

public:
	Vec3();
	Vec3(const T x, const T y, const T z);
	Vec3(const Vec3<T>& v);

	inline T getXValue() const; 
	inline T getYValue() const; 
	inline T getZValue() const;

	const T dotProduct(const Vec3<T>& v) const;
	const T getMagnitude() const;
	Vec3<T>& normalize();
	const T distanceTo(const Vec3<T>& v) const;
	const Vec3<T> crossProduct(const Vec3<T>& v) const;
	const T angleBetween(const Vec3<T>& v) const;

	const Vec3<T> operator+(const Vec3<T>& v) const;
	const Vec3<T> operator-(const Vec3<T>& v) const;

};

template <class T>
Vec3<T>::Vec3() {
	this->x = 0;
	this->y = 0;
	this->z = 0;
}

template <class T>
Vec3<T>::Vec3(const T x, const T y, const T z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

template <class T>
Vec3<T>::Vec3(const Vec3<T>& v) {
	this->x = v.getXValue();
	this->y = v.getYValue();
	this->z = v.getZValue();
}

template <class T>
inline T Vec3<T>::getXValue() const { return this->x; }

template <class T>
inline T Vec3<T>::getYValue() const { return this->y; }

template <class T>
inline T Vec3<T>::getZValue() const { return this->z; }

template <class T>
const T Vec3<T>::dotProduct(const Vec3<T>& v) const {
	return this->x * v.getXValue() 
		 + this->y * v.getYValue() 
		 + this->z * v.getZValue();
}

template <class T>
const T Vec3<T>::getMagnitude() const {
	return abs(sqrt(dotProduct(*this)));
}

template <class T>
Vec3<T>& Vec3<T>::normalize() {
	T magnitude = getMagnitude();
	if (magnitude) {
		this->x /= magnitude;
		this->y /= magnitude;
		this->z /= magnitude;
	}
	return *this;
}

template <class T>
const T Vec3<T>::distanceTo(const Vec3<T>& v) const {
	return sqrt(pow(v.getXValue() - this->x, 2)
		+ pow(v.getYValue() - this->y, 2)
		+ pow(v.getZValue() - this->z, 2));
}

template <class T>
const Vec3<T> Vec3<T>::crossProduct(const Vec3<T>& v) const {
	return Vec3<T>(this->y * v.getZValue() - this->z * v.getYValue(),
		this->z * v.getXValue() - this->x * v.getZValue(),
		this->x * v.getYValue() - this->y * v.getXValue());
}

template <class T>
const T Vec3<T>::angleBetween(const Vec3<T>& v) const {
	return acos(dotProduct(v) / (getMagnitude() * v.getMagnitude()));
}

template <class T>
const Vec3<T> Vec3<T>::operator+(const Vec3<T>& v) const {
	return Vec3<T>(this->x + v.getXValue(),
		this->y + v.getYValue(),
		this->z + v.getZValue());
}

template <class T>
const Vec3<T> Vec3<T>::operator-(const Vec3<T>& v) const {
	return Vec3<T>(this->x - v.getXValue(),
		this->y - v.getYValue(),
		this->z - v.getZValue());
}

#endif //_Vec3_