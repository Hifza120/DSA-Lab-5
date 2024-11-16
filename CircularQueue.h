#include"Queue.h"
using namespace std;
template<typename T>
class CircularQueue:public Queue<T> {
private:
	int front;
	int rear;
public:
	CircularQueue(int size):Queue<T>(size),front(0),rear(0) {}
	bool isFull() {
		return 		Queue<T>::maxSize == Queue<T>::currentSize;
	}
	bool isEmpty() {
		return   Queue<T>::currentSize == 0;
	}
	void enqueue( T value )override {
		if (isFull()) {
			cout << " Queue is Full " << endl;
		}
	
			Queue<T>::arr[rear % Queue<T>::maxSize] = value;
			rear++;
			Queue<T>::currentSize++;
	
	}
	T dequeue()override {
		if (isEmpty()) {
			cout << "Queue is Empty " << endl;
			return T();
		}
		T value = Queue<T>::arr[front % Queue<T>::maxSize];
		front++;
		Queue<T>::currentSize--;
		return value;

	}
	T peek()override {
		if (isEmpty()) {
			cout << "Queue is Empty " << endl;
			return T();
		}
		T value = Queue<T>::arr[front % Queue<T>::maxSize];
		return value;

	}
	void display() {
		cout << " maxSize : " << Queue<T>::maxSize << endl;
		cout << "currentSize : " << Queue<T>::currentSize << endl;
		cout << "front : " << front << endl;
		cout << "rear : " << rear << endl;
		for (int i = front; i < rear; i++) {
			cout << i % Queue<T>:: maxSize << " . ";
			cout << Queue<T>::arr[i % Queue<T>::maxSize] << endl;
		}
		cout << endl;
	}
	T frontElement() {
		if (isEmpty()) {
			cout << "Queue is Empty " << endl;
			return T();
		}
		T value = Queue<T>::arr[front % Queue<T>::maxSize];
		return value;

	}
	T lastElement(){
		if (isEmpty()) {
			cout << "Queue is Empty " << endl;
			return T();
		}
		T value = Queue<T>::arr[rear -1% Queue<T>::maxSize];
		return value;

	}

};