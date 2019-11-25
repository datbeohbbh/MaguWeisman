// FROM VO MINH THIEN LONG - P3121

#include <bits/stdc++.h>

#define fto(i, x, y) for(auto i = (x); i <= (y); ++i)
#define fdto(i, x, y) for(auto i = (x); i >= (y); --i)
#define ftoa(i, x, y, a) for(auto i = (x); i <= (y); i += a)
#define ftoit(it, var) for (auto it = var.begin(); it != var.end(); ++it)
 
#define ii pair<int, int>
#define mp make_pair
#define ff first
#define ss second
 
#define vi vector<int>
#define vii vector<ii>
#define ll long long
#define vll vector<ll>
 
#define eb emplace_back
#define ef emplace_front
#define lb lower_bound
#define ub upper_bound
 
#define oo 1000000007
#define OO 1000000000000000007LL
 
using namespace std;
 
#define Pro "a"
#define maxN 300007

map <string, int> toInt;
string toStr[maxN];

set <int> addStr(set <int> a, int b) {
	a.insert(b);
	return a;
}

bool isContain(set <int> a, set <int> b) {
	ftoit(it, b) {
		if (a.lb(*it) == a.end() || *a.lb(*it) > (*it)) return 0;
	}
	return 1;
}
 
int main(int argc, char **argv) {
    string s;
    cin >> s;

    vector <set <int>> vc;
    int cntStr = 0;

    bool firstTime = 0;
    fto(i, 0, (int)s.size()-1) {
    	if (s[i] == '+' || s[i] == '(' || s[i] == ')' || s[i] == '*') continue;
    	if (s[i-1] == '(') {
			vector <set <int>> vt;
    		while (1) {
		    	string str = "";

		    	while (s[i] != '+' && s[i] != ')') {
		    		str += s[i];
		    		++i;
		    	}

		    	if (toInt[str] == 0) toInt[str] = ++cntStr;
		    	toStr[toInt[str]] = str;

				if (!firstTime) {
					set <int> tmp;
					tmp.insert(toInt[str]);
					vc.eb(tmp);
				}

				ftoit(it, vc) vt.eb(addStr((*it), toInt[str]));

				if (s[i] == ')') {
					if (!firstTime) firstTime = 1;
					else vc = vt;
					break;
				}
				++i;
			}
		}
		else {
			string str = "";

	    	while (s[i] != '*') {
	    		str += s[i];
	    		++i;
	    	}

	    	if (toInt[str] == 0) toInt[str] = ++cntStr;
	    	toStr[toInt[str]] = str;

			if (!firstTime) {
				set <int> tmp;
				tmp.insert(toInt[str]);
				vc.eb(tmp);
				firstTime = 1;
				continue;
			}

			vector <set <int>> vt;
			ftoit(it, vc) vt.eb(addStr((*it), toInt[str]));

			vc = vt;
		}
    }

    fto(i, 0, (int)vc.size()-1) {
    	if (vc[i].empty()) continue;
    	fto(j, 0, (int)vc.size()-1) {
    		if (i == j) continue;
    		if (vc[j].empty()) continue;
    		if (isContain(vc[j], vc[i])) vc[j].clear();
    	}
    }

    fto(i, 0, (int)vc.size()-1) {
    	if (vc[i].empty()) {
    		vc[i] = vc.back();
    		vc.pop_back();
    		--i;
    		continue;
    	}
    }

    fto(i, 0, (int)vc.size()-1) {
    	ftoit(it, vc[i]) {
    		if (it != (--vc[i].end())){
    			cout << toStr[(*it)] << "*";
    		}
    		else {
    			cout << toStr[(*it)];
    		}
    	}
    	if (i != (int)vc.size()-1) printf("+");
    }
    return 0;
}
