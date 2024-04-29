#include <iostream>
#include <cmath>
#include <locale.h>

using namespace std;

float z1(float a) {
	return ((a + 2) / (sqrt(2 * a)) - a / (sqrt(2 * a) + 2) + 2 / (a - sqrt(2 * a))) * ((sqrt(a) - sqrt(2)) / (a + 2));
}

float z2(float a) {
	return 1 / (sqrt(a) + sqrt(2));
}

int Check(float a) {
	if ((sqrt(a) + sqrt(2) == 0) || (sqrt(2 * a) + 2 == 0) || (a - sqrt(2 * a) == 0) || (a + 2 == 0)) {
		return 0;
	}
	else {
		return 1;
	}
}

void Compar(float a) {
	float z1_1, z1_2;
	z1_1 = z1(a);
	z1_2 = z2(a);
	z1_1 = round(z1_1 * 10000000) / 10000000;
	z1_2 = round(z1_2 * 10000000) / 10000000;
	cout << "Первое число: " << z1_1 << "\n";
	cout << "Второе число: " << z1_2 << "\n";
	if (z1_1 == z1_2) {
		cout << "Эти значения равны";
	}
	else {
		cout << "Эти значения различны";
	}
}

int main() {
	setlocale(0, "");
	cout << "Введите угол \n";
	float a;
	cin >> a;
	int ch = Check(a);
	if (ch != 0) {
		Compar(a);
	}
	else {
		cout << "Ошибка! Точка не принадлежит ОДЗ.";
	}
}