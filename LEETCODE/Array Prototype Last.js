/**
 * @return {null|boolean|number|string|Array|Object}
 */
Array.prototype.last = function() {
    const length = this.length;
    return length ? this[length - 1] : -1;
};
