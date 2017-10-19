function solution(A, K) {
  var tmp = 0
    for(var i=0; i < A.length; i++) {
     if(i+K >= A.length) {
       console.log(i)
         console.log(((i+K)%(A.length)))
     }else {
       A[i+K] =tmp
       A[i+K] =A[i]
       A[i] = tmp
     }
    }
    console.log(A)
}
solution([0,1,2,3], 3)
