var net = require('net')

// connect 事件用于客户端，当套接字与服务器端连接成功时会被触发该事件
var client = net.connect({port: 8124}, function () {
    console.log('client connected')
    client.write('world!\r\n')
})

// 当一端调用 write() 发送数据时，另一端会触发 data 事件
client.on('data', function (data) {
    console.log(data.toString())
    client.end()
})

client.on('end', function () {
    console.log('client disconnected')
})