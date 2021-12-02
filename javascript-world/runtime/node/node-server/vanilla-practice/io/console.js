console.time('label')

var name = 'hylerrix'
var user = { name: 'hylerrix' }

// Console 对象的方法有：
// log、info、warn、error、dir、time、timeEnd、trace、assert
// info 和 watn 方法是 log 和 error 的同义词，区别是输出流不同
console.dir(console)

console.log('Hello')
// 消息内容的格式化是通过 util.format 实现的，支持 %s、%d、%j
console.log('Hello %s', name)
console.log('Hello:', name)
// user 对象将被 util.inspect 格式化
console.log('Hello:', user)

console.error('Error, bad user:', user)

console.timeEnd('label')