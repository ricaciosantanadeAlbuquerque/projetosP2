<!DOCTYPE html>
<html lang="pt-br">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="style.css">
    <title>BUSCA</title>
</head>
<body>
  <?php
   if(isset($_POST['enviado'])){// se $_POST['enviado'] foi configurado então pode executar  
    $nome = isset($_POST['nome1'])?$_POST['nome1']:'erro !o valor não foi passado'; // O perador ternário
    $matricula = (int)(isset($_POST['matricula1'])?$_POST['matricula1']:'erro ! o  valor não foi passado');
    //echo "$matricula";
    include_once('conexão.php');// estabele a conecxão com a página conecxao.php aonde está o codigo SQL
  ?>
 <div>
    <table border="1px;"> <!--Início da tabela,  propriédade dorbe="" depreciada com valor 1 --->
      <thead><!--Cabeçalho da tabela --->
        <tr><!--Primeira linha --->
          <th scope="col">nome</th><!---cabeçalho da tabela--->
          <th scope="col">matricula</th>
          <th scope="col">nota1</th>
          <th scope="col">nota2</th>
          <th scope="col">media</th>
        </tr>
      </thead>
      <tbody> <!--Corpo da tabela --->
        <?php
       
          try{ // bloco de tratamento try. se estiver correto então poderá entra nesse bloco se não cai no bloco catch
            $qls ="SELECT nome,matricula,nota1,nota2,media FROM aulunos WHERE matricula = $matricula ";
            $resultado1 = $conecxao->query($qls);

           // print_r($resultado1); essa função mostra o que foi passado ou o que está dentro de $$resultado1
          
            while($valor = mysqli_fetch_assoc($resultado1)){ // VALOR É UM VETOR QUE VAI POSSUIR OS ELEMENTOS DO BANCO
                if($matricula == $valor['matricula']){// SE MEU VETOR VALOR NA POSIÇÃO MATRICULA FOR == a variável matricula então oks
                  // echo "oks" ;
                  echo "<tr>"; // seguda linha da tabela 
                  echo "<td>".$valor['nome']."</td>"; // selulas
                  echo "<td>".$valor['matricula']."</td>";
                  echo "<td>".$valor['nota1']."</td>";
                  echo "<td>".$valor['nota2']."</td>";
                  echo "<td>".$valor['media']."</td>";
                  echo "</tr>";
              
                }
             
          }
        
          }
          catch(Exception $e){ // bloco o erro catch
           echo "Erro:". $se -> getMessage();
          }
          }else{
              echo "ERRO ! "; 
          }
       
        ?>
      </tbody>
    </table>
  </div>
  <a href="buscar.html">Voltar</a>
</body>
</html>