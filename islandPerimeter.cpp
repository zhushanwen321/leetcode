// You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water. Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells). The island doesn't have "lakes" (water inside that isn't connected to the water around the island). One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

// Example:

// [[0,1,0,0],
//  [1,1,1,0],
//  [0,1,0,0],
//  [1,1,0,0]]

// Answer: 16
// Explanation: The perimeter is the 16 yellow stripes in the image below:

#include "commHead.h"
using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0;
        for(int r = 0; r < grid.size(); ++r) {
            for(int c = 0; c < grid[r].size(); ++c) {
                if(grid[r][c] == 1) {
                    int up = (r==0) ? 1 : (grid[r-1][c] == 0);
                    int down = (r==grid.size()-1) ? 1 : (grid[r+1][c] == 0);
                    int left = (c==0) ? 1 : (grid[r][c-1] == 0);
                    int right = (c==grid[r].size()-1) ? 1 : (grid[r][c+1] == 0);
                    perimeter += up + down + left + right;
                }
            }
        }
        return perimeter;
    }
};