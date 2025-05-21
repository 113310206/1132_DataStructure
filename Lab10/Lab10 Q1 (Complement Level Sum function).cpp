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
    
    // 計算指定層的總和
    int sumLayer(TreeNode* root, int targetLayer) {
        if (root == nullptr) return 0;
        queue<TreeNode*> q;//建立queue儲存待處理的節點指標
        q.push(root); // 將根節點的指標加入queue

        int layer = 0; // 假設層數=0
        
        while (!q.empty()) { // queue不為空時
            int layerSize = q.size(); // 當前層的節點數量
            if (layer == targetLayer) { // 如果當前層數等於目標層數
                int sum = 0;
                for(int i = 0; i < layerSize; i++) { // 遍歷當這層所有節點
                    TreeNode* node = q.front();      // 取出queue的第一個節點指標
                    q.pop();                         // 將該節點從queue中刪除
                    sum += node->value;              // 計算總和
                }
                return sum;                          // 返回當前層的總和
            }
            for (int i = 0; i < layerSize; i++) { // 遍歷當前層的所有節點
                TreeNode* current = q.front();    // 遍歷當這層所有節點                           
                q.pop();                          // 取出queue的第一個節點指標
           
                if (current->left) q.push(current->left);   // 將左子節點的指標加入queue
                if (current->right) q.push(current->right); // 將右子節點的指標加入queue
            }
            layer++;
        }
        cout << "Layer not found\n";
        return 0; // 如果沒有找到目標層，返回0
    }
};

int main() {
    BinaryTree tree;
    vector<int> arr = { 1, 2, 3, 4, 5, 6, 7, 8, 9, NULL, NULL, 10, 11, NULL, NULL };
    tree.buildTree(arr);

    // 輸入要查詢的層數
    int targetLayer;
    cout << "Number_of_layers: ";
    cin >> targetLayer;

    cout << "BFS Result: ";
    tree.Breadth_first_search(tree.root, targetLayer);
    cout << endl;

    // 計算指定層的總和
    int sum = tree.sumLayer(tree.root, targetLayer);
    cout <<"SUM: "<< sum << "\n";

    system("pause");
    return 0;
}
