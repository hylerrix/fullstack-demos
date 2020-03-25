// 工作线程代码中，onmessage 事件在其全局作用域可以访问
// 工作线程代码中，postMessage 方法在其全局作用域可以访问
onmessage = function(message) {
    var data = message.data
    data.msg = 'Hi from task.js'
    postMessage(data)
}