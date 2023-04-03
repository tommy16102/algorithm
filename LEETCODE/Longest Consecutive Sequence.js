/**
 * @param {number[]} nums
 * @return {number}
 */

var longestConsecutive = function(nums) {
    const increMap = new Map();
    const decreMap = new Map();
    const getIncre = (v) => increMap.get(v - 1);
    const getDecre = (v) => decreMap.get(v + 1);
    let ans = 0;
    nums.sort((a, b) => a - b).forEach(v => {
        if (getIncre(v)) increMap.set(v, getIncre(v) + 1)
        else increMap.set(v, 1);
        if (getDecre(v)) decreMap.set(v, getDecre(v) + 1)
        else decreMap.set(v, 1);
        ans = Math.max(ans, increMap.get(v), decreMap.get(v));
    })
    return ans;
};
