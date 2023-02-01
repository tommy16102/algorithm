var uniquePaths = function(m, n) {
    const arr = new Array(m).fill(0).map(() => new Array(n).fill(0));
    arr[0][0] = 1;
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (i === 0 && j === 0) continue;
            if (i > 0) arr[i][j] += arr[i - 1][j];
            if (j > 0) arr[i][j] += arr[i][j - 1];
        }
    }
    return arr[m - 1][n - 1];
};
