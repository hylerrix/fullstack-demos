# Node.js 硬实战: 115 个核心技巧

1. 安装与加载模块

npm search、npm install、npmsearch

2. 创建与管理模块

exports、module.exports 对象
导出模块、导出多个对象、使用 require 加载模块、缓存模块、卸载模块
node 寻找模块路径的顺序、node 自动添加模块名后缀的问题

3. 加载一组相关的模块

4. 使用路径

```__dirname、__filename、path.join()```

5. 标准 I/O 流的读写

process 对象来读写 I/O

6. 打印日志消息

console.log、console.info、console.error、console.warn
消息内容的格式化通过 util.format 实现，可使用格式占位符 %s String、%d Number、%j JSON
Node 通过 process.stderr 暴露了错误流，console.error 方法将写入这个流而不是 process.stdout

7. 基准测试

console.time()、console.timeEnd() 方法基于 Date.now()，精确到毫秒，获取更精确的基准，可以使用第三方模块 benchmark，并结合 microtime 模块

8. 获取平台信息

process 来获取操作系统信息，并通过退出码、信号量与其他进程通信

9. 传递命令行参数

10. 退出程序

process.exit() 返回退出码

11. 响应信号量

使用发给 process 对象的信号事件

12. 通过 setTimeout 延迟执行函数

全局延迟执行一段代码

13. 通过定时器定时调用回调函数

setInterval

14. 安全的操作异步接口

使用 process.nextTick 把一个回调放在下一次事件轮询队列的头上, 可以用来延迟执行

15. Buffer 转换为其它格式

16. 使用 Buffers 来修改字符串编码

17. 使用 Buffer 来转换原始数据

18. 创建自己的网络协议

19. 从 EventEmitter 集成

20. 混合 EventEmitter

21. 管理异常

22. 通过 domains 管理异常

23. 反射

24. 探索 EventEmitter

25. 组织事件名称

26. EventEmitter 的替代方案