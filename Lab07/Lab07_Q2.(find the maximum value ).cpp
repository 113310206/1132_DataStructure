#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

// 樹的節點
class TreeNode {
public:
    int value;             // 節點的值
    TreeNode* left;        // 左子節點
    TreeNode* right;       // 右子節點

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {} // 初始化節點
};

// 樹結構
class BinaryTree {
public:
    TreeNode* root;

    BinaryTree() : root(nullptr) {} // 初始化樹

    // 用陣列構建二元樹
    TreeNode* buildTree(vector<int>& arr) {
        if (arr.empty()) return nullptr;

        queue<TreeNode*> q; // 建立queue儲存待處理的節點
        root = new TreeNode(arr[0]); // 建立根節點 (陣列第一個元素)
        q.push(root); // 將根節點加入queue

        size_t i = 1; // 陣列索引
        while (!q.empty() ) {//&& i < arr.size()
            TreeNode* current = q.front(); // 取出queue中的節點
            q.pop();

            // 添加左子節點
            if (i < arr.size()) {
                current->left = new TreeNode(arr[i]);
                q.push(current->left); // 將左子節點加入queue
                i++;
            }

            // 添加右子節點
            if (i < arr.size()) {
                current->right = new TreeNode(arr[i]);
                q.push(current->right); // 將右子節點加入queue
                i++;
            }
        }
        return root;
    }

    // 中序遍歷
    void inorderTraversal(TreeNode* node) {
        if (node == nullptr) return; // 如果節點為空，忽略

        inorderTraversal(node->left);  // 遍歷左子樹
        cout << node->value << " ";    // 訪問當前節點
        inorderTraversal(node->right); // 遍歷右子樹
    }
    
    // post遍歷
    void postorderTraversal(TreeNode* node) {
        if (node == nullptr) return; // 如果節點為空，忽略

        postorderTraversal(node->left);  // 遍歷左子樹
        postorderTraversal(node->right); // 遍歷右子樹
        cout << node->value << " ";    // 訪問當前節點
    }

    // 計算樹中所有節點的最大值
    int findMax(TreeNode* node) {
        if (node == nullptr) return 0; // 如果節點為空，返回0
        int l = findMax(node->left); // 遞迴計算左子樹的最大值
        int r = findMax(node->right); // 遞迴計算右子樹的最大值
        return max(node->value, max(l, r)); // 先找左右子樹的最大值，再比現在節點的值
    }

    // 分別回傳左子樹與右子樹的最大值
    void findLRMax(TreeNode* node, int& leftMax, int& rightMax) {
        if (node == nullptr) return; // 如果節點為空，忽略

        // 左子樹最大值
        leftMax = findMax(node->left); // 遞迴計算左子樹的最大值
        // 右子樹最大值
        rightMax = findMax(node->right); // 遞迴計算右子樹的最大值
    }
};

int main() {
    BinaryTree tree; // 宣告二元樹

    // 輸入陣列用於構建樹，NULL 表示空子節點
    vector<int> arr = { 1, 2, 3, 4, 5, 6, 7 };

    tree.buildTree(arr); // 建立樹

    // 中序遍歷輸出
    cout << "Inorder Traversal: ";
    tree.inorderTraversal(tree.root);
    cout << "\n" << "postorder Traversal: ";
    tree.postorderTraversal(tree.root);

    int leftMax, rightMax;
    tree.findLRMax(tree.root, leftMax, rightMax); // 查找最大值
    cout << "\n最大左子樹值: " << leftMax << endl; // 輸出左子樹的最大值
    cout << "最大右子樹值: " << rightMax << endl; // 輸出右子樹的最大值
    cout << endl;

    cin.ignore();
    cin.get(); // 等待用戶輸入以保持控制台開啟
    return 0;
}
