function solution(A) {
  var re = A.replace(/[^0-9]/g, '')
  var len = re.toString().length
  var addr = ''


  for (var i = 0; i < len; i++) {
    if (re.slice(i, len).length < 3) {
      addr += re.slice(i, i + 3)
      i += 2
    } else if (re.slice(i, len).length == 4) {
      addr += re.slice(i, i + 2) + '-' + re.slice(i + 2, i + 4)
      i = len
    } else if (re.slice(i, len).length > 3) {
      addr += re.slice(i, i + 3) + '-'
      i += 2
    }
  }
  console.log(addr)
}
solution("022-198-532-4")
solution("555372654")
