// udp 套接字一旦创建，即可以作为客户端，也可以作为服务器端
var dgram = require('dgram')
var server = dgram.createSocket('udp4')

server.on('message', function (msg, rinfo) {
  console.log('server got: ' + msg + ' from ' +
    rinfo.address + ':' + rinfo.port)
})

// 该套接字将接受所有网卡 41234 端口上的信息，在绑定完成后，将触发 listening 事件
server.on('listening', function () {
  var address = server.address()
  console.log('server listening ' +
    address.address + ':' + address.port)
})

// 若想让 UDP 套接字接收网络消息，只要调用 dgram.bind 方法对网卡和端口进行绑定即可
server.bind(41234)