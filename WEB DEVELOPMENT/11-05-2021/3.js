function f_p() {
    var a = document.getElementById("main").value;
    var b = document.getElementById("sub").value;
    // var a = prompt("Enter the number");
    //var b = prompt("Enter the digit");
    var c, d;
    d = 1;
    console.log(a);
    while (a != 0) {
        c = a % 10;
        a = parseInt(a / 10);
        if (b == c) {
            c * d;
            break;
        } else {
            d = d * 10;
        }
    }
    c = c * d;
    console.log("The face value of " + b + " is " + b + " and place value is " + c);
}