function checkPalin(str, left, right) {
    let ret = '';
    while(left >= 0 && right < str.length) {
        if (str[left] === str[right]) {
            ret = str.slice(left, right + 1);
            left--;
            right++;
        }
        else break;
    }
    return ret;
}

var longestPalindrome = function(s) {
    let ans = '';
    for (let i = 0; i < s.length; i++) {
        const palin1 = checkPalin(s, i, i);
        const palin2 = checkPalin(s, i - 1, i);
        if (palin1.length < ans.length && palin2.length < ans.length) continue;
        ans = palin1.length > palin2.length ? palin1 : palin2;
    }
    return ans;
};
