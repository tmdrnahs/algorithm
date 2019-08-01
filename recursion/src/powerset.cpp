#include <iostream>

using namespace std;

#define SIZE 4
char array[] = {'a', 'b', 'c', 'd'};
bool mark[SIZE];

void PowerSet(int k)
{
    if (k == SIZE) {
        for (int i = 0; i < SIZE; i++) {
            if (mark[i])
                cout << array[i];
        }
        cout << endl;
        return;
    }

    mark[k] = false;
    PowerSet(k+1);

    mark[k] = true;
    PowerSet(k+1);
}

int main(void)
{
    PowerSet(0);
    return 0;
}