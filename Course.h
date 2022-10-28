#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Course {
private:
	string name;
	int capacity;
	string time;
	string instructor;
	pair<string, int> room;
	double fitness_score;
	vector<string> preferFaculty;
	vector<string> otherFaculty;
public:
	Course() {
		this->name = "";
		this->capacity = 0;
		this->time = "";
		this->instructor = "";
		this->room = {};
		this->fitness_score = 0.0;
		this->preferFaculty = {};
		this->otherFaculty = {};
	}
	void setPreferFaculty(string instructor);
	void setOtherFaculty(string instructor);
	void setName(string n);
	void setCapacity(int c);
	void setTime(string t);
	void setInstructor(string i);
	void setRoom(pair<string, int> r);
	void incFitnessScore(double f);
	void printCourseProperties();

	string getName();
	int getCapacity();
	string getTime();
	string getInstructor();
	pair<string, int> getRoom();
	double getFitnessScore();
	vector<string> getPreferredFaculty();
	vector<string> getOtherFaculty();



};
