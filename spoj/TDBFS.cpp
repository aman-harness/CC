// Knowledge:- Important-- A queue is directly cpied. a=b and the queue is copied.

#include<bits/stdc++.h>
#define f(i,a,n) for(i=a;i<n;i++)
using namespace std;

int print(queue<int> y){
	while(!y.empty()){
		cout << y.front() << " ";
		y.pop();
	}
	cout << '\n';
	return 0;
}

int bfs(int n,queue<int> input[]){
	queue<int> x, output;
	x.push(n);
	int visited[25000];
	memset(visited, 0, 25000);
	visited[n] = 1;
	int temp, tempp;
	while(!(x.empty())){
	    temp=x.front();
		while(!input[temp].empty()){
            tempp=input[temp].front();
            if(!visited[tempp])
			{
				visited[tempp] = 1; 
				x.push(tempp);
			}
			input[temp].pop();
		}
		x.pop();output.push(temp);
	}
	print(output);
}
int dfs(int u,queue<int> q[]){
stack<int > blue;
int visited[25000];
memset(visited, 0, 25000);
queue <int> output;
int top,index;
index=u;
blue.push(u);output.push(u);visited[u] = 1;
while(!blue.empty()){
    index=blue.top();
    while(!q[index].empty()){
        top=q[index].front();q[index].pop();
        if (!visited[top]){
            visited[top] = 1;
            blue.push(top);output.push(top);
            index=top;
            //cout<< "Pushed :"<< top;
        }
    }index=blue.top();
    blue.pop();
}
print(output);
}

int main(){
	ios_base::sync_with_stdio(false);
	int n,temp,m,u,i,v;int count=1,t;
	cin >> t;
	while(t--){
	cin>>n;
	queue<int> input[1000],dupl[1000];
	f(i,1,n+1){
		cin >> temp >> m;
		while(m--){
			cin >> temp;
			if(temp) input[i].push(temp);
		}
	}
	cout << "graph "<< count++ << '\n';
	while(1){
	cin >> u >> v;
	if(!u && !v) break;
	f(i,0,n+3) dupl[i]=input[i];

	if(v)bfs(u,dupl);
	if(!v)dfs(u,dupl);}
	}
	return 0;
}