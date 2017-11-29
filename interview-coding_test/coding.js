"use strict"

var arr = [
            [0,0,1,0,1,1],
            [1,1,1,1,1,1],
            [1,1,1,1,1,1],
            [1,1,1,1,1,1],
            [1,1,1,1,1,1],
            [1,1,1,1,1,0]
          ];
var max = 0;
var before = 0;
var tmp = [];
var big = 0;
for(var i=0; i < arr.length; i++) {
  before = 0;
  max = 0;
  for(var j=0; j < arr[i].length; j++) {
    if(arr[i][j] == 1) {
      if(before == 0) {
        max = 1;
      }else {
        max += 1;
        tmp.push([i,j-1]);
        if(arr[i].length -1 == j) {
          tmp.push([i,j]);
        }
      }
    }else {
      max = 0;
    }
    before = arr[i][j];
  }
}
// 포문 i를 돌면서 1이 연속했을 때만 그 인덱스값을 새로운 배열 tmp에 저장

for(var i=0; i < tmp.length; i++) {
    find( tmp[i][0],tmp[i][1]);
}
// tmp에 있는 1이 연속한 인덱스 값을 바탕으로 정말로 정사각형이 되는지 조건을 확인
// find라는 함수를 이용해서 찾음
  console.log(tmp)
  console.log("정사각형의 넓이는 "+big*=big)

function find(i, j) {
  var length = 1;
  var num;
    for(num = 1; j+num < arr[0].length && i+num < arr.length; num++) {
        if(arr[i+num][j+num] == 1) {
          if(arr[i][j+num] == 1 && arr[i+num][j] == 1) {
            length += 1;
            //정사각형의 조건이 맞았을 때 변수의 길이가 length다.
            // 이 조건에 들어온다면 정사각형의 조건을 만족한다는 의미다.
          }
        }else
         break;

      if (big < length)
        big = length;
        //정사각형의 변수의 길이를 비교해서 big이라는
        //변수에 담아 제곱하면 변수의 넓이가 된다
        //정사각이 클때만 갱신함
    }
}
