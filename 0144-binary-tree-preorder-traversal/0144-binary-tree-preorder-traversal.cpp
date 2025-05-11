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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        if(root == nullptr) {
            return preorder;
        }
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()) {
            TreeNode* Root=st.top();
            st.pop();
            preorder.push_back(Root->val);
            if(Root->right != nullptr) st.push(Root->right);
            if(Root->left != nullptr) st.push(Root->left);
        }
        return preorder;
    }
};