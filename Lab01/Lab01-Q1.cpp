class Solution {
    public:
        bool isMonotonic(vector<int>& nums) {
            bool ins = 1, dec = 1;
            // count +2 for the assignment
    
            for(size_t i = 1; i < nums.size(); i++)
            {
                // count +1 for the comparison
                // count +1 for the increment
                // count +1 for the initialization
                if(nums[i] < nums[i - 1])
                {
                    // count +1 for the comparison
                    // count +1 for the assignment
                    dec = 0;
                    // count +1 for the assignment
                }
                if(nums[i] > nums[i -1])
                {
                    // count +1 for the comparison
                    // count +1 for the assignment
                    ins = 0;
                    // count +1 for the assignment
                }
            }
            return ins || dec;
            // count +1 for the return
            // count +1 for the OR
        }
    };
