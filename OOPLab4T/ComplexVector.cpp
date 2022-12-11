#include <iostream>
#include "ComplexVector.h"
#include <math.h>

const double range = 1.e-5;

VectorDouble::VectorDouble(int n) {
	if (n <= 0) n = 1;
	num = n;
	Vec = new double[n];
	for (int i = 0; i < n; i++) {
		Vec[i] = 0.0;
	}
}
VectorDouble::VectorDouble(int n, double b) : VectorDouble(n) {
	for (int i = 0; i < num; i++) {
		Vec[i] = b;
	}
}
VectorDouble::VectorDouble(VectorDouble& s){
	num = s.num;
	Vec = new double[num];
	for (int i = 0; i < num; i++) {
		Vec[i] = s.Vec[i];
	}
}
VectorDouble::VectorDouble(VectorDouble&& s) {
	num = s.num;
	Vec = new double[num];
	for (int i = 0; i < num; i++) {
		Vec[i] = s.Vec[i];
	}
}
VectorDouble& VectorDouble::operator++(int){
	for (int i = 0; i < num; i++) Vec[i] += 1;
	return *this;
}
VectorDouble& VectorDouble::operator--(int) {
	for (int i = 0; i < num; i++) Vec[i] -= 1;
	return *this;
}
bool VectorDouble::operator!() const {  
	for (int i = 0; i < num; i++)
		if (fabs(Vec[i]) > range)
			return true;
	return false;
}
VectorDouble VectorDouble::operator-(){
	VectorDouble tmp(*this);

	for (int i = 0; i < num; i++)
		tmp[i] = -Vec[i];
	for (int i = 0; i < num; i++)
		Vec[i] = tmp[i];
	return *this;
}
VectorDouble& VectorDouble::operator=(VectorDouble& s) {
	if (this == &s) return *this;
	if (num != s.num){
		if (Vec) delete[] Vec;
		num = s.num;
		Vec = new double[num];
		codeError = 1;
	}
	for (int i = 0; i < num; i++)   Vec[i] = s.Vec[i];
	return *this;
}
VectorDouble& VectorDouble::operator=(VectorDouble&& s) {
	if (this == &s) return *this;
	if (num != s.num) {
		if (Vec) delete[] Vec;
		num = s.num;
		Vec = new double[num];
		codeError = 1;
	}
	for (int i = 0; i < num; i++)   Vec[i] = s.Vec[i];
	return *this;
}
VectorDouble VectorDouble::operator+(VectorDouble b){
	VectorDouble tmp(*this);
	tmp += b;
	return tmp;
}
VectorDouble VectorDouble::operator+(double b) {
	VectorDouble tmp(*this);
	for (int i = 0; i < num; i++) tmp[i] += b;
	return tmp;
}
VectorDouble VectorDouble::operator-(VectorDouble b){
	VectorDouble tmp(*this);
	tmp -= b;
	return tmp;
}
VectorDouble VectorDouble::operator-(double b) {
	VectorDouble tmp(*this);
	for (int i = 0; i < num; i++) tmp[i] -= b;
	return tmp;
}
VectorDouble VectorDouble::operator*(int b) {
	VectorDouble tmp(*this);
	for (int i = 0; i < num; i++) tmp[i] *= b;
	return tmp;
}
VectorDouble VectorDouble::operator*(double b) {
	VectorDouble tmp(*this);
	for (int i = 0; i < num; i++) tmp[i] *= b;
	return tmp;
}
VectorDouble VectorDouble::operator/(int b) {
	VectorDouble tmp(*this);
	for (int i = 0; i < num; i++) tmp[i] /= b;
	return tmp;
}
VectorDouble VectorDouble::operator/(double b) {
	VectorDouble tmp(*this);
	for (int i = 0; i < num; i++) tmp[i] /= b;
	return tmp;
}
VectorDouble& VectorDouble::operator+=(VectorDouble& b){
	int i;
	if (num == b.num) 
		for (i = 0; i < num; i++) Vec[i] += b.Vec[i];
	else{
		cout << " Warning: vectors of different sizes are used in operation += \n";
	}
	return *this;
}
VectorDouble& VectorDouble::operator+=(VectorDouble&& b) {
	int i;
	if (num == b.num)
		for (i = 0; i < num; i++) Vec[i] += b.Vec[i];
	else {
		cout << " Warning: vectors of different sizes are used in operation += \n";
	}
	return *this;
}
VectorDouble& VectorDouble::operator+=(int b){
	if (num > 0) {
		for (int i = 0; i < num; i++) Vec[i] += b;
	}
	return *this;
}
VectorDouble& VectorDouble::operator+=(float b){
	if (num > 0) {
		for (int i = 0; i < num; i++) Vec[i] += b;
	}
	return *this;
}
VectorDouble& VectorDouble::operator-=(VectorDouble& b){
	int i;
	if (num == b.num) for (i = 0; i < num; i++) Vec[i] -= b.Vec[i];
	else {
		cout << " Warning: vectors of different sizes are used in operation -= \n";
	}
	return *this;
}
VectorDouble& VectorDouble::operator-=(VectorDouble&& b) {
	int i;
	if (num == b.num) for (i = 0; i < num; i++) Vec[i] -= b.Vec[i];
	else {
		cout << " Warning: vectors of different sizes are used in operation -= \n";
	}
	return *this;
}
VectorDouble& VectorDouble::operator-=(int b){
	if (num > 0) {
		for (int i = 0; i < num; i++) Vec[i] -= b;
	}
	return *this;
}
VectorDouble& VectorDouble::operator-=(float b){
	if (num > 0) {
		for (int i = 0; i < num; i++) Vec[i] -= b;
	}
	return *this;
}
VectorDouble& VectorDouble::operator*=(int b) {
	if (num > 0) {
		for (int i = 0; i < num; i++) Vec[i] *= b;
	}
	return *this;
}
VectorDouble& VectorDouble::operator*=(float b) {
	if (num > 0) {
		for (int i = 0; i < num; i++) Vec[i] *= b;
	}
	return *this;
}
VectorDouble& VectorDouble::operator/=(int b) {
	if (num > 0) {
		for (int i = 0; i < num; i++) Vec[i] /= b;
	}
	return *this;
}
double& VectorDouble::operator[](int index) {
	if (index >= 0 || index < num)
		return Vec[index];
	else {
		cout << " Error : operator[] - index out of range \n";;
		codeError = 1;
		return Vec[0];
	}
}
void VectorDouble::Output() {
	if (num != 0) {
		for (int i = 0; i < num; i++) {
			cout << Vec[i] << "     ";
		}
	}
}
double VectorDouble::GetNum() {
	return num;
}
double VectorDouble::GetVec(int k) {
	return Vec[k];
}

int main() 
{
	VectorDouble B1(4, 10), B2(4, 50), B3(4, 5.5);
	VectorDouble A1, A2(5), A3(4, 5);
	std::cout << "Конструктор без параметрів: \n";
	A1.Output(); 
	std::cout << "\nКонструктор з одним параметром: \n";
	A2.Output();
	std::cout << "\nКонструктор з двома параметрами: \n";
	A3.Output();
	std::cout << "\nУнарний префікс ++: \n";
	A3++;
	A3.Output();
	std::cout << "\nУнарний постфікс --: \n";
	A3--;
	A3.Output();
	std::cout << "\nУнарне логічне ! : \n";
	std::cout << !A3;
	std::cout << "\nУнарний арифметичний - : \n";
	-A3;
	A3.Output();
	std::cout << "\nПрисвоєння: копіює вектор : \n";
	A3 = B2;
	A3.Output();
	std::cout << "\nДодавання двох векторів: \n";
	A3 = B1 + B2;
	A3.Output();
	std::cout << "\nДодавання вектора і скаляра типу double: \n";
	A3 = B1 + 90;
	A3.Output();
	std::cout << "\nВіднімання двох векторів: \n";
	A3 = B2 - B1;
	A3.Output();
	std::cout << "\nВіднімання вектора і скаляра типу double: \n";
	A3 = B2 - 30;
	A3.Output();
	std::cout << "\nМноження вектора і скаляра типу int: \n";
	A3 = B2 * 10;
	A3.Output();
	std::cout << "\nМноження вектора і скаляра типу double: \n";
	A3 = B2 * 2.4;
	A3.Output();
	std::cout << "\nДілення вектора і скаляра типу int: \n";
	A3 = B2 / 10;
	A3.Output();
	std::cout << "\nДілення вектора і скаляра типу double: \n";
	A3 = B2 / 2.5;
	A3.Output();
	std::cout << "\nПрисвоєння з додаванням двох векторів: \n";
	A3 += B2;
	A3.Output();
	std::cout << "\nПрисвоєння з додаванням для вектора і скаляра типу int: \n";
	A3 += 10;
	A3.Output();
	std::cout << "\nПрисвоєння з додаванням для вектора і скаляра типу float: \n";
	A3 += (float)2.2;
	A3.Output();
	std::cout << "\nПрисвоєння з відніманням двох векторів: \n";
	A3 -= B1;
	A3.Output();
	std::cout << "\nПрисвоєння з відніманням для вектора і скаляра типу int: \n";
	A3 -= 10;
	A3.Output();
	std::cout << "\nПрисвоєння з відніманням для вектора і скаляра типу float: \n";
	A3 -= (float)2.2;
	A3.Output();
	std::cout << "\nПрисвоєння з множення для вектора і скаляра типу int: \n";
	A3 *= 3;
	A3.Output();
	std::cout << "\nПрисвоєння з множення для вектора і скаляра типу float: \n";
	A3 *= (float)2.2;
	A3.Output();
	std::cout << "\nПрисвоєння з ділення для вектора і скаляра типу int: \n";
	A3 /= 3;
	A3.Output();
	std::cout << "\nOперація індексації: \n";
	std::cout << A3[3] << "\n";

	return 0;
}