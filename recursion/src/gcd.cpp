#include <iostream>

using namespace std;

int GCD(int a, int b)
{
    if (a == 0 || b == 0)
        return 0;
    else if (a < 0 || b < 0)
        return 0;

    int rest = a%b;
    if (rest == 0)
        return b;
    
    return GCD(b, rest);
}

int main(void)
{
    int a = 0;
    int b = 0;

    cout << "Input a: ";
    cin >> a;
    cout << "Input b: ";
    cin >> b;

    cout << GCD(a, b) << endl;
    return 0;
}