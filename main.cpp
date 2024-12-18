#include <cstdlib>
#include <ctime>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

using namespace std;

#define FAST_IO                \
  ios::sync_with_stdio(false); \
  cin.tie(nullptr);            \
  cout.tie(nullptr)
#define READ_WRITE_FILE          \
  freopen("in.txt", "r", stdin); \
  freopen("out.txt", "w", stdout)

int solve(const string &s) {
  const int n = s.length();
  vector<vector<int>> dp(n, vector<int>(n, 0));

  for (int i = 0; i < n; ++i)
    dp[i][i] = 1;

  for (int len = 2; len <= n; ++len) {
    for (int i = 0; i < n - len + 1; ++i) {
      int j = i + len - 1;
      if (s[i] == s[j]) {
        dp[i][j] = dp[i + 1][j - 1] + 2;
      } else {
        dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
      }
    }
  }

  return dp[0][n - 1];
}

int main() {
  FAST_IO;
  READ_WRITE_FILE;

  int TC;
  cin >> TC;
  cin.ignore();
  while (TC--) {
    string s;
    getline(cin, s);
    cout << solve(s) << endl;
  }

  return 0;
}
