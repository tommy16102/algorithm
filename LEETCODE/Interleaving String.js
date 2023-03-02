var isInterleave = function(s1, s2, s3) {
    const map = new Map();

    const calc = (a, b, c) => {
        if(c === s3.length) return a === s1.length && b === s2.length;
        const key = [a, b, c].join(' ');
        
        if(map.has(key)) return map.get(key);
        
        let res1 = false, res2 = false;
        if(s1[a] == s3[c]) res1 = calc(a + 1, b, c + 1);
        if(s2[b] == s3[c]) res2 = calc(a, b + 1, c + 1);

        map.set(key, res1 || res2);
        
        return res1 || res2;
    }
    
    return calc(0, 0, 0);
};
