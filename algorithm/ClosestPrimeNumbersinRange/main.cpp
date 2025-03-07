#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isPrime(int n) {
        if (n <= 1) return false;
        if (n <= 3) return true;
        if (n % 2 == 0 || n % 3 == 0) return false;
        for (int i = 5; i * i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0) return false;
        }
        return true;
    }

    vector<int> closestPrimes(int left, int right) {
        if (left > right) return {-1, -1};
        vector<int> primes;
        for (int i = left; i <= right; i++) {
            if (isPrime(i)) {
                primes.push_back(i);
            }
        }
        if (primes.size() < 2) return {-1, -1};
        int minDiff = INT_MAX;
        int closestPair[2] = {-1, -1};
        for (int i = 0; i < primes.size() - 1; i++) {
            int diff = primes[i + 1] - primes[i];
            if (diff < minDiff) {
                minDiff = diff;
                closestPair[0] = primes[i];
                closestPair[1] = primes[i + 1];
            }
        }
        return vector<int>(closestPair, closestPair + 2);
    }
};

int main() {
    Solution solution;
    vector<int> result = solution.closestPrimes(10, 30);
    cout << result[0] << " " << result[1] << endl;
    return 0;
}
