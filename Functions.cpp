#include <iostream>
#include <string>
#include <set>
#include <random>
#include <queue>
#include <cmath>
#include <map>
#include <vector>
#include "Course.h"
#include "Functions.h"

//function for generating random class name
pair<string, int> generateRandomClassName(vector<pair<string, int>> classes, int size) {
	//srand(1);
	int randIndex = rand() % size;
	return classes.at(randIndex);


}

//function for generating random time
string generateRandomTime(vector<string> times, int size) {
	//srand(1);
	int randIndex = rand() % size;
	return times.at(randIndex);

}

//function for generating random instructor
string generateRandomInstructor(vector<string> instructors, int size) {
	//srand(1);
	int randIndex = rand() % size;
	return instructors.at(randIndex);

}

//function for generating random room
pair<string, int> generateRandomRoom(vector<pair<string, int>> rooms, int size) {
	//srand(time(0));
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



void setPreferredFaculty(map<pair<int, double>, vector<Course>>& schedules,
	map<pair<int, double>, vector<Course>>::iterator i) {
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

void CourseSpecificFitnessAdjust(vector<Course>& schedule) {
	map<string, vector<int>> CourseAndTime;
	map<string, vector<int>>::iterator it;
	map<string, vector<int>>::iterator it2;

	/*test before course specific criteria
	//cout << "--------Pre Change: Course Specific---------" << endl;
	//for (int i = 0; i < schedule.size(); i++) {
		//if (schedule.at(i).getName().substr(0, 5) == "CS101" || schedule.at(i).getName().substr(0, 5) == "CS191") {
			//schedule.at(i).printCourseProperties();
		//}
	}
	*/

	//if the course name is any of these, insert it into data structure with its name and time
	for (int i = 0; i < schedule.size(); i++) {
		Course& course = schedule.at(i);
		//cout << "OG: " << course.getName() << "Chng: " << course.getName().substr(0, 5) << endl;
		if (course.getName().substr(0, 5) == "CS101" || course.getName().substr(0, 5) == "CS191") {
			vector<int> v = { course.makeTimeInt(), -1, -1, 0 };
			CourseAndTime.insert(make_pair(course.getName(), v));
			//checks course 1 and course 2 rooms (if one is in Katz or Bloch, and the other isnt)
			for (int j = i + 1; j < schedule.size(); j++) {
				Course& course2 = schedule.at(j);
				string room1 = course.getRoom().first.substr(0, course.getRoom().first.find(' '));
				string room2 = course2.getRoom().first.substr(0, course.getRoom().first.find(' '));
				//value at index 3 is room difference
				if ((room1 == "Katz" || room1 == "Bloch") && (room2 != "Katz" && room2 != "Bloch")) {
					CourseAndTime[course.getName()].at(3) = 1;
					//CourseAndTime[course2.getName()].at(3) = CourseAndTime[course.getName()].at(3);
				}
			}
		}


	}

	for (it = CourseAndTime.begin(); it != CourseAndTime.end(); it++) {
		string course1 = it->first;
		for (it2 = CourseAndTime.begin(); it2 != CourseAndTime.end(); it2++) {
			string course2 = it2->first;
			//match course name (first four characters) with different sections (last character)
			if (course1.substr(0, 5) == course2.substr(0, 5) && (course1.back() != course2.back())) {
				//value at index = 1 is section time difference
				CourseAndTime[course1].at(1) = abs(CourseAndTime[course1].at(0) - CourseAndTime[course2].at(0));
				CourseAndTime[course2].at(1) = CourseAndTime[course1].at(1);
			}
			//different course name (first four characters) 
			if (course1.substr(0, 5) != course2.substr(0, 5)) {
				//value at index = 2 is the course time difference
				CourseAndTime[course1].at(2) = abs(CourseAndTime[course1].at(0) - CourseAndTime[course2].at(0));
				CourseAndTime[course2].at(2) = CourseAndTime[course1].at(2);
			}
		}
	}


	/*
	cout << "------Course and Time Map (CourseSpecificFitnessCriteria)--------" << endl;
	for (it = CourseAndTime.begin(); it != CourseAndTime.end(); it++) {

		cout << it->first << ", Time: " << it->second.at(0) << ", Sect_Diff: " << it->second.at(1) << ", Course_Diff: " << it->second.at(2) << ", Room_Diff: " << it->second.at(3) << endl;

	}
	cout << "-------------------------------------------" << endl;
	cout << endl;
	*/
	//fitness criteria is applied here
	for (int i = 0; i < schedule.size(); i++) {
		Course& course = schedule.at(i);
		//finds course name CS101 and CS191 in map
		if (CourseAndTime.find(course.getName()) != CourseAndTime.end()) {
			//if both sections of the same course are in the same time slot
			if (CourseAndTime[course.getName()].at(1) == 0) {
				course.incFitnessScore(-0.5);
			}
			//if both sections of the same course are more than 4 hours apart
			if (CourseAndTime[course.getName()].at(1) > 4) {
				course.incFitnessScore(0.5);
			}
			//if any section of 101 or 191 are in the same time slot
			if (CourseAndTime[course.getName()].at(2) == 0) {
				course.incFitnessScore(-0.25);
			}
			//if any section of 101 or 191 are in consecutive time slots
			if (CourseAndTime[course.getName()].at(2) == 1) {
				if (CourseAndTime[course.getName()].at(3) == 1) {
					course.incFitnessScore(-0.4);

				}
				else {
					course.incFitnessScore(0.5);
				}

			}
			//if any section of 101 or 191 are taught 2 hours apart
			if (CourseAndTime[course.getName()].at(2) == 2) {
				course.incFitnessScore(0.25);
			}

		}


	}





}


void InstructorLoadFitnessAdjust(vector<Course>& schedule) {
	/* test print out statements before instructor load*/
	/*
	cout << "-----Pre Change: Instructor Load-----" << endl;
	cout << endl;
	for (int i = 0; i < schedule.size(); i++) {
		schedule.at(i).printCourseProperties();
	}
	*/

	map<string, vector<int>> instructorProps;
	//map<string, vector<int>>::iterator it;
	//loop through courses to determine course counts 
	for (int i = 0; i < schedule.size(); i++) {
		Course& course1 = schedule.at(i);
		bool first_time = false;
		//if course1 instructor is not in map (same as the map.end()), add it
		if (instructorProps.find(course1.getInstructor()) == instructorProps.end()) {
			vector<int> v = { 1, 1 };
			instructorProps.insert(make_pair(course1.getInstructor(), v));
			first_time = true;
		}
		for (int j = i + 1; j < schedule.size(); j++) {
			Course& course2 = schedule.at(j);
			string room1 = course1.getRoom().first.substr(0, course1.getRoom().first.find(' '));
			string room2 = course2.getRoom().first.substr(0, course2.getRoom().first.find(' '));
			if (course1.getInstructor() == course2.getInstructor() &&
				course1.getTime() == course2.getTime()) {
				//at index 0 is count of courses with same instructor and same time
				instructorProps[course1.getInstructor()].at(0) += 1;

			}
			if (course1.getInstructor() == course2.getInstructor() && first_time) {
				//at index 1 is count of courses with same instructor
				instructorProps[course1.getInstructor()].at(1) += 1;

			}

		}
	}
	/*
	for (it = instructorProps.begin(); it != instructorProps.end(); it++) {
		cout << "Instructor: " << it->first << "-> " << it->second.first << ", " << it->second.second << endl;
	}
	*/
	//loop through courses to check for course counts and apply fitness
	for (int j = 0; j < schedule.size(); j++) {
		//at index 0 is count of courses with same instructor and same time
		if (instructorProps[schedule.at(j).getInstructor()].at(0) == 1) {
			schedule.at(j).incFitnessScore(0.2);
		}
		if (instructorProps[schedule.at(j).getInstructor()].at(0) > 1) {
			schedule.at(j).incFitnessScore(-0.2);
		}
		//at index 1 is count of courses with same instructor
		if (instructorProps[schedule.at(j).getInstructor()].at(1) > 4) {
			schedule.at(j).incFitnessScore(-0.5);
		}
		if (instructorProps[schedule.at(j).getInstructor()].at(1) < 3 &&
			schedule.at(j).getInstructor() != "Xu") {
			schedule.at(j).incFitnessScore(-0.4);
		}




	}




}

void PreferFacultyFitnessAdjust(Course& course) {
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


void RoomSizeFitnessAdjust(Course& course) {
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


void SameRoomSameTimeAdjust(map<pair<int, double>, vector<Course>>& schedules) {

	cout << "Schedule size: " << schedules.size() << endl;
	map<pair<int, double>, vector<Course>>::iterator i;

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
			RoomSizeFitnessAdjust(course1);
			/* test print out statements after room size*/
			//cout << "--------Post Change: Room Size-------" << endl;
			//cout << endl;
			//course1.printCourseProperties();

			PreferFacultyFitnessAdjust(course1);
			/* test print out statements after prefer faculty*/
			//cout << "--------Post Change: Prefer Faculty-------" << endl;
			//cout << endl;
			//course1.printCourseProperties();










		}
		//cout << "Schedule: " << i->first << endl;
		InstructorLoadFitnessAdjust(schedule);
		//cout << "------------------------" << endl;
		/*test print out statements after instructor load*/
		//cout << "-----Post Change: Instructor Load-----" << endl;
		//cout << endl;
		//for (int i = 0; i < schedule.size(); i++) {
			//schedule.at(i).printCourseProperties();
		//}
		CourseSpecificFitnessAdjust(schedule);

		/*test print out statements after course specific criteria
		cout << "--------Post Change: Course Specific---------" << endl;
		for (int i = 0; i < schedule.size(); i++) {
			if (schedule.at(i).getName().substr(0, 5) == "CS101" || schedule.at(i).getName().substr(0, 5) == "CS191") {
				schedule.at(i).printCourseProperties();
			}
		}
		*/




	}

	cout << "End of SameRoomSameTime()" << endl;




}

vector<pair<double, double>> SoftMax(vector<double>& total_fitness) {
	vector<double> Exponen;
	double Sum = 0.0;
	vector<double> probabilities;
	vector<pair<double, double>> distributionTable;
	/*
	cout << "----Fitness Scores for Each Schedule-----" << endl;
	for (int f = 0; f < total_fitness.size(); f++) {
		cout << "Schedule: " << f + 1 << ", Fitness: " << total_fitness.at(f) << endl;

	}
	*/
	//cout << endl;
	//cout << endl;
	for (int i = 0; i < total_fitness.size(); i++) {
		Exponen.push_back(exp(total_fitness.at(i)));
	}
	/*
	cout << "-------Exponentials for Each Schedule-------" << endl;
	for (int e = 0; e < Exponen.size(); e++) {
		cout << "Schedule: " << e + 1 << ", Exponential: " << Exponen.at(e) << endl;

	}
	*/
	//cout << endl;
	//cout << endl;
	for (int j = 0; j < Exponen.size(); j++) {
		Sum += Exponen.at(j);
	}
	//cout << "Sum of Exponents: " << Sum << endl;
	//cout << endl;
	for (int k = 0; k < Exponen.size(); k++) {
		double probability = Exponen.at(k) / Sum;
		probabilities.push_back(probability);
	}
	/*
	cout << "-----Probabilities for Each Schedule-------" << endl;
	for (int p = 0; p < probabilities.size(); p++) {
		cout << "Schedule: " << p + 1 << ", Exponential: " << probabilities.at(p) << endl;


	}
	*/

	for (int p = 0; p < probabilities.size(); p++) {
		//cout << "Schedule: " << p + 1 << ", Exponential: " << probabilities.at(p) << endl;
		if (p == 0) {
			distributionTable.push_back(make_pair(probabilities.at(p), probabilities.at(p)));
		}
		else {
			distributionTable.push_back(make_pair(probabilities.at(p), distributionTable.at(p - 1).second + probabilities.at(p)));
		}

	}

	cout << "Schedule\t| " << "P(n)\t| " << "Cumulative P(n)\t| " << endl;
	cout << endl;
	for (int d = 0; d < distributionTable.size(); d++) {
		cout << d + 1 << "\t| " << distributionTable.at(d).first << "\t| " << distributionTable.at(d).second << endl;
	}


	


	return distributionTable;

}

vector<double> Find_Total_Schedule_Fitnesses(map<pair<int, double>, vector<Course>>& schedules, map<pair<int, double>, vector<Course>>::iterator it) {
	//calculates the fitness for all schedules (indexes line up with randSchedules map)
	double fitness = 0;
	vector<double> total_fitness;
	for (it = schedules.begin(); it != schedules.end(); it++) {
		vector<Course> schedule = it->second;
		//cout << "Schedule: " << it->first.first << endl;
		//cout << "-----------------" << endl;
		for (int i = 0; i < schedule.size(); i++) {
			fitness += schedule.at(i).getFitnessScore();
			//cout << "Fitness after Course " << i + 1 << ": " << fitness << endl;
			//cout << endl;

		}
		//cout << endl;
		//cout << "Total Fitness for Schedule " << it->first.first << ": " << fitness << endl;
		total_fitness.push_back(fitness);
		fitness = 0;

	}
	//because indexes in total fitness vector line up with map, remove old key and value from initialization and replace it with total fitness score
	for (int i = 0; i < total_fitness.size(); i++) {
		auto node = schedules.extract(make_pair(i, 0.0));
		if (!node.empty()) {
			node.key() = make_pair(i, total_fitness.at(i));
			schedules.insert(move(node));
		}
	}
	return total_fitness;

}

int Genetic_Alg(map<pair<int, double>, vector<Course>>& schedules, vector<pair<double, double>> dist, vector<double> fitness_scores) {

	//flag if found 2 parents to make a child
	int found = 0;
	//double randSched2 = rand() / static_cast<double>(RAND_MAX);

	//iterator for schedules
	map<pair<int, double>, vector<Course>>::iterator s;

	//children variables
	map<pair<int, double>, vector<Course>> children;
	vector<Course> childCourses;
	map<pair<int, double>, vector<Course>>::iterator ch;
	//parent variables
	map<pair<int, double>, vector<Course>> parents;
	map<pair<int, double>, vector<Course>>::iterator p;

	//one schedule picked as a parent
	pair<pair<int, double>, vector<Course>> parent;



	double randParent = rand() / static_cast<double>(RAND_MAX);
	for (int i = 0; i < dist.size(); i++) {
		//picks parents according to cumulative probability
		if (randParent < dist.at(i).second) {
			parent = make_pair(make_pair(i, fitness_scores.at(i)), schedules[make_pair(i, fitness_scores.at(i))]);
			parents.insert(parent);

		}
	}
	cout << "Size of Parents: " << parents.size() << endl;
	//represents parent count
	
	int count = 1;
	int child = schedules.size();
	for (p = parents.begin(); p != parents.end(); p++) {
		vector<Course>& parentCourses = p->second;
		if (count == 1) {
			for (int i = 1; i <= 5; i++) {
				int randCourse = rand() % parentCourses.size();
				childCourses.push_back(parentCourses.at(randCourse));
			}
		}
		else if (count == 2) {
			for (int i = 1; i <= 6; i++) {
				int randCourse = rand() % parentCourses.size();
				childCourses.push_back(parentCourses.at(randCourse));

			}
			for (int i = 0; i < childCourses.size(); i++) {
				childCourses.at(i).resetFitnessScore();
			}
			if (childCourses.size() == 0) {
				cout << "Child does not have courses" << endl;
			}
			children.insert(make_pair(make_pair(child, 0.0), childCourses));
			child++;
			count = 0;

		}
		count++;


	}
	cout << "Size of Children: " << children.size() << endl;



	
	//remove weakest schedule
	for (int i = 0; i < children.size(); i++) {
		schedules.erase(make_pair(i, fitness_scores.at(i)));

	}

	cout << "After removal of Weakest -> Size of Schedule: " << schedules.size() << endl;

	//resetting key for all surviving parents 
	for (int i = 0; i < schedules.size(); i++) {
		auto node = schedules.extract(make_pair(i, fitness_scores.at(i)));
		if (!node.empty()) {
			node.key() = make_pair(i, 0.0);
			schedules.insert(move(node));
		}
	}

	//add children back into original population
	schedules.insert(children.begin(), children.end());

	cout << "After adding Children -> Size of Schedule: " << schedules.size() << endl;




	return children.size();




	





}




