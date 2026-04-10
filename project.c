#include <stdio.h>

#define MAX 10

int rows, cols;
int grid[MAX][MAX];
int visited[MAX][MAX];

// BFS parent
int parentX[MAX][MAX];
int parentY[MAX][MAX];

// DFS longest path storage
int bestPathX[MAX*MAX], bestPathY[MAX*MAX];
int tempPathX[MAX*MAX], tempPathY[MAX*MAX];
int maxLen;

// Directions
int dx[] = {1, 0, 0, -1};
int dy[] = {0, 1, -1, 0};

void printPath(int pathX[], int pathY[], int len){
    for(int i=0;i<len;i++){
        printf("(%d,%d)", pathX[i], pathY[i]);
        if(i != len-1) printf(" -> ");
    }
    printf("\nTotal Cost: %d\n", len-1);
}
// DFS
void dfs(int x, int y, int tx, int ty, int len){
    if(x<0 || y<0 || x>=rows || y>=cols) return;
    if(visited[x][y] || grid[x][y]==1) return;

    visited[x][y] = 1;

    tempPathX[len] = x;
    tempPathY[len] = y;

    if(x == tx && y == ty){
        if(len > maxLen){
            maxLen = len;
            for(int i=0;i<=len;i++){
                bestPathX[i] = tempPathX[i];
                bestPathY[i] = tempPathY[i];
            }
        }
        visited[x][y] = 0;
        return;
    }

    for(int i=0;i<4;i++){
        dfs(x + dx[i], y + dy[i], tx, ty, len + 1);
    }

    visited[x][y] = 0; // backtrack
}

//BFS
typedef struct { int x,y; } Node;

Node queue[MAX*MAX];

void bfs(int sx, int sy, int tx, int ty){
    int front=0, rear=0;
    int visitedB[MAX][MAX] = {0};

    queue[rear++] = (Node){sx, sy};
    visitedB[sx][sy] = 1;

    parentX[sx][sy] = -1;
    parentY[sx][sy] = -1;

    while(front < rear){
        Node curr = queue[front++];

        if(curr.x == tx && curr.y == ty){
            int pathX[MAX*MAX], pathY[MAX*MAX];
            int count = 0;

            int x = tx, y = ty;
            while(x != -1){
                pathX[count] = x;
                pathY[count] = y;
                count++;
                int px = parentX[x][y];
                int py = parentY[x][y];
                x = px; y = py;
            }

            printf("\nBFS (Shortest Path):\n");
            for(int i=count-1;i>=0;i--){
                printf("(%d,%d)", pathX[i], pathY[i]);
                if(i!=0) printf(" -> ");
            }
            printf("\nTotal Cost: %d\n", count-1);
            return;
        }

        for(int i=0;i<4;i++){
            int nx = curr.x + dx[i];
            int ny = curr.y + dy[i];

            if(nx>=0 && ny>=0 && nx<rows && ny<cols &&
               !visitedB[nx][ny] && grid[nx][ny]==0){

                queue[rear++] = (Node){nx, ny};
                visitedB[nx][ny] = 1;

                parentX[nx][ny] = curr.x;
                parentY[nx][ny] = curr.y;
            }
        }
    }

    printf("\nNo path found using BFS\n");
}

int main(){
    int sx, sy, tx, ty;

    printf("Enter rows and cols: ");
    scanf("%d %d",&rows,&cols);

    printf("Enter grid:\n");
    for(int i=0;i<rows;i++)
        for(int j=0;j<cols;j++)
            scanf("%d",&grid[i][j]);

    printf("Enter start: ");
    scanf("%d %d",&sx,&sy);

    printf("Enter target: ");
    scanf("%d %d",&tx,&ty);

    // DFS
    for(int i=0;i<rows;i++)
        for(int j=0;j<cols;j++)
            visited[i][j]=0;

    maxLen = -1;

    dfs(sx, sy, tx, ty, 0);

    printf("\nDFS (Longest Path):\n");
    if(maxLen != -1)
        printPath(bestPathX, bestPathY, maxLen+1);
    else
        printf("No path found\n");

    // BFS
    bfs(sx, sy, tx, ty);

    return 0;
}
