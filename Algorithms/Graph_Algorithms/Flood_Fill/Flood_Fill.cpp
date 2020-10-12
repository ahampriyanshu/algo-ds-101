#include<iostream>
using namespace std;

#define M 5
#define N 5

void floodFillUtil(int screen[][N], int x, int y, int prevC, int newC)
{
    if (x < 0 || x >= M || y < 0 || y >= N)
        return;
    if (screen[x][y] != prevC)
        return;
    if (screen[x][y] == newC)
        return;

    screen[x][y] = newC;

    floodFillUtil(screen, x+1, y, prevC, newC);
    floodFillUtil(screen, x-1, y, prevC, newC);
    floodFillUtil(screen, x, y+1, prevC, newC);
    floodFillUtil(screen, x, y-1, prevC, newC);
}

void floodFill(int screen[][N], int x, int y, int newC)
{
    int prevC = screen[x][y];
    floodFillUtil(screen, x, y, prevC, newC);
}

int main()
{
    int screen[M][N],x,y,newC;

    cout << "Enter the colors of the pixels\n";

    for(int i=0;i<M;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin >> screen[i][j];
        }
    }

    cout << "\nEnter the co-ordinates (x,y) of point in screen\n";
    cin >> x;
    cin >> y;
    cout << "Enter the new color of the point (" << x << " , " << y << ")\n";
    cin >> newC;

    floodFill(screen, x, y, newC);

    cout << "Updated screen after call to floodFill: \n";
    for (int i=0; i<M; i++)
    {
        for (int j=0; j<N; j++)
        {
           cout << screen[i][j] << " ";
        }
        cout << endl;
    }
}
