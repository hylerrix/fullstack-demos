var CountStream = require('./countstream')
// 创建一个 CountStream 的实例用来匹配 book 的文本计数
var countStream = new CountStream('book')
var http = require('http')

// 下载页面
http.get('http://www.jianshu.com/u/ecbf49bf207b', function (res) {
  // 从网站中以管道的方式把数据传给 countStream 用于文本计数
  // node Stream 主要的操作也是 .pipe()，使用者可以使用反压力机制来控制读和写的平衡 
  // 所有类型的 Stream 都是使用 .pipe() 来创建一个输入输出对，
  // 如下接收一个可读流 res 并将其数据输出到可写流 countStream
  res.pipe(countStream)
})

// on 用来绑定事件函数
countStream.on('total', function (count) {
  console.log('Total matches:', count)
})