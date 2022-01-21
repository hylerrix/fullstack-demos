// 通过 this 指针，用类的方法将 CheckObject 改造
var CheckObject = function () {
  var i = 0
  this.checkName = function () {
      i++
      console.log('checkName: ', i)
      // 允许实例进行链式调用
      return this
  },
  this.checkEmail = function () {
      console.log('checkEmail: ', i)
      return this
  },
  this.checkPassword = function () {
      console.log('checkPassword: ', i)
      return this
  }
}

var a = new CheckObject()
a.checkName() // 1
a.checkName() // 2
var b = new CheckObject()
b.checkName() // 1
b.checkName() // 2

// 重构成链式调用
a.checkName().checkName() // 3 // 4