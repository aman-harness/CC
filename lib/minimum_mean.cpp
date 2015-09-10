vector<int> Solution::equal(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    map<int , pair<int, int> >m;
    map<int, int> check;
    vector<int> ret;
    vector<vector<int>> temp;
    for(int i = 0; i < A.size(); i++){
        for(int j = i + 1; j < A.size(); j++){
            if(!check[A[i] + A[j]]) {m[A[i] + A[j]] = make_pair(i, j); check[A[i] + A[j]] = 1;}
        }
    }
    for(int i = 0; i < A.size(); i++){
        for(int j = i + 1; j < A.size(); j++){
            if(m[A[i] + A[j]] == make_pair(i, j)) continue;
            else if(check[A[i] + A[j]] && ( (m[A[i] + A[j]]).first == i || (m[A[i] + A[j]]).second == j ) )continue; 
            else (check[A[i] + A[j]]){
                ret.push_back((m[A[i] + A[j]]).first);
                ret.push_back((m[A[i] + A[j]]).second);
                ret.push_back(i);
                ret.push_back(j);
                temp.push_back(ret);
                ret.clear();
            }
        }
    }if(temp.size()){
    sort(temp.begin(), temp.end());
    return temp[0];}
    else return ret;
}
