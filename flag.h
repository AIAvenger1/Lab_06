//
// Bohdan Petrov
// flag.h
//

#pragma once

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

const string DEFAULT_OUTPUT = "out.txt";

void help_flag();

bool get_args(int argc, char* argv[], string & input, string & output);