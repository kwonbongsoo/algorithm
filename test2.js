// you can write to stdout for debugging purposes, e.g.
// console.log('this is a debug message');

// function solution(A) {
//   var tmp = 0
//   var cnt = 0
//   var arr = []
//     for(var i = 0; i < A.length; i++) {
//       tmp = A[i]
//       for(var j = 0; j < A.length; j++) {
//         if(tmp == A[j] && i != j) {
//           arr.push(A[i])
//         }
//       }
//     }
//     for(var i = 0; i < A.length; i++) {
//       for(var j = 0; j < arr.length; j++) {
//         if(A[i] == arr[j]) {
//           A[i] = 0
//           arr[j] = 0
//         }
//       }
//     }
//
//     for(var i = 0; i < A.length; i++) {
//       if(A[i] != 0)
//         return A[i]
//     }
// }

function solution(A) {
  var arr = []
  arr = A.slice().sort()
  var length = arr.length
  for(var i= arr.length -1; i > -1; i--) {
      if(arr[i] == arr[i-1])
        arr.splice(i-1, 2)
  }
  return arr[0]
}
solution([2, 2, 3, 3, 4])
solution([9, 9, 9, 9, 9])
