var threeSumClosest = function(nums, target) {
    nums.sort((a, b) => a - b);
  
    let ans = Infinity;
    for (let i = 0; i < nums.length - 2; i++) {
        let l = i + 1;
        let r = nums.length - 1;
        while (l < r) {
            let sum = nums[i] + nums[l] + nums[r];
            if (Math.abs(sum - target) < Math.abs(ans - target)) ans = sum;
            if (sum > target) r--;
            else if (sum < target) l++;
            else return sum;
        }
    }

    return ans;
};
