#include"Queue.h"
template<typename T>
class LinearQueue : public Queue<T>{
public:
	LinearQueue(int maxSize) :Queue<T>(maxSize) {}
	void enqueue(T value)override {
		if (Queue<T>::maxSize == Queue<T>::currentSize) {
			cout << " Queue is Full " << endl;
		}
		else {
			Queue<T>::arr[Queue<T>::currentSize++] = value;
		}
	}
	T    dequeue()override {
		if (Queue<T>::currentSize == 0) {
			cout << " Queue is Empty" << endl;
			return T();
		}
		T value = Queue<T>::arr[0];
		for (int i = 0; i < Queue<T>::currentSize; i++) {
			Queue<T>::arr[i] = Queue<T>::arr[i + 1];
		}
		Queue<T>::currentSize--;
		return value;
	}
	T    peek()override {
		if (Queue<T>::currentSize == 0) {
			cout << " Queue is Empty" << endl;
			return T();
		}
		T value = Queue<T>::arr[0];
		for (int i = 0; i < Queue<T>::currentSize; i++) {
			Queue<T>::arr[i] = Queue<T>::arr[i + 1];
		}
		return value;
	}
	bool isFull()override {
		return Queue<T>::currentSize == Queue<T>::maxSize;
	}
	bool isEmpty()override {
		return Queue<T>::currentSize == 0;
	}
	void display() {
		for (int i = 0; i < Queue<T>::currentSize; i++) {
			Queue<T>::arr[i].display();
		}
	}
};