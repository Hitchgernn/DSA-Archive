#include <iostream>
#include <chrono>
#include <vector>
using namespace std;
using namespace std::chrono;

// Dynamic Programming Implementaion of Grid Problem
int dp(int n, int m, vector <vector<int>> &grid) {
    if (n == 0 || m == 0) {
        return 0;
    } else if (n == 1 || m == 1) {
        return 1;
    } else if (grid[n][m] != -1) {
        return grid[n][m];
    } else return grid[n][m] = dp(n-1, m, grid) + dp(n, m-1, grid);
}

int main() {
    int n, m;
    cin >> n >> m;

    // using recursion
    vector <vector<int>> grid(n + 1, vector<int>(m + 1, -1));
    
    auto start = high_resolution_clock::now();
    cout << dp(n, m, grid) << endl;
    auto stop = high_resolution_clock::now();
    // print time taken by recursion
    auto duration = duration_cast<microseconds>(stop - start);
    cout << duration.count() << endl;

    // using iteration
    vector <vector<int>> grid1(n + 1, vector<int> (m + 1));
    auto start1 = high_resolution_clock::now();
    for (int i = 1; i <= n; i++) {
        grid1[i][1] = 1;
    }
    for (int j = 1; j <= m; j++) {
        grid1[1][j] = 1;
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= m; j++) {
            grid1[i][j] = grid1[i-1][j] + grid1[i][j-1];
        }
    }
    cout << grid1[n][m] << endl;
    auto stop1 = high_resolution_clock::now();
    //print timme taken by iteration
    auto duration1 = duration_cast<microseconds>(stop1 - start1);
    cout << duration1.count() << endl;
    
    return 0;
}
