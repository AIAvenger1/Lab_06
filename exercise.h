#pragma once

//
// Bohdan Petrov
// exercise.cpp
//

#include <map>
#include <iostream>
#include <fstream>
#include <set>

using std::map;
using std::pair;
using std::vector;
using std::set;
using std::endl;
using std::ifstream;
using std::ofstream;

void read_stream(map<pair<int,int>,pair<bool,int> >&, ifstream &); // reads input file and put input inside map

void change_sq(map<pair<int,int>,pair<bool,int> >&); // for each points finds the biggest square it is locating in

bool check_input(map<pair<int,int>,pair<bool,int>>); // check if given set of points creates continuous square

set<pair<int,int> > get_LfBtsquare(int M, map<pair<int,int>,pair<bool,int> >); // returns left-bottom point for each MxM square that aren't inside bigger one

void rand_input(int M ,int size_x, int size_y, ofstream & os); // for easier check of algorithm and given code