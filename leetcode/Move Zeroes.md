# Move Zeroes
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

For example, given nums = `[0, 1, 0, 3, 12]`, after calling your function, nums should be `[1, 3, 12, 0, 0]`.

## 解析
这道题没有看到很惊艳的思路，但是我最开始做错了...因为我竟然用了快排的做法，没有看到题目里的要求`maintaining the relative order of the non-zero elements`

所以这道题只需要用两个指针，一个寻找非零元素，一个标记位置即可。代码如下：

```c++
class Solution {
public: 
    void moveZeroes(vector<int>& nums) {
        int j =0;
        int tmp;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i]!=0){
                tmp = nums[j];
                nums[j] = nums[i];
                nums[i] = tmp;
                j++;
            }
        }
    }
};
```

