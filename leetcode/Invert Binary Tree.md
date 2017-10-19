# Invert Binary Tree
Invert a binary tree.

```
     4
   /   \
  2     7
 / \   / \
1   3 6   9
    
to

     4
   /   \
  7     2
 / \   / \
9   6 3   1
```

# 解析
* 递归

```c++
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root != NULL){
            invertTree(root->left);
            invertTree(root->right);
            TreeNode* tmp;
            tmp = root->left;
            root->left  = root -> right;
            root -> right = tmp;
        }       
        return root;
    }
};
```
* 非递归的做法：BFS和DFS，BFS用队列，DFS用栈。

```c++
// Non-Recursion,BFS
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return NULL;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode *node = q.front(); q.pop();
            TreeNode *tmp = node->left;
            node->left = node->right;
            node->right = tmp;
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        return root;
    }
};
```

