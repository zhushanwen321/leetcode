// Given a non-empty binary tree, return the average value of the nodes on each level in the form of an array.

// Example 1:
// Input:
//     3
//    / \
//   9  20
//     /  \
//    15   7
// Output: [3, 14.5, 11]
// Explanation:
// The average value of nodes on level 0 is 3,  on level 1 is 14.5, and on level 2 is 11. Hence return [3, 14.5, 11].
// Note:
// The range of node's value is in the range of 32-bit signed integer.

#include "commHead.h"
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        queue<TreeNode*> que;
        int numOfCur = 0, numOfNext = 0;
        que.push(root);
        numOfCur = 1;
        while(!que.empty()) {
            double average = 0;
            for(int i=0; i<numOfCur; ++i) {
                TreeNode* p = que.front();
                average += (int) p->val;
                if(p->left != nullptr) {
                    que.push(p->left);
                    ++numOfNext;
                }
                if(p->right != nullptr) {
                    que.push(p->right);
                    ++numOfNext;
                }
                que.pop();
            }
        res.push_back(average/numOfCur);
        numOfCur = numOfNext;
        numOfNext = 0; 
        }
        return res;
    }
};