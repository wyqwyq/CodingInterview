class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        if(matrix.empty())  return 0;
        int ans = numeric_limits<int>::min();
        for(int r1 = 0; r1 < matrix.size(); r1++){
            vector<int> arr(matrix[0].size(), 0);
            for(int r2 = r1; r2 < matrix.size(); r2++){
                for(int c = 0; c < matrix[r2].size(); c++){
                    arr[c] += matrix[r2][c];
                }
                ans = max(ans, maxSumSubArray(arr, k));
            }
        }
        
        return ans;
    }
    
    int maxSumSubArray(vector<int> & arr, int k){
        int sum = 0;
        int maxS = numeric_limits<int>::min();
        for (int i = 0; i < arr.size(); i++) {
            sum += arr[i];
            maxS = max(sum, maxS);
            if (maxS == k ) return maxS;
            if (sum < 0) sum = 0;
        }
        if (maxS <= k) return maxS;
        
        set<int> s;
        s.insert(0);
        int val = 0, ans = numeric_limits<int>::min();
        for(int i = 0; i < arr.size(); i++){
            val +=  arr[i];
            auto it = s.lower_bound(val - k);
            if(it != s.end()){
                ans = max(ans, val - *it);
            }
            s.insert(val);
        }
        return ans;
    }
};
