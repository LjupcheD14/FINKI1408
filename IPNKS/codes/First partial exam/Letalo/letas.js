function najava() {
    var ime = document.getElementById("ns")
    var oznaka = document.getElementById("oznaka")
    var koordinati = document.getElementById("koordinati")
    var radius = document.getElementById("radius")
    var visina = document.getElementById("visina")
    var tip = document.getElementById("tip")

    if (ime.value == "" || oznaka.value == "" || koordinati.value == "" || radius.value == "" || visina.value == "" || tip.value == "") {
        alert("Внесете ги сите податоци")
        return;
    }

    var parsedRadius = parseInt(radius.value)
    var parsedHeight = parseInt(visina.value)

    if (istiBrojki(oznaka.value)) {
        var lista = document.getElementById("dodavaj")
        var liItem = document.createElement("li")
        if (tip.value === "Eдрилица") {
            liItem.style.border = "2px solid black"
        } else if (tip.value === "Дрон") {
            if (parsedRadius === parsedHeight) {
                liItem.style.border = "2px solid black"
            }
        }
        liItem.innerHTML = "<p>" + ime.value + "</p>" +
            "<p>" + oznaka.value + "</p>" +
            "<p>" + koordinati.value + "</p>" +
            "<p>" + radius.value + "</p>" +
            "<p>" + visina.value + "</p>" +
            "<p>" + tip.value + "</p>" +
            "<button onclick='potvrda(this)'>Потврди</button><button onclick='otkaz(this)'>Откажи</button>"
        global++;
        lista.append(liItem);
    } else {
        if (parsedRadius <= 500 && parsedHeight <= 150) {
            var lista = document.getElementById("dodavaj")
            var li = document.createElement("li")
            if (tip.value === "Едрилица") {
                li.style.border = "2px solid black"
            } else if (tip.value == "Дрон") {
                if (parsedRadius === parsedHeight) {
                    li.style.border = "2px solid black"
                }
            }
            li.innerHTML = "<p>" + ime.value + "</p>" +
                "<p>" + oznaka.value + "</p>" +
                "<p>" + koordinati.value + "</p>" +
                "<p>" + radius.value + "</p>" +
                "<p>" + visina.value + "</p>" +
                "<p>" + tip.value + "</p>" +
                "<button onclick='potvrda(this)'>Потврди</button><button onclick='otkaz(this)'>Откажи</button>"
            global++
            lista.append(li)

        } else {
            alert("Не може да се регистрира лет поради висината или радиусот")
            return;
        }
    }

    var element = document.getElementById("prijaveni")
    element.innerHTML = global
    ime.value = ""
    oznaka.value = ""
    koordinati.value = ""
    radius.value = ""
    visina.value = ""
    tip.value = ""
}


function checkTag(tag) {
    var o = tag.split("-")
    var brojka = parseInt(o[2])
    if (isNaN(brojka)) {
        return true
    }
    if (tag.length != 11 || o[0] != "Z3" || o[1] != "UNR" || !(brojka >= 1000 || brojka <= 9999)) {
        return true;
    } else {
        return false;
    }
}

function istiBrojki(oznaka) {
    var deli = oznaka.split("-")
    var cifri = deli[2]
    if (cifri[0] === cifri[1] === cifri[2] === cifri[3]) {
        return true;
    } else {
        return false;
    }
}

function otkaz(btn) {
    var parent = btn.parentNode
    parent.remove()
}

function potvrda(btn) {
    var parent = btn.parentNode
    parent.style.backgroundColor = "lightgreen"
}



