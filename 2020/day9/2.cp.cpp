// Username: WillTheBill
// Time of creation: 2020-12-09 18:07
// Original filename: 1.cp.cpp

#include<bits/stdc++.h>
using namespace std;

// shortcuts
#define pb push_back
#define fi first
#define se second
#define all(_v) _v.begin(),_v.end()
#define ll long long

// IO
#define multitest signed __T; cin >> __T; while(__T--)
template<typename T>
void _read(T& t);
template<typename T>
void _read(vector<T>&v);
template<typename T1, typename T2>
void _read(pair<T1,T2>&p);
template<typename T>
void _read(T& t){cin >> t;}
template<typename T>
void _read(vector<T>&v){for(unsigned _i=0;_i<v.size();_i++)_read(v[_i]);}
template<typename T1, typename T2>
void _read(pair<T1,T2>&p){_read(p.first);_read(p.second);}
void _masterread(){}
template<typename T,typename... V>
void _masterread(T& t, V&... v){_read(t);_masterread(v...);}
#define re(...)_masterread(__VA_ARGS__)

template<typename T>
void _print(T t);
template<typename T>
void _print(vector<T>&v);
template<typename T1, typename T2>
void _print(pair<T1,T2>&p);
template<typename T>
void _print(T t){cout<<t;}
template<typename T>
void _print(vector<T>&v){for(unsigned _i=0;_i<v.size();_i++)_print(v[_i]),cout<<(_i==v.size()-1?"":" ");}
template<typename T1, typename T2>
void _print(pair<T1,T2>&p){_print(p.first);cout<<" ";_print(p.second);}
void _masterprint(){cout<<endl;}
template<typename T,typename... V>
void _masterprint(T t, V... v){_print(t);if(sizeof...(v))cout<<" ";_masterprint(v...);}
#define pr(...)_masterprint(__VA_ARGS__)

// DEBUG
// colored output???
template <typename T> // start forward declaration
void _debug(T t);
template<typename T1,typename T2>
void _debug(pair<T1,T2> p);
template<typename T>
void _debug(vector<T>v);
template <typename T> // end forward declaration
void _debug(T t){cerr<<t;}
template<typename T1,typename T2>
void _debug(pair<T1,T2> p){cerr<<"{";_debug(p.first);cerr<<", ";_debug(p.second);cerr<<"}";}
template<typename T>
void _debug(vector<T>v){cerr<<"(";for(unsigned _i=0;_i<v.size();_i++)_debug(v[_i]),cerr<<(_i==v.size()-1?"":", ");cerr << ")";}
void _masterdebug(){cerr<<"]\n";}
template<typename T,typename... V>
void _masterdebug(T t,V... v){_debug(t);if(sizeof...(v))cerr<<", ";_masterdebug(v...);}
#ifdef __local__
#define debug(...) cerr<<"["<<#__VA_ARGS__<<"] = [";_masterdebug(__VA_ARGS__)
#else
#define debug(...) 
#endif

// TYPES
#define int long long

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n; re(n);
	vector<int> a (n); re(a);
	int goal = 29221323;
	auto sum = a;
	debug(a);
	for(int i = 1; i < n; i++) sum[i] += sum[i-1];
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			if(sum[j] - (i == 0 ? 0 : sum[i-1]) == goal){
				int mn = LLONG_MAX;
				int mx = LLONG_MIN;
				for(int k = i; k <= j; k++){
					mn = min(mn, a[k]);
					mx = max(mx, a[k]);
				}
				debug(i,j);
				pr(mn+mx);
			}
		}
	}
}
