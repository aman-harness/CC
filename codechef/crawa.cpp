#include<bits/stdc++.h>

using namespace std;

vector <int> roadsBetween[105];
inline void fast_read(int *Number){
	
	*Number=0;
	
	char CurrentCharacter=getchar_unlocked();
	
	while(CurrentCharacter<'0'||CurrentCharacter>'9')
	     CurrentCharacter=getchar_unlocked();
	     
	while(CurrentCharacter>='0'&&CurrentCharacter<='9'){
		
		*Number=(*Number)*10+CurrentCharacter-'0';
		CurrentCharacter=getchar_unlocked();
	}
	
}

int findFastPath(int from, int to, int locations){
    queue<int> q;
    if(from == to) return 1;
    int visited[1005], i, flag = 0, currentNode;
    for(i = 0; i < locations; i++) visited[i] = 0;
    visited[from] = 1;
    q.push(from);
    while(!q.empty()) {
        currentNode = q.front();
        q.pop();
        int i, j, index;
        /*for(i = 0; i < locations; i++){
             if(roadsBetween[currentNode][i] && !visited[i]){
                 if(to != i){
                     q.push_back(i);
                     visited[i] = 1;
                     roadsBetween[from][i] = 1;
                 }
                 else{
                     flag = 1;
                     break;
                 } 
             }
        }*/
       for(i = 0; i < roadsBetween[currentNode].size(); i++){
           if(!visited[(roadsBetween[currentNode])[i]]){
               if(to != (roadsBetween[currentNode])[i]){
                     q.push(( roadsBetween[currentNode])[i] );
                     visited[ (roadsBetween[currentNode])[i] ] = 1;
                     //cout << (roadsBetween[currentNode])[i] << currentNode <<endl;
                     //roadsBetween[from][i] = 1;
                 }
                 else{
                     flag = 1;
                     break;
                 } 
           }
       }
    if(flag) break;
    }
    if(flag) return 1;
    else return 0;
}
int main(){
std::ios_base::sync_with_stdio(false);
int queries, i, j, queryFrom, queryTo, to, from, a, b, c, d, f, g, h, testCases, locations, fastRoads;
cin >> testCases;
while(testCases--){
    fast_read(&locations); fast_read(&fastRoads);
    for(i = 0; i < locations; i++) roadsBetween[i].clear();
    while(fastRoads --){
        fast_read(&from);
        fast_read(&to);
        roadsBetween[to].push_back(from);
        roadsBetween[from].push_back(to);
    }
    fast_read(&queries);
    while(queries--){
        fast_read(&queryFrom); 
        fast_read(&queryTo);
        if (findFastPath(queryFrom, queryTo, locations)){
            cout << "YO" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
}
return 0;
}
