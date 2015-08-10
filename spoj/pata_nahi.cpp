#include<bits/stdc++.h>

using namespace std;

int check(int a, int b){
	if ((a < 8 && a >= 0) &&  (b < 8 && b >= 0)) return 1;
	else return 0;
}



int possible_posn(int a, int ret[]){
	int i = 0;
	memset(a, -1, 8);
	if(check(a/8 + 1, a%8 -2)) ret[0] = a + 6;
	if(check(a/8 + 2, a%8 - 1)) ret[1] = a + 15;
	if(check(a/8 + 2, a%8 + 1)) ret[2] = a + 17;
	if(check(a/8 + 1, a%8) + 2) ret[3] = a + 10;
	if(check(a/8 - 1, a%8 + 2)) ret[4] = a - 6;
	if(check(a/8 - 1, a%8 - 2)) ret[5] = a - 10;
	if(check(a/8 - 2, a%8 - 1)) ret[6] = a - 17;
	if(check(a/8 - 2, a%8 + 1)) ret[7] = a + 15;
}

update(queue<int > *input, int index)
{
	int graph[8], i;
	possible_posn(index, graph);
	for(i = 0; i < 8; i++) if(graph[i]) input[index].push(graph[i]);
}

int BFS(int n, vector <int> *graph, int vertices){
	set<int> blue,red;
	queue<int> x,y, input[10005], father;
	int i, j, count = 0;
	update(input, n);

	blue.insert(n);x.push(n);
	int temp = n,tempp;
	while(!(x.empty())){
	    temp=x.front();
	    if(temp == last)
	    update(input, temp);
		while(!input[temp].empty()){
            tempp=input[temp].front();
		    int xx=blue.find(tempp)==blue.end();
            if(blue.find(tempp)==blue.end())
			{
				blue.insert(tempp); x.push(tempp);
				last = tempp;
			}
			input[temp].pop();
		}
		x.pop();y.push(temp);
	}
	print(y);
}

int main(){
	cin >> a;
	bfs(a);
}