#include <iostream>
using namespace std;

long long int factorial(int n)
{
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}

int main()
{
    int n;
    cout << "Enter a number less than or equal to 20 : ";
    cin >> n;
    long long int ans = factorial(n);
    cout << "The factorial of " << n << " is " << ans;
    return 0;
}