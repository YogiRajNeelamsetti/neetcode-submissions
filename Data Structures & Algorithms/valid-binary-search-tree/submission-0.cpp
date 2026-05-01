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
    bool isValidBST(TreeNode* root) {
        return validBst(root, INT_MIN, INT_MAX);
    }

    bool validBst(TreeNode* root, int min, int max) {
        if(root == NULL) return true;

        if(root -> val >= max || root -> val <= min) return false;

        return validBst(root -> left, min, root -> val) &&
               validBst(root -> right, root -> val, max); 
    }
};
