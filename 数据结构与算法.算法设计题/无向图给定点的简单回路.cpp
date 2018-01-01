// 假设图G采用邻接表存储，利用深度优先搜索方法求出无向图中给定点v的简单回路
#define  MAX_VERTEX_NUM 20
struct ArcNode {
    int adjvex;                  // 该弧所指向的顶点的位置
    struct ArcNode *nextarc;     // 指向下一条弧的指针
    InfoType *info;               // 该弧相关信息的指针
};
typedef struct VNode {
    VertexType data;              // 顶点信息
    ArcNode *firstarc;            // 指向第一条依附于该顶点的弧的指针
} VNode, AdjList[MAX_VERTEX_NUM];
struct ALGraph {                // 邻接表存储的图
    AdjList vertices;
    int vexnum, arcnum;         // 图的当前顶点数和弧数
    int kind;                   // 图的种类标志
};

bool visited[MAX_VERTEX_NUM];
vector<int> path;
int start;

int DFS(ALGraph *G, int v) {
    visited[v] = true;
    if (v == start && path.size()) {
        path.push_back(v);
        return v;
    }
    for (int w = FirstAdjVex(G, v); w >= 0; w = NextAdjVex(G, v, w)) {
        if (!visited[w]) {
            int t = DFS(G, w);
            if (t) {
                path.push_back(w);
                return w;
            }
        }
    }
    visited[v] = false;
}


