#include <iostream>
#define MAX_DEGREE 106 //最高次方數

using namespace std;

class poly { 
public:
    int coef[MAX_DEGREE + 1]; // 係數數量
    int deg; // 最高次方

    poly() : deg(0) { // 把所有係數設為0  poly預設的多項式是常數0
        for (int i = 0; i <= MAX_DEGREE; i++) {
            coef[i] = 0;
        }
    }

    void input() {
        cout << "請輸入多項式的最高次數(ex: 2x^2+1x+1輸入2): ";
        cin >> deg; 

        for (int i = 0; i <= deg; i++) {
            coef[i] = 0; // 把所有係數設為0
        }

        cout << "請輸入多項式的係數(ex: 1x+1輸入1 1): ";
        for (int i = deg; i >= 0; i--) {
            cin >> coef[i];
        }
    }

    void print() const { // 印出結果
        bool first = true; // 假設是第一項

        for (int i = deg; i >= 0; i--) { // 從最高次方開始
            if (coef[i] != 0) { // 如果係數不為0
                if (!first) { // 又如果不是第一項
                    cout << "+";
                } else {
                    first = false; 
                }
                if (i == 0) { // 如果是常數項
                    cout << coef[i];
                } else if (i == 1) { // 如果是一次項
                    cout << coef[i] << "x";
                } else { // 次方項
                    cout << coef[i] << "x^" << i;
                }
            }
        }
        if (first) { // 如果是第一項
            cout << "0";
        }
        cout << endl;
    }

    poly add(const poly& poly2) const { // 多項式加法 
        poly result; 
        result.deg = max(deg, poly2.deg); 
        // 把result物件的deg成員變數設置為當前物件和poly2物件的deg成員變數中的較大值
        // 確保結果多項式的降冪

        for (int i = 0; i <= result.deg; i++) {
            result.coef[i] = 0;  // 把所有係數設為0
        }

        for (int i = 0; i <= deg; i++) result.coef[i] += coef[i]; // 把第一個多項式的係數加到result
        for (int i = 0; i <= poly2.deg; i++) result.coef[i] += poly2.coef[i]; // 把地二個多項式物件的係數加到result

        return result;
    }

    poly multiply(const poly& poly2) const { // 多項式乘法
        poly result;
        result.deg = deg + poly2.deg; // 多項式的次方數為兩個多項式的次方數相加

        for (int i = 0; i <= result.deg; i++) result.coef[i] = 0;  // 初始化為 0

        for (int i = 0; i <= deg; i++) {
            for (int j = 0; j <= poly2.deg; j++) {
                result.coef[i + j] += coef[i] * poly2.coef[j]; 
                // 第一個多項式的第i次方的係數與第二個多項式的第j次方的係數相乘
                // 並加到結果多項式的第i+j次方的係數上
            }
        }

        return result;
    }

    int evaluate(int x) const { // 計算多項式的值 
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
    int x; // 計算值 

    //輸入X(x)和Y(x)
    X.input();
    Y.input();

    // 輸入x的值
    cout << "請輸入 x 的值: ";
    cin >> x;

    // 計算X(x)+Y(x)
    Z = X.add(Y);
    cout << "X(x) + Y(x) = ";
    Z.print();

    // 計算多項式加法帶入x的結果
    cout << "X(" << x << ") + Y(" << x << ") = " << Z.evaluate(x) << endl;

    // 計算 X(x)*Y(x)
    Z = X.multiply(Y);
    cout << "X(x) * Y(x) = ";
    Z.print();

    // 計算多項式乘法帶入x的的結果
    cout << "X(" << x << ") * Y(" << x << ") = " << Z.evaluate(x) << endl;

    return 0;
}
