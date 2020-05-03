#include "A_star.h"

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



/* directional deltas */
constexpr int delta[4][2]{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};



string CellString(State state)
{
    switch (state)
    {
    case State::kObstacle:
        return "⛰️  ";
        break;
    case State::kStart:
        return "🚦 ";
        break;
    case State::kFinish:
        return "🏁 ";
        break;
    case State::kPath:
        return "🚗 ";
        break;
    default:
        return "0  ";
    }
}

vector<State> ParseLine(string line)
{
    vector<State> nums;
    int num;
    char ch;
    istringstream sline(line);
    while (sline >> num >> ch)
    {
        switch (num)
        {
        case 0:
            nums.emplace_back(State::kEmpty);
            break;
        case 1:
            nums.emplace_back(State::kObstacle);
            break;
        default:
            break;
        }
    }
    return nums;
}

void PrintBoard(vector<vector<State>> board)
{
    for (auto i = 0; i < board.size(); i++)
    {
        for (auto j = 0; j < board[i].size(); j++)
        {
            cout << CellString(board[i][j]);
        }
        cout << "\n";
    }
}

vector<vector<State>> ReadBoardFile(string path)
{
    vector<vector<State>> board;
    fstream inFile(path);
    if (inFile)
    {
        string line;
        while (getline(inFile, line))
        {
            board.emplace_back(ParseLine(line));
        }
    }
    else
    {
        std::cerr << "File doesn't exist" << endl;
    }
    return board;
}
/* computes the distance to the goal */
int Heuristic(int x1, int y1, int x2, int y2)
{
    return abs(x2 - x1) + abs(y2 - y1);
}

/* Adds the node to the open list and marks the grid cell as closed */
void AddToOpen(int h, int g, int x, int y, vector<vector<int>> &openList, vector<vector<State>> &grid)
{
    openList.emplace_back(vector<int>{x, y, g, h});
    grid[x][y] = State::kClosed;
}

bool Compare(const vector<int> first, const vector<int> second)
{
    return (first[2] + first[3]) > (second[2] + second[3]);
}

/* Sort the openList vector according to the Compare function */
void CellSort(vector<vector<int>> *v)
{
    std::sort(v->begin(), v->end(), Compare);
}


bool CheckValidCell(int x, int y, vector<vector<State>> &grid)
{

    if (((x >= 0) && (x < grid.size())) && ((y >= 0) && (y < grid[0].size())))
    {
        if (grid[x][y] == State::kEmpty)
        {
            return true;
        }
    }
    return false;
}

/* Expand the neighbout nodes */
void ExpandNeighbors(vector<int> currentNode, int goal[], vector<vector<State>> &grid, vector<vector<int>> &openList)
{
    /* Get node data */
    int curX = currentNode[0];
    int curY = currentNode[1];
    int g = currentNode[2];
    for (auto i = 0; i < 4; i++)
    {
        int nextX = curX + delta[i][0];
        int nextY = curY + delta[i][1];
        if (CheckValidCell(nextX, nextY, grid))
        {
            int h = Heuristic(nextX, nextY, goal[0], goal[1]);
            AddToOpen(h, g + 1, nextX, nextY, openList, grid);
        }
    }
}

vector<vector<State>> Search(vector<vector<State>> board, int start[], int goal[])
{
    /* initialize an empty list (open list ) of Fs */
    vector<vector<int>> openList{};
    /* The grid that will be printed after searching */
    vector<vector<State>> solution{board};

    /* g : How many steps i took to get to this step from the start node */
    int g = 0;
    /* h : The optimistical distance form the that node to the goal */
    int h = Heuristic(start[0], start[1], goal[0], goal[1]);

    /* Add the new node to the list of open nodes */
    AddToOpen(h, g, start[0], start[1], openList, solution);

    while (!openList.empty())
    {
        /* Sort the open list by the smallest F value */
        CellSort(&openList);
        /* Get the smallest F value node */
        auto current = openList.back();
        /* Remove the current node from the openList */
        openList.pop_back();
        /* Mark the current node as a path node */
        solution[current[0]][current[1]] = State::kPath;
        /* Check if the current node is the goal */
        if (current[0] == goal[0] && current[1] == goal[1])
        {
            /* Add the start and the end points to the grid */
            solution[start[0]][start[1]] = State::kStart;
            solution[goal[0]][goal[1]] = State::kFinish;
            return solution;
        }
        else
        {
            ExpandNeighbors(current, goal, solution, openList);
        }
    }
    // We've ran out of new nodes to explore and haven't found a path.
    cout << "No path found!"
         << "\n";
    return std::vector<vector<State>>{};
}


} //end of namespace