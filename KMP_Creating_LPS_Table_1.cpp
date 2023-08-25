#include<bits/stdc++.h>
#define pb push_back
#define mod 1000000007
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define read(x) int x; cin>>x
#define fd(a,b) for(int i=a ; i<b ; i++)
#define pr pair<int , int>
#define mapi unordered_map<int , int>
#define pq priority_queue<int , int>
#define que queue<int>
#define setter set<int>
#define ll long long
using namespace std;

//AIM : Creating LPS(Longest Proper Prfix and suffix) : 

/*
	Author : Mann Desai
	Topic : KMP Pattern Matching Algorithm
	TC : O(N) : Optimization Version
*/

void fillLPS(string str , vector<int> &lps){ // TC : O(N)
	int n = str.size();
	int len = 0;
	int i = 1;
	lps[0] = 0;
	while(i < n){
		if(str[i] == str[len]){
			len++;
			lps[i] = len;
			i++;
		}else{
			if(len == 0){
				lps[i] = 0;
				i++;
			}else{
				len = lps[len-1];
			}
		}
	}

}

void init_code(){
	fast_io;
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif // ONLINE_JUDGE
}  


int main(){
	init_code();
	string str = "abbabb";
	vector<int> lps(str.size() , 0);

	fillLPS(str , lps);
	for(int i=0 ; i<str.size() ; i++){
		cout<<lps[i]<<" ";
	}
	cout<<endl;
	return 0;
}