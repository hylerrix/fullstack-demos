// 构造函数继承，通过在子类的构造函数作用环境中执行一次父类的构造函数来实现的
// 声明父类
function SuperClass (id) {
    // 引用类型共用属性
    this.books = ['JavaScript', 'html', 'css']
    // 值类型公有属性
    this.id = id
}
// 父类声明原型方法
SuperClass.prototype.showBooks = function () {
    console.log(this.books)
}
// 声明子类
function SubClass (id) {
    // 继承父类，这条语句是函数式继承的精华
    SuperClass.call(this, id)
}

// 创建第一个子类的实例
var instance1 = new SubClass(10)
// 创建第二个子类的实例
var instance2 = new SubClass(11)

instance1.books.push('设计模式')
console.log(instance1.books) // [ 'JavaScript', 'html', 'css', '设计模式' ]
console.log(instance1.id) // 10
console.log(instance2.books) // [ 'JavaScript', 'html', 'css' ]
console.log(instance2.id) // 11

// 子类不能继承原型方法
instance1.showBooks() // TypeError