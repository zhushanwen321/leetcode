/*Given an array S of n integers, are there elements a, b, c 
in S such that a + b + c = 0? Find all unique triplets in 
the array which gives the sum of zero.

Note: The solution set must not contain duplicate triplets.

For example, given array S = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]*/
//

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
    	vector<vector<int> > result;
    	if(nums.empty())	return result;
    	//get sorted arr
        sort(nums.begin(),nums.end());
        //find three numbers
        vector<int> tri(3,0);
        for(int i=0;i<arr.size()-2;++i){
        	for(int j=i+1;j<arr.size()-1;++j){
        		//binary search
        		int target = 0-arr[i]-arr[j];
        		int bg = j+1, ed = arr.size()-1, mid = (bg+ed)/2;
        		cout<<"num2: "<<arr[i]<<' '<<arr[j]<<' '<<arr[mid]<<endl;
        		bool isFound = false;
        		while(bg<=ed){
        			cout<<"num3: "<<arr[i]<<' '<<arr[j]<<' '<<arr[mid]<<endl;
        			if(arr[mid]==target){
        				tri[0] = arr[i];
        				tri[1] = arr[j];
        				tri[2] = target;
        				result.push_back(tri);
        				isFound = true;
        				break;
        			}else if(arr[mid]>target){
        				ed = mid-1;
        				mid = (bg+ed)/2;
        			}else{
        				bg = mid+1;
        				mid = (bg+ed)/2;
        			}
        		}
        		if(isFound)	break;
        	}
        }
        return result;
    }
};