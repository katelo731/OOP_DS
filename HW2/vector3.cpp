#include "vector3.h"
#include <iostream>
#include <cmath>
using namespace std;

vector3::vector3()
{
}

vector3::vector3(float inX,float inY,float inZ)
{
	set(inX,inY,inZ);
}

vector3::vector3(const vector3 &v)
{
	set(v.x,v.y,v.z);
}

float &vector3::operator [] (unsigned int index)
{
	if(index==0) return x;
	else if(index==1) return y;
	else return z;
}

const float &vector3::operator [] (unsigned int index) const
{
	if(index==1) return x;
	else if(index==2) return y;
	else return z;
}

void vector3::set(float xIn,float yIn,float zIn)
{
	x=xIn;
	y=yIn;
	z=zIn;
}

float vector3::length() const
{
	return sqrt(x*x+y*y+z*z);
}

void vector3::printVector3() const
{
	cout << "(" << x << ", " << y << ", " << z << ")";
}

vector3 &vector3::operator = (const vector3 &v)
{
	if(&v!=this)
	{
		set(v.x,v.y,v.z);
	}
	return *this;
}

vector3 &vector3::operator += (const vector3 &v)
{
	set(x+v.x,y+v.y,z+v.z);
	return *this;
}

vector3 &vector3::operator -= (const vector3 &v)
{
	set(x-v.x,y-v.y,z-v.z);
	return *this;	
}

vector3 &vector3::operator *= (float f)
{
	set(x*f,y*f,z*f);
	return *this;
}

vector3 &vector3::operator /= (float f)
{
	set(x/f,y/f,z/f);
	return *this;	
}

bool operator == (const vector3 &a, const vector3 &b)
{
	if(a.x==b.x && (a.y==b.y && a.z==b.z)) return true;
	else return false;
}

bool operator != (const vector3 &a, const vector3 &b)
{
	if(a.x!=b.x || (a.y!=b.y || a.z!=b.z)) return true;
	else return false;
}

vector3 operator - (const vector3 &a)
{
	return vector3(-a.x,-a.y,-a.z);
}

vector3 operator + (const vector3 &a, const vector3 &b)
{
	return vector3(a.x+b.x,a.y+b.y,a.z+b.z);
}

vector3 operator - (const vector3 &a, const vector3 &b)
{
	return vector3(a.x-b.x,a.y-b.y,a.z-b.z);;
}

vector3 operator * (const vector3 &v, float f)
{
	return vector3(v.x*f,v.y*f,v.z*f);
}

vector3 operator * (float f, const vector3 &v)
{
	return vector3(v.x*f,v.y*f,v.z*f);
}

vector3 operator / (const vector3 &v, float f)
{
	return vector3(v.x/f,v.y/f,v.z/f);
}	
