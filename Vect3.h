#ifndef _Vec3_
#define _Vec3_

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

	inline const T dotProduct(const Vec3<T>& v) const;
	inline const T getMagnitude() const;

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
inline const T Vec3<T>::dotProduct(const Vec3<T>& v) const {
	return this->x * v.getXValue() 
		 + this->y * v.getYValue() 
		 + this->z * v.getZValue();
}

template <class T>
inline const T Vec3<T>::getMagnitude() const {
	return abs(sqrt(dotProduct(*this)));
}

#endif //_Vec3_