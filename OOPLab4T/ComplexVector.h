#pragma once
#include <iostream>
#include <math.h>
#include<complex>
using namespace std;

class VectorDouble{
	double* Vec = 0;
	int num = 2;
	int codeError = 0;
public: 
	VectorDouble() : VectorDouble(1) {}
	VectorDouble(int n);
	VectorDouble(int n, double a);
	VectorDouble(VectorDouble& s);
	VectorDouble(VectorDouble&& s);

	VectorDouble& operator++(int);
	VectorDouble& operator--(int);
	bool operator!() const;
	VectorDouble operator-();

	VectorDouble& operator=(VectorDouble& s);
	VectorDouble& operator=(VectorDouble&& s);

	VectorDouble operator+(VectorDouble b);
	VectorDouble operator+(double b);

	VectorDouble operator-(VectorDouble b);
	VectorDouble operator-(double b);

	VectorDouble operator*(int b);
	VectorDouble operator*(double b);

	VectorDouble operator/(int b);
	VectorDouble operator/(double b);

	VectorDouble& operator+=(VectorDouble& s);
	VectorDouble& operator+=(VectorDouble&& s);
	VectorDouble& operator+=(int b);
	VectorDouble& operator+=(float b);

	VectorDouble& operator-=(VectorDouble& s);
	VectorDouble& operator-=(VectorDouble&& s);
	VectorDouble& operator-=(int b);
	VectorDouble& operator-=(float b);

	VectorDouble& operator*=(int b);
	VectorDouble& operator*=(float b);

	VectorDouble& operator/=(int b);

	double& operator[](int index);

	~VectorDouble() {
		delete[] Vec;
	}
	void Output();

	double GetNum();
	double GetVec(int k);
};