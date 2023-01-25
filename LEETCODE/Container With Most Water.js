var maxArea = function(height) {
    let l = 0, r = height.length - 1;
    let ans = 0;
    while (l < r) {
        let store = Math.min(height[l], height[r]) * (r - l);
        if (store > ans) ans = store;
        if (height[l] > height[r]) r--;
        else l++;
    }

    return ans;
};
