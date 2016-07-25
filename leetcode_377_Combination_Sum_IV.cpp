class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, -1);
        return _calc(nums, dp, target);
    }
    
    int _calc(vector<int> & nums, vector<int> & dp, int i){
        if(dp[i] != -1) return dp[i];
        int ret = 0;
        for(auto & v: nums){
            if(i > v){
                ret += _calc(nums, dp, i - v);
            }else if(i == v){
                ret++;
            }
        }
        return dp[i] = ret;
    }
};