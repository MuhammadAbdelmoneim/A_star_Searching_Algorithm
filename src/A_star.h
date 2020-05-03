#ifndef A_STAR_H_
#define A_STAR_H_

/* Includes */
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>


namespace A_star{


using std::cout;
using std::endl;
using std::fstream;
using std::istringstream;
using std::string;
using std::vector;

enum class State
{
    kEmpty,
    kObstacle,
    kClosed,
    kStart,
    kFinish,
    kPath
};


void PrintBoard(vector<vector<State>> board);


vector<vector<State>> ReadBoardFile(string path);


vector<vector<State>> Search(vector<vector<State>> board, int start[], int goal[]);

} //end of namespace
#endif //A_STAR_H_
