/**
 * @param {number[]} nums
 * @return {number[][]}
 */

var threeSum = function(nums) {
    nums.sort((a, b) => a - b);    
    const set = new Set();
    const ans = [];
    for (let i = 0; i < nums.length - 2; i++) {
        let p1 = i + 1;
        let p2 = nums.length - 1;
        while (p1 < p2) {
            let sum = nums[i] + nums[p1] + nums[p2];
            if (sum < 0) p1++;
            else if (sum > 0) p2--;
            else {
                const str = `${nums[i]}-${nums[p1]}-${nums[p2]}`;
                if (!set.has(str)) {
                    ans.push([nums[i], nums[p1], nums[p2]]);
                    set.add(str);
                }
                p1++;
                p2--;
            }
        }
    }
    return ans;
};
