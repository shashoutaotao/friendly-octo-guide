class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int left = 1;
        int right = nums.size() - 1;
        int found = -1;
        while(left <= right) {
            int mid = (left + right) / 2;
            int count = 0;
            for(int i = 0; i < nums.size(); ++i) {
                if(mid >= nums[i]) {
                    ++count;
                }
            }
            if(count <= mid) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
                found = mid;
            }
        }
        return found;
    }
};
