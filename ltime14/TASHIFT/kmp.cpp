#include <iostream>
#include <string>
#include <vector>
using namespace std;

class KMP {
public:
    typedef vector<int> IntVector;

    int n;
    int m;
    string t;
    string p;
    IntVector b;
    
    int l;
    
    void init( string text, string pattern ) {
        t = text;
        p = pattern;
        n = t.size();
        m = p.size();
        b = IntVector(max(n, m), -1);
        l = 0;
        
        preprocess();
    }

    void preprocess()
    {
        int i=0, j=-1;
        b[i]=j;
        while (i<m)
        {
            while (j>=0 && p[i]!=p[j]) j=b[j];
            i++; j++;
            b[i]=j;
        }
    }
    
    template <class Func> void search(Func callback)
    {
        int i=0, j=0;
        while (i<n)
        {
            while (j>=0 && t[i]!=p[j]) j=b[j];
            i++; j++;
            if ( j > l ) {
                l = j;
                callback(i - j, j);
            }
            if ( j == m )
            {
                j=b[j];
            }
        }
    }
};

int n;
string a, b;
int max_len;
int res;

void callback( int x, int l ) {
    // cout << x << ", " << l << endl;
    if ( l > max_len ) {
        res = x;
        max_len = l;
    }
}

int main() {
    max_len = 0;
    res = 0;
    
    cin >> n;
    cin >> a >> b;
    
    KMP kmp;
    kmp.init(b + b, a);
    kmp.search(callback);
    
    cout << res << endl;
    
    return 0;
}
