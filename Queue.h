#include<iostream>
using namespace std;
template<typename T>
class Queue {
protected:
	T* arr;
	int maxSize;
	int currentSize;
public:
	Queue(int size):maxSize(size) ,currentSize(0){
		arr = new T[maxSize];
	}
	virtual T dequeue() = 0;
	virtual void enqueue(T value) = 0;
	virtual  bool isEmpty() = 0;
	virtual bool isFull() = 0;
	virtual T peek() = 0;
	~Queue() {
		delete[] arr;
		arr = nullptr;
	}
};
