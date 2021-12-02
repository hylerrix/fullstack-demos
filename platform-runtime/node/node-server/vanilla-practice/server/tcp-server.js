var net = require('net')

// 通过 net.createServer() 创建的服务器而言，是一个 EventEmitter 实例
//   自定义事件有：listening、connection、close、error
var server = net.createServer(function (socket) {
  // 新的连接
  socket.on('connection', function (socket) {
      console.log('新的连接')
  })

  // data 事件从一端读取另一端发来的数据
  socket.on('data', function (data) {
      socket.write('你好\n')
  })

  socket.on('end', function () {
      console.log('连接断开\n')
  })

  // write 事件从一端向另一端发送数据
  socket.write("欢迎光临《深入浅出 Node.js》示例：\n")
})

server.listen(8124, function () {
    console.log('server bound')
})

// node tcp-sercer.js
// server.listen() 监听端口时：客户端访问：telnet 127.0.0.1 8124
// server.listen() 监听 Domain Socket 如 '/tmp/echo.sock' 时：nc -U /tmp/echo.sock

// TCP 针对网络中的小数据包有一定的优化策略：Nagle 算法，优化网络
// Node 中 TCP 默认启用 Nagle 算法，可以调用 socket.setNoDelay(true) 去掉该算法