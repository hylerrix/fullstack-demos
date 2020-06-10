// dirname: 当前文件上的文件夹的绝对路径
console.log('__dirname: ', __dirname)
// filename: 当前文件的绝对路径
console.log('__filename: ', __filename)
// 虽然 Windows API 能将斜杠转换为它的标准格式，但 path.join 能确保跨平台的兼容性
console.log('path.join(__dirname, "views/", "view.html"): ', require('path').join(__dirname, 'views/', 'view.html'))