// Given a binary search tree with non-negative values, find the minimum absolute difference between values of any two nodes.

// Example:

// Input:

//    1
//     \
//      3
//     /
//    2

// Output:
// 1

// Explanation:
// The minimum absolute difference is 1, which is the difference between 2 and 1 (or between 2 and 3).
// Note: There are at least two nodes in this BST.

#include "commHead.h"
using namespace std;

class Solution {
public:
    void midTrav(TreeNode* root, vector<int>& res) {
        if(root == nullptr) return;
        midTrav(root->left, res);
        res.push_back(root->val);
        midTrav(root->right, res);
    }
    
    int getMinimumDifference(TreeNode* root) {
        vector<int> res;
        midTrav(root, res);
        int min = 999999;
        for(int i=1; i<res.size(); ++i) {
            int diff = res[i]-res[i-1];
            if(diff < min) min = diff;
        }
        return min;
    }
};