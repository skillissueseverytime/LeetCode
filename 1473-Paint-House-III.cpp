class Solution {
    int dp[101][21][101];
    int fun(int idx, int prev, int cnt,vector<int>& h, vector<vector<int>>& cost, int m, int n,
                int target) {
                    if(cnt>target) return 1e9;
        if (idx == m) {
            if (cnt == target)
                return 0;

            return 1e9;
        }

        if(dp[idx][prev][cnt]!=-1) return dp[idx][prev][cnt];
        int newp = cnt + (h[idx] != prev);

        if (h[idx] == 0) {
            // try every color
            int ans = 1e9;
            for (int i = 1; i <= n; i++) {
                int t = cnt + (i != prev);

                ans = min(ans, cost[idx][i - 1] + fun(idx + 1, i, t,h,cost,m,n,target));
            }
            return dp[idx][prev][cnt]=ans;
        }

        return dp[idx][prev][cnt] =fun(idx + 1, h[idx], newp,h,cost,m,n,target);
    }

public:
    int minCost(vector<int>& h, vector<vector<int>>& cost, int m, int n,
                int target) {
                    memset(dp,-1,sizeof(dp));
                    int fl=0;
                    for(int i=0;i<m;i++){
                        if(h[i]==0){ fl=1; break;}
                        
                    }
                    if(!fl){
                        int prev=h[0],x=1;
                        for(int i=0;i<m;i++){
                            if(prev!=h[i]) {prev=h[i]; x++;}
                            
                        }
                        cout<<x;
                        if(target==x) return 0;
                        else return -1;
                    }
                    
                    int ans=fun(0,0,0,h,cost,m,n,target);

                    return ans!=1e9?ans:-1;
                }
};