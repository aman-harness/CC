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


void dijkstra(int n, vector< list <pair <int , vi> > > &G, int s, int to){
	// n: number of vertices
	vi D(n, 987654321); 
	priority_queue <pii, vector<pii>, greater <pii> > Q;
	// int *D = new int[n];
	// memset(D, 63, sizeof(D));
	// RNG(i, n) D[i] = INT_MAX;
	// vi path(n, -1);
	// Assuming that 0 is the starting vertices.
	D[0] = 0;
	Q.push(pii(0, 0));

	while(!Q.empty()){
		pii top = Q.top();
		Q.pop();
		int v = top.second, d = top.first;
		if(d <= D[v]){
			tr(G[v], it){
				int v2 = it -> first; int cost = it -> second[(d + s)% 24];
				if(D[v2] > D[v] + cost) {
					// update distance if possible
					 D[v2] = D[v] + cost;
					Q.push(pii(D[v2], v2));
				}
			}
		}
	}
	// RNG(i, n) cout << D[i] << endl;
	if(D[to] == 987654321) cout  << -1 << " ";
	else cout << D[to] << " ";
}
int main(){
	std::ios::sync_with_stdio(false);
	int n, v, t, from, to, weight, s, k, at;
	cin >> t;RNG(z, t){
		vector< list <pair <int , vi> > > G;
		list <pair <int , vi> > vpii;
		cin >> n >> v >> k;
		RNG(i, n) G.PB(vpii);
		while(v--){
			cin >> from >> to; from--; to--;
			vi hours(24, 0); RNG(i, 24) cin >> hours[i];
			G[from].PB(MP(to, hours));
			G[to].PB(MP(from, hours));
		}
		cout << "Case #" << z+1 << ": "; 
		while(k--){
			cin >> to >> at;
			dijkstra(n, G, at, to - 1);
		}
		cout << endl;
	}
return 0;
}