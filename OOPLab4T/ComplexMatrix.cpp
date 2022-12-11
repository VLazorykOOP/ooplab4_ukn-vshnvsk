#include <iostream>
#include "ComplexMatrix.h"
#include "ComplexVector.h"
#include <math.h>

const double EpsCalculations = 1.e-5;

MatrixDouble::MatrixDouble(int n1) {
	if (n < 0 || n > 1.e+100)
		cout << " ERROR !!!\n";
	else {
		n = n1;
		DoubleArray = new VectorDouble[n];
		for (int i = 0; i < n; i++) {
			DoubleArray[i] = VectorDouble(n);
		}
	}
}

MatrixDouble::MatrixDouble(int n1, int size1) {
	if (n < 0 || n > 1.e+100 || size1 < 0 || size1 > 1.e+100)
		cout << " ERROR !!!\n";
	else {
		n = n1;
		size = size1;
		DoubleArray = new VectorDouble[n];
		for (int i = 0; i < n; i++) {
			DoubleArray[i] = VectorDouble(size1);
		}
	}
}

MatrixDouble::MatrixDouble(int n1, int size1, double a){
	if (n < 0 || n > 1.e+100 || size1 < 0 || size1 > 1.e+100)
		cout << " ERROR !!!\n";
	else {
		n = n1;
		size = size1;
		DoubleArray = new VectorDouble[n];
		for (int i = 0; i < n; i++) {
			DoubleArray[i] = VectorDouble(size1, a);
		}
	}
}

MatrixDouble::MatrixDouble(const MatrixDouble* s){
	n = s->n;
	DoubleArray = new VectorDouble[n];
	for (int i = 0; i < n; i++) 
		DoubleArray[i] = s->DoubleArray[i];
	codeError = s->codeError;
}

double MatrixDouble::GetN() {
	return n;
}

double MatrixDouble::GetSIZE() {
	return size;
}

double MatrixDouble::GetCodeError() {
	return codeError;
}

MatrixDouble& MatrixDouble::operator++(int) {
	for (int i = 0; i < n; i++) DoubleArray[i]++;
	return *this;
}

MatrixDouble& MatrixDouble::operator--(int) {
	for (int i = 0; i < n; i++) DoubleArray[i]--;
	return *this;
}

bool MatrixDouble::operator!() const {
	for (int i = 0; i < n; i++)
		if (!DoubleArray[i] == false)
			return false;
		else
			return true;
}

MatrixDouble MatrixDouble::operator-() {
	for (int i = 0; i < n; i++) -DoubleArray[i];
	return *this;
}

MatrixDouble& MatrixDouble::operator=(MatrixDouble& s) {
	for (int i = 0; i < n; i++) DoubleArray[i] = s.DoubleArray[i];
	return *this;
}

MatrixDouble MatrixDouble::operator+(MatrixDouble b) {
	for (int i = 0; i < n; i++)  DoubleArray[i] += b.DoubleArray[i];
	return *this;
}

MatrixDouble MatrixDouble::operator+(int b) {
	for (int i = 0; i < n; i++) DoubleArray[i] += b;
	return *this;
}

MatrixDouble MatrixDouble::operator+(float b) {
	for (int i = 0; i < n; i++) DoubleArray[i] += b;
	return *this;
}

MatrixDouble MatrixDouble::operator-(MatrixDouble b) {
	for (int i = 0; i < n; i++)  DoubleArray[i] -= b.DoubleArray[i];
	return *this;
}

MatrixDouble MatrixDouble::operator-(int b) {
	for (int i = 0; i < n; i++) DoubleArray[i] -= b;
	return *this;
}

MatrixDouble MatrixDouble::operator-(float b) {
	for (int i = 0; i < n; i++) DoubleArray[i] -= b;
	return *this;
}

MatrixDouble MatrixDouble::operator*(float b) {
	for (int i = 0; i < n; i++) DoubleArray[i] *= b;
	return *this;
}

MatrixDouble MatrixDouble::operator/(int b) {
	for (int i = 0; i < n; i++) DoubleArray[i] /= b;
	return *this;
}

MatrixDouble MatrixDouble::operator+=(MatrixDouble b) {
	for (int i = 0; i < n; i++)  DoubleArray[i] += b.DoubleArray[i];
	return *this;
}

MatrixDouble MatrixDouble::operator+=(float b) {
	for (int i = 0; i < n; i++) DoubleArray[i] += b;
	return *this;
}

MatrixDouble MatrixDouble::operator-=(MatrixDouble b) {
	for (int i = 0; i < n; i++)  DoubleArray[i] -= b.DoubleArray[i];
	return *this;
}

MatrixDouble MatrixDouble::operator-=(float b) {
	for (int i = 0; i < n; i++) DoubleArray[i] -= b;
	return *this;
}

MatrixDouble MatrixDouble::operator*=(float b) {
	for (int i = 0; i < n; i++) DoubleArray[i] *= b;
	return *this;
}

MatrixDouble MatrixDouble::operator/=(int b) {
	for (int i = 0; i < n; i++) DoubleArray[i] /= b;
	return *this;
}

double& MatrixDouble::operator[](int index) {
	if (index >= 0 || index < size) {
		double DD = DoubleArray[0].GetVec(index);
		return DD;
	}
	else {
		cout << " Error : operator[] - index out of range \n";;
		codeError = 1;
		double Dd = DoubleArray[0].GetVec(0);
		return Dd;
	}
}

void MatrixDouble::OutputMat() {

	for (int i = 0; i < n; i++) {
		std::cout << "   ";
		DoubleArray[i].Output(); 
		std::cout << "\n";
	}
}

int main() 
{
	MatrixDouble A1(3), A2(3, 5), A3(3, 5, 15);
	MatrixDouble B2(3, 2), B4(3, 5, 20), B5(3, 5, 0), B6(5, 3, 2),B3(A3);
	std::cout << "Конструктор без параметрів: \n";
	A1.OutputMat();
	std::cout << "Конструктор з двома параметрами: \n";
	A2.OutputMat();
	std::cout << "Конструктор з трьома параметрами: \n";
	A3.OutputMat();
	std::cout << "Конструктор копій: \n";
	B3.OutputMat();
	std::cout << "n : ";
	std::cout << A3.GetN();
	std::cout << "\nsize : ";
	std::cout << A3.GetSIZE();
	std::cout << "\ncodeError : ";
	std::cout << A3.GetCodeError();
	std::cout << "\n";
	std::cout << "Унарних префікс ++: \n";
	A3++;
	A3.OutputMat();
	std::cout << "Унарних постфікс --: \n";
	A3--;
	A3.OutputMat();
	std::cout << "\nУнарне логічне ! : \n";
	std::cout << !A3;
	std::cout << "\n";
	std::cout << "\nУнарний арифметичний - : \n";
	-A3;
	A3.OutputMat();
	std::cout << "\nПрисвоєння: копіює вектор : \n";
	B4 = A3;
	B4.OutputMat();
	std::cout << "Додавання для двох матриць : \n";
	(A3 + B4).OutputMat();
	std::cout << "Додавання для матриці та скаляра типу int : \n";
	(A3 + 10).OutputMat();
	std::cout << "Додавання для матриці та скаляра типу float : \n";
	(A3 + (float)2.5).OutputMat();
	std::cout << "Віднімання для двох матриць : \n";
	(A3 - B4).OutputMat();
	std::cout << "Віднімання для матриці та скаляра типу int : \n";
	(A3 - 10).OutputMat();
	std::cout << "Віднімання для матриці та скаляра типу float : \n";
	(A3 - (float)2.5).OutputMat();
	std::cout << "Множення для матриці та скаляра типу float : \n";
	(B4 * 50).OutputMat();
	std::cout << "Ділення для матриці та скаляра типу int : \n";
	(B4 / 5).OutputMat();
	std::cout << "Присвоєння додавання для двох матриць : \n";
	(B4 += A3).OutputMat();
	std::cout << "Присвоєння додавання для матриці та скаляра типу float : \n";
	(B4 += (float)2.3).OutputMat();
	std::cout << "Присвоєння віднімання для двох матриць : \n";
	(B4 -= A3).OutputMat();
	std::cout << "Присвоєння віднімання для матриці та скаляра типу float : \n";
	(B4 -= (float)2.3).OutputMat(); 
	std::cout << "Присвоєння множення для матриці та скаляра типу float : \n";
	(B4 *= (float)2.3).OutputMat(); 
	std::cout << "Присвоєння ділення для матриці та скаляра типу float : \n";
	(B4 /= 5).OutputMat(); 
	std::cout << "\nOперація індексації: \n";
	std::cout << A3[3] << "\n";

	return 0;
}