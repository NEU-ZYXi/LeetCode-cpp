/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        if (n == 0) {
            return NULL;
        }
        return build(inorder, 0, n - 1, postorder, 0, n - 1);
    }
    
private:
    TreeNode* build(vector<int>& inorder, int l1, int r1, vector<int>& postorder, int l2, int r2) {
        if (l1 > r1 || l2 > r2) {
            return NULL;
        }
        TreeNode *root = new TreeNode(postorder[r2]);
        int root_idx = l1;
        while (root_idx <= r1) {
            if (inorder[root_idx] == root->val) {
                break;
            }
            root_idx++;
        }
        root->left = build(inorder, l1, root_idx - 1, postorder, l2, root_idx - 1 - l1 + l2);
        root->right = build(inorder, root_idx + 1, r1, postorder, r2 - r1 + root_idx, r2 - 1);
        return root;
    }
};
