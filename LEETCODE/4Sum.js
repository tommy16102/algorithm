var fourSum = function(nums, target) {
    nums.sort((a, b) => a - b);
    const set = new Set();
    const ans = [];
    for (let i = 0; i < nums.length - 3; i++) {
        for (let j = i + 1; j < nums.length - 2; j++) {
            let p1 = j + 1;
            let p2 = nums.length - 1;
            while(p1 < p2) {
                const sum = nums[i] + nums[j] + nums[p1] + nums[p2];
                if (sum < target) p1++;
                else if (sum > target) p2--;
                else {
                    const str = `${nums[i]}-${nums[j]}-${nums[p1]}-${nums[p2]}`;
                    if (!set.has(str)) {
                        set.add(str);
                        ans.push([nums[i], nums[j], nums[p1], nums[p2]]);
                    }
                    p1++;
                    p2--;
                }
            }
        }
    }
    return ans;
};
