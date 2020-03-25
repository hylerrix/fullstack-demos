define(function () {
  var count = 0;
  
  function incrementCount () {
    ++count
  }

  function getCount () {
    return count
  }

  return {
    incrementCount: incrementCount,
    getCount: getCount
  }
})