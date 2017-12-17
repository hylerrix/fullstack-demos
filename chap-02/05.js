// 类式继承的缺点
function SuperClass () {
    // 父类中的共有属性是引用类型
    this.books = ['JavaScript', 'html', 'css']
}
function SubClass () {}
SubClass.prototype = new SuperClass()
var instance1 = new SubClass
var instance2 = new SubClass
console.log(instance2.books) // [ 'JavaScript', 'html', 'css' ]
instance1.books.push('设计模式')
console.log(instance2.books) // [ 'JavaScript', 'html', 'css', '设计模式' ]