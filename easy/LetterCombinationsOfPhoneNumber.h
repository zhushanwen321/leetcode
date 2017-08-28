// Given a digit string, return all possible letter combinations that the number could represent.

// A mapping of digit to letters (just like on the telephone buttons) is given below.

// 1       2abc    3def
// 4ghi    5jkl    6mno
// 7pqrs   8tuv    9wxyz
// *+      0_      #


// Input:Digit string "23"
// Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
// Note:
// Although the above answer is in lexicographical order, your answer could be in any order you want.

#include "commHead.h"

using namespace std;

class Solution {
private:
    const char alphabet[8][4] = {
            {'a','b','c','\0'},
            {'d','e','f','\0'},
            {'g','h','i','\0'},
            {'j','k','l','\0'},
            {'m','n','o','\0'},
            {'p','q','r','s'},
            {'t','u','v','\0'},
            {'w','x','y','z'}
        };

public:
    bool comb(char* res_str, const char* digits, const int d_i, vector<string>& res){
        if(digits[d_i]=='\0'){
            string str(res_str, d_i);
            res.push_back(str);
            return true;
        }
        const char *alp_row;
        int len = 3;
        if(digits[d_i]>='2' && digits[d_i]<='9'){
            alp_row = alphabet[digits[d_i]-'2'];
            if(digits[d_i]=='7' || digits[d_i]=='9') len = 4;
        }else{
            return false;
        }
        for(int i=0;i<len;++i){
            res_str[d_i] = alp_row[i];
            if(!comb(res_str, digits, d_i+1, res)) return false;
        }
        return true;
    }

    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.empty()) return res;
        char * res_str = new char[digits.size()+1];
        const char* dgts = digits.c_str();
        bool valid = comb(res_str, dgts, 0, res);
        if(!valid) res.clear();
        delete[] res_str;
        return res;
    }

    
};