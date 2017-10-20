
/*

A zero-indexed array A consisting of N different integers is given. The array contains integers in the range [1..(N + 1)], which means that exactly one element is missing.



Your goal is to find that missing element.



Write a function:



function solution(A);
that, given a zero-indexed array A, returns the value of the missing element.
For example, given array A such that:
  A[0] = 2
  A[1] = 3
  A[2] = 1
  A[3] = 5
the function should return 4, as it is the missing element.
Assume that:
N is an integer within the range [0..100,000];
the elements of A are all distinct;
each element of array A is an integer within the range [1..(N + 1)].
Complexity:
expected worst-case time complexity is O(N);
expected worst-case space complexity is O(1), beyond input storage (not counting the storage required for input arguments).
Elements of input arrays can be modified.
*/
//
// function solution(A) {
//     A = A.sort()
//     var n = A[0]
//     for(var i=1; i < A.length; i++) {
//       if(n+1 != A[i])
//         return A[i]-1
//       else
//         n = A[i]
//     }
// }
// solution([2,3,1,5,4,6,8])


function solution(A) {
    var tmp = 0
    var sum = 0
    var max = A.length+1

    if(max % 2 == 0)
        tmp = (max+1) * (max/2)
    else
        tmp = max*((max-1)/2) + max


    for(var i=0; i < A.length; i++)
        sum += A[i]
    return tmp - sum
}
solution([2,3,1,5,4,6,8])
