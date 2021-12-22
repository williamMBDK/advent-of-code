#include<bits/stdc++.h>
using namespace std;

// Username: WillTheBill
#define _multitest_ 0
#define _multitestexpr_ re(tests)
#define _interactive_ 0
// #define int long long

// defines
#define vec vector
#define pb push_back
#define fi first
#define se second
#define all(_v) _v.begin(),_v.end()
#define ll long long
#define fun(ret,x,...) function<ret(__VA_ARGS__)> x;x=[&](__VA_ARGS__)->ret
#define Void(x,...) fun(void,x,__VA_ARGS__)
#define mp make_pair
// loops
#define foabc(i,a,b,c) for (int i = (a); i < (b); i+=(c))
#define foab(i,a,b) for (int i = (a); i < (b); i++)
#define fon(i,n) for(int i = 0; i < n; i++)
#define foe(e,a) for(auto& e : a)
#define rep(n) for(int _ = 0; _ < n; _++)
// constructing multidimensional vectors
template<typename T> inline void init(vec<T>& v, deque<int> sizes) {
    assert(sizes.size() == 1);
    v = vec<T> (sizes[0]);
}
template<typename T, typename C> inline void init(vec<T>& v, deque<int> sizes, C content) {
    assert(sizes.size() == 1);
    v = vec<T> (sizes[0], content);
}
template<typename T> inline void init(vec<vec<T>>& v, deque<int> sizes) {
    v = vec<vec<T>> (sizes[0]);
    sizes.pop_front();
    if(sizes.size() == 0) return;
    for(auto& subv : v) init(subv, sizes);
}
template<typename T, typename C> inline void init(vec<vec<T>>& v, deque<int> sizes, C content) {
    v = vec<vec<T>> (sizes[0]);
    sizes.pop_front();
    if(sizes.size() == 0) return;
    for(auto& subv : v) init(subv, sizes, content);
}
// reading
template<typename T>void _read(T& t);
template<typename T>void _read(vec<T>&v);
template<typename T1, typename T2>void _read(pair<T1,T2>&p);
template<typename T>void _read(T& t){cin >> t;}
template<typename T>void _read(vec<T>&v){for(unsigned _i=0;_i<v.size();_i++)_read(v[_i]);}
template<typename T1, typename T2>void _read(pair<T1,T2>&p){_read(p.first);_read(p.second);}
void _masterread(){}
template<typename T,typename... V>void _masterread(T& t, V&... v){_read(t);_masterread(v...);}
#define re(...)_masterread(__VA_ARGS__)
// writing
stringstream _effout;
#if defined(__local__) || (_interactive_ == 1)
#define _stdout cout
#else
#define _stdout _effout
#define endl '\n'
#endif
template<typename T>void _print(T t);
template<typename T>void _print(vec<T>&v);
template<typename T1, typename T2>void _print(pair<T1,T2>&p);
template<typename T>void _print(T t){_stdout<<t;}
template<typename T>void _print(vec<T>&v){for(unsigned _i=0;_i<v.size();_i++)_print(v[_i]),_stdout<<(_i==v.size()-1?"":" ");}
template<typename T1, typename T2>void _print(pair<T1,T2>&p){_print(p.first);_stdout<<" ";_print(p.second);}
void _masterprint(){}
template<typename T,typename... V>void _masterprint(T t, V... v){_print(t);if(sizeof...(v))_stdout<<" ";_masterprint(v...);}
#define pr(...)_masterprint(__VA_ARGS__)
#define prl(...) (_masterprint(__VA_ARGS__),_stdout<<endl)
// debugging, instead of a similar implementation for each container type a seperate generic function could be used
template <typename T> void _debug(T t); //forward declaration
template<typename T1,typename T2> void _debug(pair<T1,T2> p);
template<typename T> void _debug(vec<T> v);
template<typename T> void _debug(set<T>s);
template<typename T> void _debug(unordered_set<T>s);
template<typename T> void _debug(multiset<T>s);
template<typename T> void _debug(unordered_multiset<T>s);
template<typename T1,typename T2> void _debug(map<T1,T2>mp);
template<typename T1,typename T2> void _debug(unordered_map<T1,T2>mp);
template<typename T1,typename T2> void _debug(multimap<T1,T2>mp);
template<typename T1,typename T2> void _debug(unordered_multimap<T1,T2>mp); // end forward declaration
template <typename T> void _debug(T t){cerr<<t;}
template<typename T1,typename T2> void _debug(pair<T1,T2> p){cerr<<"{";_debug(p.first);cerr<<", ";_debug(p.second);cerr<<"}";}
template<typename T> void _debug(vec<T>v){cerr<<"(";for(unsigned _i=0;_i<v.size();_i++)_debug(v[_i]),cerr<<(_i==v.size()-1?"":", ");cerr << ")";}
template<typename T> void _debug(set<T>s){cerr<<"(";for(auto e=s.begin();e!=s.end();)_debug(*e),cerr<<((++e)==s.end()?"":", ");cerr << ")";}
template<typename T> void _debug(unordered_set<T>s){cerr<<"(";for(auto e=s.begin();e!=s.end();)_debug(*e),cerr<<((++e)==s.end()?"":", ");cerr << ")";}
template<typename T> void _debug(multiset<T>s){cerr<<"(";for(auto e=s.begin();e!=s.end();)_debug(*e),cerr<<((++e)==s.end()?"":", ");cerr << ")";}
template<typename T> void _debug(unordered_multiset<T>s){cerr<<"(";for(auto e=s.begin();e!=s.end();)_debug(*e),cerr<<((++e)==s.end()?"":", ");cerr << ")";}
template<typename T1,typename T2> void _debug(map<T1,T2>mp){cerr<<"(";for(auto e=mp.begin();e!=mp.end();)_debug(*e),cerr<<((++e)==mp.end()?"":", ");cerr << ")";}
template<typename T1,typename T2> void _debug(unordered_map<T1,T2>mp){cerr<<"(";for(auto e=mp.begin();e!=mp.end();)_debug(*e),cerr<<((++e)==mp.end()?"":", ");cerr << ")";}
template<typename T1,typename T2> void _debug(multimap<T1,T2>mp){cerr<<"(";for(auto e=mp.begin();e!=mp.end();)_debug(*e),cerr<<((++e)==mp.end()?"":", ");cerr << ")";}
template<typename T1,typename T2> void _debug(unordered_multimap<T1,T2>mp){cerr<<"(";for(auto e=mp.begin();e!=mp.end();)_debug(*e),cerr<<((++e)==mp.end()?"":", ");cerr << ")";}
void _masterdebug(){cerr<<"]"<<endl;}
template<typename T,typename... V> void _masterdebug(T t,V... v){_debug(t);if(sizeof...(v))cerr<<", ";_masterdebug(v...);}
#ifdef __local__
#define debug(...)(cerr<<"["<<#__VA_ARGS__<<"] = [",_masterdebug(__VA_ARGS__))
template<typename T> void _debugall(T c, string n){_debug("debugall: ");_debug(n);cerr<<endl;for(auto _e:c){_debug("  ");_debug(_e);cerr<<endl;}} //2d vectors and similar
#define debugall(c)(_debugall(c,#c)) //2d vectors and similar
#else
#define debug(...)
#define debugall(c)
#endif
// main
void prep();
void testcase(signed tc);
signed main(){
    if(!_interactive_) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }
    pr(setprecision(10));
    pr(fixed);
    prep();
    if(_multitest_) {
        signed tests; _multitestexpr_;
        for(signed tc = 1; tc <= tests; tc++) {
            testcase(tc);
        }
    } else {
        testcase(1);
    }
#ifndef __local__
    cout<<_effout.str();
#endif
}
void prep(){
}
int overlap(int a, int b, int c, int d) {
    return max(min(b,d) - max(c,a)+1, 0);
}
void testcase(__attribute__((unused)) signed tc){
    int n; re(n);
    map<int,map<int,vec<pair<int,int>>>> starting, ending;
    map<int,set<int>> indices;
    ll res = 0;
    vec<vec<pair<int,int>>> as (n);
    vec<bool> types (n);
    fon(j, n) {
        string s; re(s);
        vec<pair<int,int>> a (3);
        fon(i, 3) {
            char c; re(c); re(c);
            int l; re(l);
            re(c); re(c);
            int r; re(r);
            if(i < 2) re(c);
            a[i] = {l,r};
        }
        as[j] = a;
        types[j] = s == "on";
    }
    reverse(all(as));
    reverse(all(types));
    fon(k, n) {
        bool type = types[k];
        vec<pair<int,int>> a = as[k];
        debug(k,a);
        if(type) {
            map<set<int>,ll> mem;
            for(int i = a[0].fi; i <= a[0].se; i++) {
                if(mem.count(indices[i])) {
                    res += mem[indices[i]];
                    continue;
                }
                ll ans = 0;
                vec<int> ys = {a[1].fi, a[1].se, a[1].fi+1, a[1].se+1,a[1].fi-1,a[1].se-1};
                foe(p, starting[i]) {
                    ys.pb(p.fi);
                }
                foe(p, ending[i]) {
                    ys.pb(p.fi);
                }
                sort(all(ys));
                int l = a[2].fi, r = a[2].se;
                multiset<pair<int,int>> active;
                ll prevcnt = r - l + 1;
                int prevy = a[1].fi;
                foe(y, ys) {
                    ans += (ll)overlap(a[1].fi, a[1].se, prevy, y - 1) * (ll)prevcnt;
                    foe(e, starting[y]) {
                        foe(e2, e.se) {
                            active.insert(e2);
                        }
                    }
                    map<int,int> cnt;
                    cnt[l] = 0;
                    cnt[r] = 0;
                    cnt[l+1] = 0;
                    cnt[r+1] = 0;
                    cnt[l-1] = 0;
                    cnt[r-1] = 0;
                    foe(e, active) {
                        cnt[e.fi]++;
                        cnt[e.se+1]--;
                    }
                    int sum = 0;
                    int prev = l;
                    ll newcnt = 0;
                    foe(e, cnt) {
                        if(prev != INT_MIN) {
                            newcnt += (ll)overlap(l,r,prev,e.fi-1);
                            prev = INT_MIN;
                        }
                        sum += e.se;
                        if(sum == 0) {
                            prev = e.fi;
                        }
                    }
                    prevcnt = newcnt;
                    prevy = y;
                    foe(e, ending[y]) {
                        foe(e2, e.se) {
                            active.erase(active.find(e2));
                        }
                    }
                }
                mem[indices[i]] = ans;
                res += ans;
            }
        }
        for(int i = a[0].fi; i <= a[0].se; i++) {
            int l = a[2].fi, r = a[2].se;
            starting[i][a[1].fi].pb({l,r});
            ending[i][a[1].se].pb({l,r});
            indices[i].insert(k);
        }
        debug(res);
    }
    prl(res);
}

// Gready
    // find solution cloest to zero: min and max, then everything in between?
    // two pointer?
// Intervals
    // Process from minimum b value ([a,b]) to maximum b value and check overlaps by sorting from minimum a to max a
// Pairs
    // Are they edges in a graph?
    // Are they points in a 2d plot?
// Trees
    // Offline queries
        // DFS and do all the queries on the node
            // Good for queries from node to root
// Speed
    // Unordered can be SLOW
