
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


pii edge[400005];
bool cats[400005];
bool visited[400005];
int start[400005];
int count_cats[400005];
int max_cats;

int paths = 0;
int calc_paths(int n){
	stack<int> blue;
	int top,index = 1;
	if(cats[1]) count_cats[1] = 1; else count_cats[1] = 0;
	if(max_cats >= count_cats[1]) {blue.push(index);}
	// int s_index = lower_bound(start + 1, start + n, index) - start;
	// int e_index = upper_bound(start + 1, start + n, index) - start;
	visited[1] = 1;
	while(!blue.empty()){
		index = blue.top();blue.pop();
		if(!cats[index]) count_cats[index] = 0;
		int s_index = lower_bound(start + 1, start + n + n - 1, index) - start;
		int e_index = upper_bound(start + 1, start + n + n - 1, index) - start;
		int flag = 1;
		if(e_index - s_index == 1) paths++;
		// if(flag) 
		// cin >> paths;
		FOR(i, s_index, e_index){
			// cout << "In for loop: " << s_index << e_index << endl;
			if(visited[edge[i].second]) continue;
			if(count_cats[index] == max_cats) {if(!cats[edge[i].second]) {
							blue.push(edge[i].second);
							count_cats[edge[i].second] = 0;
							visited[edge[i].second] = 1;
						}
				else continue;
			}
			else{
				blue.push(edge[i].second);
				visited[edge[i].second] = 1;
				count_cats[edge[i].second] = count_cats[index] + cats[edge[i].second];
			}
		}
		if(blue.empty()) break;
		index = blue.top();
	}
	cout << paths << endl;
}

int main(){
	std::ios::sync_with_stdio(false);
	int n; cin >> n >> max_cats;
	FOR(i, 1, n + 1) cin >> cats[i];
	FOR(i, 1, n) {cin >> edge[i].first >> edge[i].second; start[i] = edge[i].first; edge[i + n -1].first = edge[i].second;edge[i + n -1].second = edge[i].first;
				start[i + n - 1] = edge[i].second;
				}
	sort(edge + 1, edge + n + n - 1);
	sort(start + 1, start + n + n - 1);
	calc_paths(n);
return 0;
}
