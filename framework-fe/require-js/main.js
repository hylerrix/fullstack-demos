requirejs.config({
  // baseUrl 相对 Web 应用程序根目录
  baseUrl: "app/example",
  // 路径相对于 baseUrl
  paths: {
    counter: "modules/counter",
    util: "modules/displayUtil"
  }
})

require(
  // 使用模块名称将资源声明为依赖
  ["util"],
  // 回调函数参数接受对应依赖导出的对象
  function (utilModule) {
    console.log(utilModule)
    // 第一次增加计数器
    utilModule.displayNewCount()
    // 第二次增加计数器
    utilModule.displayNewCount()
  }
)