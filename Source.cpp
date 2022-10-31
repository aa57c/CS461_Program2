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

double AvgVector(vector<double> v) {
	double d = 0;
	for (int i = 0; i < v.size(); i++) {
		d += v.at(i);
	}
	return d / v.size();
}


int main() {
	srand(time(NULL));

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
	//first value of pair is the schedule number, second value of pair is the total_fitness for that schedule
	map<pair<int, double>, vector<Course>> randSchedules;
	map<pair<int, double>, vector<Course>>::iterator it;

	//temporary variable for one random class
	Course Class;



	//generate 500+ (10 for testing rn) random schedules
	for (int count = 0; count < 500; count++) {
		//temporary vector for random schedule
		vector<Course> schedule;

		//loop until all classes have been assigned times, teachers, and rooms
		for (int i = 1; i <= 11; i++) {
			//calls the generate random class function (which calls other functions for other random properties)
			Class = generateRandomClass(classes, times, instructors, rooms);
			//push back random class into temp vector
			schedule.push_back(Class);

		}
		//add each random schedule to state space
		randSchedules.insert(make_pair(make_pair(count, 0.0), schedule));

	}

	int gen_count = 0;
	int cumulative_child_count = 0;
	double avgFitness = 0;
	while (gen_count < 2) {

		cout << "Cume Child Count: " << cumulative_child_count << endl;
		SameRoomSameTimeAdjust(randSchedules);

		vector<double> total_fitness = Find_Total_Schedule_Fitnesses(randSchedules, it);


		vector<pair<double, double>> DistTable = SoftMax(total_fitness);

		avgFitness = AvgVector(total_fitness);

		cumulative_child_count += Genetic_Alg(randSchedules, DistTable, total_fitness);
		if (cumulative_child_count > 500) {
			gen_count++;
			cumulative_child_count -= 500;
		}
		

	}

	









	//print out schedules
	/*
	for (it = randSchedules.begin(); it != randSchedules.end(); it++) {
		cout << "-----------------------------" << endl;
		cout << "Schedule: " << it->first.first << ", Total Fitness: " << it->first.second << endl;
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










