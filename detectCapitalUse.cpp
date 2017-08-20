// Given a word, you need to judge whether the usage of capitals in it is right or not.

// We define the usage of capitals in a word to be right when one of the following cases holds:

// All letters in this word are capitals, like "USA".
// All letters in this word are not capitals, like "leetcode".
// Only the first letter in this word is capital if it has more than one letter, like "Google".
// Otherwise, we define that this word doesn't use capitals in a right way.
// Example 1:
// Input: "USA"
// Output: True
// Example 2:
// Input: "FlaG"
// Output: False
// Note: The input will be a non-empty word consisting of uppercase and lowercase latin letters.

#include "commHead.h"
using namespace std;

class Solution {
public:
    bool allCapital(string word, int st) {
        for(int i=st; i<word.size(); ++i) {
            if(word[i] < 'A' || word[i] > 'Z') {
                return false;
            }
        }
        return true;
    }
    
    bool nonCapital(string word, int st) {
        for(int i=st; i<word.size(); ++i) {
            if(word[i] < 'a' || word[i] > 'z') {
                return false;
            }
        }
        return true;
    }
    
    bool detectCapitalUse(string word) {
        if(word.size() <= 1){
            return true;
        }
        if(word[0] >= 'A' && word[0] <= 'Z') {
            if(word[1] >= 'A' && word[1] <= 'Z') {
                return allCapital(word, 2);
            }else{
                return nonCapital(word, 2);
            }
        }else{
            return nonCapital(word, 1);
        }
    }
};