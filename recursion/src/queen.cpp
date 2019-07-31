#include <iostream>
#include <complex>

using namespace std;

#define SIZE 8

int position[SIZE+1] = {0,};

bool isPromising(int level)
{
    for (int i = 1; i < level; i++)
    {
        if (position[level] == position[i])
            return false;
        else
        {
            int distance_x = abs(position[level] - position[i]);
            int distance_y = level - i;
            if (distance_x == distance_y)
                return false;
        }
    }

    return true;
}

bool queen(int level)
{
    if (!isPromising(level))
        return false;
    else if (level == SIZE)
        return true;
    else
    {
        for (int i = 1; i < SIZE+1; i++)
        {
            position[level+1] = i;
            if (queen(level+1))
                return true;
        }
    }

    return false;
}

int main(void)
{
    queen(0);

    for (int i = 1; i < SIZE+1; i++)
        cout << i << ": " << position[i] << endl;

    return 0;
}