#pragma once

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

void read_stream(map<pair<int,int>,pair<bool,int> >&, ifstream &);

void change_sq(map<pair<int,int>,pair<bool,int> >&);

bool check_input(map<pair<int,int>,pair<bool,int>>);

set<pair<int,int> > get_LfBtsquare(int M, map<pair<int,int>,pair<bool,int> >);

void rand_input(int M ,int size_x, int size_y, ofstream & os);