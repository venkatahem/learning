function divide() {
  var amount = document.getElementById("amount").value;
  var notes = [2000, 500, 200, 100, 50, 20, 10, 5, 2, 1];
  var note_count = [];
  var i;
  // amount = 685684;
  for (i = 0; i < 10; i++) {
    if (amount >= notes[i]) {
      note_count[i] = parseInt(amount / notes[i]);
      amount = amount - notes[i] * note_count[i];
    }
  }
  console.log("Minimun number of currency notes:\n");
  for (i = 0; i < 10; i++) {
    if (note_count[i] != undefined) {
      console.log(notes[i] + " : " + note_count[i]);
    }
  }
}
