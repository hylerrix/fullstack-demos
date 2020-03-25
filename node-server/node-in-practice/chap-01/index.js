var CountStream = require('./countstream')
var countStream = new CountStream('前端')
var http = require('http')

http.get('http://xupt-fe.top/', function (res) {
    // 当使用管道传输数据时，不用去关心数据有多大或者网络速度有多慢，Node 会把文件一块一块进行处理
    res.pipe(countStream)
})

countStream.on('total', function (count) {
    console.log('Total matches:', count)
})