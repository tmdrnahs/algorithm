#include <iostream>

using namespace std;

#define SIZE 8

typedef enum
{
    BLOCKED = 1,
    VISITED = 2,
    PATH = 5
} MARK;

typedef struct
{
    int x = 7;
    int y = 7;
} Exit;

Exit exitCord;

int maze[SIZE][SIZE] = 
{
    {0, 0, 0, 0, 0, 0, 0, 1},
    {0, 1, 1, 0, 1, 1, 0, 1},
    {0, 0, 0, 1, 0, 0, 0, 1},
    {0, 1, 0, 0, 1, 1, 0, 0},
    {0, 1, 1, 1, 0, 0, 1, 1},
    {0, 1, 0, 0, 0, 1, 0, 1},
    {0, 0, 0, 1, 0, 0, 0, 1},
    {0, 1, 1, 1, 0 ,1, 0, 0}
};

int count = 0;
bool FindPath(int x, int y)
{
    count++;

    if (x < 0 || y < 0 || x >= SIZE || y >= SIZE)
        return false;

    if (x == exitCord.x && y == exitCord.y)
    {
        maze[x][y] = MARK::PATH;
        return true;
    }

    if (maze[x][y] == MARK::VISITED || maze[x][y] == MARK::BLOCKED)
        return false;
    else
    {
        maze[x][y] = MARK::VISITED;
        if (FindPath(x, y+1) || FindPath(x+1, y) || FindPath(x, y-1) || FindPath(x-1, y))
        {
            maze[x][y] = MARK::PATH;
            return true;
        }
        else 
            return false;
    }

    return true;
}

int main(void)
{
    bool result = FindPath(0, 0);
    cout << "result: " << (result ? "true" : "false") << endl;
    cout << "count: " << count << endl;

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            cout << maze[i][j] << ", ";
        }
        cout << endl;
    }

    return 0;
}
