#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>

#include<queue>
#include<stack>
#include<cmath>
#include<string>
#include<sstream>
#include<cstring>

#include<bitset>
#include<stdio.h>

#include<stdlib.h>
#include<math.h>
#include<limits.h>
using namespace std;

int find(int sink, int parent[]){
    if (sink == -1) return 0;
    find(parent[sink], parent);
    cout << sink << " ";
    return 0;

    // for(int i = 1;i<= vertices; i++) cout << parent[i] << " " << min_dist[i];
}

int find_n(int min_dist[], int visited[], int vertices){
    int a, i, ret, min = INT_MAX, index = 0;
    for(i= 1; i  <= vertices; i++){
        if(min > min_dist[i]) if(!visited[i]) {min = min_dist[i];index = i;}
    }
    // cout << index << " - index \n";
    return index;
}

int dijkstra(queue<int> *que, int source, int sink, pair<int, int>* edge, map <pair<int, int> , int> *ccost, int vertices, int edges){
    int visited[100000], min_dist[100000], count_visited = 0, index, current;
    map <pair<int, int> , int> cost = *ccost;
    int parent[100000];
    pair<int, int> p;
    for(int i=1; i<=vertices; i++){
        visited[i] = 0;
        min_dist[i] = INT_MAX;
        parent[i] = 0;
    }
    // cout << INT_MAX << "  "<<min_dist[sink]<<" "<<sink << endl;f
    min_dist[source] = 0;
    current = source;
    // visited[source] = 1;
    while(count_visited++ != vertices){
        index = find_n(min_dist, visited, vertices);
        visited[index] = 1;
        while(!que[index].empty()){
            current = que[index].front();
            que[index].pop();
            p.first = index; p.second = current;
            // cout << min_dist[current]<<" - " << min_dist[index] <<" - " <<min_dist[index] + cost[p]<< " - " << current<<   " " << index<<endl;
            if(min_dist[current] > min_dist[index] + cost[p]){
                min_dist[current] = min_dist[index] + cost[p];
                parent[current] = index;
            }
        }
    }
    parent[source] = -1;
    if(!parent[sink]) {cout << -1;}
    else find(sink, parent);    
    return min_dist[sink];
}

int main(){
    ios_base::sync_with_stdio(false);
    int a, b, t,i,j,m,n, v, k, c, source, sink, dist;
    // cin >> t;
    t = 1;
    while(t--){
    map<pair<int, int> , int> cost;
    pair<int, int> edge[200000];
    queue<int> que[100000];
    cin >> v >> k;
    for(i = 0 ; i < k; i++) {
        cin >> a >> b >> c;
        // a = 1; b = 2; c = 1; 
        edge[i].first = a; edge[i].second = b;
        cost[edge[i]] = c;
        que[a].push(b);
        que[b].push(a);
        edge[i + v].first = b; edge[i + v].second = a;
        cost[edge[i + v]] = c;
    }
    // cin >> source >> sink;
    dist = dijkstra(que, 1, v, edge, &cost, v, k);
    }

}