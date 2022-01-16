#include <bits/stdc++.h>
#include<queue>
using namespace std;
 
#define N 20
#define M 20
 
// QItem for current location and distance
// from source location
class QItem {
public:
    int row;
    int col;
    int dist;
    QItem(int x, int y, int w)
        : row(x), col(y), dist(w)
    {
    }
};
 
// int minDistance(char grid[20][20])
// {
//     QItem source(0, 0, 0);
 
//     // To keep track of visited QItems. Marking
//     // blocked cells as visited.
//     bool visited[20][20];
//     for (int i = 0; i < 20; i++) {
//         for (int j = 0; j < 20; j++)
//         {
//             if (grid[i][j] == '$' && grid[i][j] == '0')
//                 visited[i][j] = true;
//             else
//                 visited[i][j] = false;
 
//             // Finding source
//             if (grid[i][j] == 's')
//             {
//                source.row = i;
//                source.col = j;
//             }
//         }
//     }
    
//     // applying BFS on matrix cells starting from source
//     queue<QItem> q;
//     q.push(source);
//     visited[source.row][source.col] = true;
//     while (!q.empty()) {
//         QItem p = q.front();
//         q.pop();
 
//         // Destination found;
//         if (grid[p.row][p.col] == 'd')
//             return p.dist;
 
//         // moving up
//         if (p.row - 1 >= 0 &&
//             visited[p.row - 1][p.col] == false) {
//             q.push(QItem(p.row - 1, p.col, p.dist + 1));
//             visited[p.row - 1][p.col] = true;
//         }
 
//         // moving down
//         if (p.row + 1 < N &&
//             visited[p.row + 1][p.col] == false) {
//             q.push(QItem(p.row + 1, p.col, p.dist + 1));
//             visited[p.row + 1][p.col] = true;
//         }
 
//         // moving left
//         if (p.col - 1 >= 0 &&
//             visited[p.row][p.col - 1] == false) {
//             q.push(QItem(p.row, p.col - 1, p.dist + 1));
//             visited[p.row][p.col - 1] = true;
//         }
 
//          // moving right
//         if (p.col + 1 < M &&
//             visited[p.row][p.col + 1] == false) {
//             q.push(QItem(p.row, p.col + 1, p.dist + 1));
//             visited[p.row][p.col + 1] = true;
//         }
//     }
//     return -1;
// }
 int shortestPathBinaryMatrix(grid[20][20]) {
        int n = 20;
        int m = 20;
        //if(grid[0][0] or grid[19][19]) return -1;
        queue<vector<int>>q;
        q.push({0,0,1});
        int xdir[8] = {1,-1,0,0,1,1,-1,-1};
        int ydir[8] = {0,0,1,-1,1,-1,1,-1};
        while(!q.empty()){
            int x = q.front()[0];
            int y = q.front()[1];
            int c = q.front()[2];
            if(x==n-1 and y==n-1) return c;
            q.pop();
            grid[x][y] = 1;
            for(int k=0;k<8;k++){
                int x1 = x + xdir[k];
                int y1 = y + ydir[k];
                if(x1>-1 and x1<n and y1>-1 and y1<n and grid[x1][y1]==0){
                    grid[x1][y1] = 1;
                    q.push({x1,y1,c+1});
                }
            }
        }
        return -1;
// Driver code
int finder(int desti,int destj)
{
    char grid[20][20];
    for(int i =0 ;i< 10;i++)
    {
        int k = i;
        for(int j =0 ;j< 20;j++)
        {
            if(j < k || 19 - j < k)
            {
                grid[i][j] = '0';
            }
            else
            {
                grid[i][j] = '*';
            }
        }
    }
    

    for(int i =10 ;i<13;i++)
    {
        int k = i;
        for(int j =0 ;j< 20;j++)
        {
            if(j > k || 19 - j > k)
            {
                grid[i][j] = '0';
            }
            else
            {
                grid[i][j] = '$';
            }
        }
    }

    for (int i = 13; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            grid[i][j] = '$';
        }
    }

    // for (int i = 0; i < 20; i++)
    // {
    //     for (int j = 0; j < 20; j++)
    //     {
    //         cout << grid[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    char region = grid[desti][destj];
    grid[desti][destj] = 'd';

    grid[9][9] = 's';
    int a = minDistance(grid);
    grid[9][10] = 's';
    if(a == -1)
    {
        a = 10000;
    }
    int b = minDistance(grid);
    if(b == -1)
    {
        b = 10000;
    }
    int min = a<b ? a : b;
    //cout<<min<<"\n";
    int sub;

    if(region == '*')
    {
        sub = min*5;
    }
    else if (region == '0')
    {
        sub = min*5;
    }
    else
    {
        sub = min*8.75;
    }
    int price = 220 - sub;
    if(desti >=17)
    {
        price = 50;
    }
    //cout<<price;
    return price;
    
}

int main()
{
    for(int i =0 ;i<20;i++)
    {
        for(int j = 0;j<20;j++)
        {   
            int price = finder(i,j);
            if(i == 9 && (j == 10 || j == 9))
            {
                price = 220;
            }
            cout<<price<<" ";
        }
        cout<<"\n";
    }
}