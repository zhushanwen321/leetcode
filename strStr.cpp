#include <iostream>

using namespace std; 

int strStr(string haystack, string needle) {
    int i_hx = 0;
    while( haystack.size()-i_hx >= needle.size() ){
        bool isSub = true;
        for(int i=0; i<needle.size(); ++i) {
        	cout << haystack.at(i_hx + i) << needle.at(i) << endl;
            if( haystack.at(i_hx + i) != needle.at(i) ) {
                isSub = false;
                break;
            }
        }
        if( isSub ) {
            return i_hx;
        }
        ++i_hx;
    }
    return -1;
}

int main() {
	string haystack = "haystack";
	string needle = "yst";
	cout << strStr(haystack, needle) << endl;
}
