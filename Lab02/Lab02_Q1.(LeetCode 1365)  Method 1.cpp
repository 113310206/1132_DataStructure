// Method 1
class Solution {
    public:
        vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
            int count = 0;

            int count[101]={0};//計數陣列,範圍 0-100
            int n=num.size();//陣列長度
            vector<int> result(n);//vector<int>是動態陣列,在執行分配記憶體時,可以根據 num.size()自動調整大小
                                  //計算每個數字的出現次數,此迴圈遍歷 nums,並統計每個數字 num 出現的次數 
            count++; //count +1 for the operation
            count++; //count +1 for the operation
            count++; //count +1 for the assignment
            count++; //count +1 for the call of the function
                            
            for(int num:nums){ count[num]++;}//計算比當前數字小的數量
            count++; //count +1 for the for loop
            count++; //count +1 for the operation
            count++; //count +1 for the call of the for loop

            for(int i=1; i<101; i++){//計算 result 陣列
                count++; //count +1 for the for loop
                count[i]+=count[i-1];

                count++; //count +1 for the operation
                count++; //count +1 for the operation in array
            }
            count++; //count +1 for the call of the for loop
    
            for(int i=0; i<n; i++){
                count++; //count +1 for the for loop
                result[i]=(nums[i]==0)?0:count[nums[i]-1];//count[nums[i]-1]代表比 nums[i]小的數的數量,nums[i]==0 時則直接返回 0
                count = count + 5; //count +5 for the operation
            }
            count++; //count +1 for the call of the for loop
            count++; //count +1 for the return
    return result;
    }
};
