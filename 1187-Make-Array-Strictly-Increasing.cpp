class Solution {
    // temp shows 0 arr1 // 1 arr2
    int fun(int idx, int prev, int temp, vector<int>& arr, vector<int>& a2) {
        if (idx >= arr.size()) {
            return 0;
        }
        //we can change curr one right
        int one = 1e9, two = 1e9;
        if (temp == 0) {
            if (arr[prev] >= arr[idx]){
                int it = upper_bound(a2.begin(), a2.end(), arr[prev]) - a2.begin();
                if (it  == a2.size()) return 1e9;
                else return 1+ fun(idx + 1, it, 1, arr, a2);
            }

        } else {
            if (a2[prev] >= arr[idx]) {
                int it = upper_bound(a2.begin(), a2.end(), a2[prev]) - a2.begin();
                if (it== a2.size()) return 1e9;
                else return 1+ fun(idx + 1, it, 1, arr, a2);
            }
        }
        

        // only two choices ki change kro ya mt kro
        // we should change wrt next
       // if(idx==0 || arr[prev]<arr[idx])
        one = fun(idx + 1, idx, 0, arr, a2);

        if (temp == 0) {
            int it = upper_bound(a2.begin(), a2.end(), arr[prev]) - a2.begin();
            if (it != a2.size())
                two = 1 + fun(idx + 1, it, 1, arr, a2);
        } else {
            int it = upper_bound(a2.begin(), a2.end(), a2[prev]) - a2.begin();
            if (it != a2.size())
                two = 1 + fun(idx + 1, it, 1, arr, a2);
        }

        return min(one, two);
    }

public:
    int makeArrayIncreasing(vector<int>& arr, vector<int>& a2) {

        sort(a2.begin(), a2.end());
        int it = upper_bound(a2.begin(), a2.end(), -1)-a2.begin();
int temp=min(fun(1, 0, 0, arr, a2), 1 + fun(1, it, 1, arr, a2));
if(temp>=1e9) return -1;
        return temp;
    }
};