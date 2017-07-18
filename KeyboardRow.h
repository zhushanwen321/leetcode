/*
Suppose Andy and Doris want to choose a restaurant for dinner, 
and they both have a list of favorite restaurants represented by strings.
You need to help them find out their common interest with the 
least list index sum. If there is a choice tie between answers, 
output all of them with no order requirement. You could assume there always exists an answer.

Example 1:
Input:
["Shogun", "Tapioca Express", "Burger King", "KFC"]
["Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"]
Output: ["Shogun"]
Explanation: The only restaurant they both like is "Shogun".
Example 2:
Input:
["Shogun", "Tapioca Express", "Burger King", "KFC"]
["KFC", "Shogun", "Burger King"]
Output: ["Shogun"]
Explanation: The restaurant they both like and have the least index sum is "Shogun" with index sum 1 (0+1).
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<int> dict(26);
        vector<string> rows = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};
        
        for (int i = 0; i < rows.size(); ++i) {
            for (auto c : rows[i]) {
                dict[c - 'a'] = (1 << i);
            }
        }
        
        vector<string> res;
        for (auto w : words) {
            int r = 7;
            for (auto c : w) {
                r &= dict[tolower(c) - 'a'];
                if (r == 0)
                    break;
            }
            if (r)
                res.emplace_back(w);
        }
        return res;
    }
};