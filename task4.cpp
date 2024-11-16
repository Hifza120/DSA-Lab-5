#include"myStack.h"
#include<cstring>
bool isDigit(char ch) {
	if (ch >= '0' && ch <= '9') {
		return true;
	}
	return false;
}
bool isOperator(const char ch) {
	return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

void infixoperation(const char* a) {
	myStack<char> S(20);
	int result = 0;
	for (int i = 0; i < strlen(a); i++) {
		if (isDigit(a[i])) {
			S.push(a[i]);
		}
		else if (isOperator(a[i])) {
			char topchar = S.top();
			int value;
			while (!S.isEmpty() && (isDigit(topchar))) {
				value = S.pop() - '0';
				if (a[i] == '+') { result += value; }
				else if (a[i] == '-') { result -= value; }
				else if (a[i] == '*') { result *= value; }
				else if (a[i] == '/') { result /= value; }

				topchar = S.top();
			}

		}

	}
	cout << result << endl;
}
int main() {

	char inf[100];
	cin.getline(inf, 100);
	infixoperation(inf);


	return 0;
}