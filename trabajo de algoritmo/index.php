<?php
			$objetos=3;
			$pesoMax=$_POST["pesoMax"];
			$pesosobj = array($_POST["peso_gold"], $_POST["peso_silver"], $_POST["peso_copper"]);
			$valoresobj = array($_POST["valor_gold"], $_POST["valor_silver"], $_POST["valor_copper"]);

			function mochila($pesoMax, $pesos, $valor, $objetos){
				$K = array();

				for ($i = 0; $i <= $objetos; ++$i){
					for ($w = 0; $w <= $pesoMax; ++$w){
						if ($i == 0 || $w == 0) $K[$i][$w] = 0;
						else if ($pesos[$i - 1] <= $w)
							$K[$i][$w] = max($valor[$i-1] + $K[$i-1][$w-$pesos[$i-1]], $K[$i-1][$w]);
						else $K[$i][$w] = $K[$i-1][$w];
						echo " ".$K[$i][$w];
					}
					echo "<br>";
				}
				return $K[$objetos][$pesoMax];
			}
			$result = mochila($pesoMax, $pesosobj, $valoresobj, $objetos);
			function resultado($pesoMax, $pesos, $valor, $objetos){
				$K = array();
				$x = array(0, 0, 0);
		
				for ($i = 0; $i <= $objetos; ++$i){
					for ($w = 0; $w <= $pesoMax; ++$w){
						if ($i == 0 || $w == 0) $K[$i][$w] = 0;
						else if ($pesos[$i - 1] <= $w)
							$K[$i][$w] = max($valor[$i-1] + $K[$i-1][$w-$pesos[$i-1]], $K[$i-1][$w]);
						else $K[$i][$w] = $K[$i-1][$w];
						if($K[$i][$w]==$valor[0]){$x[0]=1;}
						else if($K[$i][$w]==$valor[1]){$x[1]=1;}
						else if($K[$i][$w]==$valor[2]){$x[2]=1;}
					}
				}
		
				return $x;
			}
			$res = resultado($pesoMax, $pesosobj, $valoresobj, $objetos);
?>

<!DOCTYPE html>
<html>
<head>
	<link rel="stylesheet" href="bootstrap/css/bootstrap.min.css"></link>
	<script src="bootstrap/js/bootstrap.min.js" ></script>
	<script src="jquery.js" ></script>
	<title>php</title>
</head>
<body style="background-color: rgb(134, 134, 134)">
	<table class="table table-striped table-dark" style="width:30%" align="center">
  	<tr>
    	<th>objeto</th>
    	<th>peso</th>
    	<th>valor</th>
    	<th>obj. tomados</th>
  	</tr>
  	<tr>
    	<td><img src="gold.png"></td>
    	<td><?php echo $_POST["peso_gold"]?></td>
    	<td><?php echo $_POST["valor_gold"]?></td>
    	<td><?php echo $res[0]; ?></td>
  	</tr>
  	<tr>
    	<td><img src="silver.png"></td>
    	<td><?php echo $_POST["peso_silver"]?></td>
    	<td><?php echo $_POST["valor_silver"]?></td>
    	<td><?php echo $res[1]; ?></td>
  	</tr>
  	<tr>
    	<td><img src="copper.png"></td>
    	<td><?php echo $_POST["peso_copper"]?></td>
    	<td><?php echo $_POST["valor_copper"]?></td>
    	<td><?php echo $res[2]; ?></td>
  	</tr>
  	<tr>
		<td colspan="4">
			<center><?php echo "Valor maximo obtenido: ".$result; ?></center>
		</td>
  	</tr>
  	<tr>
  		<td colspan="4">
		  <center><?php echo "Peso maximo soportado: ".$_POST["pesoMax"]; ?></center>
  		</td>
  	</tr>
	</table>
	
</body>
</html>