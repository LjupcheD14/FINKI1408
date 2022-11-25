function importStudent() {
    let ime = document.getElementById("name")
    let indeks = document.getElementById("index")
    let telefon = document.getElementById("phone")
    let sesija = document.getElementById("month")

    let ocenka5 = document.getElementById("five")
    let ocenka6 = document.getElementById("six")
    let ocenka7 = document.getElementById("seven")
    let ocenka8 = document.getElementById("eight")
    let ocenka9 = document.getElementById("nine")
    let ocenka10 = document.getElementById("ten")

    if (ime.value == "" || indeks.value == "" || telefon.value == "" || (ocenka5.checked == false && ocenka6.checked == false && ocenka7.checked == false && ocenka8.checked == false && ocenka9.checked == false && ocenka10.checked == false)) {
        alert("All fields are required!")
        return;
    }

    let firstSub = telefon.value.toString().substring(0, 3)
    let secondSub = telefon.value.toString().substring(3, 6)
    let thirdSub = telefon.value.toString().substring(6, 9)

    let formatTel = firstSub + "/" + secondSub + "-" + thirdSub


    console.log(firstSub)
    console.log(" ")
    console.log(secondSub)
    console.log(" ")
    console.log(thirdSub)
    console.log(formatTel)

    let sumaOceni = 0
    let counter = 0

    let ocenka = ""

    if (ocenka5.checked == true) {
        ocenka = "5"
    }
    if (ocenka6.checked == true) {
        ocenka = "6"
    }
    if (ocenka7.checked == true) {
        ocenka = "7"
    }
    if (ocenka8.checked == true) {
        ocenka = "8"
    }
    if (ocenka9.checked == true) {
        ocenka = "9"
    }
    if (ocenka10.checked == true) {
        ocenka = "10"
    }

    //
    // let result = document.getElementById("here")
    //
    // result.innerHTML += "<td>"+ime.value+"</td>"+
    //     "<td>"+indeks.value+"</td>"+
    //     "<td>"+formatTel+"</td>"+
    //     "<td>"+ocenka+"</td>"+
    //     "<td>"+sesija.value+"</td>"+
    //     "<td><button class='still' onclick='potvrda(this)'>Confrim</button><button class='still' onclick='svrti(this)'>Revert</button></td>"


    let tabela = document.getElementById("here")
    let redica = document.createElement("tr")

    let prosek = document.getElementById("average")

    redica.innerHTML = "<td>" + ime.value + "</td>" +
        "<td>" + indeks.value + "</td>" +
        "<td>" + formatTel + "</td>" +
        "<td>" + ocenka + "</td>" +
        "<td>" + sesija.value + "</td>" +
        "<td><button class='still' onclick='potvrda(this)'>Confrim</button><button class='still' onclick='svrti(this)'>Revert</button></td>"

    tabela.append(redica)


    let r1 = redica.children[3].innerHTML
    let parsedR1 = parseInt(r1)
    counter++
    sumaOceni += parsedR1
    let prosekTmp = sumaOceni / counter
    let prosekKraj = prosekTmp.toFixed(1)

    prosek.innerHTML = prosekKraj

}

function potvrda(btn) {
    let parent = btn.parentNode.parentNode
    parent.style.backgroundColor = "lightgreen"
    btn.disabled = true
    btn.nextElementSibling.disabled = true
}

function svrti(btn) {
    let parent = btn.parentNode.parentNode
    let lista = document.getElementById("history")
    let listItem = document.createElement("li")
    let indeks = parent.children[1].innerHTML
    let ocena = parent.children[3].innerHTML

    listItem.innerHTML = indeks + " " + "-" + " " + "grade" + " " + ocena
    lista.append(listItem)

    let r1 = parent.children[3].innerHTML
    let parsed = parseInt(r1)
    counter--
    sumaOceni -= parsed

    let final = sumaOceni / counter
    let finalOne = final.toFixed(1)
    let element01 = document.getElementById("average")
    element01.innerHTML = finalOne
    parent.remove()

}

