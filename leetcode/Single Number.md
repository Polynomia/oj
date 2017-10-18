# Single Number
Given an array of integers, every element appears twice except for one. Find that single one.
## 解析
* 首先是最简单的办法，就是挨个搜索每个元素是否出现了2次，这样的时间复杂度是O(n^2)，代码就不写了。

* 可以先排序然后再搜索每个元素是否出现了两次。这样可以将时间复杂度降到O(nlogn)

```python
class Solution:
    # @param A, a list of integer
    # @return an integer
    def singleNumber(self, A):
        A.sort()
        for i in range(1, len(A), 2):
            if A[i] != A[i-1]: # 与前一元素对比
                return A[i-1]
        return A[-1] # 要找的元素是最后一个元素
```

* 超级炫酷的位运算方法。将所有元素异或起来，最后的结果就是我们要找的Single Number。因为a ^ a = 0, 0 ^ b = b

```c++
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x = 0;
        for(int i=0;i<nums.size();i++){
            x ^= nums[i];
        }
        return x;
    }
};
```


