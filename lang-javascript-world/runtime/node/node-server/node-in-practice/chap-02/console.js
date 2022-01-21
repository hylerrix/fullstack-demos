console.time('label')

console.log(console)

console.log('hylerrix')
console.info('hylerrix')
// 当使用 node console.js 2> error.log 的时候， warn 和 error 会被重定向到 error.log
// 总共有三个标准流, 0 stdin 输入流、1 stdout 输出流、2 stderr 错误流
console.warn('hylerrix')
console.error('hylerrix')

console.timeEnd('label')