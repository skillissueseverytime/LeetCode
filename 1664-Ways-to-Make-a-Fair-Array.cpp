class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return 1;
        vector<pair<int, int>> prefix(n, {0, 0}), suffix(n, {0, 0});
        //<even,odd>

        prefix[0].second = nums[0];
        for (int i = 1; i < n; i++) {
            if ((i + 1) % 2 == 1) {
                prefix[i].second = nums[i];
            } else
                prefix[i].first = nums[i];

            prefix[i].first += prefix[i - 1].first;
            prefix[i].second += prefix[i - 1].second;
        }
        if (n % 2 == 0)
            suffix[n - 1].first = nums[n - 1];
        else
            suffix[n - 1].second = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            if ((i + 1) % 2 == 1)
                suffix[i].second = nums[i];

            else
                suffix[i].first = nums[i];

            suffix[i].first += suffix[i + 1].first;
            suffix[i].second += suffix[i + 1].second;
        }

        int ans = 0;
        for (int i = 1; i < n - 1; i++) {

            // if  idx is removed
            int odd = 0, even = 0;
            odd += prefix[i - 1].first;
            even += prefix[i - 1].second;

            odd += suffix[i + 1].second;
            even += suffix[i + 1].first;

            if (odd == even)
                ans++;
        }
        if (suffix[1].first == suffix[1].second)
            ans++;
        if (prefix[n - 2].first == prefix[n - 2].second)
            ans++;

        return ans;
    }
};