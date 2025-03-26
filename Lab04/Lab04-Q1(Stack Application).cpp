#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;
// 表示單張撲克牌的類別
class Card {
public:
    string colors; //儲存撲克牌的花色
    string rank; //儲存撲克牌的數值
    Card(string s, string r) : colors(s), rank(r) {} //建立constructor來初始化物件，當Card物件建立時，它會自動執行這個函式，並把s和r的值存入colors和rank
    void display() const { //顯示撲克牌的資訊
        cout << rank << " of " << colors << endl;
    }
};

// 實作Stack
class Stack {
private:
    vector<Card> stack; //表示stack是一個能存放Card類別物件的vector

public:
    void push(const Card& card) {
        stack.push_back(card); // 把card這張牌放入stack這個vector
    }

    Card pop() {
        if(!stack.empty()) { // 如果stack不是空的
            Card lastCard = stack.back(); // 取出stack的最後一張牌
            stack.pop_back(); // 把最後一張牌刪掉
            return lastCard; // 回傳最後一張牌
        }
    }

    bool isEmpty() const {
        return stack.empty(); // 如果stack是空的 return 1
    }
};

// 代表一副撲克牌的類別
class Deck {
private:
    vector<Card> cards; // 存放未洗牌的撲克牌
    Stack shuffledDeck; // 存放洗過的牌，用實作的stack來管理
public:
    Deck() { //建立constructor來初始化物件
        string colors[] = { "Hearts", "Diamonds", "Clubs", "Spades" }; //儲存撲克牌的花色
        string ranks[] = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A" }; //儲存撲克牌的數值

        //利用迴圈將52張牌加入cards這個vector裡面
        for (int i = 0; i < 4; i++) { // 四種花色
            for (int j = 0; j < 13; j++) { // 13 種點數
                cards.push_back(Card(colors[i], ranks[j]));
            }
        }
    }

    //洗牌(Hint:使用shuffle函數)
    void shuffleDeck() {
        random_device rand; // 產生一個隨機數
        mt19937 r(rand());  // 產生一個以rand()為種子的mt19937物件
        shuffle(cards.begin(), cards.end(), r); // 將cards這個vector裡面的牌洗亂

        for(int i = 0; i < cards.size(); i ++) {
            shuffledDeck.push(cards[i]); // 把cards洗完的牌放入shuffledDeck這個stack
        }
    }

    //發牌
    void drawAllCards() {
        while (!shuffledDeck.isEmpty()) { // shuffledDeck不是空的時候，就發牌
            shuffledDeck.pop().display(); // 取出一張牌並顯示
        }
    }
};

int main() {
    Deck deck; //建立deck產生52張撲克牌
    deck.shuffleDeck(); //進行洗牌並放入堆疊
    cout << "Shuffled deck:" << endl;
    deck.drawAllCards(); //依序取出堆疊內的牌並顯示
    return 0;
}
