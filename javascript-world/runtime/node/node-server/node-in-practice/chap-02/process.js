// Run with:
//   cat file.txt | node process.js

// 通知 stream 开始读取数据
process.stdin.resume()
process.stdin.setEncoding('utf8')

// 这个回调以块的形式处理数据
process.stdin.on('data', function (text) {
    process.stdout.write(text.toUpperCase())
})