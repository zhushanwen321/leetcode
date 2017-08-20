//Initially, there is a Robot at position (0, 0). Given a sequence of its moves, judge if this robot makes a circle, which means it moves back to the original place.
//
//The move sequence is represented by a string. And each move is represent by a character. The valid robot moves are R (Right), L (Left), U (Up) and D (down). The output should be true or false representing whether the robot makes a circle.
//
//Example 1:
//Input: "UD"
//Output: true
//Example 2:
//Input: "LL"
//Output: false

class Solution {
public:
    bool judgeCircle(string moves) {
        int direction[] = {0, 0};
        for(const char &c : moves) {
            switch(c){
                case 'U' : ++direction[0];break;
                case 'D' : --direction[0];break;
                case 'L' : ++direction[1];break;
                case 'R' : --direction[1];break;
                default : return false;
            }
        }
        return (direction[0] == 0 && direction[1] == 0);
    }
};
