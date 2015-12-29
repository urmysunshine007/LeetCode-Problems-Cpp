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
    TreeNode* invertTree(TreeNode* root) {
        return solution1(root);
    }
    
private:
    TreeNode* solution1(TreeNode* root){
        queue<TreeNode *> que;
        que.push(root);
        while (que.empty()== false){
            TreeNode* node = que.front();
            if(node!= NULL){
            swap(node->left, node->right);
            que.push(node->left);
            que.push(node->right);
            }
            que.pop();
        }
        return root;
    }
    TreeNode* solution2(TreeNode* root){
        if (root == NULL) return root;
        swap(root->right, root->left);
        solution2(root->right);
        solution2(root->left);
        return root;
    }
};