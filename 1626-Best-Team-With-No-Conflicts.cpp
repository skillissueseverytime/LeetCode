class Solution {
    int dp[1001][1002];
    int fun(int idx,int prev,vector<pair<int,int>>& temp){
        if(idx>=temp.size()) return 0;

        if(dp[idx][prev+1]!=-1) return dp[idx][prev+1];
        int one=0,two=0;

        if(prev==-1 ||temp[idx].first==temp[prev].first|| temp[prev].second<=temp[idx].second)
        one=temp[idx].second+fun(idx+1,idx,temp);

        two=fun(idx+1,prev,temp);

        return dp[idx][prev+1]=max(one,two);
    }
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n=ages.size();
        memset(dp,-1,sizeof(dp));
        vector<pair<int,int>> temp;

        for(int i=0;i<n;i++){
            pair<int,int> p={ages[i],scores[i]};
            temp.push_back(p);
        }
        sort(temp.begin(),temp.end());


        return fun(0,-1,temp);
    }
};