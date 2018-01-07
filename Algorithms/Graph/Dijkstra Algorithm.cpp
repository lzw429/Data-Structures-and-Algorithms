class Graph {
private:
    float Edge[NumVertices][NumVertices]; // 边的权值矩阵，不邻接为MAXNUM
    float dist[NumVertices]; // 最短路径长度数组
    int path[NumVertices];// 最短路径数组，存储的是最短路径中的前一个顶点
    bool set[NumVertices]; // 最短路径顶点集

public:
    void ShortestPath(int, int);

    int choose(int);
};

void Graph::ShortestPath(int n, int v) {
    // 在具有n个顶点的非负权值有向图中，各边上权值由Edge[][]给出
    // 建立一个数组dist[j]，0≤j<n，保存从顶点v到顶点j的最短路径长度
    // path[j]，0≤j<n，存放j所在的最短路径的上一个顶点
    for (int i = 0; i < n; i++) {
        dist[i] = Edge[v][i];// dist数组初始化
        set[i] = false;
        if (i != v && dist[i] < MAXNUM)// 如果i与v邻接
            path[i] = v;
        else // 如果i不与v邻接
            path[i] = -1;
    }

    // 选择当前不在集合set中的具有最短路径的顶点u
    for (i = 0; i < n; i++) {
        float min = MAXNUM;
        int u = v;
        for (int j = 0; j < n; j++) {
            if (!set[j] && dist[j] < min) {
                u = j;
                min = dist[j];
                set[u] = true;// 将顶点u加入集合set
                for (int w = 0; w < n; w++) // 修改u的相邻顶点
                {
                    if (!set[w] && Edge[u][w] < MAXNUM && Edge[u][w] + min < dist[w]) {
                        dist[w] = Edge[u][w] + min;
                        path[w] = u;
                    }
                }
            }
        }
    }
}