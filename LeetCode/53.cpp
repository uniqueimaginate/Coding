class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        long long curr_sum = nums[0];
        long long ret = nums[0];
        int n = nums.size();
        for(int i=1; i<n; ++i){
            if(curr_sum + nums[i] < nums[i]) {
                curr_sum = nums[i];
            }
            else{
                curr_sum = curr_sum + nums[i];
            }
            ret = max(ret, curr_sum);
        }

        return ret;
    }
};