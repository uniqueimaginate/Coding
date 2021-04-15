
// Faster
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret(2);
        unordered_map<int, int> numbers;

        for(int i=0; i<nums.size(); ++i){
            int diff = target - nums[i];
            
            if(numbers.count(diff)){
                return {numbers[diff], i};
            }
            numbers[nums[i]] = i;
        }
        
        return {};
    }
};


// Slower
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        for(int i=0; i<nums.size(); ++i){
            for(int j=i+1; j<nums.size(); ++j){
                if(nums[i] + nums[j] == target){
                    ret.push_back(i);
                    ret.push_back(j);
                }
            }
        }
        return ret;
    }
};