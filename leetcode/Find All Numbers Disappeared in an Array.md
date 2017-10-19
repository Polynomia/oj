# Find All Numbers Disappeared in an Array
Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements of [1, n] inclusive that do not appear in this array.

Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.

## example

```
Input:
[4,3,2,7,8,2,3,1]

Output:
[5,6]
```

## 解析
* 首先是自己的思路，类似于元素归类法。将出现过的元素对应的位置设为0，但是为了避免出错，此时这个位置的数也需要归位设为0，就这样递归下去，直到不能再归位为止。

```c++
class Solution {
public:
    void have(int i, vector<int>& nums){
        if(nums[i-1]){
            int tmp = nums[i-1];
            nums[i-1] = 0;
            have(tmp,nums);
        }
    }
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int tmp;
        vector<int> v;
        for(int i = 0; i < nums.size(); i++){
            have(nums[i],nums);
        }
        for(int i = 0; i < nums.size(); i++){
            if(nums[i])
                v.push_back(i+1);
        }
        return v;
    }
};
```

* 巧妙的取负法。只要出现过的元素我们就将对应的位置取负，最后再遍历一遍，为正的index即是没有出现过的。

```c
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
    int* result=(int*)malloc(sizeof(int)*numsSize);

    for(int i=0;i<numsSize;i++)
    {
        int index=abs(nums[i])-1;

        if(nums[index]>0) nums[index]=-nums[index];
    }

    *returnSize=0;

    for(int i=0;i<numsSize;i++)
    {
        if(nums[i]>0)
        {
            result[*returnSize]=i+1;
            *returnSize=*returnSize+1;
        }
    }

    return result;
}
```

* 另一种很巧妙的取余法。数组的元素范围为1~n，第一次循环首先把每个元素对应的位置加上（n+1）；第二次循环把每个位置除以（n+1），如果该位置为0，表示某个元素没有出现；如果该位置等于2，表示出现两次。

```c
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
    int* result=(int*)malloc(sizeof(int)*numsSize);

    *returnSize=0;

    for(int i=0;i<numsSize;i++)
    {
        nums[nums[i]%(numsSize+1)-1]+=(numsSize+1);
    }

    for(int i=0;i<numsSize;i++)
    {
        if(nums[i]/(numsSize+1)==0) 
        {
            result[*returnSize]=i+1;
            *returnSize=*returnSize+1;
        }
    }

    return result;
}
```


