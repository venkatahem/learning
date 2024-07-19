function s_l() {
    var num = document.getElementById("num").value;
    var arr = [];
    var len = num.length;
    var rem, x, i, k, j, lar, sml;
    x = num;
    for (i = 0; i < len; i++) {
        rem = x % 10;
        x = parseInt(x / 10);
        arr[i] = rem;
    }
    console.log("Entered digits\n");
    for (i = 0; i < len; i++) {
        console.log(arr[i]);
    }
    for (j = 0; j < len - 1; j++) {
        for (k = j + 1; k < len; k++) {
            if (arr[j] > arr[k]) {
                x = arr[j];
                arr[j] = arr[k];
                arr[k] = x;
            }
        }
    }
    lar = 0;
    sml = 0;
    for (i = 0; i < len; i++) {
        x = arr[i];
        sml = sml * 10 + x;
    }
    x = sml;
    while (x != 0) {
        rem = x % 10;
        x = parseInt(x / 10);
        lar = lar * 10 + rem;
    }
    console.log("The smallest number is " + sml);
    console.log("The larget number is " + lar);
}