// checking wheteher a number is 
/* Function to check if x is power of 2*/
bool isPowerOfTwo(long long int a){
    return x && (!(x&(x-1)));
}

// Assuming no duplicates


int BinarySearch( int key, int data[], const int len )
{
    int low  = 0;
    int high = len-1;

    while( high >= low )
    {
        int mid = low + ((high - low) / 2);

        /**/ if (data[mid] < key) low  = mid + 1;
        else if (data[mid] > key) high = mid - 1;
        else return                      mid    ;
    }
    return -1; // KEY_NOT_FOUND
}

int LessThanEqualBinSearch( int key, int data[], const int len )
{
    int min = 0;
    int max = len-1;
    // var max = data.length - 1; // Javascript, Java conversion

    while( min <= max)
    {
        int mid = min + ((max - min) / 2);

        /**/ if (data[mid] < key)  min  = mid + 1;
        else if (data[mid] > key)  max  = mid - 1;
        else   /*data[mid] = key)*/return mid    ;
    }

    if( max < 0 )
        return 0;  // key < data[0]
    else
    if( min > (len-1))
        return -1; // key >= data[len-1] // KEY_NOT_FOUND
    else
        return (min < max)
            ? min  
            : max + 1;
}

int LessThanEqualOrLastBinSearch( int key, int data[], const int len )
{
    int min = 0;
    int max = len-1;
    // var max = data.length - 1; // Javascript, Java conversion

    while( min <= max)
    {
        int mid = min + ((max - min) / 2);

        /**/ if (data[mid] < key)  min  = mid + 1;
        else if (data[mid] > key)  max  = mid - 1;
        else   /*data[mid] = key)*/return mid    ;
    }

    if( max < 0 )
        return 0;     // key < data[0]
    else
    if( min > (len-1))
        return len-1; // key >= data[len-1]
    else
        return (min < max)
            ? min  
            : max + 1;
}

int NextLargestBinSearch( int key, int data[], const int len )
{
    int low  = 0;
    int high = len-1;

    while( low <= high)
    {
        // To convert to Javascript:
        // var mid = low + ((high - low) / 2) | 0;
        int mid = low + ((high - low) / 2);

        /**/ if (data[mid] < key) low  = mid + 1;
        else if (data[mid] > key) high = mid - 1;
        else return                      mid + 1;
    }

    if( high < 0 )
        return 0;   // key < data[0]
    else
    if( low > (len-1))
        return len; // key >= data[len-1]
    else
        return (low < high)
            ? low  + 1
            : high + 1;
}

////////////////////////////////////////////////////////////////////////////////////////////
// BFS DFS
/////////////////////////////////////////////////////////////////////////////////////////////


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