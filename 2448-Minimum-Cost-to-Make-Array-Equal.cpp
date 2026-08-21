class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        // we should sort on basis of cost
        int n = cost.size();
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++) {
            pair<int, int> p = {nums[i], cost[i]};
            v.push_back(p);
        }
        sort(v.begin(), v.end());
        long long l = v[0].first, r = v.back().first;

        long long ans = 0;

        while (l < r) {
            long long m = l + (r - l) / 2;
            // we have to check for mid
            long long temp = 0;
            for (int i = 0; i < n; i++) {
                temp += 1LL * abs(v[i].first - m) * v[i].second;
            }
            // mid -1
            long long temp1 = 0;
            for (int i = 0; i < n; i++) {
                temp1 += 1ll * abs(v[i].first - (m + 1)) * v[i].second;
            }

            if (temp < temp1) {
                r = m ;
                // ans=temp;
            } else {
                l = m + 1;
                // ans=temp;
            }
        }

        for (int i = 0; i < n; i++) {
            ans += 1ll*abs(l - v[i].first) * v[i].second;
        }

        return ans;
    }
};