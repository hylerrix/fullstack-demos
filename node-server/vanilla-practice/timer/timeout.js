function Bomb () {
  this.message = 'Boom!'
}

Bomb.prototype.explode = function () {
  console.log(this.message)
}

var bomb = new Bomb()

// 调用 bind 方法可以确保这个方法绑定到正确的对象上
// 这样它可以访问这个对象的内部属性
// 否则，setTimeOut 会导致与 this 绑定到全局对象运行
var timeoutId = setTimeout(bomb.explode.bind(bomb), 1000)

// 取消将被执行的函数
clearTimeout(timeoutId)