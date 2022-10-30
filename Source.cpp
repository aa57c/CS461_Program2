//CS 461 - Intro to AI 
//Program 2


#include <iostream>
#include <string>
#include <random>
#include <cmath>
#include <map>
#include <vector>
#include "Course.h"
#include "Functions.h"

using namespace std;


int main() {

	//vectors for classes, times, instructors, rooms (read only)
	 vector<string> times = {
		"10 AM", 
		"11 AM", 
		"12 NOON",
		"1 PM", 
		"2 PM", 
		"3 PM" };
	vector<pair<string, int>> classes = { 
		{"CS101A", 50}, 
		{"CS101B", 50},
		{"CS191A", 50}, 
		{"CS191B", 50}, 
		{"CS201", 50}, 
		{"CS291", 50}, 
		{"CS303", 60}, 
		{"CS304", 25}, 
		{"CS394", 20}, 
		{"CS449", 60}, 
		{"CS451", 100}};
	vector<string> instructors = { 
		"Gharibi", 
		"Gladbach", 
		"Hare", 
		"Nait-Abdesselam", 
		"Shah", 
		"Song", 
		"Uddin",
		"Xu", 
		"Zaman", 
		"Zein el Din" };
	vector<pair<string, int>> rooms = { 
		{"Katz 003", 45}, 
		{"FH 216", 30}, 
		{"Royall 206", 75}, 
		{"Royall 201", 50}, 
		{"FH 310", 108}, 
		{"Haag 201", 60}, 
		{"Haag 301", 75}, 
		{"MNLC 325", 450}, 
		{"Bloch 119", 60} };





	//map for randomly generated schedules
	map<int, vector<Course>> randSchedules;
	map<int, vector<Course>>::iterator it;

	//temporary variable for one random class
	Course Class;



	//generate 500+ (10 for testing rn) random schedules
	for (int count = 1; count <= 10; count++) {
		//temporary vector for random schedule
		vector<Course> schedule;

		//loop until all classes have been assigned times, teachers, and rooms
		for (int i = 1; i <= 11; i++) {
			//calls the generate random class function (which calls other functions for other random properties)
			Class = generateRandomClass(classes, times, instructors, rooms);
			//push back random class into temp vector
			schedule.push_back(Class);

		}
		//in case duplicate classes (THE EXACT SAME) in the same schedule  are made, remove them
		removeDuplicates(schedule);

		//add each random schedule to state space
		randSchedules.insert(make_pair(count, schedule));

	}

	SameRoomSameTimeAdjust(randSchedules);

	for (it = randSchedules.begin(); it != randSchedules.end(); it++) {
		int scheduleNumber = it->first;
		vector<Course> schedule = it->second;
		Fitness_Function(scheduleNumber, schedule);
	}



	//print out schedules
	/*
	for (it = randSchedules.begin(); it != randSchedules.end(); it++) {
		cout << "-----------------------------" << endl;
		cout << "Schedule: " << it->first << endl;
		vector<Course> schedule = it->second;
		cout << "Num of Classes: " << schedule.size() << endl;
		cout << "-----------------------------" << endl;
		cout << endl;
		for (int i = 0; i < schedule.size(); i++) {
			schedule.at(i).printCourseProperties();
			cout << endl;

		}

	}
	*/
	
	



	return 0;


}










