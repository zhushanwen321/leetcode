// Given a non-empty integer array of size n, find the minimum number of moves required to make all array elements equal, where a move is incrementing n - 1 elements by 1.

// Example:

// Input:
// [1,2,3]

// Output:
// 3

// Explanation:
// Only three moves are needed (remember each move increments two elements):

// [1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]

#include "commHead.h"
using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int sum = 0, min = nums[0];
        for(int i=0; i<nums.size(); ++i) {
            sum += nums[i];
            if(nums[i] < min) {
                min = nums[i];
            }
        }
        return sum - min * nums.size();
    }
};