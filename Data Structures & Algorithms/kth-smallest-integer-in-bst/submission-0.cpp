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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> pre;
        int cnt = 0;

        TreeNode* curr = root;
        int ans;
        while(curr != NULL) {
            
            if(curr -> left == NULL) {
                pre.push_back(curr -> val);
                cnt++;
                if(cnt == k) {
                    ans = curr -> val;
                    break;
                }
                curr = curr -> right;
            } else {
                TreeNode* prev = curr -> left;
                while(prev -> right && prev -> right != curr) {
                    prev = prev -> right;
                }

                if(prev -> right == NULL) {
                    prev -> right = curr;
                    curr = curr -> left;
                } else {
                    prev -> right = NULL;
                    pre.push_back(curr -> val);
                    cnt++;
                    if(cnt == k) {
                        ans = curr -> val;
                        break;
                    }
                    curr = curr -> right;
                }
            }
            
        }
        return ans;
    }
};
