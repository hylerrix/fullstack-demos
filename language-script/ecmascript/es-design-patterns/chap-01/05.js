// 相比 04.js，这里使用类式调用
Function.prototype.addMethod = function (name, fn) {
    this.prototype[name] = fn
    return this
}

// 类式调用需要 new 关键字创建新对象
var Methods = function () {}

Methods.addMethod('checkName', function () {
    console.log('checkName')
    return this
}).addMethod('checkEmail', function () {
    console.log('checkEmail')
    return this
})

var m = new Methods()
m.checkName()
m.checkEmail()

m.checkName().checkEmail()