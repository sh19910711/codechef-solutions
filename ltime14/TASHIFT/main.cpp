#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

// ref: http://codeforces.com/blog/entry/4025
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

namespace SuffixArray
{
    const int MAXN = 1 << 21;
    const char * S;
    int N, gap;
    int sa[MAXN], pos[MAXN], tmp[MAXN], lcp[MAXN];

    bool sufCmp(int i, int j)
    {
        if (pos[i] != pos[j])
            return pos[i] < pos[j];
        i += gap;
        j += gap;
        return (i < N && j < N) ? pos[i] < pos[j] : i > j;
    }

    void buildSA()
    {
        N = strlen(S);
        REP(i, N) sa[i] = i, pos[i] = S[i];
        for (gap = 1;; gap *= 2)
        {
            sort(sa, sa + N, sufCmp);
            REP(i, N - 1) tmp[i + 1] = tmp[i] + sufCmp(sa[i], sa[i + 1]);
            REP(i, N) pos[sa[i]] = tmp[i];
            if (tmp[N - 1] == N - 1) break;
        }
    }

    void buildLCP()
    {
        for (int i = 0, k = 0; i < N; ++i) if (pos[i] != N - 1)
        {
            for (int j = sa[pos[i] + 1]; S[i + k] == S[j + k];)
            ++k;
            lcp[pos[i]] = k;
            if (k)--k;
        }
    }
}

typedef long long Int;
typedef unsigned long long UInt;
const Int N_MAX = 2000000 + 11;
const UInt d = 257;

// ref: http://ronzii.wordpress.com/2012/02/26/rabin-karp-algorithm/
int search(string pattern, string text)
{
    set<Int> ps;
    int res = 0;
    int M = pattern.length();
    int N = text.length();
    UInt h = 1;
    //The value of h would be "pow(d, M-1)%prime"
    for(int i=0; i<M-1; i++)
    {
        h *= d;
    }
    UInt p = 0,t = 0,i,j;
    // Calculate the hash value of pattern and first window of text
    for(i=0; i<M; i++)
    {
        p = d*p+pattern[i];
        ps.insert(p);
        t = d*t+text[i];
    }
    for(i=0; i<=(N-M); i++)
    {
        if ( p == t )
        {
            // Chaeck the hash values of current window of text and pattern
            // If the hash values match then only check for characters on by one
            for (j = 0; j < M; j++)
            {
                if (text[i+j] != pattern[j])
                    break;
            }
            if (j == M)  // if p == t and pat[0...M-1] = txt[i, i+1, ...i+M-1]
            {
                // printf("Pattern found at index %d \n", i);
                cout << text.substr(i) << endl;
                res = max(res, M);
            }
        }
        // Calulate hash value for next window of text: Remove leading digit,
        // add trailing digit
        if(i<(N-M))
        {
            t = (t - text[i]*h)*d + text[i+M];
        }
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    string a;
    string b;
    cin >> a >> b;
    b += b;
    string ab = a + b;
    SuffixArray::S = ab.c_str();
    SuffixArray::buildSA();
    SuffixArray::buildLCP();
    
    int na = a.size();
    int nb = b.size();
    int nab = ab.size();
    int lcs_len = 0;
    for ( int i = 0; i + 1 < nab; ++ i ) {
        if ( SuffixArray::sa[i] < na && SuffixArray::sa[i + 1] < na ) continue;
        if ( SuffixArray::sa[i] > na && SuffixArray::sa[i + 1] > na ) continue;
        if ( SuffixArray::sa[i] == na || SuffixArray::sa[i + 1] == na ) continue;
        lcs_len = max(lcs_len, SuffixArray::lcp[i]);
    }
    
    cout << search(a, b) << endl;
    
    return 0;
}
