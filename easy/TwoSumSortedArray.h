// Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

// The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

// You may assume that each input would have exactly one solution and you may not use the same element twice.

// Input: numbers={2, 7, 11, 15}, target=9
// Output: index1=1, index2=2

#include "commHead.h"

using namespace std;

class Solution {
public:
    int binarySearch(const vector<int>& arr, int begin, int end, int target){
        if(arr.empty() || begin>end) return -1;
        int mid;
        while(begin < end){
            mid = (begin+end)/2;
            if(target > arr[mid]) begin = mid+1;
            else if(target <arr[mid]) end = mid-1;
            else{
                cout<<"mid: "<<mid<<endl;
                return mid;
            } 
        }
        if(arr[begin] == target) return begin;
        else return -1;
    }
    
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        if(numbers.size()<2) return numbers;
        for(int i=0;i<numbers.size()-2;++i){
            int tar = target - numbers[i];
            if(tar < 0) return res;
            int find = binarySearch(numbers, i+1, numbers.size()-2, tar);
            if(find != -1){
                res.push_back(i);
                res.push_back(find);
                return res;
            }
        }
        return res;
    }
};