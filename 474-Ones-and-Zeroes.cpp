class Solution {
    int dp[601][101][101];
public:
    // 1 zero
    int fun(int idx, int temp1,int temp2, vector<string>& strs, int m, int n) {
        // if(wt.first>m || wt.second>n) return -1000;

        if (idx >= strs.size())
            return 0;

        int one = 0, zero = 0;

        if(dp[idx][temp1][temp2]!=-1) return dp[idx][temp1][temp2];

        int o = 0, t = 0;
        for (int j = 0; j < strs[idx].length(); j++) {
            if (strs[idx][j] == '1')
                one++;
            else
                zero++;
        }

        if (temp1 + one <= n && temp2 + zero <= m)
            o = 1 +fun(idx + 1, temp1 + one, temp2 + zero, strs, m, n);

        t = fun(idx + 1, temp1,temp2, strs, m, n);

        return dp[idx][temp1][temp2]=max(o, t);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(dp,-1,sizeof(dp));
        
        return fun(0, 0, 0, strs, m, n);
    }
};