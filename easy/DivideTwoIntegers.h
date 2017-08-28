#include <iostream>
#include <fstream>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (!divisor || (dividend == INT_MIN && divisor == -1))
            return INT_MAX;
        int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
        long long dvd = labs(dividend);
        long long dvs = labs(divisor);
        if (dvs==1) return sign == 1 ? dvd : -dvd;
        long long tmp = dvs;
        int res = 0, multiple = 1;
        while (dvd >= dvs) { 
        	while (dvd < tmp){
        		tmp >>= 1;
        		multiple >>= 1;
        	}
            dvd -= tmp;
            res += multiple;
            tmp <<= 1;
            multiple <<= 1;
        }
        return sign == 1 ? res : -res; 
    }
};

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(!divisor || (dividend==INT_MIN && divisor==-1))   return INT_MAX;
        
        int sign=((dividend<0)^(divisor<0)) ? -1:1;
        long long m=labs(dividend);
        long long n=labs(divisor);
        int result=0;
        
        /** dvd >= 2^k1*dvs + 2^k2*dvs ... **/
        while(m>=n){
            long long temp=n, count=1;
            while(m >= (temp<<1)){
                temp<<=1;
                count<<=1;
            }
            m-=temp;
            result+=count;
        }
        
        return sign==1?result:-result;
    }
};

int main(){
	ifstream fin;
	fin.open("input.txt");
	int a, b;
	fin >> a >> b;
	Solution s;
	cout << s.divide(a,b) << endl;
	fin.close();
	return 0;
}