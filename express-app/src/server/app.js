/**
 * Created by hanyile on 2017/10/19.
 */

const express = require('express')
const birds = require('./birds')
const app = express()

const appLogger = function (req, res, next) {
  console.log('LOGGED')
  next()
}

const appRequestTime = function (req, res, next) {
  req.requestTime = Date.now()
  next()
}

app.all('/secret', function (req, res, next) {
  console.log('Accessing the secret section ...')
  next() // pass control to the next handler
})

// 根目录及其第一子目录处理请求时首先调用 appLogger 中间件函数
app.use([appLogger, appRequestTime])
app.use('/birds', birds)

app.get('/', function (req, res) {
  let responseText = 'GET request to the HomePage.\n'
  responseText += 'Requested at: ' + req.requestTime + ''
  res.send(responseText)
})

app.post('/', function (req, res) {
  res.send('POST request to the HomePage.')
})

app.get('/user', function (req, res, next) {
  console.log('the response will be sent by the next function.')
  next()
}, function (req, res) {
  res.send('GET request to the User Center from next.')
})

app.get('/user/:id', function (req, res, next) {
  console.log('Request URL:', req.originalUrl)
  console.log('Request Type:', req.method)
  console.log('ID:', req.params.id)
  // 如果用户 ID 是 0, 跳过剩余中间件, 返回特殊用户页面
  if (req.params.id == 0) next('route')
  // 否则进入下一个中间件, 返回普通用户页面
  else next()
}, function (req, res) {
  // 返回普通用户页面
  let responseText = req.params.id + '`s User Info.'
  res.send('Regular User.\n' + responseText)
})

app.get('/user/:id', function (req, res, next) {
  res.send('Special User 0, Welcome!')
})

app.listen(3333, function () {
  console.log('Example app listening on port 3333!')
})
