let ans = [];

const calc = (arr, elem, sum, target) => {
    if (sum === target) {
        ans.push(elem);
        return;
    }

    for (let i = 0; i < arr.length; i++) {
        let e = arr[i];
        if (sum + e > target) continue;
        calc(arr.slice(i), [...elem, e], sum + e, target);
    }
}

var combinationSum = function(candidates, target) {
    ans = [];
  
    for (let i = 0; i < candidates.length; i++) {
        let elem = candidates[i];
        if (elem > target) continue;
        calc(candidates.slice(i), [elem], elem, target);
    }
  
    return ans;
};
