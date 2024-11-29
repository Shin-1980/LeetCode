#include<iostream>
#include<new>

struct TreeNode {
    std::string val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(): val(), left(nullptr), right(nullptr) {}
    TreeNode(std::string x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(std::string x, TreeNode* l, TreeNode* r): val(x), left(l), right(r) {}
};

class Solution {
    TreeNode* createNode(const std::string& branch, TreeNode* left, TreeNode* right) {

        TreeNode* node = new TreeNode();
        node->val = branch;
        node->left = left;
        node->right = right;

        return node;
    }

    int getPrecedence(const std::string& ope){
        if (ope == "+" || ope == "-") return 1;
        if (ope == "*" || ope == "/") return 2;
        
        return 0;
    }

public:
    TreeNode* arithMeticBinaryTree(const std::string& expression) {
        std::vector<std::string> tokens;
        std::string num;

        for(auto c: expression) {
            if (isdigit(c)) {
                num += c;
            }
            else {
                if (!num.empty()) {
                    tokens.push_back(num);
                    num.clear();
                }
                
                if (c == '+' || c == '-' || c == '*' || c== '/') {
                    tokens.push_back(std::string(1, c));
                }
            }
        }

        if (!num.empty()){
            tokens.push_back(num);
        }

        for (auto token: tokens) std::cout << token << ' ';
        std::cout << std::endl;

        std::stack<TreeNode*> nodes;
        std::stack<std::string> branches;

        for (auto token: tokens) {
            if (isdigit(token[0])) {
                TreeNode* node = new TreeNode(token);
                nodes.push(node);
            }
            else {
                if (!branches.empty() && (getPrecedence(branches.top()) > getPrecedence(token))) {
                    std::string branch = branches.top();
                    branches.pop();
                    TreeNode* node_r = nodes.top();
                    nodes.pop();
                    TreeNode* node_l = nodes.top();
                    nodes.pop();

                    nodes.push(createNode(branch, node_l, node_r));
                }
                
                branches.push(token);
                
            }
        }

        while (branches.size() > 0) {
            std::string operand = branches.top();
            //std::cout << operand << std::endl;
            branches.pop();

            TreeNode* right = nodes.top();
            nodes.pop();
            TreeNode* left = nodes.top(); 
            nodes.pop();

            nodes.push(createNode(operand, left, right));

        }

        return nodes.top();    

    }
};


bool testCase1() {

    Solution sl = Solution();

    std::string expression = "3 + 2 * 5";

    TreeNode* res = sl.arithMeticBinaryTree(expression);

    std::queue<TreeNode*> que_output;
    que_output.push(res);

    TreeNode* ansRoot = new TreeNode("+");
    ansRoot->left = new TreeNode("3");
    ansRoot->right = new TreeNode("*");
    ansRoot->right->left = new TreeNode("2");
    ansRoot->right->right = new TreeNode("5");
    
    std::queue<TreeNode*> que_ans;
    que_ans.push(ansRoot);

    TreeNode* node_output;
    TreeNode* node_ans;

    while (!que_output.empty() || !que_ans.empty()) {
        node_output = que_output.front();
        que_output.pop();
        if (node_output->left != NULL) que_output.push(node_output->left);
        if (node_output->right != NULL) que_output.push(node_output->right);
    
        node_ans = que_ans.front();
        que_ans.pop();
        if (node_ans->left != NULL) que_ans.push(node_ans->left);
        if (node_ans->right != NULL) que_ans.push(node_ans->right);

        if (node_output->val != node_ans->val) return false;

    }

    std::cout << std::endl;

    return true;

}

bool testCase2() {

    Solution sl = Solution();

    std::string expression = "3 * 2 + 5";

    TreeNode* res = sl.arithMeticBinaryTree(expression);

    std::queue<TreeNode*> que_output;
    que_output.push(res);

    TreeNode* ansRoot = new TreeNode("+");
    ansRoot->left = new TreeNode("*");
    ansRoot->right = new TreeNode("5");
    ansRoot->right->left = new TreeNode("3");
    ansRoot->right->right = new TreeNode("2");
    
    std::queue<TreeNode*> que_ans;
    que_ans.push(ansRoot);

    TreeNode* node_output;
    TreeNode* node_ans;

    while (!que_output.empty() || !que_ans.empty()) {
        node_output = que_output.front();
        que_output.pop();
        if (node_output->left != NULL) que_output.push(node_output->left);
        if (node_output->right != NULL) que_output.push(node_output->right);
    
        node_ans = que_ans.front();
        que_ans.pop();
        if (node_ans->left != NULL) que_ans.push(node_ans->left);
        if (node_ans->right != NULL) que_ans.push(node_ans->right);

        std::cout << node_output->val << "," << node_ans->val << std::endl;
        if (node_output->val != node_ans->val) return false;

    }

    std::cout << std::endl;

    return true;

}


int main(){

    bool result;
    int testCount = 0;
    
    result = testCase1();
    testCount++;
    if (result) std::cout << "PATH" << testCount << std::endl;
    else std::cout << "ERROR" << testCount << std::endl;

    result = testCase2();
    testCount++;
    if (result) std::cout << "PATH" << testCount << std::endl;
    else std::cout << "ERROR" << testCount << std::endl;

}