#include<bits/stdc++.h>

using namespace std;
int change(vector <int> * aman){
	aman[1][0] = -1;
}

int main(){
	vector <int> aman[2];
	aman[1].push_back(10);
	aman[2].push_back(15);
	change(aman);
	cout << aman[1][0] << aman[1][1];
}