
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
#include <limits.h>
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

//////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
// FOR USING: 
// 1. Create an array of segTree of sufficient size.(lazy also if needed)
// 2. Create call consructTree function:
//   input: Input Array: Indexing From 0.
//   segTree: The tree to be updated.
// //   len_input: Number of NUmbers in Input Array.

// Query : rangeMinimumQuery()
//   1. segmentTree: segTree array
//   2. qlow : Query lower Bound
//   3. qhigh : QUery Upper Bound (inclusive)
//   4. len_input : Input Length.


void constructMinSegmentTree(int input[], int segTree[], int low, int high, int pos){
  // Input :- Input array
  // segTree :- Segment Tree Array
  // low :- The lower boundof the area in consideration
  // high // The Upper Bound of the area in consideration (inclusive)
  // Pos: Current pos in segTree
  if(low == high) {segTree[pos] = input[low]; return;}
  int mid = low + (high - low) / 2;
  constructMinSegmentTree(input, segTree, low, mid, 2*pos + 1);
  constructMinSegmentTree(input, segTree, mid + 1, high, 2*pos + 2);
  segTree[pos] = min(segTree[2 * pos + 1], segTree [2 * pos + 2]);
  return ;
}

void consructTree(int input[], int segTree[], int len_input){
    constructMinSegmentTree(input, segTree, 0, len_input - 1, 0);
}

int rangeMinimumQuery(int segTree[], int qlow, int qhigh, int low, int high, int pos){
    // qlow, qhigh = query low and query high
    // low, high are the area of inpput into consideration.
    // Low and high are always to ba initialised with 0, N - 1 (inclusinve)
    // pos is the node of tree : -Initialised with 0;

    if(qlow <=low && qhigh >= high) return segTree [pos];
    else if( qlow  > high || qhigh < low ) return INT_MAX;
    else{
      int mid = low + (high - low) / 2;
      return min(rangeMinimumQuery(segTree, qlow, qhigh, low, mid, 2 * pos + 1),
                 rangeMinimumQuery(segTree, qlow, qhigh, mid + 1, high, 2 * pos + 2));
    }
}

int rangeMinimumQuery(int segmentTree[],int qlow, int qhigh, int len){
    // len is the length of input
        return rangeMinimumQuery(segmentTree, 0, len-1, qlow, qhigh, 0);
    }

void updateSegmentTree(int segmentTree[], int index, int delta, int low, int high, int pos){
       
        //if index to be updated is less than low or higher than high just return.
        if(index < low || index > high){
            return;
        }
        
        //if low and high become equal, then index will be also equal to them and update
        //that value in segment tree at pos
        // Sure: This is a leaf Node
        if(low == high){
            segmentTree[pos] += delta;
            return;
        }
        //otherwise keep going left and right to find index to be updated 
        //and then update current tree position if min of left or right has
        //changed.
        int mid = (low + high)/2;
        updateSegmentTree(segmentTree, index, delta, low, mid, 2 * pos + 1);
        updateSegmentTree(segmentTree, index, delta, mid + 1, high, 2 * pos + 2);
        segmentTree[pos] = min(segmentTree[2*pos+1], segmentTree[2*pos + 2]);
}


void updateSegmentTree(int input[], int segmentTree[], int index, int delta, int len_input){
        input[index] += delta;
        updateSegmentTree(segmentTree, index, delta, 0, len_input - 1, 0);
}

void updateSegmentTreeRange(int segmentTree[], int startRange, int endRange, int delta, int low, int high, int pos) {
        if(low > high || startRange > high || endRange < low ) {
            return;
        }

        if(low == high) {
            segmentTree[pos] += delta;
            return;
        }

        int middle = (low + high)/2;
        updateSegmentTreeRange(segmentTree, startRange, endRange, delta, low, middle, 2 * pos + 1);
        updateSegmentTreeRange(segmentTree, startRange, endRange, delta, middle + 1, high, 2 * pos + 2);
        segmentTree[pos] = min(segmentTree[2*pos+1], segmentTree[2*pos+2]);
    }

void updateSegmentTreeRange(int input[], int segmentTree[], int startRange, int endRange, int delta, int len_input) {
        for(int i = startRange; i <= endRange; i++) {
            input[i] += delta;
        }
        updateSegmentTreeRange(segmentTree, startRange, endRange, delta, 0, len_input - 1, 0);
    }

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// LAZY PROPOGATION 
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void updateSegmentTreeRangeLazy(int segmentTree[], int lazy[], int startRange, int endRange,
                                int delta, int low, int high, int pos) {
        if(low > high) {
            return;
        }
        //make sure all propagation is done at pos. If not update tree
        //at pos and mark its children for lazy propagation.
        if (lazy[pos] != 0) {
            segmentTree[pos] += lazy[pos];
            if (low != high) { //not a leaf node
                lazy[2 * pos + 1] += lazy[pos];
                lazy[2 * pos + 2] += lazy[pos];
            }
            lazy[pos] = 0;
        }
        //no overlap condition
        if(startRange > high || endRange < low) {
            return;
        }
        //total overlap condition
        if(startRange <= low && endRange >= high) {
            segmentTree[pos] += delta;
            if(low != high) {
                lazy[2*pos + 1] += delta;
                lazy[2*pos + 2] += delta;
            }
            return;
        }
        //otherwise partial overlap so look both left and right.
        int mid = (low + high)/2;
        updateSegmentTreeRangeLazy(segmentTree, lazy, startRange, endRange,
                delta, low, mid, 2*pos+1);
        updateSegmentTreeRangeLazy(segmentTree, lazy, startRange, endRange,
                delta, mid+1, high, 2*pos+2);
        segmentTree[pos] = min(segmentTree[2*pos + 1], segmentTree[2*pos + 2]);
    }

void updateSegmentTreeRangeLazy(int input[], int segmentTree[], int lazy[], int startRange, int endRange, int delta, int len) {
  // len is input length.
        updateSegmentTreeRangeLazy(segmentTree, lazy, startRange, endRange, delta, 0, len - 1, 0);
    }

int rangeMinimumQueryLazy(int segmentTree[], int lazy[], int qlow, int qhigh,
                                      int low, int high, int pos) {

        if(low > high) {
            return INT_MAX;
        }

        //make sure all propagation is done at pos. If not update tree
        //at pos and mark its children for lazy propagation.
        if (lazy[pos] != 0) {
            segmentTree[pos] += lazy[pos];
            if (low != high) { //not a leaf node
                lazy[2 * pos + 1] += lazy[pos];
                lazy[2 * pos + 2] += lazy[pos];
            }
            lazy[pos] = 0;
        }

        //no overlap
        if(qlow > high || qhigh < low){
            return INT_MAX;
        }

        //total overlap
        if(qlow <= low && qhigh >= high){
            return segmentTree[pos];
        }

        //partial overlap
        int mid = (low+high)/2;
        return min(rangeMinimumQueryLazy(segmentTree, lazy, qlow, qhigh,
                        low, mid, 2 * pos + 1),
                rangeMinimumQueryLazy(segmentTree, lazy,  qlow, qhigh,
                        mid + 1, high, 2 * pos + 2));

    }
int rangeMinimumQueryLazy(int segmentTree[], int lazy[], int qlow, int qhigh, int len) {
  // len is input length
        return rangeMinimumQueryLazy(segmentTree, lazy, qlow, qhigh, 0, len - 1, 0);
    }

// len meanse the input length
// seg tree and lazy sizes should be minimum nearest next power of 2 -1;

//////////////////////////////////////////////////////////////////////////////////////////


int segTree[3000000];

int main(){
	std::ios::sync_with_stdio(false);
	int a, b, x, y;
	cin >> a >>b;
	// MaxVal = a;
	int *bit = new int[a + 2];
	memset(bit, 0, sizeof(int) * (a + 2));
	consructTree(bit, segTree, a);
	while(b--){
		cin >> x >> y;
		updateSegmentTreeRange(bit, segTree, x, y, 1, a);
	}
	int power = 1;
	while(power < a) power*=2;
	// cout << power << endl;
	sort(segTree + 2*power - 1 - a , segTree + 2*power - 1);
	// FOR(i, 0, 2*power - 1 ) cout << segTree[i] << endl;
	cout << segTree[2 * power -2 - a/2];
return 0;
}
