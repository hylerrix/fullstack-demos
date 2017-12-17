// 在函数祖先上设置一种不污染全局变量的方法，这里是函数式调用
Function.prototype.addMethod = function (name, fn) {
    this[name] = fn
    // 允许实例链式设置方法
    return this
}

var methods = function() {}

// 链式添加方法
methods.addMethod('checkName', function () {
    console.log('checkName')
    // 允许实例链式调用方法
    return this
}).addMethod('checkEmail', function () {
    console.log('checkEmail')
    return this
})

methods.checkName()
methods.checkEmail()

// 链式调用
methods.checkName().checkEmail()