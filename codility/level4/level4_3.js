function solution(A) {
    var b = []
    b = A.sort()
    var tmp = b[0]
    var result = -1
    var m
    for (var i=1; i < b.length; i++) {
        if(b[i] > 0) {
          if(tmp == b[i]-1 || tmp == b[i])
              tmp = b[i]
          else {
              result = b[i]
              m = b[i]-tmp-1
              return result - m
          }
        }
    }
    if(result == -1) {
     if(tmp < 0) {
      return 1
     }
     tmp += 1
     return tmp
    }
}
solution([1,2,4,5,6,9])
solution([1,2,3])
solution([-1, -3])
