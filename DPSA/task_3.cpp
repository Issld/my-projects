#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int Length(ifstream& fr) {
	int n = 0;
	string s;
	while (!fr.eof()) {
		getline(fr, s);
		n++;
	}
	return n;
}

void Input(ifstream& fr, int** file, int* mpr) {
	int moment, time, prior;
	int i = 0;
	while (!fr.eof()) {
		fr >> moment;
		fr >> time;
		fr >> prior;
		file[i][0] = moment;
		file[i][1] = prior;
		file[i][2] = time;
		if (prior > *mpr) {
			*mpr = prior;
		}
		i++;
	}
}

void Input(int** file, int n, int* mpr) {
	for (int i = 0; i < n; i++) {
		cin >> file[i][0];
		cin >> file[i][1];
		cin >> file[i][2];
		if (file[i][1] > *mpr) {
			*mpr = file[i][1];
		}
	}
}

void Task(int** file, int n, int mpr) {
	int head_st = 0, head_qu = 0, c = 0, k = 0, i = 0, count = 0, m = 0;
	int pr1_takt, pr2_takt, j;
	int l = mpr * 1000;
	int st[5][3];
	int qu[5][3];
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 3; j++) {
			st[i][j] = -1;
			qu[i][j] = -1;
		}
	}
	int pr1[3] = { -1, -1, -1 };
	int pr2[3] = { -1, -1, -1 };
	while (pr2[2] > 0 || head_qu != 5) {
		if (k < n && head_st < 5) {
			if (file[k][0] > 0 || k == 0) {
				st[head_st][0] = file[k][0];
				st[head_st][1] = file[k][1];
				st[head_st][2] = file[k][2];
				head_st++;
				k++;
			}
			else if (st[4][0] != -1) {
				cout << "Переполнение стека" << endl;
				break;
			}
		}
		else if (st[4][0] != -1) {
			cout << "Переполнение стека" << endl;
			break;
		}
		if (pr1[2] == 0 && pr1[0] != -1) {
			qu[c][0] = pr1[0];
			qu[c][1] = pr1[1];
			qu[c][2] = pr1_takt;
			c++;
			if (head_st > -1) {
				pr1[0] = st[head_st - 1][0];
				pr1[1] = st[head_st - 1][1];
				pr1[2] = st[head_st - 1][2];
				pr1_takt = st[head_st - 1][2];
				head_st--;
			}
		}
		if ((pr1[2] == -1 || pr1[2] == 0) && k >= 1) {
			pr1[0] = st[head_st - 1][0];
			pr1[1] = st[head_st - 1][1];
			pr1[2] = st[head_st - 1][2];
			pr1_takt = st[head_st - 1][2];
			head_st--;
		}
		if ((pr2[2] == -1 || pr2[2] == 0) && qu[head_qu][0] > 0) {
			pr2[0] = qu[head_qu][0];
			pr2[1] = qu[head_qu][1];
			pr2[2] = qu[head_qu][2];
			pr2_takt = qu[head_qu][2];
			head_qu++;
		}
		if (pr2[2] == 0 && st[0][0] < 0) {
			pr2[0] = qu[head_qu][0];
			pr2[1] = qu[head_qu][1];
			pr2[2] = qu[head_qu][2];
			pr2[0] = 0;
			pr2[1] = 0;
			pr2[2] = 0;
			head_qu++;
		}
		if (k < n) {
			cout << "Входные задания:" << endl;
			for (int j = k; j < n; j++) {
				cout << "Время поступления задачи: " << file[j][0] << "; Приоритет задачи: " << file[j][1] << "; Такты задачи: " << file[j][2] << endl;
			}
		}
		if (st[0][0] > 0 && head_st > 0) {
			cout << "Содержимое стека:" << endl;
			for (int j = 0; j < head_st; j++) {
				cout << "Время поступления задачи: " << st[j][0] << "; Приоритет задачи: " << st[j][1] << "; Такты задачи: " << st[j][2] << endl;
			}
			if (pr1[2] < 0) {
				cout << endl;
			}
		}
		if (pr1[2] > 0) {
			cout << "Первый процессор" << endl;
			cout << "Время поступления задачи: " << pr1[0] << "; Приоритет задачи: " << pr1[1] << "; Такты задачи: " << pr1[2] << endl;
			if (pr2[2] <= 0) {
				cout << endl;
			}
		}
		j = head_qu;
		if (qu[j][0] > 0) {
			cout << "Содержимое очереди:" << endl;
			while (qu[j][0] > 0) {
				cout << "Время поступления задачи: " << qu[j][0] << "; Приоритет задачи: " << qu[j][1] << "; Такты задачи: " << qu[j][2] << endl;
				j++;
			}
			if (pr2[2] < 0) {
				cout << endl;
			}
		}
		if (pr2[2] > 0) {
			cout << "Второй процессор" << endl;
			cout << "Время поступления задачи: " << pr2[0] << "; Приоритет задачи: " << pr2[1] << "; Такты задачи: " << pr2[2] << endl;
			cout << endl;
		}
		if (pr1[2] > 0) {
			pr1[2]--;
		}
		if (pr2[2] > 0) {
			pr2[2]--;
		}
		if (m > l) {
			break;
		}
		m++;
	}
}

int main() {
	setlocale(0, "");
	ifstream fr;
	string s = "Test_";
	int mpr = 0, n = 0;
	cout << "Выберете какой генератор задач использовать:" << endl;
	cout << "1) На 3 задачи" << endl;
	cout << "2) На 5 задач" << endl;
	cout << "3) На 7 задач с переполнением стека" << endl;
	cin >> n;
	cout << endl;
	s = s + to_string(n) + ".txt";
	fr.open(s);
	n = Length(fr);
	fr.seekg(0, SEEK_SET);
	/*cout << "Введите количество задач: " << endl;
	cin >> n;*/
	int** file = new int* [n];
	for (int i = 0; i < n; i++) {
		file[i] = new int[3];
	}
	Input(fr, file, &mpr);
	//Input(file, n, &mpr);
	Task(file, n, mpr);
	for (int i = 0; i < n; i++) {
		delete[]file[i];
	}
	delete[] file;
	fr.close();
	return 0;
}