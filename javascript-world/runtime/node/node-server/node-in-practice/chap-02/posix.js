// 从标准输入流中读取，这样程序会一直执行，直到按下 CTRL-C 或者进程被杀死
process.stdin.resume()
// 对 SIGHUP 信号绑定一个监听器
process.on('SIGHUP', function () {
    console.log('Reloading configuration...')
})
// 显示 PID，你可以用它来终止进程
// 终端输入 kill -HUP PID 可以给该进程 SIGHUP 信号
console.log('PID:', process.pid)