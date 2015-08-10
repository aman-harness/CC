#include<bits/stdc++.h>

using namespace std;

bool comp(const pair<int, int> &a, const pair<int , int> &b){
	return (a.second < b.second);
}
int main(){
	pair<int, int> a[1000];
	a[0].first = 2;
	a[0].second = 2;
	a[1].first = 1;
	a[1].second = 1;
	a[2].first = 3;
	a[2].second = 6;
	a[3].first = 2;
	a[3].second = 1;
	a[4].first = 6;
	a[4].second = 5;
	sort(a, a + 5, comp);
	for(int i = 0; i < 5; i++) cout << a[i].first << " " << a[i].second << endl;
	cout << binary_search(a, a + 5, 3);

}