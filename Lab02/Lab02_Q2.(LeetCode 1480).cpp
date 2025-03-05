class Solution {
    public:
        vector<int> runningSum(vector<int>& nums) {
        int n =nums.size(); // n=nums的陣列長度
        vector<int> result(n); // 建立一個大小為n的動態陣列result
        result[0]=nums[0]; // 把nums的值丟進result

        for(int i=1; i<n; i++){ //重複運算n次(陣列長度)
            result[i]=result[i-1]+nums[i]; //陣列中的值等於前一個值加上目前的值
                                           //ex:[1,2,3,4] -> [1,1+2,1+2+3,1+2+3+4]
        }
    return result; //回傳 [1,1+2,1+2+3,1+2+3+4]
    }   
};
