#include <iostream>
#include <string>
#include "Course.h"

using namespace std;



int Course::makeTimeInt() {
	string temp = this->time;
	size_t i = 0;
	for (; i < this->time.length(); i++) {
		if (isdigit(this->time[i])) {
			break;
		}
	}
	temp = temp.substr(i, temp.length() - i);
	int newTime = atoi(temp.c_str());

	//convert am/pm to 24 time
	if (newTime >= 1 && newTime <= 3) {
		newTime += 12;
	}
	return newTime;


}
void Course::setPreferFaculty(string instructor) {
	this->preferFaculty.push_back(instructor);
}

void Course::setOtherFaculty(string instructor) {
	this->otherFaculty.push_back(instructor);
}
void Course::incFitnessScore(double f) {
	this->fitness_score += f;
}

void Course::setName(string n) {
	this->name = n;

}

void Course::setCapacity(int c) {
	this->capacity = c;
}


void Course::setTime(string t) {
	this->time = t;
}

void Course::setInstructor(string i) {
	this->instructor = i;
}

void Course::setRoom(pair<string, int> r) {
	this->room = r;
}

vector<string> Course::getPreferredFaculty() {
	return this->preferFaculty;
}
vector<string> Course::getOtherFaculty() {
	return this->otherFaculty;
}
double Course::getFitnessScore() {
	return this->fitness_score;
}

string Course::getName() {
	return this->name;

}

int Course::getCapacity() {
	return this->capacity;
}

string Course::getTime() {
	return this->time;
}

string Course::getInstructor() {
	return this->instructor;
}

pair<string, int> Course::getRoom() {
	return this->room;
}

void Course::printCourseProperties() {
	cout << "Class Name: " << this->name << " Capacity: " << this->capacity << endl;
	cout << "Instructor: " << this->instructor << endl;
	cout << "Room: " << this->room.first << " Capacity: " << this->room.second << endl;
	cout << "Time: " << this->time << endl;
	cout << "Fitness Score: " << this->fitness_score<< endl;
	cout << "Preferred Instructors: " << endl;
	for (int i = 0; i < this->preferFaculty.size(); i++) {
		cout << this->preferFaculty.at(i) << ", ";
	}
	cout << endl;
	cout << "Other Instructors: " << endl;
	for (int j = 0; j < this->otherFaculty.size(); j++) {
		cout << this->otherFaculty.at(j) << ", ";

	}
	cout << endl;
	cout << "************************" << endl;
}
