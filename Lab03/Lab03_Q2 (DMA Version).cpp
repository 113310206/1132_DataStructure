#include <iostream>
using namespace std;

class poly {
public:
    int* coef; // 儲存多項式的係數 是一個指向整數陣列的指標
    int deg;   // 最高次方項

    poly() : coef(nullptr), deg(0) {} // coef陣列初始化為nullptr deg初始化為0次方

    // 拷貝建構函式 (深拷貝) 確保每個多項式物件擁有獨立的記憶體空間
    poly(const poly& poly2) : deg(poly2.deg) { // 傳入另一個多項式物件
        coef = new int[deg + 1]{0}; // 動態配置記憶體 並初始化為0
        for (int i = 0; i <= deg; i++) {
            coef[i] = poly2.coef[i]; // 複製另一個多項式的係數
        }
    }

    ~poly() { // 釋放記憶體
        delete[] coef;
    }

    void input() { // 輸入多項式
        cout << "請輸入多項式的最高次數(ex: 2x^2+1x+1輸入2): ";
        cin >> deg;

        delete[] coef; // 釋放舊記憶體
        coef = new int[deg + 1]{0}; // 分配記憶體並初始化為0

        cout << "請輸入多項式的係數 (從高次到低次): ";
        for (int i = deg; i >= 0; i--) { // 從高次到低次輸入
            cin >> coef[i];
        }
    }

    void print() const {
        bool first = true; // 假設第一項
        for (int i = deg; i >= 0; i--) { // 從高次到低次輸出
            if (coef[i] != 0) { // 如果係數不為0
                if (!first) cout << " + "; // 如果不是第一項就加號
                first = false; // 不是第一項了
                if (i == 0) { //如果是常數項
                    cout << coef[i];
                } else if (i == 1) { // 如果是一次項
                    cout << coef[i] << "x";
                } else { // 次方項
                    cout << coef[i] << "x^" << i;
                }
            }
        }
        if (first) cout << "0"; // 如果是零多項式
        cout << endl;
    }

    poly polyAdd(const poly& other) const { // 多項式加法
        poly result;
        result.deg = max(deg, other.deg);  
        // 把result物件的deg成員變數設置為當前物件和poly2物件的deg成員變數中的較大值
        // 確保結果多項式的降冪

        result.coef = new int[result.deg + 1]{0}; // 分配記憶體並初始化為0

        for (int i = 0; i <= deg; i++) result.coef[i] += coef[i]; // 把第一個多項式的係數加到result
        for (int i = 0; i <= other.deg; i++) result.coef[i] += other.coef[i]; // 把地二個多項式物件的係數加到result

        return result;
    }

    poly polyMul(const poly& other) const { // 多項式乘法
        poly result;
        result.deg = deg + other.deg; // 多項式的次方數為兩個多項式的次方數相加
        result.coef = new int[result.deg + 1]{0}; // 分配記憶體並初始化為0

        for (int i = 0; i <= deg; i++) {
            for (int j = 0; j <= other.deg; j++) {
                result.coef[i + j] += coef[i] * other.coef[j];
                // 第一個多項式的第i次方的係數與第二個多項式的第j次方的係數相乘
                // 並加到結果多項式的第i+j次方的係數上
            }
        }

        return result;
    }

    int evaluate(int x) const { // 計算多項式在 x 的值
        int result = 0;
        int power = 1; // x的0次方
        for (int i = 0; i <= deg; i++) { // 從0次方開始係數乘以x的冪次方
            result += coef[i] * power; 
            power *= x; // i=1的時候power=x i=2的時候power=x^2 ...
        }
        return result;
    }

};

int main() {
    poly X, Y, Z; // 宣告三個多項式物件 (X是第一個, Y是第二個, Z是結果)多項式
    int x;

    //輸入X(x)和Y(x)
    X.input();
    Y.input();

    // 輸入x的值
    cout << "請輸入 x 的值: ";
    cin >> x;

    // 計算X(x)+Y(x)
    Z = X.polyAdd(Y);
    cout << "X(x) + Y(x) = ";
    Z.print();

    // 計算多項式加法帶入x的結果
    cout << "X(" << x << ") + Y(" << x  << ") = " << Z.evaluate(x) << endl;

    // 計算X(x)*Y(x)
    Z = X.polyMul(Y);
    cout << "X(x) * Y(x) = ";
    Z.print();

    // 計算多項式乘法帶入x的結果
    cout << "X(" << x << ") * Y(" << x << ") = " << Z.evaluate(x) << endl;

    return 0;
}
