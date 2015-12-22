class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int value = 0;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            value = nums[i] ^ value;
        }
        return value;
    }
};