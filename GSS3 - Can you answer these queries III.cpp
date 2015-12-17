#include<fstream>
#include<iostream>
#include<sstream>
#include<bitset>
#include<deque>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<vector>
#include<algorithm>
#include<iterator>
#include<string>
#include<cassert>
#include<cctype>
#include<climits>
#include<cmath>
#include<cstddef>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>

using namespace std;

const int MAX = 1 << 16;
int a[MAX];

struct node
{
    int Sum, bestLeftSum, bestRightSum, bestSum;

    node merge(node& l, node& r)
    {
        Sum = l.Sum + r.Sum;
        bestLeftSum = max(l.bestLeftSum, l.Sum + r.bestLeftSum);
        bestRightSum = max(r.Sum + l.bestRightSum, r.bestRightSum);
        bestSum = max(max(l.bestSum, r.bestSum), l.bestRightSum+r.bestLeftSum);
    }

    node setValue(int val) {
    Sum = bestLeftSum = bestRightSum = bestSum = val;
    }
};


node T[MAX << 1];

void init(int Node, int i, int j) {
    if(i == j) {
        T[Node].setValue(a[i]);
        return;
    }
    else {
        int m = (i+j)/2;
        init(2*Node, i, m);
        init(2*Node+1, m+1, j);
        T[Node].merge(T[2*Node], T[2*Node+1]);
    }
}

void update(int Node, int i, int j, int idx, int val) {
    if(i==j && i==idx) {
        T[Node].setValue(val);
        return;
    }
    else {
        int m = (i+j)/2;
        if(idx<=m)
            update(2*Node, i, m, idx, val);
        else
            update(2*Node+1, m+1, j, idx, val);
        T[Node].merge(T[2*Node], T[2*Node+1]);
    }
}
void range_query(node& resultNode, int Node, int i, int j, int L, int R) {
    if(i == L && j == R) {
        resultNode = T[Node];
        return;
    }
    else {
        int m = (i+j)/2;
        if(R<=m)
            range_query(resultNode, 2*Node, i, m, L, R);
        else if(L>m)
            range_query(resultNode, 2*Node+1, m+1, j, L, R);
        else {
            node left, right;
            range_query(left, 2*Node, i, m, L, m);
            range_query(right, 2*Node+1, m+1, j, m+1, R);
            resultNode.merge(left, right);
        }
    }
}

int main()
{
    int N, M;
    node res;
    cin>>N;
    for(int i=0; i<=N-1; ++i)
        scanf("%d", &a[i]);
    init(1, 0, N-1);
    cin>>M;
    int x, y;
    while(M--) {
        int query;
        scanf("%d", &query);
        scanf("%d %d", &x, &y);
        if(query == 1) {
            range_query(res, 1, 0, N-1, --x, --y);
            printf("%d\n", res.bestSum);
        }
        else {
            update(1, 0, N-1, --x, y);
        }
    }
    return 0;
}
