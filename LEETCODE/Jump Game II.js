var jump = function(nums) {
    const arr = new Array(nums.length).fill(Infinity);
    arr[0] = 0;
    for (let i = 0; i < nums.length; i++) {
        const val = nums[i];
        for (let j = i + 1; j <= i + val; j++) {
            arr[j] = Math.min(arr[j], arr[i] + 1);
        }
    }
  
    return arr[nums.length - 1];
};
