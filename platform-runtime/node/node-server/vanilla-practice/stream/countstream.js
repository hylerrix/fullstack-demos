// 一个用于计数的可写流
// Streams 从 EventEmitter 继承而来，所以它们都有同样的 emit 和 on 方法
// 有五种基本的 Stream：Readable, Writable, Transform, Duplex 和 Classic
var Writable = require('stream').Writable
var util = require('util')

module.exports = CountStream

// 继承可写流
util.inherits(CountStream, Writable)

function CountStream (matchText, options) {
  Writable.call(this, options)
  this.count = 0
  // 创建一个全局且忽略大小写的正则对象
  this.matcher = new RegExp(matchText, 'ig')
}

CountStream.prototype._write = function (chunk, encoding, cb) {
  // 把当前的输入数据转化为字符串并进行匹配
  var matches = chunk.toString().match(this.matcher)
  if (matches) {
    this.count += matches.length
  }
  cb()
}

// 当不再有数据时，Node 的 Writable 基类会调用 end 方法，
// 该类可以被实例化，并且根据需要通过管道进行传输数据
CountStream.prototype.end = function () {
  // 当输入流结束时，触发 total 事件
  // emit 用于触发事件
  this.emit('total', this.count)
}