var http = require('http')
// HTTP 服务只做两件事情：处理 HTTP 请求和发送 HTTP 响应
http.createServer(function (req, res) {
  res.writeHead(200, {'Content-Type': 'text/plain'})
  res.end('Hello World!')
}).listen(1337, '127.0.0.1')
console.log('Server running at http://127.0.0.1:1337')