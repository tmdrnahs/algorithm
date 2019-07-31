#include <iostream>

using namespace std;

#define SIZE 7
char array[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};
bool mark[] = {false,};

void PowerSet(int k)
{
    if (k == SIZE)
    {
        for (int i = 0; i < SIZE; i++)
            cout << array[i];
    }
    else
    {
        /*
            Under Implementing
        */
        for (int i = k; i < SIZE; i++)
        {
            if (mark[k])
                cout << array[k];
        }
        cout << endl;

        mark[k] = false;
        PowerSet(k+1);
        mark[k] = true;
        PowerSet(k+1);
    }
}

int main(void)
{
    PowerSet(0);
    return 0;
}