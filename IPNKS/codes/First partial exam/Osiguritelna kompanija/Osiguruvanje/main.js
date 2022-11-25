function generiraj() {
    var ime = document.getElementById("name")
    var prezime = document.getElementById("sname")
    var regTabla = document.getElementById("reg")
    var godini = document.getElementById("god")
    var yes = document.getElementById("da")
    var no = document.getElementById("ne")


    if (ime.value == "" || prezime.value == "" || regTabla.value == "" || godini.value == "" ||
        (yes.checked == false && no.checked == false)) {
        alert("Внесете ги сите податоци!")
        return;
    }

    if (isNaN(godini.value)) {
        alert("Внеси број за годините!")
        return;
    }

    let str = regTabla.value.toString();
    let firstsub = regTabla.value.toString().substring(0, 2);
    let secondsub = regTabla.value.toString().substring(2, 6);
    let thirdsub = regTabla.value.toString().substring(6, 8);

    const regex = /^[A-Za-z\s]*$/;
    const regexNum = /^\d+$/;

    if (regex.test(firstsub) && regex.test(thirdsub) && regexNum.test(secondsub)) {
        console.log("OK")
    } else {
        alert("Погрешен формат на регистрација!")
        return;
    }

    let registracija = firstsub.toUpperCase()+"-"+secondsub+"-"+thirdsub.toUpperCase()


    let brojac = 0
    let soobrakajka
    let osnovnaCena = 3000
    cena = parseInt(osnovnaCena)

    let lista = document.getElementById("smetki")
    let result = document.createElement("div")


    if (secondsub[0] == secondsub[1] == secondsub[2] == secondsub[3]) {
        cena += 1000;
    }

    if (yes.checked == true) {
        cena+=500
        soobrakajka = "Има"
    } else if (no.checked == true) {
        soobrakajka = "Нема"
    }

    if (godini.value > 30) {
        result.style.backgroundColor = "red"
    } else {
        result.style.backgroundColor = "lightgreen"
    }

    result.innerHTML = "<p>" + ime.value + "</p>" +
        "<p>" + prezime.value + "</p>" +
        "<p>" + registracija + "</p>" +
        "<p>Сообраќајки: " + soobrakajka + "</p>" +
        "<p>Старост на возилото: " + godini.value + "</p>" +
        "<p>За плаќање: " + cena + "</p>" +
        "<button onclick='plati(this)'>Плати</button><button onclick='izbrisi(this)'>Избриши</button>"

    result.setAttribute("class", "novo")
    lista.append(result)
    brojac++
    let elm = document.getElementById("vkupno")
    elm.innerHTML = brojac
}

function plati(btn) {
    btn.disabled = true
    btn.nextElementSibling.disabled = true
}

function izbrisi(btn) {
    let parent = btn.parentNode
    parent.remove()
    brojac--
    let element = document.getElementById("vkupno")
    element.innerHTML = global
}
