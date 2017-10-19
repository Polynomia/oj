# Maximum Depth of Binary Tree
Given a binary tree, find its maximum depth.
## 解析
没什么好的思路，就只有递归：

```c++
class Solution {
public:
    int maxDepth(TreeNode* root) {
        return root == NULL ? 0 : max(maxDepth(root -> left), maxDepth(root -> right)) + 1;
        
    }
};
```


