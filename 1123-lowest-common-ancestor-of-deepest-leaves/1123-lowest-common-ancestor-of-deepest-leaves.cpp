class Solution {
public:
    TreeNode* helper(unordered_set<TreeNode*>&s, TreeNode *root){
        if(!root) return NULL;
        if(s.count(root))return root;
        TreeNode* l = helper(s, root->left);
        TreeNode* r = helper(s, root->right);
        if(l && r)return root;
        return l ? l : r;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) { 
        unordered_set<TreeNode*>s;
        queue<TreeNode*>q;
        q.push(root);
        while(q.size()){
            int n = q.size();
            s.clear();
            while(n--){
                TreeNode* temp = q.front();
                q.pop();
                s.insert(temp);
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
        }
        return helper(s, root);
    }
};