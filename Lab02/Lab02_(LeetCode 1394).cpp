class Solution {
    public:
        int findLucky(vector<int>& arr) {
            int count1 = 0;

            int lucky = -1; //假設沒有找到
            count1 ++; //count +1 for the operation

            for(int i = 0; i < arr.size(); i++) // 跑一輪讓每個數字都重複檢查是否=count
            {
                count1 ++; //count +1 for the for loop
                int count = 0; //count初始化

                count1 ++; //count +1 for the operation
                
                for(int j = 0; j < arr.size(); j++) // 計算有幾個相同的數字
                {
                    count1 ++; //count +1 for the for loop

                    if(arr[j] == arr[i]) //如果相同
                    {
                        count1 ++; //count +1 for the if statement
                        count++; //+1

                        count1 ++; //count +1 for the operation
                    }
                }
                count1 ++; //count +1 for the call of for loop

                if(count == arr[i]) //如果有luckynumber
                {
                    count1 ++; //count +1 for the if statement
                    lucky = max(lucky, arr[i]); //找最大的

                    count1 ++; //count +1 for the operation
                    count1 ++; //count +1 for the max function
                }
            }
            count1++; //count +1 for the call of for loop

            count1++; //count +1 for the return
            return lucky, count1; //回傳luckynumber 和 count1
        }
    };
