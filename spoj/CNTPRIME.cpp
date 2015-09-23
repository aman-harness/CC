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
int m[1000000];
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

// int ifPrime(int x){
// 	if(x == 2) return 1;
// 	if(x % 2 == 0) return 0;
// 	for(int i = 3; i < sqrt(x) + 1; i += 2) if(x % i == 0) return 0;
// 	return 1;
// }
inline int ifPrime(unsigned int number) {
  	if(m[number]) return 1;
  	else return 0;
}


/////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////


void updateSegmentTreeRangeLazy(int segTree[], int lazy[], int startRange, int endRange,
                                int delta, int low, int high, int pos) {
        if(low > high) {
            return;
        }
        //make sure all propagation is done at pos. If not update tree
        //at pos and mark its children for lazy propagation.
        // if (lazy[pos] != 0) {
        //     segTree[pos] += lazy[pos];
        //     if (low != high) { //not a leaf node
        //         lazy[2 * pos + 1] += lazy[pos];
        //         lazy[2 * pos + 2] += lazy[pos];
        //     }
        //     lazy[pos] = 0;
        // }
        // //no overlap condition
        if(startRange > high || endRange < low) {
            return;
        }
        //total overlap condition
        if(startRange <= low && endRange >= high) {
            lazy[pos] = delta;
            // if(low != high) {
            //     lazy[2*pos + 1] += delta;
            //     lazy[2*pos + 2] += delta;
            // }
            return;
        }
        //otherwise partial overlap so look both left and right.
        int mid = (low + high)/2;
        updateSegmentTreeRangeLazy(segTree, lazy, startRange, endRange,
                delta, low, mid, 2*pos+1);
        updateSegmentTreeRangeLazy(segTree, lazy, startRange, endRange,
                delta, mid+1, high, 2*pos+2);
        // segTree[pos] = min(segTree[2*pos + 1], segTree[2*pos + 2]);
    }

void updateSegmentTreeRangeLazy(int segTree[], int lazy[], int startRange, int endRange, int delta, int len) {
  // len is input length.
        updateSegmentTreeRangeLazy(segTree, lazy, startRange, endRange, delta, 0, len - 1, 0);
    }

int rangeMinimumQueryLazy(int input[], int segTree[], int lazy[], int qlow, int qhigh,
                                      int low, int high, int pos) {

        cout << "HERE\n";
        if(low > high) {
            return 0;
        }
        if(low == high) {
            if(lazy[pos] != 0){input[low] = lazy[pos];} lazy[pos] = 0;
            if(ifPrime(input[low])) segTree[pos] = 1; else segTree[pos] = 0; return segTree[pos];
        }

        //make sure all propagation is done at pos. If not update tree
        //at pos and mark its children for lazy propagation.
        if (lazy[pos] != 0) {
            // segTree[pos] += lazy[pos];
            if (low != high) { //not a leaf node
                lazy[2 * pos + 1] += lazy[pos];
                lazy[2 * pos + 2] += lazy[pos];
            }
            lazy[pos] = 0;
        }

        //no overlap
        if(qlow > high || qhigh < low){
            return 0;
        }

        //total overlap
        if(qlow <= low && qhigh >= high){
            return segTree[pos];
        }

        //partial overlap
        int mid = (low+high)/2;
        return (rangeMinimumQueryLazy(input, segTree, lazy, qlow, qhigh,
                        low, mid, 2 * pos + 1) + 
                rangeMinimumQueryLazy(input, segTree, lazy,  qlow, qhigh,
                        mid + 1, high, 2 * pos + 2));

    }
int rangeMinimumQueryLazy(int input[], int segTree[], int lazy[], int qlow, int qhigh, int len) {
  // len is input length
        return rangeMinimumQueryLazy(input, segTree, lazy, qlow, qhigh, 0, len - 1, 0);
    }

// len meanse the input length
// seg tree and lazy sizes should be minimum nearest next power of 2 -1;



/////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////





inline void constructMinSegmentTree(int input[], int segTree[], int low, int high, int pos){
  // Input :- Input array
  // segTree :- Segment Tree Array
  // low :- The lower boundof the area in consideration
  // high // The Upper Bound of the area in consideration (inclusive)
  // Pos: Current pos in segTree
  // if(low == high) {segTree[pos] = input[low]; return;}
  if(low == high) {if(ifPrime(input[low])) segTree[pos] = 1; else segTree[pos] = 0; return;}
  int mid = low + (high - low) / 2;
  constructMinSegmentTree(input, segTree, low, mid, 2*pos + 1);
  constructMinSegmentTree(input, segTree, mid + 1, high, 2*pos + 2);
  segTree[pos] = (segTree[2 * pos + 1] + segTree [2 * pos + 2]);
  return ;
}

 void constructTree(int input[], int segTree[], int len_input){
    constructMinSegmentTree(input, segTree, 0, len_input - 1, 0);
}

int rangeMinimumQuery(int segTree[], int qlow, int qhigh, int low, int high, int pos){
	// cout << " Calclating for " << qlow << qhigh << low << high << pos << endl; 
    // qlow, qhigh = query low and query high
    // low, high are the area of inpput into consideration.
    // Low and high are always to ba initialised with 0, N - 1 (inclusinve)
    // pos is the node of tree : -Initialised with 0;

    if(qlow <=low && qhigh >= high) return segTree [pos];
    if( qlow  > high || qhigh < low ) return 0;
    else{
      int mid = low + (high - low) / 2;
      return rangeMinimumQuery(segTree, qlow, qhigh, low, mid, 2 * pos + 1) +
                 rangeMinimumQuery(segTree, qlow, qhigh, mid + 1, high, 2 * pos + 2);
    }
}

int rangeMinimumQuery(int segTree[],int qlow, int qhigh, int len){
    // len is the length of input
        return rangeMinimumQuery(segTree, qlow, qhigh,  0, len-1, 0);
    }

inline void updateSegmentTree(int input[], int segTree[], int index, int delta, int low, int high, int pos){
       
        //if index to be updated is less than low or higher than high just return.
        if(index < low || index > high){
            return;
        }
        
        //if low and high become equal, then index will be also equal to them and update
        //that value in segment tree at pos
        // Sure: This is a leaf Node
        // if(low == high){
        //     segTree[pos] += delta;
        //     return;
        // }

         if(low == high){
            if(low == high) {if(ifPrime(input[low])) segTree[pos] = 1; else segTree[pos] = 0; return;}
            return;
        }
        //otherwise keep going left and right to find index to be updated 
        //and then update current tree position if min of left or right has
        //changed.
        int mid = (low + high)/2;
        updateSegmentTree(input, segTree, index, delta, low, mid, 2 * pos + 1);
        updateSegmentTree(input, segTree, index, delta, mid + 1, high, 2 * pos + 2);
        segTree[pos] = (segTree[2*pos+1] + segTree[2*pos + 2]);
}


void updateSegmentTree(int input[], int segTree[], int index, int delta, int len_input){
        input[index] += delta;
        updateSegmentTree(input, segTree, index, delta, 0, len_input - 1, 0);
}

inline void updateSegmentTreeRange(int input[], int segTree[], int startRange, int endRange, int delta, int low, int high, int pos) {
        if(low > high || startRange > high || endRange < low ) {
            return;
        }

        // if(low == high) {
        //     segTree[pos] += delta;
        //     return;
        // }
        if(low == high){
            if(low == high) {if(ifPrime(input[low])) segTree[pos] = 1; else segTree[pos] = 0; return;}
            return;
        }

        int middle = (low + high)/2;
        updateSegmentTreeRange(input, segTree, startRange, endRange, delta, low, middle, 2 * pos + 1);
        updateSegmentTreeRange(input, segTree, startRange, endRange, delta, middle + 1, high, 2 * pos + 2);
        segTree[pos] = segTree[2*pos+1] + segTree[2*pos+2];
    }

void updateSegmentTreeRange(int input[], int segTree[], int startRange, int endRange, int delta, int len_input) {
        for(int i = startRange; i <= endRange; i++) {
            input[i] = delta;
        }
        updateSegmentTreeRange(input, segTree, startRange, endRange, delta, 0, len_input - 1, 0);
    }


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


inline void markMultiples(bool arr[], int a, int n)
{
    int i = 2, num;
    while ( (num = i*a) <= n )
    {
        arr[ num-1 ] = 1; // minus 1 because index starts from 0.
        ++i;
    }
}

// A function to print all prime numbers smaller than n
void SieveOfEratosthenes(int n)
{
    // There are no prime numbers smaller than 2
    if (n >= 2)
    {
        // Create an array of size n and initialize all elements as 0
        bool arr[n];
        memset(arr, 0, sizeof(arr));

        /* Following property is maintained in the below for loop
           arr[i] == 0 means i + 1 is prime
           arr[i] == 1 means i + 1 is not prime */
        for (int i=1; i<n; ++i)
        {
            if ( arr[i] == 0 )
            {
                //(i+1) is prime, print it and mark its multiples
                // printf("%d ", i+1);
                m[i+1] = 1;
                markMultiples(arr, i+1, n);
            }
        }
    }
}



int main(){
	std::ios::sync_with_stdio(false);
	int segTree[45360], lazy[45360];
	int t;si(t);
	SieveOfEratosthenes(1000000);
	int input[20000];
	// int t = 1;
	while(t--){
		int n, q = 1; si(n); si(q);
		
		FOR(i, 0, n) si(input[i]);
		// cout << "Input Complete\n";
		constructTree(input, segTree, n);
		RNG(i, 16) cout << segTree[i] << " "; cout << endl;
		int d, a, b, c;
		cout <<"what\n"; 
		RNG(i, q){
			si(d);
			cout <<"what\n"; 
			if(!d){
				si(a); si(b);si(c);
				updateSegmentTreeRangeLazy(segTree, lazy, a - 1, b - 1, c, n);
			}
			else{
				si(a); si(b);
				cout << "here\n";
				cout << rangeMinimumQueryLazy(input, segTree, lazy, a - 1, b - 1, n) << '\n';
			}
		}
	}
return 0;
}
