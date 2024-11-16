#include"CircularQueue.h"
#include<string>

int main1() {
	int option;
	CircularQueue<string> Q(5);
	do {
		cout << "Enter your Option : ";
		cin >> option;
		cout << "1.	Add a customer to the queue." << endl;
		cout << "2.	Remove the first customer from the queue.  " << endl;
		cout << "3.Display the number of customers waiting in line" << endl;
		cout << "4.	View the first customer in the queue" << endl;
		cout << "5.	View the last customer in the queue " << endl;
		cout << "6.	Exit" << endl;
		if (option == 1) {
			string customer;
			cout << "Enter : ";
			cin.ignore();
			getline(cin, customer);
			Q.enqueue(customer);
		}
		else  if (option == 2) {
			Q.dequeue();
		}
		else  if (option == 3) {
			Q.display();
		}
		else  if (option == 4) {
			cout << " Front Element is : " << Q.frontElement() << endl;
		}
		else  if (option == 5) {
			cout << "Last Element is : " << Q.lastElement() << endl;
		}

	} while (option != 6);


	return 0;
}