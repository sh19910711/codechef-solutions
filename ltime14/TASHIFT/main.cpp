#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

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
UInt A[N_MAX];
UInt XA[N_MAX];
UInt XB[N_MAX];

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
    
    for ( int i = 0; i < na; ++ i ) XA[i] = (a[i] - 'a' + 1);
    for ( int i = 0; i < nb; ++ i ) XB[i] = (b[i] - 'a' + 1);
    
    fill(A, A + N_MAX, 0ULL);
    UInt key = 0;
    UInt base = 1;
    UInt k = 27;
    
    for ( int i = 0; i < lcs_len; ++ i ) {
        key *= k;
        key += XA[i];
    }
    A[0] = 0;
    for ( int i = 0; i < lcs_len; ++ i ) {
        A[0] *= k;
        A[0] += XB[i];
    }
    
    return 0;
}
