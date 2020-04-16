#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <map>
const int MAXN = 10000005;
using namespace std;
struct poly{
    int zhishu;
    int xisu=0;
};
bool cmp(poly a,poly b){
    return a.zhishu<b.zhishu;
}
int main() {
    int n;
    cin>>n;
    vector<poly>v1(MAXN),v2(MAXN);
    for (int i = 0; i < n; ++i) {
        int zs,xs;
        cin>>zs>>xs;
        v1[zs].zhishu=zs;
        v1[zs].xisu=xs;
    }
    cin>>n;
    for (int i = 0; i < n; ++i) {
        int zs,xs;
        cin>>zs>>xs;
        v2[zs].zhishu=zs;
        v2[zs].xisu=xs;
    }

}