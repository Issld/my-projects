#include <iostream>

using namespace std;

int InSize() {
	int x;
	cin >> x;
	while (cin.fail() || (cin.rdbuf()->in_avail() > 1) || (x <= 1)) {
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		cout << "Введены некорректные данные! \nПовторите ввод: ";
		cin >> x;
	}
	return x;
}

int In() {
	int x;
	cin >> x;
	while (cin.fail() || (cin.rdbuf()->in_avail() > 1)) {
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		cout << "Введены некорректные данные! \nПовторите ввод: ";
		cin >> x;
	}
	return x;
}

void Sort(int* a, int n, int* count, int* sr) {
	int l = 1;
	int r = 3; // первые 4 элемента
	while (l <= r) {
		for (int i = r; i >= l; i--){
			if (a[i - 1] > a[i]) { 
				swap(a[i - 1], a[i]);
				*count += 1;
			}
			*sr += 1;
		}
		l++;
		for (int i = l - 1; i < r; i++) {
			if (a[i] > a[i + 1]) {
				swap(a[i], a[i+1]);
				*count += 1;
			}
			*sr += 1;
		}
		r--;
	}
}

void Add(int* a, int* b, int n, int* count, int* sr, int x) {
	for (int i = 0; i < n; i++) {
		b[i] = a[i];
	}
	b[n] = x;
	Sort(b, n + 1, count, sr);
}

int Search(int* a, int n, int l) {
	for (int i = 0; i < n; i++) {
		if (a[i] == l) {
			return i + 1;
		}
	}
}

void Delete(int* a, int* b, int n,  int x, int l, int* count, int* sr) {
	int c = 0;
	if(x == 1) {
		for (int i = 0; i < n - 1; i++) {
			if (i < l) {
				b[i] = a[i];
			}
			else {
				b[i] = a[i + 1];
			}
		}
	}
	else {
		for (int i = 0; i < n - 1; i++) {
			if (a[i] < l && c == 0) {
				b[i] = a[i];
			}
			else {
				c++;
				b[i] = a[i + 1];
			}
		}
	}
	Sort(b, n - 1, count, sr);
}

int main() {
	int count = 0, sr = 0, k = 0, x = 0, l = 0;
	setlocale(LC_ALL, "rus");
	cout << "Введите размер массива: ";
	int n = InSize();
	int* a = new int[n];
	for (int i = 0; i < n; i++) {
		cout << "Введите элемент массива: ";
		a[i] = In();
	}
	cout << "Исходный массив: ";
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	Sort(a, n, &count, &sr);
	cout << "\nМассив после сортировки (перестановок: " << count << ", сравнений: " << sr << "): ";
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	int c = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] != a[i + 1]) {
			c++;
		}
	}
	cout << "\nРазличных элементов в массиве: " << c << endl;
	cout << "\nВведите что хотите сделать:\n1) Найти элемент\n2) Добавить элемент\n3) Удалить элемент" << endl;
	cin >> k;
	int* b = new int[n+1];
	int* d = new int[n-1];
	count = 0;
	sr = 0;
	switch (k) {
	case(1):
		cout << "Введите по чему производить поиск:\n1) По позиции\n2) По значению" << endl;
		cin >> x;
		switch (x) {
		case(1):
			cout << "Введите номер позиции: ";
			cin >> l;
			cout << "Этот элемент: " << a[l - 1] << endl;
			break;
		case(2):
			cout << "Введите значение элемента: ";
			cin >> l;
			cout << "Номер этого элемента: " << Search(a, n, l) << endl;
			break;
		}
		break;
	case(2):
		cout << "Введите добавляемое число: ";
		cin >> x;
		Add(a, b, n, &count, &sr, x);
		cout << "\nМассив после сортировки и добавления элемента (перестановок: " << count << ", сравнений: " << sr << "): ";
		for (int i = 0; i < n+1; i++) {
			cout << b[i] << " ";
		}
		break;
	case(3):
		cout << "Введите по чему производить удаление:\n1) По позиции\n2) По значению" << endl;
		cin >> x;
		switch (x) {
		case(1):
			cout << "Введите номер позиции: ";
			cin >> l;
			Delete(a, d, n, x, l - 1, &count, &sr);
			break;
		case(2):
			cout << "Введите значение элемента: ";
			cin >> l;
			Delete(a, d, n, x, l, &count, &sr);
			break;
		}
		cout << "\nМассив после сортировки и удаления элемента (перестановок: " << count << ", сравнений: " << sr << "): ";
		for (int i = 0; i < n - 1; i++) {
			cout << d[i] << " ";
		}
		break;
	}
	delete[] a;
	delete[] b;
	delete[] d;
	return 0;
}