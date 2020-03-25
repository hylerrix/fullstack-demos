define(["counter"], function (counterModule) {
  function printCount () {
    var count = counterModule.getCount()
    if (count === 1) {
      count = count + " time"
    } else {
      count = count + " times"
    }
    console.log("Count incremented: " + count)
  }

  function displayNewCount () {
    counterModule.incrementCount()
    this.printCount()
  }

  return {
    printCount: printCount,
    displayNewCount: displayNewCount
  }
})