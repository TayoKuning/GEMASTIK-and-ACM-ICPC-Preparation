
#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    freopen("race.in", "r", stdin);
    freopen("race.out", "w", stdout);

    int dist,speed; cin>>dist>>speed;

    while (speed--) {
        int mxspeed; cin>>mxspeed;
        int temp_dist = dist;
        int ans = 0;

        if (temp_dist <= ((mxspeed + 1) * mxspeed) / 2) {
            int l = 0, r = mxspeed;
            while (l <= r) {
                int mid = (l+r)/2;
                if(temp_dist <= (mid + 1) * mid / 2) {
                    r = mid - 1;
                    ans = mid;
                } else l = mid+1;
            }
        } else {
            temp_dist -= (mxspeed - 1) * mxspeed / 2;
            ans += mxspeed - 1;
            int l = mxspeed, r = temp_dist;
            int ans_tambahan = mxspeed - 1;

            while (l <= r) {
                int mid = (l+r)/2;
                if(temp_dist >= (mid + mxspeed) * (mid - mxspeed + 1)) {
                    ans_tambahan = mid;
                    l = mid + 1;
                }else r = mid - 1;
            }

            int tot = (ans_tambahan + mxspeed) * (ans_tambahan - mxspeed + 1);
            if (temp_dist > tot) {
                if (temp_dist - tot > ans_tambahan + 1)
                    ans += 2;
                else ans++;
            }

            ans_tambahan -= (mxspeed - 1);
            ans += ans_tambahan * 2;
        }

        cout<<ans<<endl;
    }
}
