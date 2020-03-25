function tick () {
  console.log('tick:', Date.now())
}

function tock () {
  console.log('tock:', Date.now())
}

setInterval(tick, 1000)

// 在第一个之后运行另外一个 setInterval
setTimeout(function () {
  setInterval(tock, 1000)
}, 500)