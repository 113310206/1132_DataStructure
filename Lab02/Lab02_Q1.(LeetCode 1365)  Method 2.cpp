// Method 2
class Solution {
    public:
        vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int count1 = 0; //初始化計數器
        vector<int> result; // 存結果
        int count; // 計數器
    
        count1 ++; //count +1 for the call of the function
        count1 ++; //count +1 for the initialization

        for (int i = 0; i < nums.size(); i++) { // 外層迴圈遍歷 nums 陣列中的每個元素
            count1 ++; //count +1 for the for loop
            count = 0; // 每次重新計算當前元素的較小數量
            
            count1 ++; //count +1 for the operation
                for (int j = 0; j < nums.size(); j++) { // 內層迴圈再次遍歷 nums 陣列,統計比 nums[i] 小的元素數量
                    count1 ++; //count +1 for the for loop
                    if (nums[j] < nums[i]) { count++; } // 如果 nums[j] 比nums[i] 小,則計數器 +1
                    count1 ++; //count +1 for the if statement
                    count1 ++; //count +1 for the operation
                    //count +1 for the if statement
                }
                count1 ++; //count +1 for the call of the for loop
                result.push_back(count); // 將計算出的數量存入 result

                count1 ++; //count +1 for the call of the function
        }
        count1 ++; //count +1 for the call of the for loop
        count1 ++; //count +1 for the return

    return result, count1;
    }
};
