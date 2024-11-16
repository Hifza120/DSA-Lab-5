#include<iostream>
using namespace std;
template<typename T>
class Stack {
protected:
	T* arr;
	int maxSize;
	int currentSize;
public:
	Stack() {}
	Stack(int size) :maxSize(size), currentSize(0) {
		arr = new T[maxSize];
	}
	virtual T pop() = 0;
	virtual T top() = 0;
	virtual void push(T value) = 0;
	virtual  bool isEmpty() = 0;
	virtual bool isFull() = 0;

	~Stack() {
		delete[] arr;
	}

};