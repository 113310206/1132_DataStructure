
class Solution {
    public:
        bool isMonotonic(vector<int>& nums) {
            int count = 0;
            bool ins = 1, dec = 1;
            // count +2 for the assignment
            count = count+2;
            for(size_t i = 1; i < nums.size(); i++)
            {
                // count +1 for the comparison
                // count +1 for the increment
                // count +1 for the initialization
                count = count + 3;
                if(nums[i] < nums[i - 1])
                {
                    // count +1 for the comparison
                    // count +1 for the assignment
                    count = count + 2;
                    dec = 0;
                    // count +1 for the assignment
                    count++;
                }
                if(nums[i] > nums[i -1])
                {
                    // count +1 for the comparison
                    // count +1 for the assignment
                    count = count + 2;
                    ins = 0;
                    // count +1 for the assignment
                    count++;
                }
            }
            return ins || dec;
            // count +1 for the return
            // count +1 for the OR
            count = count + 2;
            return count;
        }
    };
