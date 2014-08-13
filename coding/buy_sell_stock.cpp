#include <iostream>
using namespace std;

void buyStock(int s[], int days, 
              int& buy, int& sell, int& profit)
{
    int min = 0;        // tracking the day of lowest price
    int diff = 0;
    int maxDiff = 0;
    buy = sell = 0;

    for(int i=0; i<days; i++) {
        if(s[i]<s[min]) {
            min = i;
        } 

        diff = s[i] - s[min];
        if(diff > maxDiff) {
            maxDiff = diff;
            buy = min;
            sell = i;
        }
    }

    profit = maxDiff;
}

int main()
{
    //int stock[] = {2,3,1,5,4};
    //int stock[] = {2,3,1,5,4,6};
    //int stock[] = {2};
    int stock[] = {2,1};
    int days = sizeof(stock)/sizeof(int);
    int buy = 0;
    int sell = 0;
    int profit = 0;

    buyStock(stock, days, buy, sell, profit);

    cout << "buy stock at Day " << buy << " with price " << stock[buy] << endl;
    cout << "sell stock at Day " << sell << " with price " << stock[sell] << endl;
    cout << "Profit: " << profit << endl;
    
    return 0;
}
