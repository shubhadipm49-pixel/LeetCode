class Solution {
public:
    int numberOfSteps(int num) {
        int count = 0;
        int temp = num;
        while(temp != 0){
            if(temp % 2 == 0){
                temp /= 2;
                count++;
            }
            else{
                temp -= 1;
                count++;
            }
        }
        return count;
    }
};