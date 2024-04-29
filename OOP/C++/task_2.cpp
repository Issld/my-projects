//#include <iostream>
//#include <iomanip>
//using namespace std;
//
//
//class chislo
//{
//private:
//	int m[3][5];
//	int nom = 0;
//public:
//	void enter(int x);
//	void maxplus();
//	void outik();
//};
//void chislo::enter(int x)
//{
//	int k = x;
//	cout << "Введите массив: " << endl;
//	for (int i = 0; i < 3; i++)
//	{
//		for (int j = 0; j < 5; j++)
//		{
//			m[i][j] = k;
//			k++;
//		}
//	}
//}
//void chislo::maxplus()
//{
//	int k = 0;
//	/*for (int i = 0; i < 3; i++) {
//		for (int j = 0; j < 5; j++) {
//			if (m[i][j] >= 0) {
//				k++;
//			}
//		}
//		if (k > nom) {
//			nom = k;
//		}
//		k = 0;
//	}*/
//	for (int i = 0; i < 5; i++)
//	{
//		for (int j = 0; j < 3; j++)
//		{
//			if (m[i][j] > 0) k++;
//		}
//		if (k >= nom)
//		{
//			nom = k;
//		}
//		k = 0;
//	}
//}
//void chislo::outik()
//{
//	cout << "Ваш массив" << endl;
//	for (int i = 0; i < 3; i++)
//	{
//		for (int j = 0; j < 5; j++)
//		{
//			cout << setw(4) << m[i][j];
//		}
//		cout << endl;
//	}
//	cout << "Максимум положительных в столбце: " << this->nom << endl;
//}
//
//
//int main()
//{
//	setlocale(LC_ALL, "RUS");
//	chislo C;
//	C.enter(-4);
//	C.maxplus();
//	C.outik();
//	chislo D;
//	D.enter(-1);
//	D.maxplus();
//	D.outik();
//	return 0;
//}
#include <iostream>
#include <iomanip>
using namespace std;


class chislo
{
private:
	int m[3][5];
	int nom;
public:
	void enter();
	void maxplus();
	void outik();
};
void chislo::enter()
{
	cout << "Введите массив: " << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cin >> m[i][j];
		}
	}
}
void chislo::maxplus()
{
	int k = 0;
	int num = 0;
	for (int j = 0; j < 5; j++)
	{
		for (int i = 0; i < 3; i++)
		{
			if (m[i][j] > 0) k++;
		}
		if (k > num)
		{
			num = k;
			k = 0;
			this->nom = j + 1;
		}
		else k = 0;
	}
}
void chislo::outik()
{
	cout << "Ваш массив" << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout<<setw(4)<< m[i][j];
		}
		cout << endl;
	}
	cout << "Максимум положительных в столбце: " << this->nom << endl;
}


int main()
{
	setlocale(LC_ALL, "RUS");
	chislo C;
	C.enter();
	C.maxplus();
	C.outik();
	chislo D;
	D.enter();
	D.maxplus();
	D.outik();
	return 0;
}