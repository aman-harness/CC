// dijkstra implementatiion 

#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <queue>
#include <deque>
#include <set>
#include <list>
#include <map>
#include <functional>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <numeric>
#include <stack>
#include <utility>
using namespace std;

#define s(n)    scanf("%d",&n)
#define sl(n)   scanf("%lld",&n)
#define p(n)    printf("%d ",n)
#define pl(n)   printf("%lld",n)
#define sf(n)   scanf("%f",&n)
#define sd(n)   scanf("%lf",&n)
#define ss(n)   scanf("%s",n)
#define pf(n)   printf("%f ",n)
#define pd(n)   printf("%lf ",n)
#define ps(n)   printf("%s ",n)
#define nl      putchar('\n')
#define e1      first
#define e2      second

#define INF     (int)1e9
#define MOD     (int)(1e9+7)
#define LINF    (ll)1e18
#define EPS     1e-11
const double PI = acos(-1.0)

#define pow2(n) (1<<(n))
#define pow2l(n) ((ll)1<<(n))
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(n)   ((a)<0?-(a):(a))
#define MAXE(...)   max_element(__VA_ARGS__)
#define MINE(...)   min_element(__VA_ARGS__)

#define FOR(i,a,b)  for(int i=a;i<b;i++)
#define RNG(i,n)    FOR(i,0,n)
#define REV(i,a,b)  for(int i=a;i>=b;--i)
#define FORECH(v,c) for(typeof((c).begin()) v=(c).begin(); v!=(c).end(); ++v)
#define ALL(a)      (a).begin(),(a).end()
#define LEN(a)      ((int)(a.size()))
#define PB(x)       push_back(x)
#define TIMES(x)    while((x)--)
#define UPB         upper_bound
#define LWB         lower_bound
#define MP          make_pair

#ifndef ONLINE_JUDGE
#define DEBUG__
#endif
#ifdef DEBUG__
    #define derr(x)     cerr<<"<"<<#x<<": "<<x<<">"<<endl
    #define _DEBUG(...) __VA_ARGS__
    ;template<typename T> void debug(T a, T b){ for(;a!=b;++a) cerr<<*a<<" "; cerr<<endl; }
#else
    #define derr(...)
    #define _DEBUG(...)
    ;template<typename T> void debug(T a, T b){}
#endif

typedef long long       ll;
typedef pair<int, int>  pii;
typedef pair<ll, ll>    pll; 
typedef vector<int> vi;
typedef vector<ll>  vl;
typedef vector<vi>  vvi;
typedef vector<vl>  vvl;
typedef list<int>   li;
typedef map<int,int> mii;

 #define tr(container, it) \
      for(typeof(container.begin()) it = container.begin(); it != container.end(); it++) 

vector< list <pii> > G;
set <pii> Q;
void dijkstra(int n){
	cout << "Hi \n";
	// n: number of vertices
	// vi D(n, INT_MAX); 
	int *D = new int[n];
	// memset(D, 63, sizeof(D));
	RNG(i, n) D[i] = INT_MAX;
	vi path(n, -1);
	// Assuming that 0 is the starting vertices.
	D[0] = 0;
	Q.insert(pii(0, 0));

	while(!Q.empty()){
		cout << "Hi \n";
		pii top = *Q.begin();
		Q.erase(Q.begin());
		int v = top.second, d = top.first;
		// if(d <= D[v]){
			tr(G[v], it){
				int v2 = it -> first; int cost = it -> second;
				if(D[v2] > D[v] + cost) {
					// update distance if possible
					if(D[v2] != 987654321) {
                           Q.erase(Q.find(pii(D[v2],v2)));
                     }
					 path[v2] = v;
					 D[v2] = D[v] + cost;
					 // add the vertex to queue
					Q.insert(pii(D[v2], v2));
				}
			// }
			// G[v].clear();
		}
	}
	// RNG(i, n) G[i].clear();
	// G.clear();// Q = priority_queue <pii, vector<pii>, greater <pii> > ();
	int k = n - 1;
	int f = 0;
	vi print(n + 5, 0);
	while(k != -1){
		// stk.push(k);
		print[f++] = k;
		k = path[k];
	}
	if(f == 1) cout << "-1\n";
	else REV(g, f - 1, 0) cout << print[g] + 1 << " ";
	// if(stk.size() == 1) cout << "-1\n";
	// else
	// 	while(!stk.empty()){
	// 		cout << stk.top() + 1<< " "; stk.pop();
	// 	}
	// }
	// RNG(i, n) cout << i << " " << path[i] << " " << D[i]<< endl;
}
int main(){
	std::ios::sync_with_stdio(false);
	int n, v, from, to, weight;
	cout << "sdc";
	list <pii> vpii;
	cin >> n >> v;
	RNG(i, n) G.PB(vpii);
	while(v--){
		cin >> from >> to>> weight; from--; to--;
		G[from].PB(MP(to, weight));
		G[to].PB(MP(from, weight));
	}
	cout << "hi\n";
	dijkstra(n);

return 0;
}