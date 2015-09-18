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

template<typename T> T modPow(T b, T e, T m=(ll)MOD){T res=1;while(e){if(!(e&0x1))res=(res*b)%m;e>>=1;b=(b*b)%m;}return res; }
template<typename T> T gcd (T u, T v){ return (u==0||v==0||u==v)?(u|v):((~u&1)?((v&1)?gcd(u>>1,v):gcd(u>>1,v>>1)<<1):((~v&1)?gcd(u,v>>1):((u>v)?gcd((u-v)>>1,v):gcd((v-u)>>1,u)))); }
template<typename T> T lcm (T a, T b){ return a*b/gcd(a,b); }
//#undef DEBUG__
///////////////////////////////          FAST  IO          ///////////////////////////////////////
#define gc getchar_unlocked
void si(int &n){
    register int ch=gc();
    int neg = 0;
    n=0;
    while((ch<48||ch>57) && ch!='-')ch=gc();
    if(ch=='-'){ neg=1; ch=gc(); }
    for(;ch>47 && ch<58; ch=gc()) n = (n<<1)+(n<<3)+ch-48;
    if(neg)n=-n;
}


int check_ortho(vvi &x, int i, int j){
	int sum = 0;
	RNG(k, x[i].size()) sum += x[i][k] * x[j][k];
	// cout << "Result : " << sum << endl;
	if(!sum) return 1;
	else return 0;
}
int calcJacobsthal(int forr, vvi &ret){
	int q = forr;
	vi residue, temp;
	// vvi ret; 
	FOR(i, 1, forr) if((i*i % forr))residue.PB((i * i) % forr);
	sort(residue.begin(), residue.end());
	residue.erase( unique( residue.begin(), residue.end() ), residue.end() );
	int *X = new int[forr + 5];
	memset(X, 0, sizeof(int) * (forr + 3));
	FOR(i, 0, residue.size()) X[residue[i]] = 1;
	X[0] = 0;
	FOR(i, 1, forr) if(!X[i]) X[i] = -1;
	RNG(i, residue.size())cout << residue[i] << " "; cout << endl << endl;
	RNG(i, q){
		RNG(j, q){
			int x = X[(i - j + q) % q];
			temp.PB(x);
		}
		ret.PB(temp); temp.clear();
	}
	RNG(i, q) {RNG(j, q) cout << ret[i][j] << " "; cout << endl;}
	cout << endl;
	// cout << ret.size() << ret[0].size();
	return 0;
}

int pale_1(int forr){
	int q = forr;
	vvi res, coming;
	calcJacobsthal(forr, coming);
	vi ans, temp;
	RNG(i, forr + 1) temp.PB(0); RNG(i, forr + 1) res.PB(temp);
	RNG(i, forr + 1) res[0][i] = 1;
	RNG(i, forr + 1) res[i][0] = -1;
	res[0][0] = 0;
	FOR(i, 1, q + 1){
		FOR(j, 1, q + 1){
			res[i][j] = coming[i-1][j-1];
		}
	}
	RNG(i, q + 1) res[i][i] += 1;
	RNG(i, forr+ 1) RNG(j, forr+ 1) {if(i == j) continue;if(!check_ortho(res, i, j)) cout << "fail" << i <<j;}
	RNG(i, q+ 1) {RNG(j, q+ 1) cout << res[i][j] << " "; cout << endl;}
}

int update(int i, int j, vvi &r_res, vvi &res){
	if(res[i][j] == 0){
		r_res[2*i][2*j] = 1;
		r_res[2*i + 1][2*j] = - 1;
		r_res[2*i][2*j + 1] = -1;
		r_res[2*i + 1][2*j + 1]= - 1;
	}
	else if(res[i][j] == 1){
		r_res[2*i][2*j] = 1;
		r_res[2*i + 1][2*j] =  1;
		r_res[2*i][2*j + 1] = 1;
		r_res[2*i + 1][2*j + 1]= - 1;
	}
	else if (res[i][j] == -1){
		r_res[2*i][2*j] = -1;
		r_res[2*i + 1][2*j] =  -1;
		r_res[2*i][2*j + 1] = - 1;
		r_res[2*i + 1][2*j + 1]= 1;
	}
}
int pale_2(int forr){
	vvi res, coming, r_res;
	int q = forr;
	calcJacobsthal(forr, coming);
	vi ans, temp;
	RNG(i, forr + 1) temp.PB(0); RNG(i, forr + 1) res.PB(temp);
	RNG(i, forr + 1) res[0][i] = 1;
	RNG(i, forr + 1) res[i][0] = 1;
	res[0][0] = 0;
	FOR(i, 1, q + 1){
		FOR(j, 1, q + 1){
			res[i][j] = coming[i-1][j-1];
		}
	}
	RNG(i, q+ 1) {RNG(j, q+ 1) cout << res[i][j] << " "; cout << endl;}

	RNG(i, (forr + 1) * 2) temp.PB(0); RNG(i, (forr + 1) * 2) r_res.PB(temp);
	FOR(i, 0, q + 1){
		FOR(j, 0, q + 1){
			update(i, j, r_res, res);
		}
	}
	cout << endl << endl;
	// check_ortho(r_res, 3, 15);
	RNG(i, r_res.size()) RNG(j, r_res.size()) {if(i == j) continue;if(!check_ortho(r_res, i, j)) cout << "fail" << i <<j;}
	RNG(i, 2*(q+ 1)) {RNG(j, 2*(q+ 1)) cout << r_res[i][j] << " "; cout << endl;}

}

int main(){
	std::ios::sync_with_stdio(false);
	pale_1(51);
return 0;
}
