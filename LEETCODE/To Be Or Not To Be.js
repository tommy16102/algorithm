/**
 * @param {string} val
 * @return {Object}
 */
const toBeOrNotToBeFunc = (isToBe) => (val1) => (val2) => {
    if (!isToBe ^ val1 === val2) {
        return true;
    }
    
    throw new Error(isToBe ? 'Not Equal' : 'Equal');
}

const expect = function(val) {
    const toBe = toBeOrNotToBeFunc(true)(val);
    const notToBe = toBeOrNotToBeFunc(false)(val);

    return {
        toBe,
        notToBe,
    }
};

/**
 * expect(5).toBe(5); // true
 * expect(5).notToBe(5); // throws "Equal"
 */
