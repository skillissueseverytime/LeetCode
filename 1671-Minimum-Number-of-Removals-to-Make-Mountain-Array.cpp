class Solution {
    int dp1[1001][1001],dp2[1001][1001];

    int lis(int idx, int prev, vector<int>& nums) {
        if (idx == nums.size()) {
            return 0;
        }
        if(dp1[idx][prev]!=-1) return dp1[idx][prev];
        int one = 0, two = 0;
        if (nums[idx] < nums[prev])
            one = 1 + lis(idx + 1, idx, nums);

        two = lis(idx + 1, prev, nums);

        return dp1[idx][prev]=max(one, two);
    }

    int lds(int idx, int prev, vector<int>& nums) {
        if (idx < 0) {
            return 0;
        }
        int one = 0, two = 0;
    
        if(dp2[idx][prev]!=-1) return dp2[idx][prev];
        if (nums[idx] < nums[prev])
            one = 1 + lds(idx - 1, idx, nums);

        two = lds(idx - 1, prev, nums);

        return dp2[idx][prev]=max(one, two);
    }

public:
    int minimumMountainRemovals(vector<int>& nums) {
        memset(dp1,-1,sizeof(dp1));
        memset(dp2,-1,sizeof(dp2));
        int n = nums.size();
        int ans = n;
        for (int i = 1; i < n - 1; i++) {
            int maxi = lds(i - 1, i, nums) + lis(i + 1, i, nums);
            cout<<i<<maxi;
            ans = min(ans, n - (maxi + 1));
        }
        return ans;
    }
};