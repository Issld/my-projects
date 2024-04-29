#include <iostream>
#include <vector>

using namespace std;

bool In(int* a, int x) {
	int n = sizeof(a);
	for (int i = 0; i < n; i++) {
		if (a[i] == x) {
			return 1;
		}
	}
	return 0;
}

int In_menu(int* a) {
	int x;
	cin >> x;
	while (cin.fail() || (cin.get() != '\n') || (In(a, x) == 0)) {
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		cout << "Введена неизвестная команда! \nПожалуйста, повторите ввод: ";
		cin >> x;
	}
	return x;
}


struct Node {
	int value;
	int high;
	Node* left;
	Node* right;
};

int High(Node* cur) {
	if (cur != NULL) {
		return cur->high;
	}
	return 0;
}

void NewHigh(Node* cur){
	int hl = High(cur->left);
	int hr = High(cur->right);
	if (hl > hr) {
		cur->high = hl + 1;
	}
	else {
		cur->high = hr + 1;
	}
}

Node* TurnLeft(Node* root) {
	Node* cur = root;
	Node* c = root->right;
	cur->right = c->left;
	c->left = cur;
	NewHigh(cur);
	NewHigh(c);
	return c;
}

Node* TurnRight(Node* root) {
	Node* cur = root;
	Node* c = root->left;
	cur->left = c->right;
	c->right = cur;
	NewHigh(cur);
	NewHigh(c);
	return c;
}

Node* Balance(Node* root) {
	Node* cur = root;
	NewHigh(cur);
	if (High(cur->right) - High(cur->left) == 2) {
		if (High(cur->right->right) - High(cur->right->left) < 0) {
			cur->right = TurnRight(cur->right);
		}
		return TurnLeft(cur);
	}
	if (High(cur->right) - High(cur->left) == -2) {
		if (High(cur->left->right) - High(cur->left->left) > 0) {
			cur->left = TurnLeft(cur->left);
		}
		return TurnRight(cur);
	}
	return cur;
}

Node* Add(Node* root, int n) {
	Node* cur = root;
	if (cur == NULL) {
		Node* p = new Node;
		p->right = NULL;
		p->left = NULL;
		p->value = n;
		p->high = 1;
		return p;
	}
	if (cur->value == n) {
		cout << "Ошибка! Все значения должны быть уникальны! \nДерево осталось неизменным:" << endl;
		return cur;
	}
	if (n < cur->value) {
		cur->left = Add(cur->left, n);
	}
	else {
		cur->right = Add(cur->right, n);
	}
	return Balance(cur);
}

Node* Min(Node* current) {
	Node* cur = current;
	if (cur->left != NULL) {
		return Min(cur->left);
	}
	return cur;
}

Node* ReplaceMin(Node* current) {
	Node* cur = current;
	if (cur->left == NULL)
		return cur->right;
	cur->left = ReplaceMin(cur->left);
	return Balance(cur);
}

Node* Delete(Node* root, int n) {
	Node* cur = root;
	if (cur == NULL) {
		return NULL;
	}
	if (n < cur->value)
		cur->left = Delete(cur->left, n);
	else if (n > cur->value)
		cur->right = Delete(cur->right, n);
	else {
		Node* left = cur->left;
		Node* right = cur->right;
		delete cur;
		if (right == NULL) {
			return left;
		}
		Node* min = Min(right);
		min->right = ReplaceMin(right);
		min->left = left;
		return Balance(min);
	}
	return Balance(cur);
}

void Show(Node* root, int n) {
	Node* cur = root;
	if (cur != NULL) {
		Show(cur->right, n + 1);
		for (int i = 1; i <= n; i++) {
			cout << "\t";
		}
		cout << cur->value << endl;
		Show(cur->left, n + 1);
	}
}

int Round(struct Node* root) {
	Node* cur = root;
	if (cur == NULL) {
		return 0;
	}
	cout << cur->value << " ";
	Round(cur->left);
	Round(cur->right);
}

int Search(Node* root, int n, int count) {
	Node* cur = root;
	if (cur->value == n) {
		cout << "Элемент найден, шагов потребовалось: " << count << endl;
		return 1;
	}
	if (pow(cur->high, 5) < count) {
		return 0;
	}
	if (n < cur->value) {
		Search(cur->left, n, count + 1);
	}
	else {
		Search(cur->right, n, count + 1);
	}
}

int DeleteAll(struct Node* root, int* count, vector <int>& a) {
	Node* cur = root;
	if (cur == NULL) {
		return 0;
	}
	*count += 1;
	if (*count % 2 == 1) {
		cout << "Удалить: " << cur->value << endl;
		a.push_back(cur->value);
	}
	DeleteAll(cur->left, count, a);
	DeleteAll(cur->right, count, a);
}


void Task(Node* root) {
	Node* cur = root;
	cout << "--------------------------------------" << endl;
	Show(cur, 0);
	cout << "--------------------------------------" << endl;
	while (cur->left != NULL || cur->right != NULL) {
		int n = -1;
		vector <int> a;
		DeleteAll(cur, &n, a);
		cout << endl;
		for (int i = 0; i < a.size(); i++) {
			cur = Delete(cur, a[i]);
		}
		cout << "--------------------------------------" << endl;
		Show(cur, 0);
		cout << "--------------------------------------" << endl;
		cout << endl;
	}
}

int Inf() {
	int a[7] = { 1, 2, 3, 4, 5, 6, 7 };
	cout << "Хотите создать дерево, заполненное элементами по-умолчанию, нажмите 1" << endl;
	cout << "Хотите добавить элемент дерево, нажмите 2" << endl;
	cout << "Хотите найти элемент в деревое, нажмите 3" << endl;
	cout << "Хотите удалить элемент из дерева, нажмите 4" << endl;
	cout << "Хотите выполнить прямой обход дерева, нажмите 5" << endl;
	cout << "Хотите выполнить задание, нажмите 6" << endl;
	cout << "Хотите завершить сеанс, нажмите 7" << endl;
	return In_menu(a);
}

int main() {
	setlocale(0, "");
	Node* list = NULL;
	int k, x;
	do {
		//system("cls");
		k = Inf();
		switch (k) {
		case 1:
			for (int i = 1; i < 10; i++) {
				list = Add(list, i);
			}
			Show(list, 0);
			cout << endl;
			//system("pause");
			break;
		case 2:
			cout << "Введите значение добавляемого элемента: ";
			cin >> x;
			list = Add(list, x);
			Show(list, 0);
			cout << endl;
			system("pause");
			break;
		case 3:
			cout << "Введите значение искомого элемента: ";
			cin >> x;
			if (Search(list, x, 0) == 2) {
				cout << "Элемент не найден" << endl;
			}
			system("pause");
			break;
		case 4:
			cout << "Введите значение удаляемого элемента: ";
			cin >> x;
			list = Delete(list, x);
			Show(list, 0);
			cout << endl;
			system("pause");
			break;
		case 5:
			cout << "Вершины в порядке обхода: ";
			Round(list);
			cout << endl;
			system("pause");
			break;
		case 6:
			Task(list);
			system("pause");
			break;
		}
	} while (k != 7);
	return 0;
}