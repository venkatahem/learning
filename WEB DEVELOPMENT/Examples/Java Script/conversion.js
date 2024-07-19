console.clear()
let num
let str

num = String(6)
console.log(num, typeof(num))

num = '123'
console.log(num, typeof(num))

num = Number('123')
console.log(num, typeof(num))

str = "Hello"

//COERCION
num = num + str
console.log(num, typeof(num))

num = 6

num = num + ""
console.log(num, typeof(num))

num = num + 5
console.log(num, typeof(num))

num = +num + 4
console.log(num, typeof(num))

num = !num
console.log(num, typeof(num))

num = num - 3
console.log(num, typeof(num))