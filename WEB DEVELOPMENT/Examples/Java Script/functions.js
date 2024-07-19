// function greet(user) {
//   return `Hello ${user}`;
// }
// let uname = "Hem";
// let str = greet(uname);
// console.log(str);

//--------------------------------------------------------//

// let add = function (x, y) {
//   return x + y;
// };
// let sum = add;
// let result = sum(10, 34);
// console.log(result);

//-------------------------------------------------------//

//let x = 5;
//{
//  let y = 4; //If we declare using 'var' it can be accessed globally
//  console.log("X = " + x + " Y = " + y);
//}
//console.log("X = " + x + " Y = " + y);

//------------------------------------------------------//

let greet = () => {
  console.log("Hello");
  return 23;
};
console.log(greet() + "\n");

//-----------------------------------------------------//

let add = (x, y) => x + y;

let sum = add(5, 87);

console.log(sum);
