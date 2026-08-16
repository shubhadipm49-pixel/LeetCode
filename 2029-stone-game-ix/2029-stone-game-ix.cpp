class Solution {
public:
    int dp[101][101][3];

    bool solve(int c1, int c2, int rem) {
        if (c1 == 0 && c2 == 0)
            return false;   

        int &ans = dp[c1][c2][rem];
        if (ans != -1)
            return ans;

        ans = false;

        
        if (c1 > 0) {
            int newRem = (rem + 1) % 3;

           
            if (newRem != 0) {
                if (!solve(c1 - 1, c2, newRem))
                    ans = true;
            }
        }

        
        if (!ans && c2 > 0) {
            int newRem = (rem + 2) % 3;

            
            if (newRem != 0) {
                if (!solve(c1, c2 - 1, newRem))
                    ans = true;
            }
        }

        return ans;
    }

    
   bool stoneGameIX(vector<int>& stones) {
        int cnt0 = 0, cnt1 = 0, cnt2 = 0;

        for (int x : stones) {
            if (x % 3 == 0)
                cnt0++;
            else if (x % 3 == 1)
                cnt1++;
            else
                cnt2++;
        }

        if (cnt0 % 2 == 0) {
            return cnt1 > 0 && cnt2 > 0;
        }

        return abs(cnt1 - cnt2) > 2;
    }
};