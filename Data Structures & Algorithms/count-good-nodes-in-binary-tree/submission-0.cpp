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
    void cntGoodOnes(TreeNode* root, int maxi, int &cnt) {
        if(root == NULL) return;

        maxi = max(maxi, root -> val);

        if(maxi == root -> val) {
            cnt++;
        }

        if(root -> left) cntGoodOnes(root -> left, maxi, cnt);
        if(root -> right) cntGoodOnes(root -> right, maxi, cnt);

        return;
    }
    int goodNodes(TreeNode* root) {
        int cnt = 0;
        int maxi = INT_MIN;

        cntGoodOnes(root, maxi, cnt);

        return cnt;
    }
};
