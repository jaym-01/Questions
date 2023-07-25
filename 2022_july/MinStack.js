var MinStack = function() {
    this.content = [];
    this.top_val = -1;
    // this.min = null;
};

/** 
 * @param {number} val
 * @return {void}
 */
MinStack.prototype.push = function(val) {
    if(this.content.length == this.top_val + 1){
        this.content.push(val);
    }
    else{
        this.content[this.top_val + 1] = val;
    }
    this.top_val++;
};

/**
 * @return {void}
 */
MinStack.prototype.pop = function() {
    if(this.top_val > -1){
        --this.top_val;
    }    
};

/**
 * @return {number}
 */
MinStack.prototype.top = function() {
    if(this.top_val > -1){
        return this.content[this.top_val];
    }
};

/**
 * @return {number}
 */
MinStack.prototype.getMin = function() {
    return Math.min.apply(null, this.content.slice(0, this.top_val + 1));
};

/** 
 * Your MinStack object will be instantiated and called as such:
 * var obj = new MinStack()
 * obj.push(val)
 * obj.pop()
 * var param_3 = obj.top()
 * var param_4 = obj.getMin()
 */

var obj = new MinStack()
console.log(obj.push(3));
console.log(obj.push(4));
console.log(obj.push(7));
console.log(obj.top());
console.log(obj.pop());
console.log(obj.top());
console.log(obj.push(8));
console.log(obj.getMin());
