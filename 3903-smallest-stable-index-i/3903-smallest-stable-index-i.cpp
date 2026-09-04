class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int res = 0;
        for(int i = 0; i < nums.size(); ++i){
            int maxValue = nums[i],minValue = nums[i];
            for(int j = 0; j < i; ++j){
                maxValue = max(maxValue,nums[j]);
            }
            for(int j = i+1; j < nums.size(); ++j){
                minValue = min(minValue,nums[j]);
            }

            res = (maxValue - minValue);
            if(res <= k){
                return i;
            }
        }
        return -1;
    }
};