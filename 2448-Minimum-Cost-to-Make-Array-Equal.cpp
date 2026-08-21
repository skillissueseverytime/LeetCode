class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        // we should sort on basis of cost
        int n = cost.size();
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++) {
            pair<int, int> p = {cost[i], nums[i]};
            v.push_back(p);
        }
        sort(v.begin(), v.end());
        int x=v.back().second;
        long long ans=0;

        for(int i=0;i<n;i++){
            if(nums[i]!=x) ans+=1LL*abs(x-nums[i])*cost[i];
        }
        return ans;
    }
};