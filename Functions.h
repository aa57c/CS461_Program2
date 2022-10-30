#pragma once
#include <iostream>
#include <string>
#include <random>
#include <cmath>
#include <map>
#include <vector>
#include "Course.h"

using namespace std;

pair<string, int> generateRandomClassName(vector<pair<string, int>> classes, int size);

string generateRandomTime(vector<string> times, int size);

string generateRandomInstructor(vector<string> instructors, int size);

pair<string, int> generateRandomRoom(vector<pair<string, int>> rooms, int size);

Course generateRandomClass(
	vector<pair<string, int>> classes,
	vector<string> times,
	vector<string> instructors,
	vector<pair<string, int>> rooms);

void removeDuplicates(vector<Course>& schedule);

void setPreferredFaculty(map<int, vector<Course>>& schedules,
	map<int, vector<Course>>::iterator i);

void CourseSpecificFitnessAdjust(vector<Course>& schedule);

void InstructorLoadFitnessAdjust(vector<Course>& schedule);

void PreferFacultyFitnessAdjust(Course& course);

void RoomSizeFitnessAdjust(Course& course);

void SameRoomSameTimeAdjust(map<int, vector<Course>>& schedules);

int Fitness_Function(map<int, vector<Course>>& schedules, map<int, vector<Course>>::iterator i);
