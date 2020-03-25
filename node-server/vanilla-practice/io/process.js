// Run with:
// cat file.txt | node process.js

// 获取平台信息
console.log(process.arch)
console.log(process.memoryUsage())

// 通知 stream 准备开始读取数据
process.stdin.resume()
process.stdin.setEncoding('utf8')

process.stdin.on('data', function (text) {
  // 这个回调以块的形式处理数据
  process.stdout.write(text.toUpperCase())
})