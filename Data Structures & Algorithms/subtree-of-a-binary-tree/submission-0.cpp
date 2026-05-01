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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!subRoot) return true;

        if(!root) return false;

        if(sameTree(root, subRoot)) {
            return true;
        }

        return isSubtree(root -> left, subRoot) ||
               isSubtree(root -> right, subRoot); 
    }

    bool sameTree(TreeNode* root, TreeNode* subTree) {
        if(!root && !subTree) return true;

        if(root && subTree && root -> val == subTree -> val) {
            return sameTree(root -> left, subTree -> left) &&
                   sameTree(root -> right, subTree -> right); 
        }

        return false;
    }
};
