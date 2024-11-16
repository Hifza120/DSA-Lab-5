#include"myStack.h"
#include<cstring>
int precedence(const char  ch) {
	if (ch == '+' || ch == '-') {
		return 1;
	}
	else if (ch == '*' || ch == '/') {
		return 2;
	}
	return 0;
}
char convert(char  ch) {
	if (ch == ')') {
		ch = '(';
	}
	else if (ch == '[') {
		ch = ']';
	}
	else if (ch == ']') {
		ch = '[';
	}
	else if (ch == '(') {
		ch = ')';
	}
	else if (ch == '{') {
		ch = '}';
	}
	return ch;
}
char* reverse(const char* arr) {
	char* line = new char[100];
	int size = strlen(arr);
	for (int i = 0; i < size; i++) {
		line[i] = arr[size - 1 - i];
	}
	line[size] = '\0';
	return line;
}
bool isOperator(const char ch) {
	return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}
bool isletter(char ch) {
	if (ch >= '0' && ch <= '9') {
		return true;
	}
	if (ch >= 'a' && ch <= 'z') {
		return true;
	}
	if (ch >= 'A' && ch <= 'Z') {
		return true;
	}
	return false;
}
char* infixtoprefix(char* expression) {
	myStack<char> S(20);
	char* prefixexpression = new char[100];
	expression = reverse(expression);
	int idx = 0;
	for (int i = 0; i < strlen(expression); i++) {
		char	ch = expression[i];
		ch = convert(ch);
		if (isletter(ch)) {
			prefixexpression[idx++] = ch;
		}
		else if (ch == '(' || ch == '{' || ch == '[') {
			S.push(ch);
			prefixexpression[idx++] = ' ';
		}
		else if (isOperator(ch)) {
			while (!S.isEmpty() && precedence(S.top()) >= precedence(ch)) {
				prefixexpression[idx++] = S.pop();

			}
			S.push(ch);
			prefixexpression[idx++] = ' ';
		}
		else if (ch == ')' || ch == '}' || ch == ']') {
			prefixexpression[idx++] = ' ';
			char topchar = S.top();
			while (!S.isEmpty() && !(topchar == '(' || topchar == '{' || topchar == '[')) {
				prefixexpression[idx++] = S.pop();
				topchar = S.top();
			}
			char value = S.pop();
		}




	}

	while (!S.isEmpty()) {
		prefixexpression[idx++] = S.pop();
	}

	delete[] expression;
	prefixexpression = reverse(prefixexpression);
	return prefixexpression;
}
int main()
{
	char express[100];
	cin.getline(express, 100);
	char* exp = infixtoprefix(express);
	cout << exp;

	return 0;
}