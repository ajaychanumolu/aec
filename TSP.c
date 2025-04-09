#include <stdio.h>
#include <limits.h>

#define MAX 9999

int n;
int dis[20][20];
int dp[1024][20];

// Recursive TSP function
int TSP(int mark, int position) {
    int visited = (1 << n) - 1;

    if (mark == visited) {
        return dis[position][0]; // return to starting city
    }

    if (dp[mark][position] != -1) {
        return dp[mark][position];
    }

    int answer = MAX;

    for (int city = 0; city < n; city++) {
        if ((mark & (1 << city)) == 0) {
            int newanswer = dis[position][city] + TSP(mark | (1 << city), city);
            if (newanswer < answer) {
                answer = newanswer;
            }
        }
    }

    return dp[mark][position] = answer;
}

int main() {
    printf("Enter the number of cities: ");
    scanf("%d", &n);

    printf("Enter the distance matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &dis[i][j]);

    // Initialize dp array to -1
    for (int i = 0; i < (1 << n); i++)
        for (int j = 0; j < n; j++)
            dp[i][j] = -1;

    int result = TSP(1, 0); // Start from city 0 (mark = 1 means city 0 visited)

    printf("Minimum cost to visit all cities: %d\n", result);

    return 0;
}
