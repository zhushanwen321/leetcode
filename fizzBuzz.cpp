// Write a program that outputs the string representation of numbers from 1 to n.

// But for multiples of three it should output “Fizz” instead of the number and for the multiples of five output “Buzz”. For numbers which are multiples of both three and five output “FizzBuzz”.

// Example:

// n = 15,

// Return:
// [
//     "1",
//     "2",
//     "Fizz",
//     "4",
//     "Buzz",
//     "Fizz",
//     "7",
//     "8",
//     "Fizz",
//     "Buzz",
//     "11",
//     "Fizz",
//     "13",
//     "14",
//     "FizzBuzz"
// ]

#include "commHead.h"
using namespace std;

class Solution {
public:
    static const string fizz;
    static const string buzz;

    vector<string> fizzBuzz(int n);
};

const string Solution::fizz = "Fizz";
const string Solution::buzz = "Buzz";

vector<string> Solution::fizzBuzz(int n) {
    vector<string> res;
    stringstream ss;
    for(int i=1; i<=n; ++i) {
        string tmp = "";
        bool unchanged = true;
        if(i%3 == 0) {
            tmp += fizz;
            unchanged = false;
        }
        if(i%5 == 0) {
            tmp += buzz;
            unchanged = false;
        }
        if(unchanged) {
            ss << i;
            ss >> tmp;
            ss.clear();
        }
        res.push_back(tmp);
    }
    return res;
}