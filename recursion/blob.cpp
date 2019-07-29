#include <iostream>

using namespace std;

#define SIZE 8

typedef enum
{
    EMPTY = 0,
    IMAGE,
    COUNTED = 5
} MARK;

typedef struct
{
    int x = 5;
    int y = 3;
} TARGET;

TARGET target;

int image[SIZE][SIZE] = 
{
    {1, 0, 0, 0, 0, 0, 0, 1},
    {0, 1, 1, 0, 0, 1, 0, 0},
    {1, 1, 0, 0, 1, 0, 1, 0},
    {0, 0, 0, 0, 0, 1, 0, 0},
    {0, 1, 0, 1, 0, 1, 0, 0},
    {0, 1, 0, 1, 0, 1, 0, 0},
    {1, 0, 0, 0, 1, 0, 0, 1},
    {0, 1, 1, 0, 0 ,1, 1, 1}
};

int count = 0;
int CoutBlob(int x, int y)
{
    count++;
    if (x < 0 || y < 0 || x >= SIZE || y >= SIZE)
        return 0;

    if (image[y][x] == MARK::COUNTED || image[y][x] == MARK::EMPTY)
        return 0;

    image[y][x] = MARK::COUNTED;
    return 1 + CoutBlob(x+1, y) + CoutBlob(x+1, y+1) + CoutBlob(x, y+1) + CoutBlob(x-1, y+1) 
             + CoutBlob(x-1, y) + CoutBlob(x-1, y-1) + CoutBlob(x, y-1) + CoutBlob(x+1, y-1);
}

int main(void)
{
    int result = CoutBlob(target.x, target.y);
    cout << "result: " << result << endl;
    cout << "count: " << count << endl;

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            cout << image[i][j] << ", ";
        }
        cout << endl;
    }

    return 0;
}
