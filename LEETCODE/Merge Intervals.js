var merge = function(intervals) {
    intervals.sort((a, b) => a[0] > b[0] ? 1 : (a[0] === b[0] && a[1] > b[1]) ? 1 : -1);
    const arr = [];
    for (const [start, end] of intervals) {
        let canPush = false;
        for (let i = 0; i < arr.length; i++) {
            if (start > arr[i][1]) continue;
            if (end <= arr[i][1]) {
                canPush = true;
                break;
            }
            arr[i][1] = end;
            canPush = true;
            break;
        }
        if (!canPush) arr.push([start, end]);
        console.log(arr);
    }
    return arr;
};
