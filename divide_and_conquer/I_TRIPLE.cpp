#include <bits/stdc++.h>
 
using namespace std;
 
int n, K;
 
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
    int tmp;

    unsigned long long cnt = 0;
    
    cin >> n >> K;
 
    vector<int> v(n);
    unordered_map<int, int> mp;
 
    
 
    for(int i = 0; i < n; i++){
    	cin >> v[i];
    }
    
    sort(v.begin(), v.end());
    
    for(int i = 0; i < n - 2; i++) {
    	mp.clear();
    	for(int j = i + 1; j != n; j++) {
    		tmp = K - v[i] - v[j];
    		if(mp.find(tmp) != mp.end())
    			cnt += mp[tmp];
			mp[v[j]]++;
		}
	}
    
    cout << cnt;
 
    return 0;
}