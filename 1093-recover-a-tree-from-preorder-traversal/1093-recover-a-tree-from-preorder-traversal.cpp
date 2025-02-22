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
private:
    int idx = 1;
    void extractNodes(vector<pair<int,int>>& nodes, string traversal) {

        int len = traversal.size();
        int curDepth = 0;
        string curNum = "";

        for(int i=0; i<len; i++) {
            if(traversal[i] == '-') {
                curDepth++;
            } else {
                curNum += traversal[i];

                if(i == len-1 or traversal[i+1] == '-') {
                    nodes.push_back({curDepth, stoi(curNum)});
                    curDepth = 0;
                    curNum = "";
                }
            }
        }

    }
    TreeNode* constructTree(vector<pair<int,int>>& nodes, int curNodeDepth) {

        if(idx == nodes.size()) return nullptr;

        if(nodes[idx].first == curNodeDepth) {

            TreeNode* newNode = new TreeNode(nodes[idx].second);
            idx++;

            newNode->left = constructTree(nodes, curNodeDepth+1);
            newNode->right = constructTree(nodes, curNodeDepth+1);

            return newNode;
        } else return nullptr;

    }

public:
    TreeNode* recoverFromPreorder(string traversal) {

        vector<pair<int, int>> nodes;
        
        extractNodes(nodes, traversal);

        TreeNode* rootNode = new TreeNode(nodes[0].second);

        rootNode->left = constructTree(nodes, 1);
        rootNode->right = constructTree(nodes, 1);

        return rootNode;
        
    }
};