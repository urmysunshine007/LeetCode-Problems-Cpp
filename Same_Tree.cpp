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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> que1, que2;
        que1.push(p);
        que2.push(q);
        while (!que1.empty() and !que2.empty()){
            TreeNode* p1 = que1.front();
            TreeNode* p2 = que2.front();
            if ((p1 == NULL and p2==NULL)){}
            else if (p1 == NULL or p2==NULL) return false;
            else if (p1->val != p2->val) return false;
            else{
                if (p1->left!=NULL) que1.push(p1->left);
                else que1.push(NULL);
                if (p1->right!=NULL) que1.push(p1->right);
                else que1.push(NULL);
                if (p2->left!=NULL) que2.push(p2->left);
                else que2.push(NULL);
                if (p2->right!=NULL) que2.push(p2->right);
                else que2.push(NULL);
            }
            que1.pop();
            que2.pop();
        }
        if (!que1.empty() or !que2.empty()) return false;
        return true;
    }
};