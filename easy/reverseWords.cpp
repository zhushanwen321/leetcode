// Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

// Example 1:
// Input: "Let's take LeetCode contest"
// Output: "s'teL ekat edoCteeL tsetnoc"
// Note: In the string, each word is separated by single space and there will not be any extra space in the string.

#include "commHead.h"
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        stack<char> reverse;
        string res = "";
        for(const char &c : s) {
            switch(c) {
                case ' ' :
                    if(!reverse.empty()) {
                        while(!reverse.empty()) {
                            res += reverse.top();
                            reverse.pop();
                        }
                        res += ' ';
                    }
                    break;
                default : reverse.push(c);break;
            }
        }
        if(!reverse.empty()) {
            while(!reverse.empty()) {
                res += reverse.top();
                reverse.pop();
            }
        }
        return res;
    }
};