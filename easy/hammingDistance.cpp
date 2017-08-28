class Solution {
public:
    int hammingDistance(int x, int y) {
        int z = x^y;
        int result = 0;
        while(z){
            z = z & z-1;
            ++result;
        }
        return result;
    }
};
