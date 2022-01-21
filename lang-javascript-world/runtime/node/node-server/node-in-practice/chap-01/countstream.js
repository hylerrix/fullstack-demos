let Writable = require('stream').Writable
let util = require('util')

module.exports = CountStream

// 继承可写流
util.inherits(CountStream, Writable)

function CountStream (matchText, options) {
    Writable.call(this, options)
    this.count = 0
    // 创建一个全局且忽略大小写的正则对象
    this.matcher = new RegExp(matchText, 'ig')
}

/*
 * 所有可写流实现必须提供一个 writable._write() 方法将数据发送到底层资源。
 * writable._write()方法前缀为下划线，不得直接由应用程序代码调用。 它应该由子类实现，并由内部的 Writable 类方法调用。
 * @chunk <Buffer> | <string> | <any> 要写的块。会一直作为缓冲区，除非 decodeStrings 选项设置为 false 或者流以对象模式运行。
 * @encoding <string> 如果块是字符串，那么 encoding 就是该字符串的字符编码。 如果块是 Buffer，或者是流在对象模式下运行，encoding 可能被忽略。
 * @callback <Function> 调用此函数 err 参数可选 当块处理完成时。
 */
CountStream.prototype._write = function (chunk, encoding, cb) {
    // 把当前的输入数据转化为字符串并进行匹配
    let matches = chunk.toString().match(this.matcher)
    if (matches) {
        this.count += matches.length
    }
    cb();
}

CountStream.prototype.end = function () {
    // 当输入流结束时，触发 total 事件
    this.emit('total', this.count);
}