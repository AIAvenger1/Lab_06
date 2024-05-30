//
// Bohdan Petrov
// flag.cpp
//

#include "flag.h"

void help_flag()
{
    cout << "usage ./lab -i INPUT_FILE [-o OUTPUT_FILE]\n" 
        << "    -i INPUT_FILE  - path to input file\n"
        << "    -o OUTPUT_FILE - path to output file, default '" << DEFAULT_OUTPUT << "'\n" << endl;
}

bool get_args(int argc, char* argv[], string & input, string & output)
{
    if(argc < 3) return false;
    input = ""; // no def value
    output = DEFAULT_OUTPUT;
    for(int i = 1; i < argc; ++i)
    {
        if (strcmp(argv[i], "-i") == 0)
        {
            if (i >= argc - 1){
                return false;
            }
            input = argv[++i];
        }

        if (strcmp(argv[i], "-o") == 0)
        {
            if (i >= argc - 1){
                return false;
            }
            output = argv[++i];
        }
    }

    return input != "";
}