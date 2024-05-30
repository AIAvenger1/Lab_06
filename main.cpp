//
// Bohdan Petrov
// main.cpp
//

#include "flag.h"
#include "exercise.h"

void greetings() //func that just returns information about author and work
{
    cout << "\nBohdan Petrov, K13, Lab, var_16\n\n";
    cout << "Press Enter to Continue...";
    char temp1 = ' '; while(temp1 != '\n') std::cin.get(temp1);

    cout << "\nFrom given table of points(they are yellow or blue) find every MxM yellow square that isn't inside one that is bigger.\n\n";
    cout << "Press Enter to Continue...";
    char temp2 = ' '; while(temp2 != '\n') std::cin.get(temp2);
}

void farewell()
{
    cout << "\nProgram terminates...\n" << "Everything should be right, check output file, Goodbye" << '\n';
}

int main(int argc, char * argv[])
{
    greetings(); // greeting message
    string IN, OUT;
    if(!get_args(argc, argv, IN, OUT)) //checking args
    {
      help_flag(); // writing help message if something wrong with arguments 
      return 0;   
    }   

    /* //delete comment to randomize file (M first input, size_x - rows, size_y - cols)
    const int M=3,size_x=20,size_y=20; 
    ofstream Check(IN, std::fstream::out | std::fstream::trunc);
    rand_input(M,size_x,size_y,Check);
    Check.close();
    */

    ifstream Input(IN); //opening input file
    

    try{
    
    if(!Input.is_open()) throw std::runtime_error("input file hasn't opened");

    int M;
    if(!(Input>>M) || M<=0) throw std::invalid_argument("Wrong input in the input file");

    map<pair<int,int>,pair<bool,int>> grid;

    read_stream(grid,Input);

    if(!check_input(grid)) throw std::invalid_argument("Not every point in matrix is given");

    change_sq(grid);

    set<pair<int,int>> work_set;
    work_set = get_LfBtsquare(M,grid);

    /* //if you want to check matrix uncoment
    for(int i = 1; i <= grid.rbegin()->first.first; ++i)
    {
      for(int j = 1; j <= grid.rbegin()->first.second; ++j)
      {
          cout << "(" << grid[pair<int,int>(i,j)].first << "," << grid[pair<int,int>(i,j)].second << ") "; 
      }
        cout << endl;
    }
    */

    ofstream Output(OUT, std::ofstream::out | std::ofstream::trunc); //opening output file

    if(!Output.is_open()) throw std::runtime_error("output file hasn't opened");

    int count_yellow=0;
    for(auto const & it: grid) // counting yellow and blue points 
    {
      if(it.second.first == 1) ++count_yellow;
    }

    int size = grid.rbegin()->first.first*grid.rbegin()->first.second; // size of matrix

    Output << count_yellow << endl << size-count_yellow << endl;

    for(auto const & it: work_set) //outputing bottom-left point that is in square we need to find
    {
      Output << it.first << " " << it.second << endl;
    }

    Output.close();
    }
    catch(const std::invalid_argument& ia)
    {
      Input.close();
      std::cerr << "Invalid argument: " << ia.what() << endl;
      return 0;
    }
    Input.close();
    farewell();
}
