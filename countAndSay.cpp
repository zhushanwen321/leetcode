//The count-and-say sequence is the sequence of integers with the first five terms as following:
//
//1.     1
//2.     11
//3.     21
//4.     1211
//5.     111221
//1 is read off as "one 1" or 11.
//11 is read off as "two 1s" or 21.
//21 is read off as "one 2, then one 1" or 1211.
//Given an integer n, generate the nth term of the count-and-say sequence.
//
//Note: Each term of the sequence of integers will be represented as a string.
//
//Example 1:
//
//Input: 1
//Output: "1"
//Example 2:
//
//Input: 4
//Output: "1211"

class Solution {
public:
    string countAndSay(int n) {
        if(n<=0){
            return "1";
        }
        string say = "1";
        for(int i=1; i<n; ++i){
            string tmp;
            char t = '0';
            int count = 1;
            for(const char &c : say){
                if('0' == t){
                    t = c;
                }else if(t == c){
                    ++count;
                }else{
                    tmp += ('0'+count);
                    tmp += t;
                    t = c;
                    count = 1;
                }
            }
            tmp += ('0'+count);
            tmp += say.at(say.size()-1);
            say = tmp;
        }
        return say;
    }
};
