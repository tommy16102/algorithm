/**
 * @param {string} homepage
 */
var BrowserHistory = function(homepage) {
    this.list = [homepage];
    this.cursor = 0;
};

/** 
 * @param {string} url
 * @return {void}
 */
BrowserHistory.prototype.visit = function(url) {
    this.cursor++;
    this.list = [...this.list.slice(0, this.cursor), url];
    
};

/** 
 * @param {number} steps
 * @return {string}
 */
BrowserHistory.prototype.back = function(steps) {
    const next = this.cursor - steps;
    this.cursor = next > 0 ? next : 0;
    return this.list[this.cursor];
};

/** 
 * @param {number} steps
 * @return {string}
 */
BrowserHistory.prototype.forward = function(steps) {
    const next = this.cursor + steps;
    this.cursor = next < this.list.length ? next : this.list.length - 1;
    return this.list[this.cursor];
};

/** 
 * Your BrowserHistory object will be instantiated and called as such:
 * var obj = new BrowserHistory(homepage)
 * obj.visit(url)
 * var param_2 = obj.back(steps)
 * var param_3 = obj.forward(steps)
 */
