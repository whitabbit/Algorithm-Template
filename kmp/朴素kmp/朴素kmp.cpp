#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define endl '\n'
#define pp(x) cout << #x << " = " << x << endl
#define io ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MAXN 1e6 + 5
#define db freopen("test.in", "r", stdin), freopen("test.out", "w", stdout)

int next1[1000005];

void get_next1(string s2) {
    next1[0] = -1;
    int len = s2.size();
    for (int i = 0, j = -1; i < len - 1;) {
        if (j == -1 || s2[i] == s2[j]) {
            next1[++i] = ++j;
        } else {
            j = next1[j];
        }
    }
    // 查看next1数组
    // for (int i = 0; i < len; ++i) {
    //     printf("%d ", next1[i]);
    // }
    // putchar(10);
}

int kmp(string s1, string s2) {
    int i = 0, j = 0, len1 = s1.size(), len2 = s2.size();
    for (; i < len1 && j < len2;) {
        if (j == -1 || s1[i] == s2[j]) {
            ++i, ++j;
        } else {
            j = next1[j];
        }
    }
    if (j == len2) {
        return i - len2;
    } else {
        return -1;
    }
}

int main() {
    string s1, s2;
    while (cin>>s1>>s2) {
        get_next1(s2);
        cout << kmp(s1, s2) << endl;
    }
    return 0;
}