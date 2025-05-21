#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int EMPTY = NULL; // 用 NULL 代表沒有節點
class TreeNode {
public:
    int value;// 節點值
    TreeNode* left;// 左子節點
    TreeNode* right;// 右子節點

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}//初始化節點
};

class BinaryTree {
public:
    TreeNode* root;// 樹根節點

    BinaryTree() : root(nullptr) {}

    TreeNode* buildTree(const vector<int>& arr) {// 建立樹
        if (arr.empty() || arr[0] == EMPTY) return nullptr;

        queue<TreeNode**> q;//建立queue儲存待處理的節點指標
        root = new TreeNode(arr[0]);// 建立根節點 (陣列第一個元素)
        q.push(&root);// 將根節點的指標加入queue

        size_t i = 1;// 陣列索引
        while (!q.empty() && i < arr.size()) {
            TreeNode** nodePtr = q.front();// 取出queue的第一個節點指標
            q.pop();// 將該節點從queue中刪除

            // 左子節點
            if (i < arr.size()) {
                if (arr[i] != EMPTY) {
                    (*nodePtr)->left = new TreeNode(arr[i]);// 添加左子節點
                    q.push(&((*nodePtr)->left));// 將左子節點的指標加入queue
                }
                i++;
            }
            // 右子節點
            if (i < arr.size()) {
                if (arr[i] != EMPTY) {
                    (*nodePtr)->right = new TreeNode(arr[i]);// 添加右子節點
                    q.push(&((*nodePtr)->right));// 將右子節點的指標加入queue
                }
                i++;
            }
        }
        return root;
    }

    void Breadth_first_search(TreeNode* root, int targetLayer) {
        if (root == nullptr) return;
        queue<TreeNode*> q;//建立queue儲存待處理的節點指標
        q.push(root); // 將根節點的指標加入queue

        int layer = 0;
        while (!q.empty()) {
            TreeNode* current = q.front();// 取出queue的第一個節點指標
            q.pop();// 將該節點從queue中刪除
            cout << current->value << " ";
            if (current->left) q.push(current->left);  // 將左子節點的指標加入queue
            if (current->right) q.push(current->right);// 將左子節點的指標加入queue
        }
    }

        // 尋找指定值的節點
    TreeNode* findNode(TreeNode* root, int val) {
        if (!root) return NULL;                           // 如果節點為空，返回NULL
        if (root->value == val) return root;              // 如果找到，返回該節點
                                                          // 如果沒找到，則在左子樹和右子樹中尋找
        TreeNode* leftResult = findNode(root->left, val); // 遞迴尋找左子樹
        if (leftResult) return leftResult;                // 如果找到，返回該節點
                                                          // 如果在左子樹沒有找到，則在右子樹尋找
        return findNode(root->right, val);                // 遞迴尋找右子樹
    }

    //計算子樹總和
    int subtreeSum(TreeNode* node) { 
        if (!node) return 0;
        return node->value + subtreeSum(node->left) + subtreeSum(node->right); // 遞迴計算子樹的總和
    }
};

int main() {
    BinaryTree tree;
    vector<int> arr = { 1, 2, 3, 4, 5, 6, 7, 8, 9, NULL, NULL, 10, 11, NULL, NULL };
    tree.buildTree(arr);

    // 輸入節點值，計算左右子樹總和
    int nodeVal;
    cout << "enter node: ";
    cin >> nodeVal;
    TreeNode* node = tree.findNode(tree.root, nodeVal); // 尋找指定值的節點
    if (!node) {
        cout << "no find\n";
    } else if (!node->left && !node->right) { // 如果節點沒有子樹
        cout << "The node is a leaf node and has no subtrees." << "\n"; 
    } else {
        int leftSum = tree.subtreeSum(node->left);   // 計算左子樹總和
        int rightSum = tree.subtreeSum(node->right); // 計算右子樹總和
        cout << "left subtrees sum: " << leftSum << endl;
        cout << "right subtrees sum: " << rightSum << endl;
        if (leftSum > rightSum)                      // 如果左子樹總和大於右子樹總和
            cout << "left subtrees sum bigger\n";
        else if (rightSum > leftSum)                 // 如果右子樹總和大於左子樹總和
            cout << "right subtrees sum bigger\n";
        else
            cout << "left=right subtree\n";
    }

    system("pause");
    return 0;
}
