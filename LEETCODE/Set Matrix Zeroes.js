var setZeroes = function(matrix) {
    const arr = [];
    for (let i = 0; i < matrix.length; i++) {
        for (let j = 0; j < matrix[i].length; j++) {
            if (matrix[i][j] === 0) arr.push({i, j});
        }
    }

    arr.forEach(({i, j}) => {
        for (let a = 0; a < matrix.length; a++) matrix[a][j] = 0;
        for (let a = 0; a < matrix[i].length; a++) matrix[i][a] = 0;
    })
};
