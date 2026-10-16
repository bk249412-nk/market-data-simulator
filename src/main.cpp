#include <iostream>
#include <vector>
#include <random>
#include <iomanip>
#include <algorithm>
#include <cmath>
using namespace std;

struct Stock {
    string symbol;
    double price;
    double initialPrice;
    vector<double> history;
};

double movingAverage(const vector<double>& prices) {
    int n = prices.size();
    int start = max(0, n - 5);
    double sum = 0;

    for (int i = start; i < n; i++)
        sum += prices[i];

    return sum / (n - start);
}

int main() {
 vector<Stock> stocks = {
    {"AAPL", 230, 230, {}},
    {"MSFT", 510, 510, {}},
    {"TSLA", 350, 350, {}}
    };

    mt19937 rng(random_device{}());
    uniform_real_distribution<double> change(-2, 2);

    cout << fixed << setprecision(2);
    cout << "=== Market Data Simulator ===\n";

    for (int tick = 1; tick <= 10; tick++) {
        cout << "\nUpdate " << tick << "\n";

        for (auto& stock : stocks) {
            stock.price = max(0.01, stock.price + change(rng));
            stock.history.push_back(stock.price);
double changePercent =
    (stock.price - stock.initialPrice)
    / stock.initialPrice * 100;

cout << stock.symbol
     << " | Price: $" << stock.price
     << " | MA-5: $" << movingAverage(stock.history)
     << " | Change: " << changePercent << "%";

if (abs(changePercent) >= 1.0)
    cout << " | PRICE ALERT!";

cout << '\n';

        }
    }

    return 0;
}
