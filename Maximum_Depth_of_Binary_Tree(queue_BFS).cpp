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
    int maxDepth(TreeNode* root) {
        return solution2(root);
    }
private:
    int solution1(TreeNode* root){
        if (root==NULL){
            return 0;
        }
        else{
            return 1+max(maxDepth(root->right), maxDepth(root->left));
        }
    }
    int solution2(TreeNode* root){ // using queue, broad first search
        if (root == NULL) return 0;
        queue<TreeNode *> que;
        que.push(root);
        int deep = 0;
        while (que.empty() == false){
            deep+=1;
            int count = que.size();
            for (int i = 0; i<count; i++){
                TreeNode * node = que.front();
                if (node->right != NULL) que.push(node->right);
                if (node->left != NULL) que.push(node ->left);
                que.pop();
            }
        }
        return deep;
    }
};