// 对 POSIX 信号添加一个监听器
// 从标准输入流中读取，这样程序会一直执行，直到按下 CTRL-C 或者进程被杀死
// 在对标准输入进行任何操作之前，应该调用 resume 来防止 Node 直接退出
process.stdin.resume()
// 对 SIGHUP 信号绑定一个监听器
process.on('SIGHUP', function () {
  console.log('Reloading configuration...')
})

// 显示 PID，你可以用它来终止进程
console.log('PID:', process.pid)