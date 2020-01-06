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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        vector<TreeNode*> stk;
        TreeNode *cur = root;
        while (!stk.empty() || cur) {
            while (cur) {
                stk.push_back(cur);
                cur = cur->left;
            }
            cur = stk.back();
            stk.pop_back();
            ans.push_back(cur->val);
            cur = cur->right;
        }
        return ans;
    }
};




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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        dfs(ans, root);
        return ans;
    }
    
private:
    void dfs(vector<int>& ans, TreeNode* root) {
        if (!root) {
            return;
        }
        dfs(ans, root->left);
        ans.push_back(root->val);
        dfs(ans, root->right);
    }
};
