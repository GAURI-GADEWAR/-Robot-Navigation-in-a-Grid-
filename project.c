#include <stdio.h> 
#define MAX 10 
int rows, cols; 
int grid[MAX][MAX]; 
int visited[MAX][MAX]; 
// Parent for path 
int parentX[MAX][MAX]; 
int parentY[MAX][MAX]; 
int dx[] = {0, 0, 1, -1}; 
int dy[] = {1, -1, 0, 0}; 
// Print Path 
void printPath(int tx, int ty){ 
 int pathX[MAX*MAX], pathY[MAX*MAX];
 int count = 0; 
 int x = tx, y = ty; 
 while(x != -1 && y != -1){ 
 pathX[count] = x; 
 pathY[count] = y; 
 count++; 
 int px = parentX[x][y]; 
 int py = parentY[x][y]; 
 x = px; 
 y = py; 
 } 
 printf("\nPath Taken:\n"); 
 for(int i=count-1;i>=0;i--){ 
 printf("(%d,%d)", pathX[i], pathY[i]); 
 if(i!=0) printf(" -> "); 
 } 
 printf("\n"); 
} 
// DFS 
int found = 0; 
void dfs(int x, int y, int tx, int ty){ 
 if(x<0 || y<0 || x>=rows || y>=cols) return; 
 if(visited[x][y] || grid[x][y]==1 || found) return; 
 visited[x][y] = 1; 
 printf("(%d,%d) ", x, y); 
 if(x==tx && y==ty){ 
 found = 1; 
 return; 
 } 
 for(int i=0;i<4;i++){ 
 int nx = x + dx[i]; 
 int ny = y + dy[i]; 
 if(nx>=0 && ny>=0 && nx<rows && ny<cols && !visited[nx][ny] && grid[nx][ny]==0){ 
 parentX[nx][ny] = x; 
 parentY[nx][ny] = y; 
 dfs(nx, ny, tx, ty); 
 }
 } 
} 
// BFS 
typedef struct { int x,y; } Node; 
Node queue[MAX*MAX]; 
int front=0, rear=0; 
void bfs(int sx, int sy, int tx, int ty){ 
 front = rear = 0; 
 int visitedB[MAX][MAX] = {0}; 
 queue[rear++] = (Node){sx, sy}; 
 visitedB[sx][sy] = 1; 
 parentX[sx][sy] = -1; 
 parentY[sx][sy] = -1; 
 printf("\nBFS Traversal:\n"); 
 while(front < rear){ 
 Node curr = queue[front++]; 
 printf("(%d,%d) ", curr.x, curr.y); 
 if(curr.x == tx && curr.y == ty){ 
 printPath(tx, ty); 
 return; 
 } 
 for(int i=0;i<4;i++){ 
 int nx = curr.x + dx[i]; 
 int ny = curr.y + dy[i]; 
 if(nx>=0 && ny>=0 && nx<rows && ny<cols &&  !visitedB[nx][ny] && grid[nx][ny]==0){ 
 queue[rear++] = (Node){nx, ny};  visitedB[nx][ny] = 1; 
 parentX[nx][ny] = curr.x; 
 parentY[nx][ny] = curr.y; 
 } 
 } 
 } 
 printf("\nNo path found using BFS\n");
} 
int main(){ 
 int sx, sy, tx, ty; 
 printf("Enter rows and cols: ");  scanf("%d %d",&rows,&cols); 
 printf("Enter grid (0 free, 1 blocked):\n");  for(int i=0;i<rows;i++) 
 for(int j=0;j<cols;j++) 
 scanf("%d",&grid[i][j]); 
 printf("Enter start coordinates: ");  scanf("%d %d",&sx,&sy); 
 printf("Enter target coordinates: ");  scanf("%d %d",&tx,&ty); 
 // DFS 
 printf("\nDFS Traversal:\n"); 
 for(int i=0;i<rows;i++) 
 for(int j=0;j<cols;j++){ 
 visited[i][j]=0; 
 parentX[i][j] = -1; 
 parentY[i][j] = -1; 
 } 
 found = 0; 
 dfs(sx, sy, tx, ty); 
 if(found) 
 printPath(tx, ty); 
 else 
 printf("\nNo path found using DFS\n"); 
 // BFS 
 bfs(sx, sy, tx, ty); 
 return 0; 
}

