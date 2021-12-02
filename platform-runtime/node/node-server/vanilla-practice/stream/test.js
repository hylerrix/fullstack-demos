var assert = require('assert')
var CountStream = require('./countstream')
var countStream = new CountStream('example')
var fs = require('fs')
var passed = 0

// 当流结束时，total 事件将会被触发
countStream.on('total', function (count) {
  // 断言所预计的计数
  assert.equal(count, 1)
  passed++
})

// 为当前文件创建一个可读流，并且把数据通过管道传给 CountStream
fs.createReadStream(__filename).pipe(countStream)

process.on('exit', function () {
  // 在程序结束前，展示执行了断言的数量
  console.log('Assertions passed:', passed)
})