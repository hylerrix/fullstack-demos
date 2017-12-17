// 组合式继承，在子类构造函数中执行父类构造函数，在子类原型上实例化父类
// 缺点，父类构造函数调用了俩遍
// 声明父类
function SuperClass (name) {
    // 值类型共有属性
    this.name = name
    // 引用类型共有属性
    this.books = ['html', 'css', 'JavaScript']
}
// 父类原型共有方法
SuperClass.prototype.getName = function () {
    console.log(this.name)
}
// 声明子类
function SubClass (name, time) {
    // 构造函数式继承父类 name 属性
    SuperClass.call(this, name)
    // 子类中新增共有属性
    this.time = time
}
// 类式继承 子类原型继承父类
SubClass.prototype = new SuperClass()
// 子类原型方法
SubClass.prototype.getTime = function () {
    console.log(this.time)
}

var instance1 = new SubClass('js book', 2014)
instance1.books.push('设计模式')
console.log(instance1.books) // [ 'html', 'css', 'JavaScript', '设计模式' ]
instance1.getName() // js book
instance1.getTime() // 2014

var instance2 = new SubClass('css book', 2013)
console.log(instance2.books) // [ 'html', 'css', 'JavaScript' ]
instance2.getName() // css book
instance2.getTime() // 2013