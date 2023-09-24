#include <iostream>
using namespace std;

const int MAX = 100;

int goldMine(int m, int n, int mine[MAX][MAX]) {
    int dp[MAX][MAX] = {0};

    for (int i = 0; i < m; i++) {
        dp[i][0] = mine[i][0];
    }

    for (int j = 1; j < n; j++) {
        for (int i = 0; i < m; i++) {
            int up = (i > 0) ? dp[i - 1][j - 1] : 0;
            int down = (i < m - 1) ? dp[i + 1][j - 1] : 0;
            int right = dp[i][j - 1];

            dp[i][j] = mine[i][j] + max(up, max(down, right));
        }
    }

    int maxGold = dp[0][n - 1];
    for (int i = 1; i < m; i++) {
        maxGold = max(maxGold, dp[i][n - 1]);
    }

    return maxGold;
}

int main() {
    int m, n;
    cout << "Enter the number of rows and columns: " << endl;
    cin >> m >> n;

    int mine[MAX][MAX];
    cout << "Enter the gold values:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mine[i][j];
        }
    }

    int maxGold = goldMine(m, n, mine);
    cout << "Maximum gold that can be collected: " << maxGold << endl;

    return 0;
}
