<? php
incluye  ' classe / mochila.php ' ;
if ( isset ( $ _POST [ ' matriz ' ])):
    $ qtd  =  $ _POST [ ' qtd ' ];
    $ pesoMaximo  =  $ _POST [ ' pesoMaximo ' ];
    $ matrizForm  =  $ _POST [ ' matriz ' ];
    // forma a matriz da mochila
    para ( $ i  =  0 ; $ i  <  $ qtd ; $ i ++ ) {
        $ matriz [ $ i ] [ ' item ' ] =  $ matrizForm [ $ i ] [ 1 ];
        $ matriz [ $ i ] [ ' peso ' ] =  $ matrizForm [ $ i ] [ 2 ];
        $ matriz [ $ i ] [ ' valor ' ] =  $ matrizForm [ $ i ] [ 3 ];
        $ matriz [ $ i ] [ ' razao ' ] =  $ matriz [ $ i ] [ ' valor ' ] /  $ matriz [ $ i ] [ ' peso ' ];
    }
    // PUNTO DE VALOR PRINCIPAL: Retorna os itens eo custo;
    $ resultMaiorValor  =  new  Mochila ( $ matriz , $ pesoMaximo , $ qtd );
    $ resultMaiorValor -> mochilaMaiorValor ();
    // ARTÍCULO DE MENOR PESO: Retorna os itens eo custo
    $ resultMenorPeso  =  new  Mochila ( $ matriz , $ pesoMaximo , $ qtd );
    $ resultMenorPeso -> mochilaMenorPeso ();
    // "ITEM DE MAIOR Razão: Retorna os itens eo custo"
    $ resultMaiorRazao  =  new  Mochila ( $ matriz , $ pesoMaximo , $ qtd );
    $ resultMaiorRazao -> mochilaMaiorRazao ();
    ? >
    <! DOCTYPE html>
    < html >
        < cabeza >
            < título > Problema da mochila </ título >
            < meta  name = " viewport "  content = " width = device-width, initial-scale = 1.0 " >
            <! - Bootstrap ->
            < link  href = " style / css / bootstrap.min.css "  rel = " stylesheet "  media = " screen " >
            < link  href = " style / css / bootstrap-responsive.min.css "  rel = " hoja de estilo "  media = " screen " >
            < link  href = " style / css / style.css "  rel = " hoja de estilo "  media = " screen " >
        </ cabeza >
        < cuerpo >
            < div  class = " row margem " >
                < div  class = " span12 " >

                    < table  class = " table-wered table-striped table-hover " >
                        < caption > < center > < h1 > Mochila peso m & aacute ; ximo = < abarcan  clase = " peso-maximo " > <? php echo $ pesoMaximo ? > Kg </ span > </ h1 > </ center > </ caption >   
                        < thead >
                            < tr >
                                < th > < center > # </ th >
                            < th > < center > Peso </ center > </ th >
                            < th > < center > Valor </ center > </ th >
                                < th > < center > Raz & atilde ; o </ center > </ th >
                            </ tr >
                            </ thead >
                            < tbody >
                                <? php para ( $ i = 0 ; $ i < $ qtd ; $ i ++ ) :? >     
                                    < tr >
                                        < td > < center > <? php echo $ i ? > </ center > </ td >   
                                < td > < center > <? php echo $ matriz [ $ i ] [ ' peso ' ] ? > </ center > </ td >  
                                < td > < center > <? php echo $ matriz [ $ i ] [ ' valor ' ] ? > </ center > </ td >  
                                < td > < center > <? php echo $ matriz [ $ i ] [ ' valor ' ] / $ matriz [ $ i ] [ ' peso ' ] ? > </ center > </ td >   
                                </ tr >
                            <? php endfor ; ? > 
                            </ tbody >
                    </ table >
                    </ br > </ br >
                    < table  class = " table-wered table-striped table-hover " >
                        < título > < centro > < h1 > Resultado </ h1 > </ centro > </ título >
                        < thead >
                            < tr >
                                < th > < center > Maior Valor </ center > </ th >
                        < th > < center > Menor Peso </ center > </ th >
                        < th > < center > Maior Raz & atilde ; o </ center > </ th >
                        </ tr >
                        </ thead >
                        < tbody >
                            < tr >
                                < td >
                        < centro >
                            <? php
                            echo  " <div class = 'separador'> " ;
                            echo  " </div> " ;
                            echo  " </br> " ;
                            echo  " <p> <span class = 'itens'> Custo Parcial = </span> "  .  $ resultMaiorValor -> getCustoParcial () .  " </p> " ;
                            echo  " </br> " ;
                            echo  " <div class = 'separador'> " ;
                            echo  " </div> " ;
                            echo "<p><span class='itens'>Peso Parcial = </span>" . $resultMaiorValor->getPesoParcial() . "</p>";
                            echo "</br>";
                            echo "<div class='separador'>";
                            echo "</div>";
                            $itensMaiorValor = $resultMaiorValor->getVetorSolucao();
                            for ($i = 0; $i < count($itensMaiorValor); $i++) {
                                echo "<p><span class='itens'>Item </span>" . $itensMaiorValor[$i] . "</p>";
                                echo '</br>';
                            }
                            ?>
                        </center>
                        </td>
                        <td>
                        <center>
                            <?php
                            $itensMenorPeso = $resultMenorPeso->getVetorSolucao();
                            echo "<div class='separador'>";
                            echo "</div>";
                            echo "</br>";
                            echo "<p><span class='itens'>Custo Parcial = </span>" . $resultMenorPeso->getCustoParcial() . '</p>';
                            echo "</br>";
                            echo "<div class='separador'>";
                            echo "</div>";
                            echo "<p><span class='itens'>Peso Parcial = </span>" . $resultMenorPeso->getPesoParcial() . '</p>';
                            echo "</br>";
                            echo "<div class='separador'>";
                            echo "</div>";
                            for ($i = 0; $i < count($itensMenorPeso); $i++) {
                                echo "<p><span class='itens'> Item </span>" . $itensMenorPeso[$i] . "</p>";
                                echo '</br>';
                            }
                            ?>
                        </center>
                        </td>
                        <td>
                        <center>
                            <?php
                            $itenMaiorRazao = $resultMaiorRazao->getVetorSolucao();
                            echo "<div class='separador'>";
                            echo "</div>";
                            echo "</br>";
                            echo "<p><span class='itens'>Custo Parcial = </span>" . $resultMaiorRazao->getCustoParcial() . '</p>';
                            echo "</br>";
                            echo "<div class='separador'>";
                            echo "</div>";
                            echo "<p><span class='itens'>Peso Parcial = </span>" . $resultMaiorRazao->getPesoParcial() . '</p>';
                            echo "</br>";
                            echo "<div class='separador'>";
                            echo "</div>";
                            for ($i = 0; $i < count($itenMaiorRazao); $i++) {
                                echo "<p><span class='itens'> Item </span>" . $itenMaiorRazao[$i] . "</p>";
                                echo '</br>';
                            }
                            ?>
                        </center>
                        </td>
                        </tr>
                        </tbody>
                    </table>
                </div>
            </div>
            <script src="http://code.jquery.com/jquery-latest.js"></script>
            < script  src = " style / js / bootstrap.min.js " > </ script >
        </ cuerpo >
    </ html >

    <? php
otra cosa :
    encabezado ( ' ubicación: index.php ' );
endif ;