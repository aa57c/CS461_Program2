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

//void removeDuplicates(vector<Course>& schedule);

void setPreferredFaculty(map<pair<int, double>, vector<Course>>& schedules,
	map<int, vector<Course>>::iterator i);

void CourseSpecificFitnessAdjust(vector<Course>& schedule);

void InstructorLoadFitnessAdjust(vector<Course>& schedule);

void PreferFacultyFitnessAdjust(Course& course);

void RoomSizeFitnessAdjust(Course& course);

void SameRoomSameTimeAdjust(map<pair<int, double>, vector<Course>>& schedules);

int Genetic_Alg(map<pair<int, double>, vector<Course>>& schedules, vector<pair<double, double>> dist, vector<double> fitness_scores);

vector<pair<double, double>> SoftMax(vector<double>& total_fitness);

vector<double> Find_Total_Schedule_Fitnesses(map<pair<int, double>, vector<Course>>& schedules, map<pair<int, double>, vector<Course>>::iterator it);
