var largestNumber = function(nums) {
    nums.sort((a, b) => `${b}${a}` - `${a}${b}`);
    const ans = nums.reduce((a, b) => (a === '0' ? '0' : `${a}${b}`), '');
    return ans;
};
