#ifndef _MATRIX33_H_
#define _MATRIX33_H_
#include "vector3.h"

class matrix33 
{  
	public:
		vector3 V1;
		vector3 V2;
		vector3 V3;
		
	public:
		// constructors
		matrix33();
		matrix33(const vector3 &v1,const vector3 &v2,const vector3 &v3);
		matrix33(const matrix33 &m1);
		// operator
		vector3 &operator [] (unsigned int index);
		const vector3 &operator [] (unsigned int index) const;
		
		matrix33 &operator =  (const matrix33 &v);
		matrix33 &operator += (const matrix33 &v);
		matrix33 &operator -= (const matrix33 &v);
		matrix33 &operator *= (float f);
		matrix33 &operator /= (float f);
		friend bool operator == (const matrix33 &a, const matrix33 &b);
		friend bool operator != (const matrix33 &a, const matrix33 &b);
		friend matrix33 operator - (const matrix33 &a);
		friend matrix33 operator + (const matrix33 &a, const matrix33 &b);
		friend matrix33 operator - (const matrix33 &a, const matrix33 &b);
		friend matrix33 operator * (const matrix33 &m, float f);
		friend matrix33 operator * (float f, const matrix33 &m);
		friend matrix33 operator * (const matrix33 &a, const matrix33 &b);
		friend matrix33 operator / (const matrix33 &m, float f);
		
		matrix33 invert();
		matrix33 identity();
		float determinant();
		
		// functions
		void set(vector3 v1,vector3 v2,vector3 v3);
		void printMatrix() const;
};

#endif
