#include "Queue.h"
// #include "Stack.h"

// 由于迷宫的特殊性，以下和右为开头进行BFS遍历
int dx[4] = {0, 1, -1, 0}, dy[4] = {-1, 0, 0, 1}; //表明每次x和y方向的位移

bool find_shortest_path(int **maze, int **path, int &path_length, int n) {
    // 请实现本函数
    // 函数逻辑请用队列类或栈类实现，并在本文件中引入相关头文件
    queue que;

    //定义一个flag来储存访问状态，0表示未访问，1表示已经访问过了
    int **flag;
    int marker;
    flag = new int *[n];
    for (int i = 0; i < n; i++) {
        flag[i] = new int[n];
    }
    for (int i = 0; i < n; i++) {
        for (int j = n; j < n; j++) {
            flag[i][j] = 0;
        }
    }

    //bfs
    que.enqueue(point(0, 0));
    while (!que.isEmpty()) {
        point tmp = que.dequeue();
        int i;
        for (i = 0; i < 4; i++) {
            if (tmp.x + dx[i] == n - 1 && tmp.y + dy[i] == n - 1) {
                que.enqueue(point(tmp.x + dx[i], tmp.y + dy[i]));
                flag[tmp.x + dx[i]][tmp.y + dy[i]] = flag[tmp.x][tmp.y] + 1;
                break;
            }
            if (tmp.x + dx[i] >= 0 && tmp.x + dx[i] < n && tmp.y + dy[i] >= 0 && tmp.y + dy[i] < n &&
                maze[tmp.x + dx[i]][tmp.y + dy[i]] == 0 && flag[tmp.x + dx[i]][tmp.y + dy[i]] == 0) {
                que.enqueue(point(tmp.x + dx[i], tmp.y + dy[i]));
                flag[tmp.x + dx[i]][tmp.y + dy[i]] = flag[tmp.x][tmp.y] + 1;
            }
        }
        flag[0][0] = 0;
        if (i != 4) break;

    }

    //回溯
    if (!que.isEmpty()) {
        for (int i = 0; i < 2; i++) {
            path[i] = new int[n * n];
        }
        marker = flag[n - 1][n - 1];
        point *tmp1;
        tmp1 = new point(n - 1, n - 1);
        while (marker >= 0) {
            for (int i = 0; i < 4; i++) {
                if (tmp1->x + dx[i] >= 0 && tmp1->x + dx[i] < n && tmp1->y + dy[i] >= 0 && tmp1->y + dy[i] < n &&
                    flag[tmp1->x + dx[i]][tmp1->y + dy[i]] == flag[tmp1->x][tmp1->y] - 1) {
                    path[0][marker] = tmp1->x;
                    path[1][marker] = tmp1->y;
                    delete tmp1;
                    tmp1 = new point(tmp1->x + dx[i], tmp1->y + dy[i]);
                    break;
                }
            }
            marker--;
            path_length++;
        }
        for (int i = 0; i < n; i++) {
            delete[]flag[i];
            flag[i] = nullptr;
        }
        delete[]flag;
        return true;
    } else {
        for (int i = 0; i < n; i++) {
            delete[]flag[i];
            flag[i] = nullptr;
        }
        delete[]flag;
        return false;
    }

}

// main cannot be modified
int main() {
    // initialize
    int N;
    cin >> N;
    int **maze = new int *[N];
    for (int i = 0; i < N; i++) {
        maze[i] = new int[N];
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> maze[i][j];
        }
    }

    // path should be an array of size [2][path_length]
    int **path = new int *[2];
    int path_length = 0;

    // should be finished
    if (find_shortest_path(maze, path, path_length, N)) {
        for (int i = 0; i < path_length; i++) {
            //path[0][i]: row
            //path[1][i]: column
            cout << '(' << path[0][i] << ',' << path[1][i] << ')';
        }
    } else {
        cout << "Not found" << endl;
    }

    // free memory
    for (int i = 0; i < N; i++) {
        delete[]maze[i];
        maze[i] = NULL;
    }
    delete[]maze;
    maze = NULL;
    for (int i = 0; i < 2; i++) {
        delete[]path[i];
        path[i] = NULL;
    }
    delete[]path;
    path = NULL;

    return 0;
}