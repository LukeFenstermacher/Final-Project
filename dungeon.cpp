#include <iostream>
#include <windows.h>
#include <ctime>

using namespace std;

int grid[20][20] = {0};

int characterPos[2] = {0, 0};
int enemy1Pos[2] = {12, 15};
int enemy2Pos[2] = {18, 6};
int enemy3Pos[2] = {10, 10};
int enemy4Pos[2] = {19, 17};

bool dead = false;
bool won = false;

string endVal;

void print();
void reset();
void enemy1GetPos();
void enemy2GetPos();
void enemy3GetPos();
void enemy4GetPos();

int main()
{
    srand(time(0));
    print();
    while (!dead && !won)
    {
        /*
        char val;
        cin >> val;
        if (val == 'w')
        {
            characterPos[0] -= 1;
        }
        else if (val == 's')
        {
            characterPos[0] += 1;
        }
        else if (val == 'a')
        {
            characterPos[1] -= 1;
        }
        else if (val == 'd')
        {
            characterPos[1] += 1;
        }
        */
//Movement
        if (GetKeyState('A') & 0x8000 && characterPos[1] > 0)
        {
            characterPos[1] -= 1;
            enemy1GetPos();
            enemy2GetPos();
            enemy3GetPos();
            enemy4GetPos();
            print ();
        }
        if (GetKeyState('D') & 0x8000 && characterPos[1] < 19)
        {
            characterPos[1] += 1;
            enemy1GetPos();
            enemy2GetPos();
            enemy3GetPos();
            enemy4GetPos();
            print ();
        }
        if (GetKeyState('S') & 0x8000 && characterPos[0] < 19)
        {
            characterPos[0] += 1;
            enemy1GetPos();
            enemy2GetPos();
            enemy3GetPos();
            enemy4GetPos();
            print ();
        }
        if (GetKeyState('W') & 0x8000 && characterPos[0] > 0)
        {
            characterPos[0] -= 1;
            enemy1GetPos();
            enemy2GetPos();
            enemy3GetPos();
            enemy4GetPos();
            print ();
        }

//Check for treasure
        if (characterPos[0] == 19 && characterPos[1] == 19)
        {
            won = true;
        }

//Check for enemies
        if (characterPos[0] == enemy1Pos[0] && characterPos[1] == enemy1Pos[1])
        {
            dead = true;
        }

    }
    if (won)
    {
        system("cls");
        cout << "You found the treasure!!!";
        cin >> endVal;
    }
    if (dead)
    {
        system("cls");
        cout << "You died";
        cin >> endVal;
    }

    return 0;
}

void print()
{
    system("cls");

    //enemy1Pos[0]

    for (int x = 0; x < 20; x++)
    {
        for (int y = 0; y < 20; y++)
        {
            reset();
            grid[characterPos[0]][characterPos[1]] = 1;
            grid[enemy1Pos[0]][enemy1Pos[1]] = 2;
            grid[enemy2Pos[0]][enemy2Pos[1]] = 3;
            grid[enemy3Pos[0]][enemy3Pos[1]] = 5;
            grid[enemy4Pos[0]][enemy4Pos[1]] = 6;
            grid[19][19] = 4;
            if (grid[x][y] == 0)
            {
                cout << ".";
            }
            else if (grid[x][y] == 1)
            {
                cout << "O";
            }
            else if (grid[x][y] == 2)
            {
                char a = 225;
                cout << a;
            }
            else if (grid[x][y] == 3)
            {
                char a = 245;
                cout << a;
            }
            else if (grid[x][y] == 4)
            {
                cout << "X";
            }
            else if (grid[x][y] == 5)
            {
                cout << "d";
            }
            else if (grid[x][y] == 6)
            {
                cout << "y";
            }
        }
        cout << endl;
    }

    /*
    for (int i = 0; i < hSpaces; i++)
    {
        cout << " ";
    }
    for (int i = 0; i < vSpaces; i++)
    {
        int x = 0;
        while (x < 80)
        {
            cout << " ";
            x++;
        }
    }
    cout << ":)" ;
    */
}

void reset()
{
    for (int x = 0; x < 20; x++)
    {
        for (int y = 0; y < 20; y++)
        {
            grid[x][y] = 0;
        }
    }
}

void enemy1GetPos()
{
    bool left = false;
    bool right = false;
    bool down = false;
    bool up = false;
    int x = rand() % 4;
    if (x == 0)
    {
        left = true;
    }
    else if (x == 1)
    {
        right = true;
    }
    else if (x == 2)
    {
        down = true;
    }
    else
    {
        up = true;
    }
    if (left && enemy1Pos[1] > 0)
    {
        enemy1Pos[1] -= 1;
    }
    if (right && enemy1Pos[1] < 19)
    {
        enemy1Pos[1] += 1;
        }
    if (down && enemy1Pos[0] < 19)
    {
        enemy1Pos[0] += 1;
    }
    if (up && enemy1Pos[0] > 0)
    {
        enemy1Pos[0] -= 1;
    }
}


void enemy2GetPos()
{
    bool left = false;
    bool right = false;
    bool down = false;
    bool up = false;
    int x = rand() % 4;
    if (x == 0)
    {
        left = true;
    }
    else if (x == 1)
    {
        right = true;
    }
    else if (x == 2)
    {
        down = true;
    }
    else
    {
        up = true;
    }
    if (left && enemy2Pos[1] > 0)
    {
        enemy2Pos[1] -= 1;
    }
    if (right && enemy2Pos[1] < 19)
    {
        enemy2Pos[1] += 1;
        }
    if (down && enemy2Pos[0] < 19)
    {
        enemy2Pos[0] += 1;
    }
    if (up && enemy2Pos[0] > 0)
    {
        enemy2Pos[0] -= 1;
    }
}


void enemy3GetPos()
{
    bool left = false;
    bool right = false;
    bool down = false;
    bool up = false;
    int x = rand() % 4;
    if (x == 0)
    {
        left = true;
    }
    else if (x == 1)
    {
        right = true;
    }
    else if (x == 2)
    {
        down = true;
    }
    else
    {
        up = true;
    }
    if (left && enemy3Pos[1] > 0)
    {
        enemy3Pos[1] -= 1;
    }
    if (right && enemy3Pos[1] < 19)
    {
        enemy3Pos[1] += 1;
        }
    if (down && enemy3Pos[0] < 19)
    {
        enemy3Pos[0] += 1;
    }
    if (up && enemy3Pos[0] > 0)
    {
        enemy3Pos[0] -= 1;
    }
}


void enemy4GetPos()
{
    bool left = false;
    bool right = false;
    bool down = false;
    bool up = false;
    int x = rand() % 4;
    if (x == 0)
    {
        left = true;
    }
    else if (x == 1)
    {
        right = true;
    }
    else if (x == 2)
    {
        down = true;
    }
    else
    {
        up = true;
    }
    if (left && enemy4Pos[1] > 0)
    {
        enemy4Pos[1] -= 1;
    }
    if (right && enemy4Pos[1] < 19)
    {
        enemy4Pos[1] += 1;
        }
    if (down && enemy4Pos[0] < 19)
    {
        enemy4Pos[0] += 1;
    }
    if (up && enemy4Pos[0] > 0)
    {
        enemy4Pos[0] -= 1;
    }
}
