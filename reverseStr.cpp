// Given a string and an integer k, you need to reverse the first k characters for every 2k characters counting from the start of the string. If there are less than k characters left, reverse all of them. If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and left the other as original.
// Example:
// Input: s = "abcdefg", k = 2
// Output: "bacdfeg"
// Restrictions:
// The string consists of lower English letters only.
// Length of the given string and k will in the range [1, 10000]

#include "commHead.h"
using namespace std;

class Solution {
public:
    void reverse(string& s, int l, int r){
        while(l<r){
            swap(s[l],s[r]);
            l++;
            r--;
        }
    }

    string reverseStr(string s, int k) {
        for(int i=0; i<s.size(); i+=(2*k)) {
        	cout << i << endl;
            if(i+k-1 < s.size()) {
                reverse(s, i, i+k-1);
                cout << "1 " << s << endl;
            }else{
                reverse(s, i, s.size()-1);
                cout << "2 " << s << endl;
            }
        }
        return s;
    }
};

int main() {
    Solution *s = new Solution();
    string str = "abcdefg";
    string res = s->reverseStr(str, 2);
    cout << res << endl;
    return 0;
}
