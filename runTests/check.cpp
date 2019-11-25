#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template <class T>
using ordered_set =
       tree <T,null_type,less <T>,rb_tree_tag,tree_order_statistics_node_update> ;
///find_by_order()
///order_of_key()

template <class T,class U>
void maximize(T &x,U y){
    if(x < y)x=y;
}
template <class T,class U>
void minimize(T &x,U y){
    if(x > y)x=y;
}
template <class T>
T Abs(T x){
    return (x < (T)0 ? -x : x);
}
template <class T>
T safe_sqrt(T x){
    return sqrt(max(x,(T)0));
}
template <class T,class U,class V>
T addmod(T x,U k,V MOD){
    return ((x+k)%MOD + MOD)%MOD;
}
template <class T,class U,class V>
T submod(T x,U k,V MOD){
    return ((x-k)%MOD + MOD)%MOD;
}
template <class T,class U,class V>
T mul(T x,U y,V MOD){
    return ( (x % MOD) * (y % MOD) ) % MOD;
}

#define ll long long
#define pll pair <ll,ll>
#define pii pair <int,int>
#define fir first
#define sec second
#define mp make_pair
#define pb push_back
#define emp emplace_back
#define MASK(i) ((1LL)<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define all(c) (c).begin(),(c).end()
#define sz(c) (int)((c).size())
#define fn "test"    ///FILE_NAME_HERE

/*------------------------------------------END_OF_TEMPLATE------------------------------------------*/

namespace task{

    vector <int> calc(string str){
        str+="+";
        stack <int> stk;
        vector <int> ret;
        for(int i = 0;i < sz(str);++i){
            if(str[i] == '*')continue;
            if(str[i] == '+'){
                int mask = 0;
                while(!stk.empty()){
                    mask |= (1 << stk.top());
                    stk.pop();
                }
                ret.emp(mask);
            } else {
                stk.push(str[i] - 'a');
            }
        }
        sort(all(ret));
        ret.erase(unique(all(ret)),ret.end());
        return ret;
    }

    void solve(){
        string s,t;
        cin>>s>>t;
        vector <int> ans_s = calc(s);
        vector <int> ans_t = calc(t);
        if(sz(ans_s) != sz(ans_t)){
            cout<<"WA";
            return ;
        } else {
            for(int i = 0;i < sz(ans_s);++i){
                if(ans_s[i] != ans_t[i]){
                    cout<<"WA";
                    return ;
                }
            }
            cout<<"OK";
        }
    }
}

int main(void){
    task::solve();
}