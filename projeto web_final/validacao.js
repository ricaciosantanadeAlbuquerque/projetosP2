
let nome = document.getElementById("nome");
let matricula = document.getElementById("matricula");
let nota1 = document.getElementById("nota1");
let nota2 = document.getElementById("nota2");
let btt = document.getElementById("btt");

const regex = /\d+/;

btt.addEventListener("click", function (event){

    //  NOME
    if (nome.value == ""){
        event.preventDefault();
        swal("Importante", "É necessário informar o nome","info")
        return;
    }
    if (nome.value.match(regex)!=null){
        event.preventDefault();
        swal("Importante", "O nome não pode conter números","info")
        return;
    }

    //  MATRICULA
    if (matricula.value == ""){
        event.preventDefault();
        swal("Importante", "É necessário informar a matricula","info")
        return;
    }
    if (isNaN(matricula.value)){
        event.preventDefault();
        swal("Importante", "A matrícula deve conter apenas números","info")
        return;
    }

    //  NOTA 1
    if (nota1.value == ""){
        event.preventDefault();
        swal("Importante", "É necessário informar a primeira nota","info")
        return;
    }
    if (isNaN(nota1.value)){
        event.preventDefault();
        swal("Importante", "A 'Nota 1' deve conter apenas números","info")
        return;
    }

    //  NOTA 2
    if (nota2.value == ""){
        event.preventDefault();
        swal("Importante", "É necessário informar a segunda nota","info")
        return;
    }
    if (isNaN(nota2.value)){
        event.preventDefault();
        swal("Importante", "A 'Nota 2' deve conter apenas números","info")
        return;
    }

    //  NOTAS
    if ((nota1.value > 10 || nota1.value < 0) || (nota2.value > 10 || nota2.value < 0)){
        event.preventDefault();
        swal("Atenção", "A Nota não pode ser negativa nem maior que 10","info")
        return;
    }
})