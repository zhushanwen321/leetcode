/*The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".*/

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1){
            return s;
        }
        string result = "";
        for(int i=0;i<numRows;++i){
            if(i<s.size()){
                result += s.at(i);
            }else{
                break;
            }
        	int gap = numRows-i-1, index = i + gap*2;
        	while(index<s.size()){
        		if(gap){
        			result += s.at(index);
        		}
        		gap = numRows-1-gap;
        		index = index + gap*2;
        	}
        }
        return result;
    }
};