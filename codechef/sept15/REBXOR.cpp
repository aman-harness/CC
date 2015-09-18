using namespace std;
#include<bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'


const int MN = 20000000;
struct trie {
  int n;
  int nodes[MN][2];


  void clear() {
    n = 1;
    nodes[0][0] = nodes[0][1] = -1;
  }


  void insert(int x) {
    int node = 0;
    for (int i = 31; i >= 0; --i) {
      int next = (x & (1 << i)) != 0;
      if (nodes[node][next] == -1) {
        nodes[node][next] = n;
        nodes[n][0] = nodes[n][1] = -1;
        n++;
      }
      node = nodes[node][next];
    }
  }


  int query(int x) {
    int node = 0;
    int ans = 0;
    for (int i = 31; i >= 0; --i) {
      int next = (x & (1 << i)) != 0;
      int cool = 1;
      if (nodes[node][next ^ 1] == -1) {
        next ^= 1;
        cool = 0;
      }
      if (cool)
        ans += (1 << i);


      if (nodes[node][next ^ 1] == -1) while (true) {}
      node = nodes[node][next ^ 1];
    }
    return ans;
  }
};


trie tree;
int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);


  int tc = 1, temp;;
  vector<int > input, ford, backd;
  while (tc--) {
    int n;cin >> n;input.clear();ford.clear(); backd.clear();
    for(int i = 0 ; i < n; i++) {cin >> temp; input.push_back(temp);}
    tree.clear();
    tree.insert(0);
    int best = 0, accum = 0, t;
    for (int i = 0; i < n; ++i) {
      t = input[i];
      accum ^= t;
      best = max(best, tree.query(accum));
      ford.push_back(best);
      tree.insert(accum);
    }

    //best = max(best, tree.query(0));
/////////////////////////////////////////////////////////////////////////////////

    reverse(input.begin(), input.end());
    tree.clear();
    tree.insert(0);
    best = 0, accum = 0;
    for (int i = 0; i < n; ++i) {
      t = input[i];
      accum ^= t;
      best = max(best, tree.query(accum));
      backd.push_back(best);
      tree.insert(accum);
    }

    // reverse(backd.begin(), backd.end());
    int maxx = 0;
    for(int i = 0 ; i < input.size() - 1; i++){
    	maxx = max(maxx, ford[i] + backd[input.size() - i - 2]);
    }
    // cout << best << endl;
    cout << maxx << endl;
  }
  return 0;
}


