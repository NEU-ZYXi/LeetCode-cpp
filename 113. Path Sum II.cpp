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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ans;
        vector<int> tmp;
        dfs(ans, tmp, root, sum);
        return ans;
    }
    
private:
    void dfs(vector<vector<int>>& ans, vector<int>& tmp, TreeNode* root, int sum) {
        if (!root) {
            return;
        }
        tmp.push_back(root->val);
        if (!root->left && !root->right && root->val == sum) {
            ans.push_back(tmp);
        }
        dfs(ans, tmp, root->left, sum - root->val);
        dfs(ans, tmp, root->right, sum - root->val);
        tmp.pop_back();
    }
};
