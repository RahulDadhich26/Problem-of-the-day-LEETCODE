#include<bits/stdc++.h>
#include<vector>
using namespace std;

int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
    vector<vector<int>> dis(n, vector<int>(n, 10001));
    int res = 0, smallest = n;
    for (auto& e : edges)
        dis[e[0]][e[1]] = dis[e[1]][e[0]] = e[2];
    for (int i = 0; i < n; ++i)
        dis[i][i] = 0;
    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
    for (int i = 0; i < n; i++) {
        int count = 0;
            for (int j = 0; j < n; ++j)
                if (dis[i][j] <= distanceThreshold)
                    ++count;
            if (count <= smallest) {
                res = i;
                smallest = count;
            }
        }
        return res;
    }
int main(){
    int n = 4;
    vector<vector<int>> edges = {{0,1,3},{1,2,1},{1,3,4},{2,3,1}};
    int distanceThreshold = 4;
    cout << findTheCity(n,edges,distanceThreshold) << endl;
    return 0;
}