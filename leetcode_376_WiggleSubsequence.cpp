/*
The following solution based on dynamic programming takes O(N^2) time complexity.

The state transition formula:

lt[i] = 1) 1, if i == 0;
        2) max{gt[j]| 0 <= j < i} + 1, otherwise;
gt[i] = 1) 1, if i == 0;
        2) max{lt[j]| 0 <= j < i} + 1, otherwise;

lt[i] is the max length for wiggle sequence whose last element is nums[i] and the previous elememnt is less than the last element;
gt[i] is the max length for wiggle sequence whose last element is nums[i] and the previous elememnt is greater than the last element;
*/

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.empty())    return 0;
        int ret = 1;
        vector<int> dp_lt, dp_gt;
        dp_lt.push_back(1);
        dp_gt.push_back(1);
        
        for(int i = 1; i < nums.size(); i++){
            int cur = nums[i];
            int lt = 1, gt = 1;
            for(int j = i - 1; j >= 0; j--){
                if(cur < nums[j])
                    lt = max(lt, dp_gt[j] + 1);
                if(cur > nums[j])
                    gt = max(gt, dp_lt[j] + 1);
            }
            dp_lt.push_back(lt);
            dp_gt.push_back(gt);
            ret = max(ret, max(lt, gt));
        }
        return ret;
    }
};

/*
The following Solution is proposed in:
https://discuss.leetcode.com/topic/51946/very-simple-java-solution-with-detail-explanation-0ms

The main idead is to find a way to get alternative higher, lower, higher number.
*/

public class Solution {
    public int wiggleMaxLength(int[] nums) {
        if(nums.length==0 || nums.length==1){
            return nums.length;
        }        
        int j=1;    // This will track the index of result array
        boolean smallReq=nums[0]>nums[1];   //To check series starting pattern
        for(int i=1;i<nums.length;i++){
            if(smallReq && nums[i-1]>nums[i]){
                nums[j]=nums[i]; 
                j++; 
                smallReq=!smallReq;   //Toggle the requirement from small to big number
            } else{
                if(!smallReq && nums[i-1]<nums[i]){
                    nums[j]=nums[i]; 
                    j++; 
                    smallReq=!smallReq;   //Toggle the requirement from big to small number
                }
            }
        }
        return j;
    }
};

