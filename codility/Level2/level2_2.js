function solution(A, K) {
  var tmp = []
    for(var i=0; i < A.length; i++) {
     if(i+K >= A.length)
       tmp[(i+K)%(A.length)] = A[i]
     else
       tmp[i+K] =A[i]
    }
    return tmp
}
solution([0,1,2,3], 3)
