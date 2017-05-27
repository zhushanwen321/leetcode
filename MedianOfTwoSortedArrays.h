/*There are two sorted arrays nums1 and nums2 of size m and n respectively.
Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

Example 1:
nums1 = [1, 3]
nums2 = [2]
The median is 2.0

Example 2:
nums1 = [1, 2]
nums2 = [3, 4]
The median is (2 + 3)/2 = 2.5*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> arr;
        auto iter1=nums1.cbegin();
        auto iter2=nums2.cbegin();
        while(iter1!=nums1.cend()&&iter2!=nums2.cend()){
            if(*iter1>*iter2){
                arr.push_back(*iter2);
                ++iter2;
            }else{
                arr.push_back(*iter1);
                ++iter1;
            }
        }
        while(iter1!=nums1.cend()){
            arr.push_back(*iter1);
            ++iter1;
        }
        while(iter2!=nums2.cend()){
            arr.push_back(*iter2);
            ++iter2;
        }
        if(arr.size()%2==1){
            return arr[arr.size()/2];
        }else{
            double a1 = arr[arr.size()/2-1], a2 = arr[arr.size()/2];
            return (a1+a2)/2;
        }
    }
};

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int *arr = new int[nums1.size()+nums2.size()];
        int i = 0;
        double result;
        auto iter1=nums1.cbegin();
        auto iter2=nums2.cbegin();
        while(iter1!=nums1.cend()&&iter2!=nums2.cend()){
            if(*iter1>*iter2){
                arr[i] = (*iter2);
                ++iter2;
            }else{
                arr[i] = (*iter1);
                ++iter1;
            }
            ++i;
        }
        while(iter1!=nums1.cend()){
            arr[i] = (*iter1);
            ++iter1;
            ++i;
        }
        while(iter2!=nums2.cend()){
            arr[i] = (*iter2);
            ++iter2;
            ++i;
        }
        if(i%2==1){
            result = arr[i/2];
        }else{
            double a1 = arr[i/2-1], a2 = arr[i/2];
            result = (a1+a2)/2;
        }
        delete[] arr;
        return result;
    }
};