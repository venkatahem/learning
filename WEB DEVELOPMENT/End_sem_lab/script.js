function roll_check() {
  let i;
  let x = 0;
  let pins = [];
  let pin = 1000;
  let ele = parseInt(document.getElementById("roll").value);

  for (i = 0; i < 100; i++) {
    pins[i] = pin++;
  }

  for (i = 0; i < 2000; i++) {
    if (pins[i] == ele) {
      x = 1;
      break;
    }
  }
  if (x === 1) {
    window.alert("Valid User");
  } else {
    window.alert("Invalid User");
  }
}
