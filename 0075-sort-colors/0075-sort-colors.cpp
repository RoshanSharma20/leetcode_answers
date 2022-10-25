class Solution {
public:
    void sortColors(vector<int>& nums) 
    {
        //dutch naional flag algorithm
        int low=0,high=nums.size()-1,mid=0;
        while(mid<=high)
        {
            if(nums[mid]==0)
            {
                swap(nums[mid],nums[low]);
                low++;
                mid++;
            }
            else if(nums[mid]==1)
                mid++;
            else
            {
                swap(nums[mid],nums[high]);
                high--;
            }
        }
    }
};