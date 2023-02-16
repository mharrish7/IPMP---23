#include <bits/stdc++.h>

using namespace std;

int comp(vector<int> a, vector<int> b){
    if(a[0] > b[0]){
        return 1;
    }
    else if(a[0] == b[0]){
        if(a[1] < b[1]){
            return 1;
        }
    }
    else{
        return 0;
    }
}

int main() {
	int t;
	cin >> t;
	while (t--){
	    int N;
	    cin >> N;
	    vector<int> arr;
	    for(int i = 0; i < N; i++){
	        int t1;
	        cin >> t1;
	        arr.push_back(t1);
	    }
	    
	    unordered_map<int,int> map;
	    
	    for(int i = 0; i < N ; i++){
	        map[arr[i]]++;
	    }
	    
	    vector<vector<int>> L;
	    
	    for(auto x : map){
	        L.push_back({x.second,x.first});
	       // cout << x.second << " " << x.first;
	    }
	    
	    sort(L.begin(),L.end(),comp);

	    for(auto x : L){
	        for(int i = 0; i < x[0] ; i++){
	            cout << x[1] << " ";
	        }
	    }
	    
	    cout << endl;
	    
	    
	    
	}
	return 0;
}