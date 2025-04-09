#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

// 定義 Stack 的節點結構
struct Node {
    char data;  // 存儲字符 (運算子或括號)
    Node* next; // 指向下一個節點
};

// 使用 linked list 實作 Stack
class Stack {
private:
    Node* top; // 指向堆疊頂端
public:
    Stack() { top = nullptr; } // 初始化堆疊

    // Push 操作：將元素放入堆疊
    void push(char ch) {
        Node* newNode = new Node(); // 創建新節點
        newNode->data = ch; // 設定節點的資料
        newNode->next = top; // 將新節點的next指向當前的 top
        top = newNode; // 下一個top為新節點       
    }
    // Pop 操作：移除並回傳頂端元素
    char pop() {
        if (isEmpty()) { // 檢查堆疊是否為空
            cout << "堆疊為空\n";
            return '\0'; // 返回空字符表示堆疊為空
        }
        char popValue = top->data; // 取得頂端元素的值
        Node* temp = top; // 暫存現在的top節點
        top = top->next; // 將top指向下一個節點
        delete temp; // 釋放舊top節點的記憶體
        return popValue; // 正確回傳頂端資料
    }

    // Peek 操作：取得頂端元素但不移除
    char peek() {
        if (isEmpty()) { // 檢查堆疊是否為空
            cout << "堆疊為空\n";
            return '\0'; // 返回空字符表示堆疊為空
        }
        return top->data; // 回傳頂端資料
    }

    // 判斷堆疊是否為空
    bool isEmpty() {
        return top == nullptr; // 如果top為空則堆疊為空
    }
};

// 判斷運算子(加減乘除) 的優先順序
int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1; // 加減的優先順序最低
    }
    if (op == '*' || op == '/') {
        return 2; // 乘除的優先順序較高
    }
    return 0; // 其他情況返回 0
}

// 將中序表達式 (infix) 轉換為後序表達式 (postfix)
void InfixToPostfix(const char* infix, char* postfix) {
    Stack stack; // 創建一個Stack物件
    int i = 0; // 記錄後序表達式的位置

    for (int j = 0; infix[j] != '\0'; j++) { 
        char token = infix[j]; // 取得當前的字符

        if (isalnum(token)) { // 如果是數字或字母直接加入後序表達式
            postfix[i++] = token; // 把token加入後序表達式
        }
        else if (token == '(') { // 如果是左括號直接推入堆疊
            stack.push(token);
        }
        else if (token == ')') { // 如果是右括號則彈出堆疊直到遇到左括號
                                 // 左括號在堆疊外是優先權最高者,會大於堆疊頂端的任何運算子 
            while (!stack.isEmpty() && stack.peek() != '(') { // 當堆疊不空且頂端不是左括號
                postfix[i++] = stack.pop(); // 彈出堆疊的運算子並加入後序表達式
            }
            if (!stack.isEmpty() && stack.peek() == '(') { // 如果是右括號則彈出堆疊直到遇到左括號
                stack.pop(); // 彈出左括號
            }
        }
        else {
            while (!stack.isEmpty() && precedence(stack.peek()) >= precedence(token)) { // 和堆疊頂端的運算子比較優先權,如果外面的運算子優先權較高,則push
                postfix[i++] = stack.pop(); // 彈出堆疊的運算子並加入後序表達式
            }
            stack.push(token); // 將現在的運算子推入堆疊
        }
    }

    while (!stack.isEmpty()) { // 彈出堆疊中的所有運算子
        postfix[i++] = stack.pop(); // 將堆疊中的運算子加入後序表達式
    }
    postfix[i] = '\0'; 
}

int main() {
    char infix[100], postfix[100];
    cout << "Enter an Infix expression: ";
    cin >> infix; // 輸入中序表達式

    InfixToPostfix(infix, postfix); // 轉換為後序表達式
    cout << "Postfix expression: " << postfix << endl; // 輸出後序表達式

    return 0;
}
