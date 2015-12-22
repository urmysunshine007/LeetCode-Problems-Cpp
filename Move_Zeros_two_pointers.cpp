class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slow = 0;
        int n = nums.size();
        for (int i = 0; i<n; i++){
            if (nums[i]!=0){
                int temp = nums[i];
                nums[i]=nums[slow];
                nums[slow]=temp;
                slow++;
            }
        }
    }
};