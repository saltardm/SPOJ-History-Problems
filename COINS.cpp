//Straight-forward memoization, implementing this : http://www.algorithmist.com/index.php/SPOJ_COINS
#include <iostream>
#include <algorithm>
using namespace std;
 
const int M = 1000000;
long long memo[M];
 
long long f(int n)
{
    if (n < M && memo[n] != -1)
        return memo[n];
 
    if (n == 0)
        return 0;
 
    long long change = f(n/2) + f(n/3) + f(n/4);
    long long result;
 
    if (n < change)
        result = change;
    else
        result = n;
 
    if (n < M)
        return memo[n] = result;
    else
        return result;
}
 
int main()
{
    memset(memo, -1, sizeof(memo));
    int n;
    while (cin >> n) {
        cout << f(n) << endl;
    }
}


