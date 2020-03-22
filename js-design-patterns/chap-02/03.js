// 图书安全类
var Book = function (title, time, type) {
    // 判断执行过程中 this 是否当前这个对象（如果是说明是用 new 创建的）
    if (this instanceof Book) {
        this.title = title
        this.time = time
        this.type = type
    } else {
        // 否则重新创建这个对象
        return new Book(title, time, type)
    }
}

var book = Book('JavaScript', 2014, 'js')
console.log(book) // Book
console.log(book.time) // 2014
console.log(book.title) // JavaScript
console.log(book.type) // js
console.log(window.time) // undefined
console.log(window.title) // undefined
console.log(window.type) // undefined