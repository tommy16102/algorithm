const check = (i, j, board, word) => {
    if (!word) return true;
    if (i < 0 || j < 0 || i >= board.length || j >= board[0].length) return false;
    if (board[i][j] !== word[0]) return false;

    const nextWord = word.slice(1);
    const nowWord = board[i][j];
    board[i][j] = '';
    const res = check(i + 1, j, board, nextWord) || check(i - 1, j, board, nextWord) || check(i, j - 1, board, nextWord) || check(i, j + 1, board, nextWord);
    board[i][j] = nowWord;
    return res;
}

var exist = function(board, word) {
    for (let i = 0; i < board.length; i++) {
        for (let j = 0; j < board[i].length; j++) {
            if (check(i, j, board, word)) return true;
        }
    }
    return false;
};
