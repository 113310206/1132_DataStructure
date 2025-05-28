#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 從檔案讀取資料，分別存入 names, date, popular
void readFromFile(const string& filename, vector<string>& names, vector<int>& date, vector<int>& popular) {
    ifstream file(filename);
    if (!file) {
        cerr << "can't open " << filename << endl;
        return;
    }

    int quantity = 0; // 商品數量
    file >> quantity; // 讀取商品數量
    file.ignore();    // 忽略換行符號

    for (int i = 0; i < quantity; i++) { // 讀取每一行資料 有幾個商品讀幾次
        string line;                     // 儲存每一行資料
        getline(file, line);             // 讀取一行資料
        istringstream iss(line);         // 使用 istringstream 拆分每行資料
        vector<string> tokens;           // 儲存拆分後的字串
        string word;                     // 儲存每個字串
        while (iss >> word) {            // 逐字讀取   
            tokens.push_back(word);      // 將字串加入 tokens   
        }

        string name;                                     // 儲存商品名稱
        for (size_t j = 0; j < tokens.size() - 2; j++) { // 最後兩個是日期和人氣
            if (j > 0) name += " ";                      // 名稱中間有空格的情況
            name += tokens[j];                           // 將名稱組合起來
        }
        int d = stoi(tokens[tokens.size() - 2]);         // 倒數第二個是日期
        int p = stoi(tokens[tokens.size() - 1]);         // 最後一個是人氣

        names.push_back(name); // 將商品名稱加入 names
        date.push_back(d);     // 將日期加入 date
        popular.push_back(p);  // 將人氣加入 popular
    }
    file.close();
}

class Record { // 紀錄商品的類別
public:
    string name;   // 名稱
    int date;      // 日期
    int popular;   // 人氣

    Record(string n, int d, int p) : name(n), date(d), popular(p) {} // 建構函式，呼叫名稱、日期、人氣

    bool operator<(const Record& other) const { // 運算子重載
                return date < other.date; // 依日期排序
    }
 
    bool operator>(const Record& other) const { // 運算子重載
        return popular < other.popular; // 依人氣排序
    }
};

void bobbleSort(vector<Record>& productItem) { // 用bobbleSort排序日期、人氣
    int n = productItem.size(); 
    for(int i = 0; i < n - 1; i++) { // 排序趟數(來回比較)
        for(int j = 0; j < n - i - 1; j++) { // 比較相鄰兩個元素
                if(productItem[j].date > productItem[j + 1].date || productItem[j].date == productItem[j + 1].date && productItem[j].popular < productItem[j + 1].popular) {
                    // 1.有效期限即將到期的商品應該放在更顯眼的位置。
                    // 2.有效期限相同的商品中，熱銷程度高的商品應該放在更顯眼的位置 。
                    swap(productItem[j], productItem[j + 1]); // 交換兩個商品位置
                }
        }
    }
}

int main() {
    string filename = "C:/Coding/c++/ds/input3.txt";//請貼上input檔案的正確路徑
    vector<string> names; // 儲存商品名稱
    vector<int> date;     // 儲存商品日期
    vector<int> popular;  // 儲存商品人氣
    readFromFile(filename, names, date, popular); // 從檔案讀取資料

    if (names.empty()) {
        cerr << "No valid data found in file." << endl;
        return -1;
    }

    vector<Record> productItem; // 儲存紀錄商品類別
    for (size_t i = 0; i < names.size(); i++) { 
        productItem.emplace_back(names[i], date[i], popular[i]); // 將讀取到的資料存入 productItem
    }

    bobbleSort(productItem); // 使用 bobbleSort 依日期和人氣排序
    cout << "Sorted productItem :\n";
    for(const auto& record : productItem) {
        cout << record.name << "\n"; // 輸出排序後的商品名稱
    }

    return 0;
}
