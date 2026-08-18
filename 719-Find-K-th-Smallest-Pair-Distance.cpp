class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end()); // kya fayda?

        int l = 0, r = *max_element(nums.begin(), nums.end());

        int n = nums.size();
        int ans = 0;

        while (l < r) {
            // log n
            int m = l + (r - l) / 2;
            // we will count how many diff before this

            int x = 0;
            int total = 0;

            for (int y = 1; y < n; y++) {
                // n
                // we have to check x-y
                while (nums[y] - nums[x] > m) {
                    x++;
                }
                total += y - x;
            }
            if (total < k) {
                l = m + 1;
            } else if (total >= k) {
                r = m;
            }
        }

        return r;
    }
};