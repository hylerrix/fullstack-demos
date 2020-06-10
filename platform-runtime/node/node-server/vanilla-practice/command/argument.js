// Usage:
// node argument.js -r argument.js

// 用来表示可用的参数
var args = {
  '-h': displayHelp,
  '-r': readFile
}

function displayHelp () {
  console.log('Argument processor:', args)
}

function readFile (file) {
  if (file && file.length) {
    console.log('Reading:', file)
    // 使用管道把文件发送到标准输出入流
    require('fs').createReadStream(file).pipe(process.stdout)
  } else {
    // console.error 和 process.exit 都是用来正确地指示发生了错误的情况
    console.error('A file must be provided with the -r option')
    process.exit(1)
  }
}

if (process.argv.length > 0) {
  process.argv.forEach(function (arg, index) {
    // 调用从参数模型中匹配到的方法，并通过对完整的参数列表进行分割来有效支持自命令行标记的选项传递
    console.log(arg)
    args[arg].apply(this, process.argv.slice(index + 1))
  })
}