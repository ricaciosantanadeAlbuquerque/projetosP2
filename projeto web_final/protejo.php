<!DOCTYPE html>
<html lang="pt-br">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="style.css">
    <title>Document</title>
</head>
<body>
    <?php
        include_once('conexão.php');// inclusão da página de conecção !

        if(!isset($_POST['enviar'])){ // se não foi configurado !isset
           die('ERRO - Não exsitem os campos necessários.'); // die() mostra o erro  e sai do programa
        }else{
           if(empty($_POST['nome'])){ // se empyt == se nome está vazio
               die('ERRO - O compo nome  tem quer ser preenchido');
           }else{
           
            
            if((strlen($_POST['nome']) >= 0 && strlen($_POST['nome'])<= 31)){ // strlen() ==  o comprimento da string passada.
                $nome = isset($_POST['nome'])?$_POST['nome']:'erro !o valor não foi passado';
            }else{
                die('Erro - O nome deve ter entre 0 e 30 caracteres.');
            }
           }

           if(empty($_POST['matricula'])){
            die('ERRO - O compo matricula  tem quer ser preenchido');
        }else{
            $matricula = (int) (isset($_POST['matricula'])?$_POST['matricula']:'erro ! o  valor não foi passado');//(int) tap casting usada para converção 
        }
        if(empty($_POST['nota1'])){
            die('ERRO - O compo nota1  tem quer ser preenchido');
        }else{
            $nota1= (float)(isset($_POST['nota1'])?$_POST['nota1']:'erro ! o  valor não foi passado');
        }
        if(empty($_POST['nota2'])){
            die('ERRO - O compo nota2 tem quer ser preenchido');
        }else{
            $nota2= (float)(isset($_POST['nota2'])?$_POST['nota2']:'erro ! o  valor não foi passado');
        }
        
        
        }
       
      
        $media = ($nota1 + $nota2)/2; 
      
        $cont =0;
        $bancoDados = "SELECT matricula FROM aulunos"; // comando para selecionar a coluna matricula da tabela aulunos
        $valorFinal = $conecxao->query($bancoDados); // -> referencia o metodo query()
       // print_r($valorFinal);
        while($x = mysqli_fetch_assoc($valorFinal)){
          $beta =  $x['matricula'];
          if($beta == $matricula){
            $cont++; // se houver uma matricula igual já cadastrada ele conta  1
            
        }
        }
        if($cont== 1){ // se cont for igual a 1 nao cadastra
            echo('ERRO! essa matricu já existe.');
            ?>
            <a href="index1.html"><strog>Tente novamente com uma matrícula válida</strog></a>
       <?php }else{
        $resultado = mysqli_query($conecxao,"INSERT INTO aulunos(nome,matricula,nota1,nota2,media)VALUES('$nome','$matricula', '$nota1','$nota2','$media')");
            echo "Cadastro realizado com sucesso  !";
            ?>
            <a href="index1.html">Voltar</a>
       <?php } 
       
    ?>
    
</body>
</html>