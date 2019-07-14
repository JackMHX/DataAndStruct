#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define INF 100000000
int map[505][505];
int cost[505][505];
int dist[505];
int mcost[505];
bool isfastpath[505] = {false};

void dijkstra(int v0,int v,int d){
    //起点
    dist[v0] = 0;
    isfastpath[v0] = true;
    int i, w;
    for (i = 1; i < v;i++){//每次求得v到某个定点得最短路径
        int MIN = INF;
        for (w = 0; w < v;w++){
            if(!isfastpath[w]){
                if(dist[w]<MIN){
                    MIN = dist[w];
                    v0 = w;
                }
            }
        }
        isfastpath[v0] = true;
        for (w = 0; w < v;w++){//更新当前得最短路径
            if(!isfastpath[w] && MIN+map[v0][w]<dist[w]){
                dist[w] = MIN + map[v0][w];
                mcost[w] = mcost[v0] + cost[v0][w];
            }
            //距离一样选更便宜的
            else if(!isfastpath[w] && MIN+map[v0][w] == dist[w] && mcost[w]>mcost[v0]+cost[v0][w] ){
                mcost[w] = mcost[v0] + cost[v0][w];
            }
        }
    }
}

int main(){
    int v, e, s, d;
    //顶点数 边数 出发地 目的地
    cin >> v >> e >> s >> d;
    //初始化
    for (int i = 0; i < v;i++){
        for (int j = 0; j < v;j++){
            map[i][j] = map[j][i] = INF;
            cost[i][j] = cost[j][i] = INF;
        }
    }
    for (int i = 0; i < e;i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        map[a][b] = map[b][a] = c;
        cost[a][b] = cost[b][a] = d;
    }
    //先记录a,b两点直接到达的距离
    for (int i = 0; i < v;i++){
        dist[i] = map[i][s];
        mcost[i] = cost[i][s];
    }
    dijkstra(s, v, d);
    cout << dist[d] << " " << mcost[d] << endl;
}