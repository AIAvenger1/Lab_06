#include "exercise.h"

void read_stream(map<pair<int,int>,pair<bool,int> >& Grid, ifstream & is)
{
    pair<int,int> x_y;
    char col;
    while(!is.eof())
    {
        if(!(is >> x_y.first) || x_y.first <= 0) 
        {
            if(is.eof()) break;
            throw std::invalid_argument("Check input file, there are some problem with size or character");
        }
        
        if(!(is >> x_y.second) || x_y.second <= 0) throw std::invalid_argument("Check input file, there are some problem with size or character");
        if(!(is >> col)) throw std::invalid_argument("Check input file, there are some problem with size or character");
        if(col == 'y')
        {
            if(Grid.contains(x_y)) throw std::invalid_argument("Check input file, there are some problem with size or character"); // if can't use contains(cpp20) tell
            Grid[x_y] = pair<bool,int>(true,-1);
        }
        else
        {
            if(col == 'b') Grid[x_y] = pair<bool,int>(false,-1);
            else throw std::invalid_argument("Check input file, there are some problem with character");
        }
    }
}

/* looking for square this way:
^            ^       
|            |            
*             *       * - >
*             *       * - >
given_point   *       * - >
*/
int find_square(map<pair<int,int>,pair<bool,int> > & Grid, pair<int,int> x_y) //↑↑↑↑ looking for the max yellow square this point is lokated (look above) ↑↑↑↑
{
                int x_iter = x_y.first;
                int y_iter = x_y.second;
                int counter;
                int k;
                //++j;
                for( k = 1 ; k+x_iter <= Grid.rbegin()->first.first && k+ x_y.second<= Grid.rbegin()->first.second; ++k)
                {
                    counter = k+1;
                    for(int it = y_iter; counter!=0; --counter,++it)
                    {
                        if(Grid[pair<int,int>(x_iter+k,it)].first == 0)
                        {
                            x_iter = x_iter+k;
                            y_iter = it;
                            break;
                        }
                    }
                    if(Grid[pair<int,int>(x_iter,y_iter)].first == 0) break;
                        
                    counter = k+1;
                    for(int it = x_iter; counter!=0; --counter, ++it)
                    {
                        if(Grid[pair<int,int>(it,y_iter+k)].first == 0)
                        {
                            x_iter = it;
                            y_iter = y_iter +k;
                            break;
                        }
                    }
                    if(Grid[pair<int,int>(x_iter,y_iter)].first == 0) break;
                }
                return k;
}

void change_sq(map<pair<int,int>,pair<bool,int> > & Grid)
{
    pair<int,int> x_y = {Grid.rbegin()->first.first,Grid.rbegin()->first.second};
        for(int i=0,j=0;;)
        {        
            if(Grid[pair<int,int>(i,j)].first == 0) 
            { 
                if(j == x_y.second) //move to the next point
                {
                    if(i == x_y.first)
                    {
                        return;
                    }  
                    j = 1; ++i; continue;
                }
                    ++j; continue;
            }
           if(Grid[pair<int,int>(i,j)].first == 1)
            {
                 if(j == x_y.second)
                {
                    if(i == x_y.first)
                    {
                        if(Grid[pair<int,int>(i,j)].second < 1) Grid[pair<int,int>(i,j)].second = 1;
                        return;
                    } 
                    if(Grid[pair<int,int>(i,j)].second < 1) Grid[pair<int,int>(i,j)].second = 1; 
                    j = 1; ++i; continue;
                }

                int size;
                size = find_square(Grid,pair<int,int>(i,j)); // finding the size of square this point is located (localy check comment above)
            
                for(int it = 0; it < size; ++it)
                {
                    for(int k = 0; k < size; ++k)
                    {
                        if(Grid[pair<int,int>(i+it,j+k)].second < size)
                        Grid[pair<int,int>(i+it,j+k)].second = size;
                    }
                }
                ++j; continue;
            }
            else throw std::runtime_error("Some problem with algorithm(input)");
        }
}

bool check_input(map<pair<int,int>,pair<bool,int>> Grid)
{
    for(int i=1; i <= Grid.rbegin()->first.first; ++i)
    {
        for(int j=1; j <= Grid.rbegin()->first.second; ++j)
        {
            if(!Grid.contains(pair<int,int>(i,j))) return false; // if can't use contains(cpp20) tell
        }
    }
    return true;
}

set<pair<int,int> > get_LfBtsquare(int M, map<pair<int,int>,pair<bool,int> > Grid)
{
    set<pair<int,int> > result;
    pair<int,int> x_y = {Grid.rbegin()->first.first,Grid.rbegin()->first.second};
    for(int i=1,j=1;;)
    {
        if(Grid[pair<int,int>(i,j)].second == M && find_square(Grid,pair<int,int>(i,j)) == M)
        {
            result.insert(pair<int,int>(i,j));
            if(j == x_y.second)
            {
                if(i == x_y.first)
                {
                    break;
                }  
                j = 1; ++i; continue;
            }
                ++j; continue;
        }
        else
        {
             if(j == x_y.second)
            {
                if(i == x_y.first)
                {
                    break;
                }  
                j = 1; ++i; continue;
            }
                ++j; continue;
        }
    }
    return result;
}

void rand_input(int M ,int size_x, int size_y, ofstream & os)
{
  srand((int) time(0)); 
  os << M << '\n';
  for(int i = 1; i<=size_x; ++i)
  {
    for(int j = 1; j<=size_y; ++j)
    {
      os << i << " " << j << " ";
      if(rand()%2 == 0) os << 'b';
      else os << 'y';
      os << '\n';
    }
  }
}