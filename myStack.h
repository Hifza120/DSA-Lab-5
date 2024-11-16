#include"Stack.h"
template<typename T>
class myStack : public Stack<T> {
public:
	myStack(int size) :Stack<T>(size) {}
	myStack(const myStack<T>& S1) {
		Stack<T>::maxSize = S1.Stack<T>::maxSize;
		Stack<T>::currentSize = S1.Stack<T>::currentSize;
		Stack<T>::arr = new T[Stack<T>::maxSize];
		for (int i = 0; i < Stack<T>::currentSize; i++) {
			Stack<T>::arr[i] = S1.Stack<T>::arr[i];
		}
	}
	void push(T value) override {
		if (Stack<T>::currentSize == Stack<T>::maxSize) {
			cout << " Stack is Full " << endl;
		}
		else {
			Stack<T>::arr[Stack<T>::currentSize++] = value;
		}
	}
	T pop()override {
		if (Stack<T>::currentSize == 0) {
			cout << " Stack is Empty " << endl;
			return T();
		}
		else {
			return Stack<T>::arr[--Stack<T>::currentSize];
		}
	}
	T top()override {
		if (Stack<T>::currentSize == 0) {
			cout << " Stack is Empty " << endl;
			return T();
		}
		else {
			return Stack<T>::arr[Stack<T>::currentSize - 1];
		}
	}
	bool isEmpty() override {
		return Stack<T>::currentSize == 0;
	}
	bool isFull()override {
		return Stack<T>::currentSize == Stack<T>::maxSize;
	}
	void display() {
		for (int i = 0; i < Stack<T>::currentSize; i++) {
			cout << Stack<T>::arr[i] << "    \n";
		}
	}
};