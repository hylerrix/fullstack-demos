// 寄生式继承，对原型继承进行第二次封装，并且对继承的对象进行了拓展

function inheritObject (o) {
    function F () {}
    F.prototype = o
    return new F()
}

// 声明基对象
var book = {
    name: 'js book',
    alikeBook: ['css book', 'html book']
}

function createBook (obj) {
    // 通过原型继承方式创建新对象
    var o = new inheritObject(obj)
    // 拓展新对象
    o.getName = function () {
        console.log(name)
    }
    // 返回拓展后的新对象
    return o
}