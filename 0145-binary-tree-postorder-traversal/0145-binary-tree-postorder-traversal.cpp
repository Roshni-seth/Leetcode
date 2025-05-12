/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st1, st2;
        TreeNode* node=root;
        TreeNode* temp;
        vector<int> ans;
        if(node == nullptr) return ans;
        st1.push(node);
        while(!st1.empty()) {
            node=st1.top();
            st2.push(node);
            st1.pop();
            if(node->left != nullptr) st1.push(node->left);
            if(node->right != nullptr) st1.push(node->right);
        }
        while(!st2.empty()) {
            temp=st2.top();
            ans.push_back(temp->val);
            st2.pop();
        }
        return ans;
    }
};