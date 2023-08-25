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
	TC : O(N^3)
*/

int find(string str , int n){
	
	for(int len=n-1 ; len>0 ; len--){
		bool flag = true;
		for(int i=0 ; i<len ; i++){
			if(str[i] != str[n-len+i]){
				flag = false;
				break;
			}
		}
		if(flag == true){
			return len;
		}
	}
return 0;
} 
void fillLPS(string str , vector<int> &lps){
	int n = lps.size();
	lps[0] = 0;
	for(int i=0 ; i<n ; i++){
		lps[i] = find(str , i+1);
	}
	return;
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
	string str = "abacabad";
	vector<int> lps(str.size() , 0);

	fillLPS(str , lps);
	for(int i=0 ; i<str.size() ; i++){
		cout<<lps[i]<<" ";
	}
	cout<<endl;
	return 0;
}