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
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> rest;
        vector<string> result;
        int min = 2000;
        if(list1.size()<list2.size()){
	        for(int i=0;i<list2.size();++i){
	        	rest[list2[i]] = i;
	        }
	    	for(int j=0;j<list1.size();++j){
	    		auto iter = rest.find(list1[j]);
	    		if(iter != rest.cend()){
	    			auto score = iter->second+j;
	    			if(score <= min){
	    				if(score < min){
	    					min = score;
	    					result.clear();
	    				}
	    				result.emplace_back(list1[j]);
	    			}
	    		}
	    	}
        }else{
	        for(int i=0;i<list1.size();++i){
	        	rest[list1[i]] = i;
	        }
	    	for(int j=0;j<list2.size();++j){
	    		auto iter = rest.find(list2[j]);
	    		if(iter != rest.cend()){
	    			auto score = iter->second+j;
	    			if(score <= min){
	    				if(score < min){
	    					min = score;
	    					result.clear();
	    				}
	    				result.emplace_back(list2[j]);
	    			}
	    		}
	    	}        	
        }
        return result;
    }
};