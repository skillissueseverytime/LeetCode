class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        int n=nums.size();
         long long maxi=nums[0];
         long long total=nums[0];
        for(int i=1;i<n;i++){
            total+=nums[i];
           maxi=max(maxi,(total+i)/(i+1));
        }

        return maxi;
    }
};