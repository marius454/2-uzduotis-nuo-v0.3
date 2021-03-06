// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <chrono>
#include <list>
#include <deque>
#include <random>

struct studentai
{
	std::string vardas, pavarde;
	std::vector<int> paz;
	unsigned short int egz;
	double vid;
	double med;
};
bool acompare(studentai lhs, studentai rhs) { return lhs.pavarde < rhs.pavarde; }

bool maziau(studentai a) { return a.vid < 6;}
bool daugiau(studentai a) { return a.vid >= 6; }

void failu_kurimas(int m);

void vectorveiksmai(std::vector<studentai>& stud, unsigned short int nr, unsigned int nd);
void listveiksmai(std::list<studentai>& stud1, unsigned short int nr, unsigned int nd);
void dequeveiksmai(std::deque<studentai>& stud1, unsigned short int nr, unsigned int nd);

void vectorveiksmai2(std::vector<studentai>& stud, unsigned short int nr, unsigned int nd);
void listveiksmai2(std::list<studentai>& stud1, unsigned short int nr, unsigned int nd);
void dequeveiksmai2(std::deque<studentai>& stud1, unsigned short int nr, unsigned int nd);



// TODO: reference additional headers your program requires here
