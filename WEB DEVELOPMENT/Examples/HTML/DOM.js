//Examine the document object

// console.dir(document);

console.log(document);
// console.log(document.domain);
// console.log(document.URL);
// console.log(document.title);
//document.title = "Hello";
// console.log(document.doctype);
// console.log(document.head);
// console.log(document.body);
// console.log(document.all);
// document.all[6].textContent = "Hello";
// console.log(document.forms);
// console.log(document.links);

//----------------------------------------------------------//

// Get Element by ID //

// var headerTitle = document.getElementById("header-title");
// console.log(headerTitle);
//headerTitle.textContent = "Hi";
//headerTitle.innerHTML = "Hello";
//console.log(headerTitle.textContent); //(.textContent displays the hidden values also)
//console.log(headerTitle.innerText); //(innerText won't show that hidden item)

//----------------------------------------------------------//

// CSS //

// headerTitle.style.color = "black";
// headerTitle.style.borderBottom = "dashed 2px red";

//----------------------------------------------------------//

// Get Elements By Class Name //

let classItems = document.getElementsByClassName("list-group-item");
// console.log(classItems);
// classItems[2].style.color = "red";
// classItems[1].style.background = "yellow";

//----------------------------------------------------------//

// Get Element By Tag Name //

// let li = document.getElementsByTagName("li");
// console.log(li);
// li[2].style.color = "red";
// li[1].style.background = "yellow";

//----------------------------------------------------------//

// QuerySelector //

// The input can be anything like class,tag,id etc //

// let selc = document.querySelector("#main-header");
// selc.style.borderBottom = "dashed 3px black";

// let input = document.querySelector("input");
// input.value = "Hello";

// Even two inputs are there(text area and submit button) querySelector selects the first one in the page //

// let submit = document.querySelector('input[type = "submit"]');
// submit.value = "Click Me";

// let item = document.querySelector(".list-group-item");
// item.style.background = "red";

// let lastItem = document.querySelector(".list-group-item:last-child"); //selects last item in ul
// lastItem.style.color = "maroon";

// let thirdItem = document.querySelector(".list-group-item:nth-child(3)");
// thirdItem.style.color = "brown";

//---------------------------------------------------------//

// Query Selector all //

let titles = document.querySelectorAll(".title");
// console.log(titles);

// titles[1].textContent = "Bye";

// let odds = document.querySelectorAll("li:nth-child(odd)");
// Similarly for even //
// for (let i = 0; i < odds.length; i++) {
// odds[i].style.background = "lime";
// }

//----------------------------------------------------------//

// Traversing the DOM //

let itemList = document.querySelector("#items");

// Parent Node //

// console.log(itemList.parentNode);
// itemList.parentNode.style.background = "lime";
//console.log(itemList.parentNode.parentNode);

// Parent Element //

// console.log(itemList.parentElement);
// itemList.parentElement.style.background = "lime";

// Child Nodes //

// console.log(itemList.childNodes);

// It also shows the line breakes, any other text and it is suggested to use 'children' instead of 'child nodes' //

//console.log(itemList.children);

// Returns an array of available child nodes//

//itemList.children[2].style.color = "aqua";

// First child //

//console.log(itemList.firstChild);

//  This also works same as 'childNodes' and shows the line breakes, any other text //

// First Element Child //

//console.log(itemList.firstElementChild);
// itemList.firstElementChild.style.background = "aqua";

// Last child //

//console.log(itemList.firstChild);

//  This also works same as 'firstChild' and shows the line breakes, any other text //

// Last Element Child //

// console.log(itemList.lastElementChild);
// itemList.lastElementChild.style.background = "aqua";

// Next Sibling //

// console.log(itemList.nextSibling);

// Same as childNode, firsrChild and lastChild //

// Next Element Sibling //

// console.log(itemList.nextElementSibling);

// Previous Sibling //

// console.log(itemList.previousSibling);

// Same as childNode, firsrChild and lastChild //

// Previous Element Sibling //

// console.log(itemList.previousElementSibling);
// itemList.previousElementSibling.textContent = "ITEM";
// itemList.previousElementSibling.style.background = "yellow";

//----------------------------------------------------------//

// Creating a div //

// let newDiv = document.createElement("div");

// Add Class //
// newDiv.className = "divs";

// Add ID //
// newDiv.id = "div1";

// Adding a attribute //
// newDiv.setAttribute("title", "newdiv");

// Creating a text node //
// let newDivText = document.createTextNode(
// 'This is the div element created from "JS"'
// );

// Adding text to div//
// newDiv.appendChild(newDivText);

// Inserting it into a page //
// let container = document.querySelector("header .container");
// let h1 = document.querySelector("header h1");

// container.insertBefore(newDiv, h1);

// console.log(newDiv);

//----------------------------------------------------------//

// Events //

let button = document
  .getElementById("button")
  .addEventListener("click", buttonClick);

function buttonClick(e) {
  // console.log("123-Clicked");
  // document.querySelector("#header-title").textContent = "You Clicked It";
  // document.querySelector("#main").style.background = "yellow";
  // console.log(e);
  // let final = e.target;
  // console.log(final);
  // let id = e.target.id;
  // console.log(id);
  // let classes = e.target.classList;
  // console.log(classes);
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
  // console.log(e.type);
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
  // console.log("X-axis: " + e.clientX);
  // console.log("Y-axis: " + e.clientY);
  //clientX and clientY gives the position of the mouse pointer relative to the browser window//
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
  // console.log("X-axis: " + e.offsetX);
  // console.log("Y-axis: " + e.offsetY);
  //offsetX and offsetY gives the position of the mouse pointer relative to the actual element//
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
  // console.log(e.altKey);
  // console.log(e.ctrlKey);
  console.log(e.shiftKey);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

// let button = document.querySelector("#button");
// let box = document.querySelector("#box");

// button.addEventListener("click", runEvent);
// button.addEventListener("dblclick", runEvent);
// button.addEventListener("mousedown", runEvent);
//button.addEventListener("mouseup", runEvent);

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

// box.addEventListener("mouseenter", runEvent);
// box.addEventListener("mouseleave", runEvent);

// 'mouseenter' and 'mouseleave' will only apply on the parent element while 'mouseover' and 'mouseout' will also apply to the child elements in it //

//box.addEventListener("mouseover", runEvent);
//box.addEventListener("mouseout", runEvent);

// box.addEventListener("mousemove", runEvent);

let itemInput = document.querySelector('input[type="text"]');

// itemInput.addEventListener("keydown", runEvent);
// itemInput.addEventListener("keyup", runEvent);
// itemInput.addEventListener("keypress", runEvent);

// itemInput.addEventListener("focus", runEvent);
// itemInput.addEventListener("blur", runEvent);

// itemInput.addEventListener("cut", runEvent);
// itemInput.addEventListener("paste", runEvent);

// itemInput.addEventListener("input", runEvent);

let select = document.querySelector("select");

// select.addEventListener("change", runEvent);
// select.addEventListener("input", runEvent);

let form = document.querySelector("form");

form.addEventListener("submit", runEvent);

function runEvent(e) {
  e.preventDefault();
  console.log("Event type: " + e.type);

  // console.log(e.target.value);
  // document.getElementById("output").innerHTML =
  //   "<h3>" + e.target.value + "</h3>";

  // output.innerHTML =
  //   "<h3>MouseX: " + e.offsetX + " </h3> <h3>MouseY: " + e.offsetY + "</h3>";

  // box.style.background = "rgb(" + e.offsetX + ",30," + e.offsetY + ")";
}
