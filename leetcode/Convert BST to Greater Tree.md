# Convert BST to Greater Tree
Given a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus sum of all keys greater than the original key in BST.

## example

```
Input: The root of a Binary Search Tree like this:
              5
            /   \
           2     13

Output: The root of a Greater Tree like this:
             18
            /   \
          20     13
```
## 解析
这道题说的是二叉搜索树，我竟然都忘记了这个。二叉搜索树的左节点比中间的小，然后右节点比中间的大。所以这道题可以用递归的方法，先不断向右查找，找到最大的元素，然后再不停地往回加，就可以了。代码如下：

```c++
class Solution {
private:
    int sum = 0;
public:
    void travel(TreeNode* root){
        if(!root) return;
        if(root->right){
            travel(root->right);
        }
        root->val +=sum;
        sum = root->val;
        if(root->left)
            travel(root->left);
    }
    TreeNode* convertBST(TreeNode* root) {
        travel(root);
        return root;
    }
};
```
这其实就是中序遍历反一下，先遍历右节点，再遍历左节点，因此也可用迭代的方法遍历。代码如下：

```c++
class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        if (!root) return NULL;
        int sum = 0;
        stack<TreeNode*> st;
        TreeNode *p = root;
        while (p || !st.empty()) {
            while (p) {
                st.push(p);
                p = p->right;
            }
            p = st.top(); st.pop();
            p->val += sum;
            sum = p->val;
            p = p->left;
        }
        return root;
    }
};
```

