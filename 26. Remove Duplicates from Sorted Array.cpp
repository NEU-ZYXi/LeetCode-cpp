class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ans = 0;
        for (int num : nums) {
            if (ans == 0 || nums[ans - 1] != num) {
                nums[ans++] = num;
            }
        }
        return ans;
    }
};
