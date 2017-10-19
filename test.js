function solution(N) {

    var result = N.toString(2)
    console.log(result)
    var arr = new Array()
    var max = 0
    var tmp = 0

    for(var i = 0; i < result.length; i++) {
      if(parseInt(result[i].indexOf(1)) == -1)
        arr.push(0)
      else
        arr.push(1)
    }
    for(var i = 0; i < arr.length; i++) {
      if(arr[i] == 0)
        tmp++
      else if(arr[i] == 1) {
        if(max < tmp)
          max = tmp
        tmp = 0
      }
    }
    console.log(max)
}

solution(21112);
