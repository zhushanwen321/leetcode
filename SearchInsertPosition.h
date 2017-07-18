/*
Given a sorted array and a target value, 
return the index if the target is found. 
If not, return the index where it would 
be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0

*/
#include "MyHead.h"
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n_begin=0, n_end=nums.size()-1, n_mid=(n_begin+n_end)/2;
        while(n_begin < n_end){
            cout<<nums[n_mid]<<' ';
        	if(target > nums[n_mid]){
        		n_begin=n_mid+1;
        	}else if(target < nums[n_mid]){
        		n_end=n_mid-1>0?n_mid-1:0;
        	}else{
        		return n_mid;
        	}
        	n_mid=(n_begin+n_end)/2;
        }
        if(target > nums[n_begin]) return n_begin+1;
        else return n_begin;
    }
};

int main(){

	return 0;
}