#include <iostream>

using namespace std;

int Factorial(int n)
{
    if (n == 0)
        return 1;

    return n * Factorial(n-1);
}

int main(void)
{
    int n = 0;
    cout << "Input 'N': ";
    cin >> n;

    cout << Factorial(n) << endl;
    return 0;
}