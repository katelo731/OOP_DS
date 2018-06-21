#include "matrix33.h"
#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;

matrix33::matrix33()
{
}

matrix33::matrix33(const vector3 &v1,const vector3 &v2,const vector3 &v3)
{
	set(v1,v2,v3);
}

matrix33::matrix33(const matrix33 &m1)
{
	set(m1.V1,m1.V2,m1.V3);
}

vector3 &matrix33::operator [](unsigned int index)
{
	if(index==0)
		return V1;
	else if(index==1)
		return V2;
	else if(index==2)
		return V3;
}

const vector3 &matrix33::operator [](unsigned int index) const
{
	if(index==0)
		return V1;
	else if(index==1)
		return V2;
	else if(index==2)
		return V3;
}

void matrix33::set(vector3 v1,vector3 v2,vector3 v3)
{
	V1=v1;
	V2=v2;
	V3=v3;
}

matrix33 &matrix33::operator = (const matrix33 &m)
{
	set(m.V1,m.V2,m.V3);
	return *this;
}

matrix33 &matrix33::operator += (const matrix33 &m)
{
	set(V1+m.V1,V2+m.V2,V3+m.V3);
	return *this;
}

matrix33 &matrix33::operator -= (const matrix33 &m)
{
	set(V1-m.V1,V2-m.V2,V3-m.V3);
	return *this;
}

matrix33 &matrix33::operator *= (float f)
{
	set(V1*f,V2*f,V3*f);
	return *this;
}

matrix33 &matrix33::operator /= (float f)
{
	set(V1/f,V2/f,V3/f);
	return *this;
}

bool operator == (const matrix33 &a, const matrix33 &b)
{
	if(a.V1==b.V1 && (a.V2==b.V2 && a.V3==b.V3)) return true;
	else return false;
}

bool operator != (const matrix33 &a, const matrix33 &b)
{
	if(a.V1!=b.V1 || (a.V2!=b.V2 || a.V3!=b.V3)) return true;
	else return false;
}

matrix33 operator - (const matrix33 &a)
{
	return matrix33(-a.V1,-a.V2,-a.V3);
}

matrix33 operator + (const matrix33 &a, const matrix33 &b)
{
	return matrix33(a.V1+b.V1,a.V2+b.V2,a.V3+b.V3);
}

matrix33 operator - (const matrix33 &a, const matrix33 &b)
{
	return matrix33(a.V1-b.V1,a.V2-b.V2,a.V3-b.V3);
}

matrix33 operator * (const matrix33 &m, float f)
{
	return matrix33(m.V1*f,m.V2*f,m.V3*f);
}

matrix33 operator * (float f, const matrix33 &m)
{
	return matrix33(m.V1*f,m.V2*f,m.V3*f);
}

matrix33 operator * (const matrix33 &a, const matrix33 &b)
{
	vector3 w1,w2,w3;
	
	w1.x=a.V1.x*b.V1.x+a.V2.x*b.V1.y+a.V3.x*b.V1.z;
	w2.x=a.V1.x*b.V2.x+a.V2.x*b.V2.y+a.V3.x*b.V2.z;
	w3.x=a.V1.x*b.V3.x+a.V2.x*b.V3.y+a.V3.x*b.V3.z;
	w1.y=a.V1.y*b.V1.x+a.V2.y*b.V1.y+a.V3.y*b.V1.z;
	w2.y=a.V1.y*b.V2.x+a.V2.y*b.V2.y+a.V3.y*b.V2.z;
	w3.y=a.V1.y*b.V3.x+a.V2.y*b.V3.y+a.V3.y*b.V3.z;
	w1.z=a.V1.z*b.V1.x+a.V2.z*b.V1.y+a.V3.z*b.V1.z;
	w2.z=a.V1.z*b.V2.x+a.V2.z*b.V2.y+a.V3.z*b.V2.z;
	w3.z=a.V1.z*b.V3.x+a.V2.z*b.V3.y+a.V3.z*b.V3.z;

	return matrix33(w1,w2,w3);
}

matrix33 operator / (const matrix33 &m, float f)
{
	return matrix33(m.V1/f,m.V2/f,m.V3/f);
}

matrix33 matrix33::invert()
{
	float invdet=1/determinant();
	vector3 w1,w2,w3;
	
	w1.x=(V2.y*V3.z-V2.z*V3.y)*invdet;
	w2.x=(V3.x*V2.z-V2.x*V3.z)*invdet;
	w3.x=(V2.x*V3.y-V3.x*V2.y)*invdet;
	w1.y=(V3.y*V1.z-V1.y*V3.z)*invdet;
	w2.y=(V1.x*V3.z-V3.x*V1.z)*invdet;
	w3.y=(V1.y*V3.x-V1.x*V3.y)*invdet;
	w1.z=(V1.y*V2.z-V1.z*V2.y)*invdet;
	w2.z=(V1.z*V2.x-V1.x*V2.z)*invdet;
	w3.z=(V1.x*V2.y-V1.y*V2.x)*invdet;
	
	return matrix33(w1,w2,w3);
}

matrix33 matrix33::identity()
{
	V1.x=1;
	V1.y=0;
	V1.z=0;
	V2.x=0;
	V2.y=1;
	V2.z=0;
	V3.x=0;
	V3.y=0;
	V3.z=1;
	
	return *this;
}

float matrix33::determinant()
{
	float sum=0;
	sum=V1.x*V2.y*V3.z+V1.y*V2.z*V3.x+V1.z*V2.x*V3.y-V1.z*V2.y*V3.x-V1.y*V2.x*V3.z-V1.x*V2.z*V3.y;
	return sum;
}

void matrix33::printMatrix() const
{
	cout << setw(4) << V1.x << " " << setw(4) << V2.x << " " << setw(4) << V3.x << endl
		 << setw(4) << V1.y << " " << setw(4) << V2.y << " " << setw(4) << V3.y << endl
		 << setw(4) << V1.z << " " << setw(4) << V2.z << " " << setw(4) << V3.z << endl;
}
