#include"LinearQueue.h"
class Student {
	string name;
	float score;
	float timetaken;
public:
	Student() {}
	Student(const string & name):name(name),score(0),timetaken(0){}
	void setScore(float score) {
		this->score = score;
	}
	void settimetaken(float timetaken) {
		this->timetaken = timetaken;
	}
	string getname() {
		return name;
	}
	float getScore() {
		return score;
	}
	float getTimetaken() {
		return timetaken;
	}
	void display() {
		cout << name << "\t" << score << "\t" << timetaken << endl;
	}
};
int main1() {
	LinearQueue<Student> waitingQueue(5);
	LinearQueue<Student> newQueue(5);
	int option;
	do {
		cout << "Enter Option   \t";
		cin >> option;
		cout << "	Add a student to the waiting queue" << endl;
		cout << "Start the quiz and generate scores" << endl;
		cout << "Display the scores, name and time taken by the students" << endl;
		cout << "Exit" << endl;
			if (option==1){
				string name;
				cout << "Enter Name :  ";
				cin >> name;
				Student S1(name);
				waitingQueue.enqueue(S1);

			}
			else if (option == 2) {
				while (!waitingQueue.isEmpty()) {
					Student S = waitingQueue.dequeue();
					S.setScore(rand() % 100);
					S.settimetaken(rand() % 60);
					newQueue.enqueue(S);
				}
				if (waitingQueue.isEmpty()) {
					cout << " quiz is ended.\n";
				}


			}
			else if (option == 3) {
				newQueue.display();
			}

	} while (option != 4);

	return 0;
}