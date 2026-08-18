class Solution {
    // temp 0 is l and 1 is r
    const long long INF=4e18;
    //long long dp[1501][1501][3];
    long long fun(int l, int r, int temp, int start, vector<int>& a, vector<vector<vector<long long>>>& dp) {
        if (l == 0 && r == a.size()-1) {
            return 0;
        }
        long long one, two, curr;

        if(dp[l][r][temp]!=-1) return dp[l][r][temp];

        int rem = a.size() - r + l-1;

        // if (temp == -1) {
        //     // mtlb starting pe hai
        //     curr = a[l];
        //     if(r==a.size()-1) two=INF;
        //     else
        //     two = 1LL*abs(curr - a[r+1]) * rem + fun(l, r + 1, 1, start, a,dp);
        //     if(l==0)
        //     one=INF;
        //     else
        //     one = 1LL*abs(curr - a[l-1]) * rem + fun(l - 1, r, 0, start, a,dp);
        // }

        // else  mle
        if (temp == 0) {

            curr = a[l];

            if (l ==0)
                one = INF;
            else
                one = 1LL*abs(curr - a[l - 1]) * rem + fun(l-1, r, 0, start, a,dp);

            if(r==a.size()-1)
            two=INF;
            else
            two = 1LL*abs(curr - a[r+1]) * rem + fun(l, r + 1, 1, start, a,dp);
        } else {
            curr = a[r];
            if(l==0)
            one=INF;
            else
            one = 1LL*abs(curr - a[l-1]) * rem + fun(l - 1, r, 0, start, a,dp);
            if (r ==a.size()-1)
                two = INF;
            else
                two = 1LL*abs(curr - a[r + 1]) * rem + fun(l, r + 1, 1, start, a,dp);
        }

        return dp[l][r][temp]=min(one, two);
    }

public:
    long long elevatorRequests(int n, int start, vector<int>& a) {
        sort(a.begin(), a.end());
        int m = a.size();
       
        vector<vector<vector<long long>>> dp(m+1,vector<vector<long long>>(m+1,vector<long long>(2,-1)));
        int starting = lower_bound(a.begin(), a.end(), start) - a.begin();
        if (starting == a.size() || a[starting] != start) {
            a.insert(a.begin() + starting, start);
        }

        return min(fun(starting,starting,1,start,a,dp),fun(starting,starting,0,start,a,dp));
       // return fun(starting, starting, -1,start, a,dp);
    }
};