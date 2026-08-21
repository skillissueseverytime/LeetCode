class Solution {
    int dp[1001][1002];
    int fun(int idx,int last,vector<vector<int>>& p){
            if(idx==p.size()) return 0;

            int one=0,two=0;
            if(dp[idx][last+1]!=-1) return dp[idx][last+1];

            if(last==-1 || p[idx].front()>p[last].back()){
                one=1+fun(idx+1,idx,p);
            }
            two=fun(idx+1,last,p);


        return dp[idx][last+1]=max(one,two);
    }
public:
    int findLongestChain(vector<vector<int>>& p) {
        memset(dp,-1,sizeof(dp));
        sort(p.begin(),p.end());
        return fun(0,-1,p);



    }
};