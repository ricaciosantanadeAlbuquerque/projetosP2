<?php

include_once('conexão.php'); // conexão

 $qls ="SELECT * FROM  aulunos ORDER BY matricula"; // comando sql
 $resultado1 = $conecxao->query($qls);
//print_r($resultado1);

?>
<!DOCTYPE html>
<html lang="pt-br">
<head>
  <meta charset="UTF-8">
  <meta http-equiv="X-UA-Compatible" content="IE=edge">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <link rel="stylesheet" href="style.css">
  <title>LISTA</title>
</head>
<body>
  <div id="form"> 
  <div class="input"><!--bloco div --->
    <table border="1px;">
      <thead>
        <tr>
          <th scope="col">nome</th>
          <th scope="col">matricula</th>
          <th scope="col">nota1</th>
          <th scope="col">nota2</th>
          <th scope="col">media</th>
        </tr>
      </thead>
      <tbody>
        <?php
        while($valor = mysqli_fetch_assoc($resultado1)){  // enquanto resultado1 possuir um valor  no banco passe para $valor
            echo "<tr>";
            echo "<td>".$valor['nome']."</td>";
            echo "<td>".$valor['matricula']."</td>";
            echo "<td>".$valor['nota1']."</td>";
            echo "<td>".$valor['nota2']."</td>";
            echo "<td>".$valor['media']."</td>";
            echo "</tr>";
        }
        // para ter a interatividade o loop deve está dentro da tabela 
        ?>
      </tbody>
    </table>
    <a href="index.html">Voltar</a>
  </div>
  </div>
  
</body>
</html>
