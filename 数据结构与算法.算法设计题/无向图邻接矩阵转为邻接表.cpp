// 设计一个将无向图的邻接矩阵转为对应邻接表的算法
struct VNode {
    ArcNode *firstArc;
    int val;
};

struct ArcNode {
    int adjVex;
    ArcNode *nextArc;
};

void adjMat_to_adjList(vector <vector<int>> &adjMat, vector <VNode> &adjList) {
    for (auto vex = adjMat.begin(); vex != adjMat.end(); ++vex) {
        VNode v = new VNode(vex - adjMat.begin());
        adjList.push_back(v);
        for (auto arc = (*vex).begin(); arc != (*vex).end(); ++arc) {
            if (*arc) {
                ArcNode a = new ArcNode(arc - (*vex).begin());
                a->nextArc = v->firstArc;
                v->firstArc = a;
            }
        }
    }
}