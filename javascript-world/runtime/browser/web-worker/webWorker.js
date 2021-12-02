// 实例化 Worker 对象，其实质为新创建的工作线程在主线程的引用
var worker = new Worker("task.js")
// postMessage 方法与新创建的工作线程通信
worker.postMessage({
        id:1,
        msg:'Hello World'
});
// 当 Worker 线程返回数据时，onmessage 回调函数执行
worker.onmessage = function(message) {
    var data = message.data;
    console.log(JSON.stringify(data))
    // terminate 方法终止 worker 线程的运行
	worker.terminate()
};
// 当 Worker 线程出错时，onerror 回调函数执行
// error 参数中封装了错误对象的文件名、出错行号和具体错误信息
worker.onerror = function(error) {
    console.log(error.filename, error.lineno, error.message)
}