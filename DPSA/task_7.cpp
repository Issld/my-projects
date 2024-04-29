#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int In() {
    int x;
    cin >> x;
    while (cin.fail() || (cin.get() != '\n') || ((x != 1) && (x != 2))) {
        cin.clear();
        cin.ignore(cin.rdbuf()->in_avail());
        cout << "Введена неизвестная команда! \nПожалуйста, повторите ввод: ";
        cin >> x;
    }
    return x;
}

void Input(ifstream& fr, int** file, int n, int m) {
    int a;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++) {
            fr >> a;
            file[i][j] = a;
        }
    }
}

void Length(ifstream& fr, int* n, int* m) {
    string s;
    while (!fr.eof()) {
        getline(fr, s);
        *n += 1;
    }
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != ' ') {
            *m += 1;
        }
    }
}

vector<int> Sort(vector <int> a) {
    int n = a.size();
    int l = 1;
    int r = n - 1;
    while (l <= r) {
        for (int i = r; i >= l; i--) {
            if (a[i - 1] > a[i]) {
                swap(a[i - 1], a[i]);
            }
        }
        l++;
        for (int i = l - 1; i < r; i++) {
            if (a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
            }
        }
        r--;
    }
    return a;
}

bool Check(vector <int> a, int x) {
    bool f = 1;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == x) {
            f = 0;
            break;
        }
    }
    return f;
}

bool Check(int** a, int x, int n) {
    bool f = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < a[i][n]; j++) {
            if (a[i][j] == x) {
                f = 0;
                break;
            }
        }
    }
    return f;
}

int Check_min(int** a, int n) {
    int x = n;
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < a[i][n]; j++) {
            if (a[i][j] != 0) {
                count++;
            }
        }
        if (count < x) {
            x = count;
        }
        count = 0;
    }
    return x;
}

vector <int> Pares(int** mi, int** may_buf, int n, int m) {
    int** buf = new int* [n];
    int** ms = new int* [n];
    for (int i = 0; i < n; i++) {
        buf[i] = new int[n + 1];
        ms[i] = new int[n];
        buf[i][0] = i + 1;
        for (int j = 1; j < n + 1; j++) {
            buf[i][j] = 0;
            if (j < n) {
                ms[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m - 1; j++) {
            if (mi[i][j] == 1) {
                for (int k = j + 1; k < m; k++) {
                    if (mi[i][k] == 1) {
                        ms[j][k] = 1;
                        ms[k][j] = 1;
                    }
                }
                break;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (ms[i][j] == 1) {
                buf[i][buf[i][n] + 1] = j + 1;
                buf[i][n] ++;
            }
        }

    }
    vector <int> a;
    vector <int> aMax;
    bool f, f1, f2, f3;
    vector <int> pars;
    int time;
    for (int i = 0; i < n - 1; i++) {
        f1 = 1;
        f2 = 0;
        for (int k = 0; k < n; k++) {
            if (k != i) {
                if (Check(pars, buf[i][0]) == 1) {
                    for (int j = 0; j < buf[i][n] + 1; j++) {
                        a.push_back(buf[i][j]);
                    }
                    a = Sort(a);
                    if (Check(a, buf[k][0]) == 1) {
                        if (Check(pars, buf[k][0]) == 1 && Check(pars, buf[i][0]) == 1) {
                            f = 1;
                            pars.push_back(buf[i][0]);
                            pars.push_back(buf[k][0]);
                            time = k;
                            for (int j = 0; j < buf[k][n] + 1; j++) {
                                if (Check(a, buf[k][j]) == 1) {
                                    a.push_back(buf[k][j]);
                                }
                            }
                        }
                    }
                    else {
                        f = 0;
                        if (k == n - 1) {
                            break;
                        }
                    }
                    if (f == 1) {
                        a = Sort(a);
                        f3 = 0;
                        for (int j = 0; j < n; j++) {
                            if (Check(a, j + 1) == 1) {
                                may_buf[i][may_buf[i][n] + 1] = j + 1;
                                may_buf[i][n]++;
                                if (time != 0) {
                                    may_buf[time][may_buf[time][n] + 1] = j + 1;
                                    may_buf[time][n]++;
                                }
                            }
                            f1 = 0;
                        }
                        
                    }
                    a.clear();
                    time = 0;
                }
            }
            if (f1 == 0) {
                break;
            }
        }
        a.clear();
        time = 0;
    }
    return pars;
}

void Task_1(int** mi, int n, int m) {
    int cur_len;
    int min_len;
    int max_len;
    int count = 0;
    bool f = 1;
    int** may_buf = new int* [n];
    for (int i = 0; i < n; i++) {
        may_buf[i] = new int[n + 1];
        may_buf[i][0] = i + 1;
        for (int j = 1; j < n + 1; j++) {
            may_buf[i][j] = 0;
        }
    }
    vector <int> pars = Pares(mi, may_buf, n, m);
    for (int i = 0; i < n; i++) {
        if ((Check(pars, i + 1) == 1) && (Check(may_buf, i + 1, n) == 1)) {
            min_len = 1;
            f = 0;
            count++;
        }
    }
    if (f == 1) {
        min_len = 2 + Check_min(may_buf, n);
    }
    max_len = min_len;
    for (int i = 0; i < pars.size(); i += 2) {
        count++;
        cur_len = 2;
        for (int j = 0; j < may_buf[i][n]; j++) {
            if ((may_buf[i][j] != 0) && (Check(pars,may_buf[i][j]) == 1)) {
                if (cur_len + 1 > max_len) {
                    if ((cur_len + 1) / min_len < 2) {
                        cur_len++;
                        max_len = cur_len;
                    }
                    else {
                        count++;
                    }
                }
                else {
                    if (max_len / min_len < 2) {
                        cur_len++;
                    }
                    else {
                        count++;
                    }
                }
            }
        }
    }
    cout << "Минимальное количество групп: " << count << endl;
}

void Task_2(int** mi, int n, int m, int x) {
    int count = 0;
    int** may_buf = new int* [n];
    for (int i = 0; i < n; i++) {
        may_buf[i] = new int[n + 1];
        may_buf[i][0] = i + 1;
        for (int j = 1; j < n + 1; j++) {
            may_buf[i][j] = 0;
        }
    }
    vector <int> pars = Pares(mi, may_buf, n, m);
    if (x > n) {
        cout << "Нельзя разбить на заданное количество групп" << endl;
    }
    else if (x == n) {
        cout << "Можно разбить на заданное количество групп" << endl;
    }
    else {
        int min_len, cur_len, max_len;
        bool f = 1;
        for (int i = 0; i < n; i++) {
            if ((Check(pars, i + 1) == 1)) {
                min_len = 1;
                f = 0;
                count++;
            }
        }
        count += pars.size() / 2;
        if (count == x) {
            cout << "Можно разбить на заданное количество групп" << endl;
        }
        else if (x > count) {
            if ((x - count + 1) % 2 == 0) {
                cout << "Можно разбить на заданное количество групп" << endl;
            }
            else {
                cout << "Нельзя разбить на заданное количество групп" << endl;
            }
        }
        else {
            int h = Check_min(may_buf, n);
            min_len = 0;
            while (h >= 0) {
                min_len += 1;
                f = 1;
                max_len = min_len;
                for (int i = 0; i < pars.size(); i += 2) {
                    cur_len = 2;
                    for (int j = 0; j < may_buf[i][n]; j++) {
                        if (may_buf[i][j] != 0) {
                            if (cur_len + 1 > max_len) {
                                if ((cur_len + 1) / min_len < 2) {
                                    cur_len++;
                                    max_len = cur_len;
                                    count--;
                                }
                            }
                            else {
                                if (max_len / min_len < 2) {
                                    cur_len++;
                                    count--;
                                }
                            }
                        }
                        if (count == x) {
                            f = 0;
                            break;
                        }
                    }
                    if (f == 0) {
                        break;
                    }
                }
                if (f == 0) {
                    cout << "Можно разбить на заданное количество групп" << endl;
                    break;
                }
                h--;
            }
            if (f == 1) {
                cout << "Нельзя разбить на заданное количество групп" << endl;
            }
        }
    }
}

int main() {
    setlocale(0, "");
    ifstream fr;
    fr.open("Test_1.txt");
    int n = 0, m = 0;
    Length(fr, &n, &m);
    fr.seekg(0, SEEK_SET);
    int** mi = new int* [n];
    for (int i = 0; i < n; i++) {
        mi[i] = new int[m];
    }
    Input(fr, mi, n, m);
    cout << "Заданная матрица инцендентности:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << mi[i][j] << " ";
        }
        cout << endl; 
    }
    int** ms = new int* [n];
    for (int i = 0; i < n; i++) {
        ms[i] = new int[n];
        for (int j = 0; j < n; j++) {
            ms[i][j] = 0;
        }
    }
    cout << "Выберете задачу: \n1) Найти минимальное количество груп разбиения \n2) Найти можно ли разбить на заданное количество групп" << endl;
    int x = In();
    switch (x) {
    case 1:
        Task_1(mi, n, m);
        break;
    case 2:
        cout << "Введите проверяемое количество групп: ";
        cin >> x;
        Task_2(mi, n, m, x);
    }
    return 0;
}