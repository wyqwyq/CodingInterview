class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        assert(n >= 1);
        int ret = 0;
        int expect = 1;
        long long  maxRange = 0;
        int i = 0;
        while(maxRange < n) {
            if(i < nums.size() && expect >= nums[i]){
                maxRange += nums[i];
                i++;
            }else{
                ret++;
                maxRange += expect;
            }
            expect = maxRange + 1;
        }
        return ret;
    }
};