var uniquePathsWithObstacles = function(arr) {
    const I = arr.length;
    const J = arr[0].length;
    const ansArr = new Array(I).fill(0).map(() => new Array(J).fill(0))
    
    if (arr[0][0] == 1) return 0;
    ansArr[0][0] = 1;

    for (let i = 0; i < I; i++) {
        for (let j = 0; j < J; j++) {
            if (arr[i][j] === 1) continue;
            if (i > 0 && arr[i - 1][j] !== 1) ansArr[i][j] += ansArr[i - 1][j];
            if (j > 0 && arr[i][j - 1] !== 1) ansArr[i][j] += ansArr[i][j - 1];
        }
    }

    return ansArr[I - 1][J - 1];
};
