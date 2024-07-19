let call = 0;
function add() {
  call++;
  if (call === 1) {
    let ele1 = document.getElementById("item2");
    let ele2 = document.getElementById("quan2");
    let ele3 = document.getElementById("li2");
    let ele4 = document.getElementById("lq2");
    let ele5 = document.getElementById("i2br1");
    let ele6 = document.getElementById("i2br2");
    ele1.style.display = "inline-block";
    ele2.style.display = "inline-block";
    ele3.style.display = "inline-block";
    ele4.style.display = "inline-block";
    ele5.style.display = "block";
    ele6.style.display = "block";
  } else if (call === 2) {
    let ele1 = document.getElementById("item3");
    let ele2 = document.getElementById("quan3");
    let ele3 = document.getElementById("li3");
    let ele4 = document.getElementById("lq3");
    let ele5 = document.getElementsByClassName("it3");
    ele1.style.display = "inline-block";
    ele2.style.display = "inline-block";
    ele3.style.display = "inline-block";
    ele4.style.display = "inline-block";
    ele5[0].style.display = "block";
    ele5[1].style.display = "block";
  } else if (call === 3) {
    let ele1 = document.getElementById("item4");
    let ele2 = document.getElementById("quan4");
    let ele3 = document.getElementById("li4");
    let ele4 = document.getElementById("lq4");
    let ele5 = document.getElementsByClassName("it4");
    ele1.style.display = "inline-block";
    ele2.style.display = "inline-block";
    ele3.style.display = "inline-block";
    ele4.style.display = "inline-block";
    ele5[0].style.display = "inline-block";
    ele5[1].style.display = "inline-block";
  } else if (call === 4) {
    let ele1 = document.getElementById("item5");
    let ele2 = document.getElementById("quan5");
    let ele3 = document.getElementById("li5");
    let ele4 = document.getElementById("lq5");
    let ele5 = document.getElementById("msg");
    let ele6 = document.getElementById("btn");
    ele1.style.display = "inline-block";
    ele2.style.display = "inline-block";
    ele3.style.display = "inline-block";
    ele4.style.display = "inline-block";
    ele6.style.display = "none";
    ele5.innerHTML =
      "<p><font color = red>(<sup>**</sup>You can add a max of 5 items per user<sup>**</sup>)</font></p>";
  }
}
//loader
function loader_hide() {
  let element = document.getElementById("loader");
  element.style.display = "none";
}
function loader() {
  window.setTimeout(loader_hide, 2500);
}
//display
function display() {
  let name = document.getElementById("uname").value;
  let email = document.getElementById("uemail").value;
  let mobile = document.getElementById("phno").value;
  let items = [];
  let quantity = [];
  items[0] = document.getElementById("item1").value;
  items[1] = document.getElementById("item2").value;
  items[2] = document.getElementById("item3").value;
  items[3] = document.getElementById("item4").value;
  items[4] = document.getElementById("item5").value;
  quantity[0] = document.getElementById("quan1").value;
  quantity[1] = document.getElementById("quan2").value;
  quantity[2] = document.getElementById("quan3").value;
  quantity[3] = document.getElementById("quan4").value;
  quantity[4] = document.getElementById("quan5").value;
  document.write(
    "Thank you for the donation" +
      "<br><br>" +
      "Name: " +
      name +
      "<br><br>" +
      "Email: " +
      email +
      "<br><br>" +
      "Mobile no: " +
      mobile +
      "<br><br>" +
      "Item: " +
      items[0] +
      "\t" +
      "---Quantity: " +
      quantity[0] +
      "<br><br>" +
      "Item: " +
      items[1] +
      "\t" +
      "---Quantity: " +
      quantity[1] +
      "<br><br>" +
      "Item: " +
      items[2] +
      "\t" +
      "---Quantity: " +
      quantity[2] +
      "<br><br>" +
      "Item: " +
      items[3] +
      "\t" +
      "---Quantity: " +
      quantity[3] +
      "<br><br>" +
      "Item: " +
      items[4] +
      "\t" +
      "---Quantity: " +
      quantity[4] +
      "<br><br>"
  );
}
