// 使用原型对象减少开销
var CheckObject = function () {
    var i = 0;
}

CheckObject.prototype.checkName = function () {
    // this 指向的是实例
    console.log(this instanceof CheckObject) // true
    console.log('checkName: ', this.checkName)
    // 允许实例链式调用
    return this
}

CheckObject.prototype.checkEmail = function () {
    console.log('checkEmail: ', this.__proto__.checkEmail)
    return this
}

CheckObject.prototype.checkPassword = function () {
    console.log('checkPassword: ', this.__proto__.checkPassword)
    return this
}

/* 或将上述结构改善为以下风格，两种风格不能同时使用
CheckObject.prototype  = {
    checkName: function () {},
    checkEmail: function () {},
    checkPassword: function () {}
}
*/

var a = new CheckObject()
a.checkName()
a.checkEmail()
a.checkPassword()

console.log('\n\n------\n\n')

// 进行链式调用
a.checkName().checkEmail().checkPassword()