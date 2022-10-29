//CS 461 - Intro to AI 
//Program 2


#include <iostream>
#include <string>
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



void InstructorLoadFitnessCriteria(vector<Course>& schedule) {
	/* test print out statements before instructor load*/
	cout << "-----Pre Change: Instructor Load-----" << endl;
	cout << endl;
	for (int i = 0; i < schedule.size(); i++) {
		schedule.at(i).printCourseProperties();
	}

	map<string, pair<int, int>> instructorProps;
	map<string, pair<int, int>>::iterator it;
	pair<int, int> p = { 1, 1 };
	//loop through courses to determine course counts 
	for (int i = 0; i < schedule.size(); i++) {
		Course& course1 = schedule.at(i);
		bool first_time = false;
		//if course1 instructor is not in map (same as the map.end()), add it
		if (instructorProps.find(course1.getInstructor()) == instructorProps.end()) {
			instructorProps.insert(make_pair(course1.getInstructor(), p));
			first_time = true;
		}
		for (int j = i + 1; j < schedule.size(); j++) {
			Course& course2 = schedule.at(j);
			if (course1.getInstructor() == course2.getInstructor() &&
				course1.getTime() == course2.getTime()) {
				//first is count of courses with same instructor and same time
				instructorProps[course1.getInstructor()].first += 1;

			}
			if (course1.getInstructor() == course2.getInstructor() && first_time) {
				//second is count of courses with same instructor
				instructorProps[course1.getInstructor()].second += 1;

			}
			
		}
	}
	for (it = instructorProps.begin(); it != instructorProps.end(); it++) {
		cout << "Instructor: " << it->first << "-> " << it->second.first << ", " << it->second.second << endl;
	}
	//loop through courses to check for course counts and apply fitness
	for (int j = 0; j < schedule.size(); j++) {
		//first is count of courses with same instructor and same time
		if (instructorProps[schedule.at(j).getInstructor()].first == 1) {
			schedule.at(j).incFitnessScore(0.2);
		}
		if (instructorProps[schedule.at(j).getInstructor()].first > 1) {
			schedule.at(j).incFitnessScore(-0.2);
		}
		//second is count of courses with same instructor
		if (instructorProps[schedule.at(j).getInstructor()].second > 4) {
			schedule.at(j).incFitnessScore(-0.5);
		}
		if (instructorProps[schedule.at(j).getInstructor()].second < 3 &&
			schedule.at(j).getInstructor() != "Xu") {
			schedule.at(j).incFitnessScore(-0.4);
		}
		


	}




}

void PreferFacultyFitnessCritera(Course& course) {
	/* test print out statements before prefer faculty */
	//cout << "-----Pre Change: Prefer Faculty-----" << endl;
	//cout << endl;
	//course.printCourseProperties();
	vector<string> preF = course.getPreferredFaculty();
	vector<string> otherF = course.getOtherFaculty();
	int facultyFlag = 0;
	for (int p = 0; p < preF.size(); p++) {
		if (course.getInstructor() == preF.at(p) && facultyFlag == 0) {
			course.incFitnessScore(0.5);
			facultyFlag = 1;
			break;
		}
	}
	for (int o = 0; o < otherF.size(); o++) {
		if (course.getInstructor() == otherF.at(o) && facultyFlag == 0) {
			course.incFitnessScore(0.2);
			facultyFlag = 2;
			break;
		}
	}
	if (facultyFlag == 0) {
		course.incFitnessScore(-0.1);
	}

}


void RoomSizeFitnessCriteria(Course &course) {
	/* test print out statements before room size */
	//cout << "-----Pre Change: Room Size-----" << endl;
	//cout << endl;
	//course.printCourseProperties();
	if (course.getRoom().second < course.getCapacity()) {
		course.incFitnessScore(-0.5);
	}
	if (course.getRoom().second > course.getCapacity() * 3) {
		course.incFitnessScore(-0.2);
	}
	if (course.getRoom().second > course.getCapacity() * 6) {
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
				}
			}
			RoomSizeFitnessCriteria(course1);
			/* test print out statements after room size*/
			//cout << "--------Post Change: Room Size-------" << endl;
			//cout << endl;
			//course1.printCourseProperties();

			PreferFacultyFitnessCritera(course1);
			/* test print out statements after prefer faculty*/
			//cout << "--------Post Change: Prefer Faculty-------" << endl;
			//cout << endl;
			//course1.printCourseProperties();
			

		



			
			


		}
		//cout << "Schedule: " << i->first << endl;
		InstructorLoadFitnessCriteria(schedule);
		//cout << "------------------------" << endl;
		/*test print out statements after instructor load*/
		//cout << "-----Post Change: Instructor Load-----" << endl;
		//cout << endl;
		//for (int i = 0; i < schedule.size(); i++) {
			//schedule.at(i).printCourseProperties();
		//}
		
		

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










