#pragma once
#include "ComplexVector.h"

class MatrixDouble {
	VectorDouble* DoubleArray;
	int n, size;
	int codeError;
	static int num_matrix;
public:
	MatrixDouble() { DoubleArray = nullptr; n = size = codeError = 0; }
	MatrixDouble(int n);
	MatrixDouble(int n, int size);
	MatrixDouble(int n, int m, double a);
	MatrixDouble(const MatrixDouble* s);

	double GetN();
	double GetSIZE();
	double GetCodeError();

	MatrixDouble& operator++(int);
	MatrixDouble& operator--(int);
	bool operator!() const;
	MatrixDouble operator-();

	MatrixDouble& operator=(MatrixDouble& s);

	MatrixDouble operator+(MatrixDouble b);
	MatrixDouble operator+(int b);
	MatrixDouble operator+(float b);

	MatrixDouble operator-(MatrixDouble b);
	MatrixDouble operator-(int b);
	MatrixDouble operator-(float b);

	MatrixDouble operator*(float b);

	MatrixDouble operator/(int b);

	MatrixDouble operator+=(MatrixDouble b);
	MatrixDouble operator+=(float b);

	MatrixDouble operator-=(MatrixDouble b);
	MatrixDouble operator-=(float b);

	MatrixDouble operator*=(float b);

	MatrixDouble operator/=(int b);

	double& operator[](int index);

	void OutputMat();
};