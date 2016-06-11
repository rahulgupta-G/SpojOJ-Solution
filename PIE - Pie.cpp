#include <bits//stdc++.h>
using namespace std;
double pi = acos(-1.0);

int main()
{
    int kase, f, n;
    double r[10010];
    cin >> kase;
    while(kase--) {
        cin >> n >> f;
        for(int i=0; i<n; i++) {
            cin >> r[i];
            r[i] = r[i]*r[i]*pi;
        }

        double lo = 0.0, hi = 4e8, mi;


        for(int j=0; j<64; j++)
        {
            mi = (lo + hi) / 2;
            int cnt = 0;

            for(int i = 0; i<n && cnt<=f; i++) {
                cnt += (int) floor(r[i]/mi);
            }

            if(cnt > f) lo = mi;
            else hi = mi;
        }

        printf("%.4lf\n", lo);
    }
    return 0;
}
