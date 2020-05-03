#include <iostream>
#include <vector>
#include "A_star.h"

using std::vector;



int main()
{

    /* Read the maze */
    auto board = A_star::ReadBoardFile("../board.txt");
    int init[2]{0, 0}; // or: int init[2]{0, 0}; or: int init[] = {0, 0}
    int goal[2]{4, 4}; /*  */
    vector<vector<A_star::State>> solution = A_star::Search(board, init, goal);
    A_star::PrintBoard(solution);
    return 0;
}
