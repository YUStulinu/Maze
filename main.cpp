#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<vector<char>> maze = {
        {'#','#','#','#','#','#','#'},
        {'#','S',' ',' ','#',' ','#'},
        {'#',' ','#',' ','#',' ','#'},
        {'#',' ','#',' ',' ',' ','#'},
        {'#',' ',' ','#','#',' ','#'},
        {'#',' ',' ',' ',' ','E','#'},
        {'#','#','#','#','#','#','#'}
    };

    int playerX = 1, playerY = 1; // Start position
    char move;

    while(true) {
        system("clear"); // sau "cls" pe Windows
        for(int i=0;i<maze.size();i++) {
            for(int j=0;j<maze[i].size();j++) {
                if(i==playerX && j==playerY) cout << 'P';
                else cout << maze[i][j];
            }
            cout << endl;
        }

        if(maze[playerX][playerY]=='E') {
            cout << "Congratulations! You reached the exit!\n";
            break;
        }

        cout << "Move (W/A/S/D): ";
        cin >> move;
        move = toupper(move);

        int nextX = playerX, nextY = playerY;
        if(move=='W') nextX--;
        else if(move=='S') nextX++;
        else if(move=='A') nextY--;
        else if(move=='D') nextY++;

        if(maze[nextX][nextY]!='#') {
            playerX = nextX;
            playerY = nextY;
        }
    }

    return 0;
}
