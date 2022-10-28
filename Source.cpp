//CS 461 - Intro to AI 
//Program 2


#include <iostream>
#include <random>
#include <map>
#include <vector>
#include "Course.h"

using namespace std;
//function for generating random class name

pair<string, int> generateRandomClassName(vector<pair<string, int>> classes, int size){
	int randIndex = rand() % size;
	return classes.at(randIndex);


}

//function for generating random time
string generateRandomTime(vector<string> times, int size) {
	int randIndex = rand() % size;
	return times.at(randIndex);

}

//function for generating random instructor
string generateRandomInstructor(vector<string> instructors, int size) {
	int randIndex = rand() % size;
	return instructors.at(randIndex);

}

//function for generating random room
pair<string, int> generateRandomRoom(vector<pair<string, int>> rooms, int size) {
	int randIndex = rand() % size;
	return rooms.at(randIndex);

}

//function for generating random class (includes room, instructor, and time)
Course generateRandomClass(
	vector<pair<string, int>> classes, 
	vector<string> times,
	vector<string> instructors,
	vector<pair<string, int>> rooms) {

	//temporary variable for one class
	Course Class;

	//temporary variables for random classes, times, rooms, and instructors
	pair<string, int> course;
	string time;
	pair<string, int> room;
	string instructor;

	course = generateRandomClassName(classes, classes.size());
	time = generateRandomTime(times, times.size());
	room = generateRandomRoom(rooms, rooms.size());
	instructor = generateRandomInstructor(instructors, instructors.size());

	Class.setName(course.first);
	Class.setCapacity(course.second);
	Class.setInstructor(instructor);
	Class.setTime(time);
	Class.setRoom(room);

	return Class;



}

//function to remove duplicates from schedule in case of them
void removeDuplicates(vector<Course>& schedule) {
	vector<Course>::iterator it;
	vector<Course>::iterator it2;

	for (it = schedule.begin(); it < schedule.end(); it++) {
		Course &course = *it;
		for (it2 = it + 1; it2 < schedule.end(); it2++) {
			if ((course.getName() == it2->getName()) &&
				(course.getCapacity() == it2->getCapacity()) &&
				(course.getInstructor() == it2->getInstructor()) &&
				(course.getRoom() == it2->getRoom()) &&
				(course.getTime() == it2->getTime())) {
				schedule.erase(it2);
			}
		}
	}


}

//fitness function defined here? (probably will put this in a header file and in its own file)

void RoomSizeCritera(Course& course) {
	if (course.getRoom().second < course.getCapacity()) {
		course.incFitnessScore(-0.5);
	}
	else if (course.getRoom().second > course.getCapacity() * 3) {
		course.incFitnessScore(-0.2);


	}
	else if (course.getRoom().second > course.getCapacity() * 6) {
		course.incFitnessScore(-0.4);
	}
	else {
		course.incFitnessScore(0.3);

	}

}

void setPreferredFaculty(map<int, vector<Course>>& schedules, 
	map<int, vector<Course>>::iterator i) {
	for (i = schedules.begin(); i != schedules.end(); i++) {
		vector<Course>& schedule = i->second;
		for (int j = 0; j < schedule.size(); j++) {
			Course& course = schedule.at(j);
			if (course.getName() == "CS101A" || 
				course.getName() == "CS101B" ||
				course.getName() == "CS191A" || 
				course.getName() == "CS191B") {
				course.setPreferFaculty("Gladbach");
				course.setPreferFaculty("Gharibi");
				course.setPreferFaculty("Hare");
				course.setPreferFaculty("Zein el Din");
				course.setOtherFaculty("Zaman");
				course.setOtherFaculty("Nait-Abdesselam");
				
			}
			else if (course.getName() == "CS201") {
				course.setPreferFaculty("Gladbach");
				course.setPreferFaculty("Hare");
				course.setPreferFaculty("Zein el Din");
				course.setPreferFaculty("Shah");
				course.setOtherFaculty("Zaman");
				course.setOtherFaculty("Nait-Abdesselam");
				course.setOtherFaculty("Song");
			}
			else if (course.getName() == "CS291") {
				course.setPreferFaculty("Gharibi");
				course.setPreferFaculty("Hare");
				course.setPreferFaculty("Zein el Din");
				course.setPreferFaculty("Song");
				course.setOtherFaculty("Zaman");
				course.setOtherFaculty("Nait-Abdesselam");
				course.setOtherFaculty("Shah");
				course.setOtherFaculty("Xu");


			}
			else if (course.getName() == "CS303") {
				course.setPreferFaculty("Gladbach");
				course.setPreferFaculty("Hare");
				course.setPreferFaculty("Zein el Din");
				course.setOtherFaculty("Zaman");
				course.setOtherFaculty("Shah");
				course.setOtherFaculty("Song");

			}
			else if (course.getName() == "CS394") {
				course.setPreferFaculty("Xu");
				course.setPreferFaculty("Song");
				course.setOtherFaculty("Nait-Abdesselam");
				course.setOtherFaculty("Zein el Din");
			}
			else if (course.getName() == "CS449") {
				course.setPreferFaculty("Xu");
				course.setPreferFaculty("Song");
				course.setPreferFaculty("Shah");
				course.setOtherFaculty("Zein el Din");
				course.setOtherFaculty("Uddin");

			}
			else if (course.getName() == "CS451") {
				course.setPreferFaculty("Xu");
				course.setPreferFaculty("Song");
				course.setPreferFaculty("Shah");
				course.setOtherFaculty("Zein el Din");
				course.setOtherFaculty("Uddin");
				course.setOtherFaculty("Nait-Abdesselam");
				course.setOtherFaculty("Hare");
				
			}
			else if (course.getName() == "CS304") {
				course.setPreferFaculty("Gladbach");
				course.setPreferFaculty("Hare");
				course.setPreferFaculty("Xu");
				course.setOtherFaculty("Zein el Din");
				course.setOtherFaculty("Uddin");
				course.setOtherFaculty("Zaman");
				course.setOtherFaculty("Song");
				course.setOtherFaculty("Nait-Abdesselam");
				course.setOtherFaculty("Shah");




			}

		}
	}



}


void RoomSizeFitnessCriteria(Course &course) {
	if (course.getRoom().second < course.getCapacity()) {
		course.incFitnessScore(-0.5);
	}
	else if (course.getRoom().second > course.getCapacity() * 3) {
		course.incFitnessScore(-0.2);
	}
	else if (course.getRoom().second > course.getCapacity() * 6) {
		course.incFitnessScore(-0.4);
	}
	else {
		course.incFitnessScore(0.3);
	}

}

void ClassFitnessCriteria(map<int, vector<Course>> &schedules) {
	map<int, vector<Course>>::iterator i;

	setPreferredFaculty(schedules, i);

	for (i = schedules.begin(); i != schedules.end(); i++) {
		vector<Course>& schedule = i->second;
		for (int j = 0; j < schedule.size(); j++) {
			Course& course1 = schedule.at(j);
			for (int k = j + 1; k < schedule.size(); k++) {
				Course& course2 = schedule.at(k);
				if (course1.getRoom() == course2.getRoom() &&
					course1.getTime() == course2.getTime()) {
					course1.incFitnessScore(-0.5);
					course2.incFitnessScore(-0.5);
				}
			}
			RoomSizeCritera(course1);

			//fitness criteria for preferred and other faculty (NOT WORKING!)
			/*
			cout << "-----Pre Change-----" << endl;
			cout << endl;
			course1.printCourseProperties();
			vector<string> preF = course1.getPreferredFaculty();
			vector<string> otherF = course1.getOtherFaculty();
			for (int l = 0; l < preF.size(); l++) {
				for (int m = 0; m < otherF.size(); m++) {
					if (course1.getInstructor() == preF.at(l)) {
						course1.incFitnessScore(0.5);
						break;
					}
					if (course1.getInstructor() == otherF.at(m)) {
						course1.incFitnessScore(0.2);
						break;
					}
					else {
						course1.incFitnessScore(-0.1);
						break;
					}

					

				}


			}


			cout << "--------Post Change-------" << endl;
			cout << endl;
			course1.printCourseProperties();
			*/


		}
	}





}




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

	ClassFitnessCriteria(randSchedules);



	//print out schedules

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
	
	



	return 0;


}










