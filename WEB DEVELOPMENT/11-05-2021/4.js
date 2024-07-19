function gen_id() {
    var _fname = document.getElementById("fname").value;
    var _lname = document.getElementById("lname").value;
    var len;
    var _fname1;
    var _lname1;
    len = _lname.length;
    _fname1 = _fname.substr(0, 3);
    len = len - 3;
    _lname1 = _lname.substr(len, 3);
    console.log("Your Mail ID is " + _fname1 + "." + _lname1 + "@mymail.com");
}