#include <vector>
#include <iostream>
using namespace std;

int maxProfit(vector<int>& prices){
    int n = prices.size();
    if(n <= 1)
        return 0;
    int maxpro = (prices[1] > prices[0])? (prices[1] - prices[0]): 0;
    int minprz = (prices[1] < prices[0]) ? prices[1] : prices[0];
    for(int i = 2; i < n; i++){
        int cpro = prices[i] - minprz;
        if(cpro > maxpro)
            maxpro = cpro;
        if(prices[i] < minprz)
            minprz = prices[i];
    }
    return maxpro;
}

int main(){
    int a[] = {2,1,0,-1,-2};
    vector<int> aa(a, a+5);
    cout << maxProfit(aa) << endl;
    return 0;
}
