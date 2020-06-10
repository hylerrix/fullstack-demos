// 简单的复制，返回的对象和 CheckObject 本身无关
var CheckObject = function () {
    var i = 0
    return {
        checkName: function () {
            i++
            console.log('checkName: ', i)
        },
        checkEmail: function () {
            i++
            console.log('checkEmail: ', i)
        },
        checkPassword: function () {
            i++
            console.log('checkPassword: ', i)
        }
    }
}

var a = CheckObject()
a.checkEmail() // 1
a.checkEmail() // 2
var b = CheckObject()
b.checkEmail() // 1
b.checkEmail() // 2