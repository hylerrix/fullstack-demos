var args = {
    '-h': displayHelp,
    '-r': readFile
}

function displayHelp () {
    console.log('Argument processor', args)
}

function readFile (file) {
    // if (file && file.length) {
    //     console.log('Reading:', file)
    //     console.time('read')
    //     var stream = require('fs').createReadStream(file)
    //     stream.on('end', function () {
    //         console.timeEnd('read')
    //     })
    //     stream.pipe(process.stdout)
    // } else {
    //     console.error('A file must be provided with the -r option')
    //     process.exit(1)
    // }
    console.log('Reading:', file)
    // 使用管道把文件发送到标准输出流
    require('fs').createReadStream(file).pipe(process.stdout)
}

if (process.argv.length > 0) {
    // node benchmark.js -r aaa 时
    // process.argv: [ 
    //   '/usr/local/bin/node',
    //   '/Users/hylerrix/WorkSpace/Github/node-server/node-in-practice/chap-02/benchmark.js',
    //   '-r',
    //   'aaa'
    // ]
    console.log(process.argv)
    process.argv.forEach(function (arg, index) {
        args[arg].apply(this, process.argv.slice(index + 1))
    })
}