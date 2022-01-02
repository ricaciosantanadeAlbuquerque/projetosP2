#include <stdio.h>
#include <stdlib.h>
int brancas = 1;
int pretas  = 0;
int contX =0;
int contX1 =0;
int cont = 0;
int cont1 = -1;
  int mover1 =0;
char xadrez[9][9] = { {' ','1','2','3','4','5','6','7','8'}
                     ,{'1','T','C','B','Q','K','B','C','T'}
                     ,{'2','P','P','P','P','P','P','P','P'}
                     ,{'3',' ',' ',' ',' ',' ',' ',' ',' '}
                     ,{'4',' ',' ',' ',' ',' ',' ',' ',' '}
                     ,{'5',' ',' ',' ',' ',' ',' ',' ',' '}
                     ,{'6',' ',' ',' ',' ',' ',' ',' ',' '}
                     ,{'7','p','p','p','p','p','p','p','p'}
                     ,{'8','t','c','b','q','k','b','c','t'}};
/* Neste caso os valores da matriz são preenchidos diretamente porém podem ser  feitos por um laço for
 tambem por exemplo  posição linha 0 coluna 0 = recebe T*/
 // METODO MOSTRAR MATRIZ========================================================================================================
int mostrarMatriz(){
  system("CLS"); // função para limpar tela;
  int linha;
  int coluna;
  int x;
  for(linha = 0; linha<9;linha++){ // 0 1 2 3 4 5 6 7
        for(x=0;x<3;x++){ // 0 1 2 para cada loop o  mais interno executa 8 vezes

            for(coluna = 0; coluna<9;coluna++){
                char peca = xadrez[linha][coluna]; // peça recebe o que está dentro das respectivas posiçoes da matrix xadrex
             char letra1 = ((linha+coluna)%2 ==0 && linha>0 && coluna>0)?'\xB2':' ';
             char letra = (x == 1 && peca != ' ')? peca: letra1;
        if((linha+coluna)%2==0 && linha>0 && coluna>0){ // através da soma das posições da linha  e da coluna e com o resto da divisão da saber se
                                 // a soma  dos indices o resto e par ou impar. as que forem par seram pintadas e as que não são ficaram em branco
           printf("\xB2\xB2%c\xB2\xB2", letra); // sequencia de escape \xB2 para pintar !!
        }else{
            printf("  %c  ", letra);//DO MESMO MODO QUE TEMOS  4 \xB2 ENVOLTA DA MASCARA %c TEMOS 4 ESPAÇOS VAZIOS ENTORNO  DESTA  MASCARA TAMBEM
        }
    }
     printf("\n");
        }
  }
}
//METODO MOVER PECA ==============================================================================================================================================================================================================
//O MAIOR DE TODOS OS MÉTODOS RESPONSÁVEL POR SOBRE ESCREVER OS VALORES DA MATRIZ SO DETERMINADAS CONDIÇÕES
//================================================================================================================================================================================================================================
int moverpeca(int LO ,int CO, int lD,int cD,int valor){ // A CADA CHAMADA AS VARIÁVEIS SÃO REINICIADAS!
    // ESTÃO SENDO RECEBIDOS OS VALORES  DOS ARGUMENTOS "{ linhaOrigem colunaOrigem linhaDestino colunaDestino } PARA OS PARÂMENTROS { LO , CO , lD ,cD}
    int mover;
     char peca;

    //O DESLOCAMNETO VERTICAL SERÁ A SUBTRAÇÃO DA LINHA DE DESTINO MENOS A LINHA DE ORIGEM. EXEMPLO{ LINHA 1 PARA LINHA 3} OPERAÇÃO SERÁ (3 - 1 QUE E == 2 CASAS) DESTINO MENOS ORIGEM.
    int deslocamentoVertical = abs(lD - LO); //ABS VALOR ABSOLUTO
      //printf("\n\n%d\n\n",deslocamentoVertical);
      //O DESLOCAMENTO HORIZONTAL SERÁ  A SUBTRÇÃO DA COLUNA DE DESTINO MENOS A COLUNA DE ORIGEM EXEMPLO (4 - 2 == 2 CASAS)
    int deslocamentoHorizontal = abs(cD - CO);
      //printf("%d %d %d %d ",LO,CO,lD,cD);
//printf("====TTTTTT%dTTTTTT=====",valor);
      if( ((LO >=1 && LO <=8) && (CO >=1 && CO <=8)) && (lD >=1 && lD <=8) && (cD >=1 && cD <=8)){// SÓ SERÃO ACEITOS OS VALORES ENTRE 1 E 8 TANTO PARA O DESTINO QUANTO PARA A ORIGEM
          // JÁ QUE O TABULEIRO ONDE AS PEÇAS IRÃO SE MOVER E UMA MATRIZ QUE VARIA  ENTRE 1 E 8  SENDO [8]POR [8]
             peca = xadrez[LO][CO];
             if(( valor == 1 )&& (xadrez[LO][CO] == 'T' || xadrez[LO][CO] == 'C' || xadrez[LO][CO] == 'B' || xadrez[LO][CO] == 'Q' || xadrez[LO][CO] == 'P' || xadrez[LO][CO] == 'K')){

                     if(xadrez[LO][CO] == 'T' || xadrez[LO][CO] == 'C' || xadrez[LO][CO] == 'B' || xadrez[LO][CO] == 'Q' || xadrez[LO][CO] == 'P' || xadrez[LO][CO] == 'K') { // se a origem  for maiúscula Branca  entra aque
                 // SE xadrez[LO][CO] na linha de origem e coluna de origem for igual a T maiusculo E xadrez[lD][cD] na linha Destino coluna Destino for igual a vaziu ou
// xadrez[LO][CO] for igual a T mauisculo E   xadrez[lD][cD] na linha Destino coluna Destino for igual a p minusculo ENTÃO ELE PODE MOVER

                      if(( xadrez[LO][CO] == 'T' && xadrez[lD][cD] == ' ') || (xadrez[LO][CO] == 'T' && xadrez[lD][cD] == 'p') || (xadrez[LO][CO] == 'T' && xadrez[lD][cD] == 't')
                  || (xadrez[LO][CO] == 'T' && xadrez[lD][cD] == 'b') || (xadrez[LO][CO] == 'T' && xadrez[lD][cD] == 'c')
                  || (xadrez[LO][CO] == 'T' && xadrez[lD][cD] == 'q') || (xadrez[LO][CO] == 'T' && xadrez[lD][cD] == 'k')
                 && (deslocamentoVertical == 0 || deslocamentoHorizontal == 0)){ // SE  O DESTINO FOR  VAZIO OU ENTÃO UM CARACTER MINÚSCULO ENTÃO PODE SOBRE ESCREVER !!
                     // NESTE CASO  A ORIGEM VAI PARA O LOCAL DE DESTINO E O DESTINO RECEBE == ' '  VAZIO
                     /*
                      1 SE O DESCOLACAMENTOVERTICAL FOR == 0 SIGNIFICA QUE A TORRE  SE MOVEU TODO NA HORIZONTAL E  NÃO SE DESLOCOU  NA VERTICAL !    EXEMPLO { deslocamentoVertical == 0
                      2 PORÉM o deslocamentoHorizontal == 8 foi oito,
                      3 O MESMO VALE PARA O deslocamentoHorizontal SE ELE FOR == 0 ENTÃO O MOVIMENTO SERA  NA VERTICAL.
                      4 OU UM OU OUTRO  NUNCA OS DOIS
                     */
                    int cont = 0;
                     int cont1 = 0;


//=============================================================================================================================================================================
                           if(deslocamentoVertical >0){




                            if(CO == 1){ // SE A COLUNA FOR IGUAL A 1
                                    int f = LO; // f RECEBE a linha de origem
                                if(LO - lD == 1 || lD - LO  == 1){ //  A solução para andar um casa, se alinha de origem menos a linha destino for == 1 ou  linha destino menos origem for == 1 ENTÃO entra na condção
// obs LINHA ORGEM == ONDE ESTÁ
// LINHA DESTINO PARA ONDE  VAI

                                 for(f;f<=lD;f++){// PARA F QUE COMEÇA NO VALOR DE LINHA ORIGEM ENQUANTO FOR MENOR OU IGUAL A LINHA DESTINO  SEJA INCREMENTADO EM UMA UNIDADE

                              if(xadrez[f][1] == ' '){// NESTE CASO A COLUNA  ESTÁ FIXA EM 1 ,  E QUEM VARIA É A LINHA f
                                    cont++;        // se xadrez[f][1] na linha f coluna 1 É  == a vazio  então a torre pode se mover  por essa casa  até porque a torre não pode saltar  por cima das peças
                                                   // O cont VAI CONTAR QUANTAS CASAS VAZIAS A ENTRE A TORRE E SEU DESTINO

                             }else if(xadrez[f+1][1] != ' ' ){ // f+1 PORQUE NA POSIÇÃO F JÁ TEM A PRÓPRIA TORRE E ELA É UMA PEÇA POR TANTO NÃO E VAZIO
                                  cont1++; // cont1 CONTA AS POSIÇÕES QUE TEM PEÇAS, SE HOUVER  PEÇAS ENTRE A TORRE E SEU DESTINO ELE VAI CONTAR.
                             }

                         }
                           f = LO; // NOVAMENTE f RECEBE O VALOR DO PARÂMETRO linhaOrigem
                  /* printf("====ttuu%d==\n\n",cont);
                   printf("====ttuu%d==\n\n",(lD -f));
                   printf("====ttuu%d===\n\n",(f - lD));*/

                    if(((cont == (lD - f)) || (cont == ( f - lD) )) && (cont1 == 0)){ //ESSA CONDIÇÃO SERVE PARA SABER SE A QUANTIDADE DE CASAS VAZIAS ENTRE A TORRE EO DESTINO É IGUAL A SUBTRÇÃO
                        // DA LINHA DE DESTINO MENOS A LINHA DE ORIGEM  EXEMPLO { cont == 6 foi contada sei casas e a lD == 8 e f == 2 o resultado de casas é  8 - 2 == 6
                        // comparando as  6 casas vazias  com o resultado  podemos ter certeza que há 6 casas entre destino e origem e que estão vazias pois cont1 e == 0
                        //PORÉM SE cont1 TIVESSE CONTADO UMA CASA ENTÃO ENTRE A TORRE E SEU DESTINO HAVIA UMA PEÇA
                        // A OPERAÇÃO NÃO SERIA ACEITA POIS A TORRE NÃO PODE SALTAR SOBRE AS PEÇAS

                            for(int i =0; i < 1;i++){ // ESSE lOOP CORRE SOMENTE UMA VEZ PARA CONTAR O contX lembrando que o contX e global
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                          }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }

                           }else{

                          for(int i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                               //printf("=========yyyyy%d========",contX1 );
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                          }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }

                               xadrez[lD][cD] = xadrez[LO][CO]; //SOB ESCREVE A FORÇA E RETORNA 1
                               xadrez[LO][CO] = ' ';
                              return 1; // movimento realizado;

                           }

                   }

//================================================================================================================================================================================================================================

                                     int   i = LO+1; // I RECEBE LINHA DE ORIGEM MAIS 1
                                    if(i < lD){ // SE A LINHA DE ORIGEM FOR MENOR QUE A LINHA DESTINO EXEMPLO{ linha 1 para linha 8}


                                 for(i;i<lD;i++){

                        if(xadrez[i][1] == ' '){// o que vai variar é a linha ( DESLOCAMENTO VERTICAL) e a coluna permanece FIXA COLUNA 1
                                cont++;// cont  vaizio

                        }else if(xadrez[i][1] != ' ' ){
                        cont1++; //cont1 conta as peças
                        }

                    }
                      i = LO+1; // I RECEBE LINHA DE ORIGEM MAIS 1 NOVAMENTE

                    if(((cont == (lD - i)) || (cont == ( i - lD) )) && (cont1 == 0)){ // SE NÃO HOUVER PEÇAS ENTRE A TORRE É O DESTINO PODE MOVER

                         for(int i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                             //  printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                          }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }



                           }else{
                               printf("Não é possivel saltar sobre as peças"); // NESTE CASO cont1 CONTOU UMA PEÇA ENTRE A TORRE E SEU DESTINO
                                                                                // NÃO PODE MOVER  POIS A TORRE NÃO SALTA SOBRE PEÇAS
                           }

                   }
//===============================================================================================================================================================================================
                   if(i > lD){ // neste caso origem é  maior que o destino ORIGEM == 8 DESTINO == 1
                           int x = LO - 1;

                     for(x;x>lD;x--){// ENTÃO PARA SE MOVER PARA TRAZ E SÓ DECREMENTAR

                        if(xadrez[x][1] == ' '){
                                cont++;

                        }else if(xadrez[x][1] != ' ' ){
                        cont1++;
                        }

                   }
                     x = LO - 1; // SERIA A LINHA 8 MENOS 1 POIS A LINHA 8 JÁ E A PRÓPRIA PEÇA

                    if(((cont == (lD - x)) || (cont == ( x - lD) )) && (cont1 == 0)){

                         for(int i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                        }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }


                           }else{
                               printf("Não é possivel saltar sobre as peças\n");
                           }

                   }


                  }else if(CO == 2){//================

                                int f = LO;
                                if(LO - lD == 1 || lD - LO  == 1){ // solução para andar um casa


                                 for(f;f<=lD;f++){

                              if(xadrez[f][2] == ' '){
                                    cont++;

                             }else if(xadrez[f+1][2] != ' ' ){
                                  cont1++;
                             }

                         }
                        f = LO;
                    if(((cont == (lD - f)) || (cont == ( f - lD) )) && (cont1 == 0)){

                          for(int i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                               //printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                        }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }


                           }else{


                         for(int i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                               //printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                          }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }

                               xadrez[lD][cD] = xadrez[LO][CO];
                               xadrez[LO][CO] = ' ';
                               return 1; // movimento realizado;

                           }

                   }

 //============================================================================================================
                         int   i = LO + 1;
                        if(i < lD){ // ESSA CONDIÇÃO SERVE PARA SABER SE A LINHA DE ORIGEM i É MENOR QUE A LINHA DE DESTINO lD, SE FOR TEREMOS QUE FAZER UM LOOP INCREMENTADO AS CASAS

                        for(i;i<lD;i++){

                        if(xadrez[i][2] == ' '){//  NESTE CASO QUEM VARIA É A LINHA (deslocamento  vertical) A COLUNA ESTÁ FIXA
                                cont++; // CONTA OS VAIOS

                        }else if(xadrez[i][2] != ' ' ){
                        cont1++; // CONTA  AS PEÇAS
                        }

                    }
                      i = LO +1;

                    if(((cont == (lD - i)) || (cont == ( i - lD) )) && (cont1 == 0)){         //ESSA CONDIÇÃO SERVE PARA SABER SE A QUANTIDADE DE CASAS VAZIAS ENTRE A TORRE EO DESTINO É IGUAL A SUBTRÇÃO
                        // DA LINHA DE DESTINO MENOS A LINHA DE ORIGEM  EXEMPLO { cont == 6 foi contada sei casas e a lD == 8 e i == 2 o resultado de casas é  8 - 2 == 6
                        // comparando as  6 casas vazias  com o resultado  podemos ter certeza que há 6 casas entre destino e origem e que estão vazias pois cont1 e == 0
                        //PORÉM SE cont1 TIVESSE CONTADO UMA CASA ENTÃO ENTRE A TORRE E SEU DESTINO HAVIA UMA PEÇA
                        // A OPERAÇÃO NÃO SERIA ACEITA POIS A TORRE NÃO PODE SALTAR SOBRE AS PEÇAS
                            for(int i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                          }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }


                           }else{
                               printf("Não é possivel saltar sobre as peças");
                           }

                   }


                   if(i > lD){ // SE A ORIGEM FOR MAIOR QUE O DESTINO, SERÁ FEITO UM LOOP  DECREMENTANDO AS CASAS.
                    int x = LO - 1; // O MENOS UM E PARA QUE A PROPRIA PEÇA NÃO SEJA  CONTADA JÁ QUE QUEREMOS CHECAR SO O INTERVALO ASSIM SUPONDO QUE VAMOS DE 8 PARA 1 O INTERVALO E 7 2

                    for(x;x>lD;x--){

                    if(xadrez[x][2] == ' '){
                                cont++; // CONTA  VAZIO

                    }else if(xadrez[x][2] != ' ' ){
                        cont1++; // CONTA PEÇA
                        }

                   }
                     x = LO - 1;
                    if(((cont == (lD - x)) || (cont == ( x - lD) )) && (cont1 == 0)){

                          for(int i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                             //  printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                          }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }


                           }else{
                               printf("Não é possivel saltar sobre as peças\n");
                           }

                   }

                 }else if(CO == 3){ // SE A COLUNA FOR == 3  ENTÃO SERA EXECUTADO ESSA CONDIÇÃO

                                int f = LO;
                                if(LO - lD == 1 || lD - LO  == 1){ // solução para andar um casa


                                 for(f;f<=lD;f++){

                              if(xadrez[f][3] == ' '){
                                    cont++;

                             }else if(xadrez[f+1][3] != ' ' ){
                                  cont1++;
                             }

                         }
                           f = LO;


                    if(((cont == (lD - f)) || (cont == ( f - lD) )) && (cont1 == 0)){ // NESTE CASO A TORRE SO SE MOVER´´A UMA CASA


                            for(int i =0; i < 1;i++){ // ESSE lOOP CORRE SOMENTE UMA VEZ PARA CONTAR O contX lembrando que o contX e global
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                        }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }


                }else{

                         for(int i =0; i < 1;i++){ // ESSE lOOP CORRE SOMENTE UMA VEZ PARA CONTAR O contX lembrando que o contX e global
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                             //  printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                    }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }


                 xadrez[lD][cD] = xadrez[LO][CO];
                 xadrez[LO][CO] = ' ';
                    return 1; // movimento realizado;
                           }

                   }


// A LOGICA É  A MESMA AO LONGO DE TODA A CONDIÇÃO DA TORRE
//===============================================================================================================================================================
                        int   i = LO + 1;
                    if(i < lD){

                        for(i;i<lD;i++){

                           if(xadrez[i][3] == ' '){
                                cont++;

                           }else if(xadrez[i][3] != ' ' ){
                               cont1++;
                           }

                        }
                             i = LO +1;

                    if(((cont == (lD - i)) || (cont == ( i - lD) )) && (cont1 == 0)){

                           for(int i =0; i < 1;i++){ // ESSE lOOP CORRE SOMENTE UMA VEZ PARA CONTAR O contX lembrando que o contX e global
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                             //  printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                        }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }


                           }else{
                               printf("Não é possivel saltar sobre as peças");
                           }

                   }

//==============================================================================================================================================================================
                   if(i > lD){

                           int x = LO - 1;

                     for(x;x>lD;x--){

                        if(xadrez[x][3] == ' '){
                                cont++;

                        }else if(xadrez[x][3] != ' ' ){
                        cont1++;
                        }

                   }
                     x = LO - 1;

                    if(((cont == (lD - x)) || (cont == ( x - lD) )) && (cont1 == 0)){

                        for(int i =0; i < 1;i++){ // ESSE lOOP CORRE SOMENTE UMA VEZ PARA CONTAR O contX lembrando que o contX e global
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                          }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }

                           }else{
                               printf("Não é possivel saltar sobre as peças\n");
                           }

                   }
//===================================================================================================================================================================================================
                    }else if(CO == 4){

                                    int f = LO;
                                if(LO - lD == 1 || lD - LO  == 1){ // solução para andar um casa


                                 for(f;f<=lD;f++){

                              if(xadrez[f][4] == ' '){
                                    cont++;

                             }else if(xadrez[f+1][4] != ' ' ){
                                  cont1++;
                             }

                         }
                           f = LO;
                    if(((cont == (lD - f)) || (cont == ( f - lD) )) && (cont1 == 0)){

                              for(int i =0; i < 1;i++){ // ESSE lOOP CORRE SOMENTE UMA VEZ PARA CONTAR O contX lembrando que o contX e global
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                          }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }

                           }else{

                          for(int i =0; i < 1;i++){ // ESSE lOOP CORRE SOMENTE UMA VEZ PARA CONTAR O contX lembrando que o contX e global
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                        }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }
                                xadrez[lD][cD] = xadrez[LO][CO];
                               xadrez[LO][CO] = ' ';
                               return 1; // movimento realizado;
                           }

                   }

//====================================================================================================================================================================
                    int   i = LO + 1;
                    if(i < lD){

                        for(i;i<lD;i++){

                           if(xadrez[i][4] == ' '){
                                cont++;

                           }else if(xadrez[i][4] != ' ' ){
                               cont1++;
                           }

                        }
                             i = LO +1;

                    if(((cont == (lD - i)) || (cont == ( i - lD) )) && (cont1 == 0)){

                                for(int i =0; i < 1;i++){ // ESSE lOOP CORRE SOMENTE UMA VEZ PARA CONTAR O contX lembrando que o contX e global
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                             //  printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                          }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }


                        }else{
                               printf("Não é possivel saltar sobre as peças");
                           }

                   }
//========================================================================================================================================================
                   if(i > lD){
                    int x = LO - 1;

                     for(x;x>lD;x--){

                        if(xadrez[x][4] == ' '){
                                cont++;

                        }else if(xadrez[x][4] != ' ' ){
                        cont1++;
                        }

                   }
                     x = LO - 1;
                  /* printf("====ttuu%d==\n\n",cont);
                   printf("====ttuu%d==\n\n",(lD -x));
                   printf("====ttuu%d===\n\n",(x - lD));*/

                    if(((cont == (lD - x)) || (cont == ( x - lD) )) && (cont1 == 0)){

                              for(int i =0; i < 1;i++){ // ESSE lOOP CORRE SOMENTE UMA VEZ PARA CONTAR O contX lembrando que o contX e global
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                        }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }



                           }else{
                               printf("Não é possivel saltar sobre as peças\n");
                           }

                   }

//===============================================================================================================================================================================
                    }else if(CO == 5){

                                    int f = LO;
                                if(LO - lD == 1 || lD - LO  == 1){ // solução para andar um casa


                                 for(f;f<=lD;f++){

                              if(xadrez[f][5] == ' '){
                                    cont++;

                             }else if(xadrez[f+1][5] != ' ' ){
                                  cont1++;
                             }

                         }
                           f = LO;


                    if(((cont == (lD - f)) || (cont == ( f - lD) )) && (cont1 == 0)){

                             for(int i =0; i < 1;i++){ // ESSE lOOP CORRE SOMENTE UMA VEZ PARA CONTAR O contX lembrando que o contX e global
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                             //  printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                     }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }


                           }else{

                                   for(int i =0; i < 1;i++){ // ESSE lOOP CORRE SOMENTE UMA VEZ PARA CONTAR O contX lembrando que o contX e global
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                          }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }
                            xadrez[lD][cD] = xadrez[LO][CO];
                            xadrez[LO][CO] = ' ';
                             return 1; // movimento realizado;;

                           }

                   }


//===================================================================================================================================================================
                        int   i = LO + 1;

                       if(i < lD){

                          for(i;i<lD;i++){

                        if(xadrez[i][5] == ' '){
                                cont++;

                        }else if(xadrez[i][5] != ' ' ){
                        cont1++;
                        }

                    }
                      i = LO +1;
                    if(((cont == (lD - i)) || (cont == ( i - lD) )) && (cont1 == 0)){

                              for(int i =0; i < 1;i++){ // ESSE lOOP CORRE SOMENTE UMA VEZ PARA CONTAR O contX lembrando que o contX e global
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                          }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }

                           }else{
                               printf("Não é possivel saltar sobre as peças");
                           }

                       }

//=========================================================================================================================================================================================
                   if(i > lD){
                      int x = LO - 1;

                     for(x;x>lD;x--){

                        if(xadrez[x][5] == ' '){
                                cont++;

                        }else if(xadrez[x][5] != ' ' ){
                        cont1++;
                        }

                   }
                     x = LO - 1;

                    if(((cont == (lD - x)) || (cont == ( x - lD) )) && (cont1 == 0)){

                         for(int i =0; i < 1;i++){ // ESSE lOOP CORRE SOMENTE UMA VEZ PARA CONTAR O contX lembrando que o contX e global
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                             //  printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                        }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }



                           }else{
                               printf("Não é possivel saltar sobre as peças\n");
                           }

                   }
//=´============================================================================================================================================================================
                }else if(CO == 6){

                                    int f = LO;
                                if(LO - lD == 1 || lD - LO  == 1){ // solução para andar um casa


                                 for(f;f<=lD;f++){

                              if(xadrez[f][6] == ' '){
                                    cont++;

                             }else if(xadrez[f+1][6] != ' ' ){
                                  cont1++;
                             }

                         }
                           f = LO;


                    if(((cont == (lD - f)) || (cont == ( f - lD) )) && (cont1 == 0)){

                              for(int i =0; i < 1;i++){ // ESSE lOOP CORRE SOMENTE UMA VEZ PARA CONTAR O contX lembrando que o contX e global
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                            //   printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                          }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }



                           }else{

                                 for(int i =0; i < 1;i++){ // ESSE lOOP CORRE SOMENTE UMA VEZ PARA CONTAR O contX lembrando que o contX e global
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                          }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }
                              xadrez[lD][cD] = xadrez[LO][CO];
                               xadrez[LO][CO] = ' ';
                               return 1; // movimento realizado;
                           }

                   }

//=============================================================================================================
                    int   i = LO + 1;
                    if(i < lD){

                        for(i;i<lD;i++){

                           if(xadrez[i][6] == ' '){
                                cont++;

                           }else if(xadrez[i][6] != ' ' ){
                               cont1++;
                           }

                        }
                             i = LO +1;

                    if(((cont == (lD - i)) || (cont == ( i - lD) )) && (cont1 == 0)){

                         for(int i =0; i < 1;i++){ // ESSE lOOP CORRE SOMENTE UMA VEZ PARA CONTAR O contX lembrando que o contX e global
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                            //   printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                      }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }

                           }else{
                               printf("Não é possivel saltar sobre as peças");
                           }

                   }

//=========================================================================================================================================================================================
                   if(i > lD){

                           int x = LO - 1;

                     for(x;x>lD;x--){

                        if(xadrez[x][6] == ' '){
                                cont++;

                        }else if(xadrez[x][6] != ' ' ){
                        cont1++;
                        }

                   }
                     x = LO - 1;


                    if(((cont == (lD - x)) || (cont == ( x - lD) )) && (cont1 == 0)){

                         for(int i =0; i < 1;i++){ // ESSE lOOP CORRE SOMENTE UMA VEZ PARA CONTAR O contX lembrando que o contX e global
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                         }
                     }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }

                           }else{
                               printf("Não é possivel saltar sobre as peças\n");
                           }

                   }



//=========================================================================================================================================================================
               }else if(CO == 7){

                        int f = LO;
                    if(LO - lD == 1 || lD - LO  == 1){ // solução para andar um casa

                                 for(f;f<=lD;f++){

                              if(xadrez[f][7] == ' '){
                                    cont++;

                             }else if(xadrez[f+1][7] != ' ' ){
                                  cont1++;
                             }

                         }
                           f = LO;

                    if(((cont == (lD - f)) || (cont == ( f - lD) )) && (cont1 == 0)){

                              for(int i =0; i < 1;i++){ // ESSE lOOP CORRE SOMENTE UMA VEZ PARA CONTAR O contX lembrando que o contX e global
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                             //  printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                      }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }

                           }else{

                         for(int i =0; i < 1;i++){ // ESSE lOOP CORRE SOMENTE UMA VEZ PARA CONTAR O contX lembrando que o contX e global
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                        }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }
                        xadrez[lD][cD] = xadrez[LO][CO];
                        xadrez[LO][CO] = ' ';
                          return 1; // movimento realizado;
                           }

                   }

//=================================================================================================================
                      int   i = LO + 1;
                    if(i < lD){

                        for(i;i<lD;i++){

                           if(xadrez[i][7] == ' '){
                                cont++;

                           }else if(xadrez[i][7] != ' ' ){
                               cont1++;
                           }

                        }
                             i = LO +1;


                    if(((cont == (lD - i)) || (cont == ( i - lD) )) && (cont1 == 0)){

                                for(int i =0; i < 1;i++){ // ESSE lOOP CORRE SOMENTE UMA VEZ PARA CONTAR O contX lembrando que o contX e global
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                      }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }


                           }else{
                               printf("Não é possivel saltar sobre as peças");
                           }

                   }
//====================================================================================================================================================================================

                   if(i > lD){
                           int x = LO - 1;

                     for(x;x>lD;x--){

                        if(xadrez[x][7] == ' '){
                                cont++;

                        }else if(xadrez[x][7] != ' ' ){
                        cont1++;
                        }

                   }
                     x = LO - 1;


                    if(((cont == (lD - x)) || (cont == ( x - lD) )) && (cont1 == 0)){
                            mover = 1;


                           }else{
                               printf("Não é possivel saltar sobre as peças\n");
                           }

                   }

//============================================================================================================================================================================================

               }else if(CO == 8 ){

                            int f = LO;
                            if(LO - lD == 1 || lD - LO  == 1){ // solução para andar um casa


                                 for(f;f<=lD;f++){

                              if(xadrez[f][8] == ' '){
                                    cont++;

                             }else if(xadrez[f+1][8] != ' ' ){
                                  cont1++;
                             }

                         }
                           f = LO;
                    if(((cont == (lD - f)) || (cont == ( f - lD) )) && (cont1 == 0)){

                             for(int i =0; i < 1;i++){ // ESSE lOOP CORRE SOMENTE UMA VEZ PARA CONTAR O contX lembrando que o contX e global
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                        }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }
                           }else{

                         for(int i =0; i < 1;i++){ // ESSE lOOP CORRE SOMENTE UMA VEZ PARA CONTAR O contX lembrando que o contX e global
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                        }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }
                               xadrez[lD][cD] = xadrez[LO][CO];
                               xadrez[LO][CO] = ' ';
                               return 1; // movimento realizado;

                           }

                   }

//============================================================================================================
                      int   i = LO + 1;
                    if(i < lD){

                        for(i;i<lD;i++){

                           if(xadrez[i][8] == ' '){
                                cont++;

                           }else if(xadrez[i][8] != ' ' ){
                               cont1++;
                           }

                        }
                             i = LO +1;


                    if(((cont == (lD - i)) || (cont == ( i - lD) )) && (cont1 == 0)){

                                for(int i =0; i < 1;i++){ // ESSE lOOP CORRE SOMENTE UMA VEZ PARA CONTAR O contX lembrando que o contX e global
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                             //  printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                        }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }



                           }else{
                               printf("Não é possivel saltar sobre as peças");
                           }

                   }


                   if(i > lD){
                           int x = LO - 1;

                     for(x;x>lD;x--){

                        if(xadrez[x][8] == ' '){
                                cont++;

                        }else if(xadrez[x][8] != ' ' ){
                        cont1++;
                        }

                   }
                     x = LO - 1;

                    if(((cont == (lD - x)) || (cont == ( x - lD) )) && (cont1 == 0)){

                             for(int i =0; i < 1;i++){ // ESSE lOOP CORRE SOMENTE UMA VEZ PARA CONTAR O contX lembrando que o contX e global
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                             //  printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                          }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }


                           }else{
                               printf("Não é possivel saltar sobre as peças\n");
                           }

                   }


                            }
//=======================================================================================================================================================================================================================
//=======================================================================================================================================================================================================================
               }else if(deslocamentoHorizontal >0){ // ESSA CONDIÇÃO SERVE PARA O DESLOCAMENTO HORIZONTAL SE ELE FOR MAIOR QUE ZERO É PORQUE O DESLOCAMENTO HORIZONTAL E 1 2 3 ETC E O VERTICAL É ZERO

                   if(LO == 1){  // VERIFICANDO A LINHA 1

                          int z = CO; // z RECEBE O VALOR DO PARÂMETRO COLUNAoRIGEM

                    if(CO - cD == 1 || cD - CO  == 1){ // solução para andar um casa  COLUNA DE ORIGEM  MENOS COLUNA DE DESTINO  == 1 OU SEJA ANDA SÓ UMA CASA


                        for(z;z<=cD;z++){ // z INICIA COM O VALOR DA COLUNA ORIGEM E VAI SENDO INCREMENTADO ATÉ QUE SEJA DADA A CONDIÇÃO

                        if(xadrez[1][z] == ' '){ //linha um fixa !!! quem vai variar e a coluna linha  1 coluna z que varia de 1 a 8
                                cont++;

                             }else if(xadrez[1][z+1] != ' ' ){ // esse mais um é para ele não contar a prória peça que esta na posição inicial  lembrando que cont1 significa que tem peça ou seja não é vazio!!
                                  cont1++;
                             }

                         }
                           z = CO;


                    if(((cont == (cD - z)) || (cont == ( z - cD) )) && (cont1 == 0)){

                                for(int i =0; i < 1;i++){ // ESSE lOOP CORRE SOMENTE UMA VEZ PARA CONTAR O contX lembrando que o contX e global
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                        }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }

                           }else{

                         for(int i =0; i < 1;i++){ // ESSE lOOP CORRE SOMENTE UMA VEZ PARA CONTAR O contX lembrando que o contX e global
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                          }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }
                               xadrez[lD][cD] = xadrez[LO][CO];
                               xadrez[LO][CO] = ' ';
                               return 1; // movimento realizado;
                           }

                   }


//===================================================================================================================================================================================
                     int j = CO + 1;
                      if(j < cD){
                             for(j;j<cD;j++){

                           if(xadrez[1][j] == ' '){
                                cont++;

                           }else if(xadrez[1][j] != ' ' ){
                               cont1++;
                           }

                        }
                            j = CO + 1; // j recebe a colunaOrigem mais 1 para não contar a propria peça  que será movimnetada
                    if(((cont == (cD - j)) || (cont == ( j - cD) )) && (cont1 == 0)){ // SE A CONTIDADE DE CASAS VAZIAS FOR == A O INTERVALO DA ORIGEM MENOS O DESTINO ENTÃO  PODE MOVER
                                                                        // PORÉM SE CONT1 TIVESSE CONTADO AO MENOS UMA CASA, NÃO PODERIAMOS MOVER POIS A TORRE NÃO SALTA CASAS
                         for(int i =0; i < 1;i++){ // ESSE lOOP CORRE SOMENTE UMA VEZ PARA CONTAR O contX lembrando que o contX e global
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                               //printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                       }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }


                           }else{
                               printf("Não é possivel saltar sobre as peças");
                           }

                   }

//=======================================================================================================================================================================================================================
//=======================================================================================================================================================================================================================
                      if(j > cD){
                          int y = CO - 1;
                           for(y;y>cD;y--){ //LOOP FEITO PARA  VARIA DE UM COLUNA 8 PARA UMA MENOR POR ISSO O DECREMNETO

                           if(xadrez[1][y] == ' '){ // AGORA E A LINHA QUE ESTÁ FIXA E QUEM VARIA É A COLUNA
                                cont++; // CONT VAZIO

                           }else if(xadrez[1][y] != ' ' ){
                               cont1++; // CONT1 PEÇA
                           }

                        }
                            y = CO - 1;

                    if(((cont == (cD - y)) || (cont == ( y - cD) )) && (cont1 == 0)){

                             for(int i =0; i < 1;i++){ // ESSE lOOP CORRE SOMENTE UMA VEZ PARA CONTAR O contX lembrando que o contX e global
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                          }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }

                           }else{
                             printf(" A TORRE NAO PODE SALTAR SOBRE AS PECAS \n");

                           }

                   }




//==============================================================================================================================================================================================

             }else if(LO == 2){ // LINHA 2

                    int z = CO;

                    if(CO - cD == 1 || cD - CO  == 1){


                        for(z;z<=cD;z++){

                        if(xadrez[2][z] == ' '){
                                cont++;

                             }else if(xadrez[2][z+1] != ' ' ){ // esse mais um é para ele não contar a prória peça que esta na posição inicial  lembrando que cont1 significa que tem peça ou seja não é vazio!!
                                  cont1++;
                             }

                         }
                           z = CO;

                    if(((cont == (cD - z)) || (cont == ( z - cD) )) && (cont1 == 0)){

                              for(int i =0; i < 1;i++){ // ESSE lOOP CORRE SOMENTE UMA VEZ PARA CONTAR O contX lembrando que o contX e global
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                          }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }


                           }else{

                                 for(int i =0; i < 1;i++){ // ESSE lOOP CORRE SOMENTE UMA VEZ PARA CONTAR O contX lembrando que o contX e global
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                               //printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                          }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }

                               xadrez[lD][cD] = xadrez[LO][CO];
                               xadrez[LO][CO] = ' ';
                                return 1; // movimento realizado;
                           }

                   }

//====================================================================================================================
// A LÓGICA É A MESMA AO LONGO DA CONDIÇÃO TORRE
                    int j = CO + 1;
                      if(j < cD){ // SE A ORIGEM E MENOR  ENTÃO  LOOP
                             for(j;j<cD;j++){

                           if(xadrez[2][j] == ' '){ // LINHA FIXA  EM 2 j COLUNA VARIANDO ENTRE ORIGEM E DESTINO
                                cont++;

                           }else if(xadrez[2][j] != ' ' ){
                               cont1++;
                           }

                        }
                            j = CO + 1;

                    if(((cont == (cD - j)) || (cont == ( j - cD) )) && (cont1 == 0)){

                             for(int i =0; i < 1;i++){ // ESSE lOOP CORRE SOMENTE UMA VEZ PARA CONTAR O contX lembrando que o contX e global
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                             //  printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                        }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }


                           }else{
                               printf("Não é possivel saltar sobre as peças");
                           }

                   }

//========================================================================================================================
                      if(j > cD){ // ORIGEM MAIOR QUE DESTINO ENTÃO LOOP DE DECREMENTO
                          int y = CO - 1;
                           for(y;y>cD;y--){

                           if(xadrez[2][y] == ' '){ // LINHA FIXA EM 2
                                cont++;

                           }else if(xadrez[2][y] != ' ' ){
                               cont1++;
                           }

                        }
                            y = CO - 1;

                    if(((cont == (cD - y)) || (cont == ( y - cD) )) && (cont1 == 0)){ // SE A QUANTIDADE DE VAZIOS FOR == A COLUNA DESTINO MENOS A ORIGEM E CONT1 FOR == 0 ENTÃO MOVER

                              for(int i =0; i < 1;i++){ // ESSE lOOP CORRE SOMENTE UMA VEZ PARA CONTAR O contX lembrando que o contX e global
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                        }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }


                           }else{
                               printf("Não é possivel saltar sobre as peças");
                           }

                   }

//========================================================================================================================================================================================
             }else if(LO == 3){ // LINHA 3

                    int z = CO;

                    if(CO - cD == 1 || cD - CO  == 1){

                        for(z;z<=cD;z++){

                        if(xadrez[3][z] == ' '){
                                cont++;

                             }else if(xadrez[3][z+1] != ' ' ){ // Z + 1 PARA NÃO CONTAR A PRÓPRIA PEÇA SE  ISSO ACONTECESSE  cont 1 SERIA  CONTADO
                                  cont1++;
                             }

                         }
                           z = CO; // Z RECEBE A COLUNA DE ORIGEM

                    if(((cont == (cD - z)) || (cont == ( z - cD) )) && (cont1 == 0)){

                             for(int i =0; i < 1;i++){ // ESSE lOOP CORRE SOMENTE UMA VEZ PARA CONTAR O contX lembrando que o contX e global
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                             //  printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                          }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }


                           }else{

                          for(int i =0; i < 1;i++){ // ESSE lOOP CORRE SOMENTE UMA VEZ PARA CONTAR O contX lembrando que o contX e global
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                             //  printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                        }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }

                               xadrez[lD][cD] = xadrez[LO][CO];
                               xadrez[LO][CO] = ' ';
                               return 1; // movimento realizado;
                           }

                   }

//====================================================================================================================================================================
                   int j = CO + 1;
                      if(j < cD){
                             for(j;j<cD;j++){

                           if(xadrez[3][j] == ' '){
                                cont++;

                           }else if(xadrez[3][j] != ' ' ){
                               cont1++;
                           }

                        }
                            j = CO + 1;
                    if(((cont == (cD - j)) || (cont == ( j - cD) )) && (cont1 == 0)){

                             for(int i =0; i < 1;i++){ // ESSE lOOP CORRE SOMENTE UMA VEZ PARA CONTAR O contX lembrando que o contX e global
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                        }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }



                           }else{
                               printf("Não é possivel saltar sobre as peças");
                           }

                   }
//=====================================================================================================================================================================================================
                      if(j > cD){
                          int y = CO - 1;
                           for(y;y>cD;y--){

                           if(xadrez[3][y] == ' '){
                                cont++;

                           }else if(xadrez[3][y] != ' ' ){
                               cont1++;
                           }

                        }
                            y = CO - 1;
                       /* printf("====ttuu%d==\n\n",cont);
                        printf("====ttuu%d==\n\n",(cD - y));
                        printf("====ttuu%d===\n\n",(y - cD));*/

                    if(((cont == (cD - y)) || (cont == ( y - cD) )) && (cont1 == 0)){


                            for(int i =0; i < 1;i++){ // ESSE lOOP CORRE SOMENTE UMA VEZ PARA CONTAR O contX lembrando que o contX e global
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                          }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }


                           }else{
                               printf("Não é possivel saltar sobre as peças");
                           }

                   }

//===================================================================================================================================================================================================
            }else if(LO == 4){

                   int z = CO;

                    if(CO - cD == 1 || cD - CO  == 1){


                        for(z;z<=cD;z++){

                        if(xadrez[4][z] == ' '){
                                cont++;

                             }else if(xadrez[4][z+1] != ' ' ){
                                  cont1++;
                             }

                         }
                           z = CO;

                    if(((cont == (cD - z)) || (cont == ( z - cD) )) && (cont1 == 0)){

                               for(int i =0; i < 1;i++){ // ESSE lOOP CORRE SOMENTE UMA VEZ PARA CONTAR O contX lembrando que o contX e global
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                          }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }

                           }else{

                         for(int i =0; i < 1;i++){ // ESSE lOOP CORRE SOMENTE UMA VEZ PARA CONTAR O contX lembrando que o contX e global
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                        }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }
                    xadrez[lD][cD] = xadrez[LO][CO];
                    xadrez[LO][CO] = ' ';
                    return 1; // movimento realizado;

                           }

                   }

//===============================================================================================================================================================================================

                int j = CO + 1;
                      if(j < cD){
                             for(j;j<cD;j++){

                           if(xadrez[4][j] == ' '){
                                cont++;

                           }else if(xadrez[4][j] != ' ' ){
                               cont1++;
                           }

                        }
                            j = CO + 1;

                    if(((cont == (cD - j)) || (cont == ( j - cD) )) && (cont1 == 0)){

                             for(int i =0; i < 1;i++){ // ESSE lOOP CORRE SOMENTE UMA VEZ PARA CONTAR O contX lembrando que o contX e global
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                               //printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                          }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }


                           }else{
                               printf("Não é possivel saltar sobre as peças");
                           }

                   }

//======================================================================================================================================================================================
                      if(j > cD){
                          int y = CO - 1;
                           for(y;y>cD;y--){

                           if(xadrez[4][y] == ' '){
                                cont++;

                           }else if(xadrez[4][y] != ' ' ){
                               cont1++;
                           }

                        }
                            y = CO - 1;
                    if(((cont == (lD - y)) || (cont == ( y - lD) )) && (cont1 == 0)){

                              for(int i =0; i < 1;i++){ // ESSE lOOP CORRE SOMENTE UMA VEZ PARA CONTAR O contX lembrando que o contX e global
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX = contX + 1 ; // contado global
                            //   printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                      }else{
                         mover = 1; // MOVIMENTO NORMAL
                          }
                     }

                           }else{
                               printf("Não é possivel saltar sobre as peças");
                           }

                   }
//================================================================================================================================================================================================
            }else if(LO == 5){ // LINHA 5

                   int z = CO;

                    if(CO - cD == 1 || cD - CO  == 1){ // SE ESSA CONDIÇÃO FOR VERDADEIRA ENTÃO O MOVIMENTO DA PEÇA SERÁ 1


                        for(z;z<=cD;z++){ // VAI CONTAR DA ORIGEM ATÉ O DESTINO XEMPLO  CASA 1 ATAÉ A CASA 2

                        if(xadrez[5][z] == ' '){
                                cont++;

                             }else if(xadrez[5][z+1] != ' ' ){ // esse mais um é para ele não contar a prória peça que esta na posição inicial  lembrando que cont1 significa que tem peça ou seja não é vazio!!
                                  cont1++;
                             }

                         }
                           z = CO;
                    if(((cont == (cD - z)) || (cont == ( z - cD) )) && (cont1 == 0)){

                         for(int i =0; i < 1;i++){ // ESSE lOOP CORRE SOMENTE UMA VEZ PARA CONTAR O contX lembrando que o contX e global
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                             //  printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                        }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }


                           }else{

                        for(int i =0; i < 1;i++){ // ESSE lOOP CORRE SOMENTE UMA VEZ PARA CONTAR O contX lembrando que o contX e global
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                            //   printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                      }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }
                         xadrez[lD][cD] = xadrez[LO][CO];
                         xadrez[LO][CO] = ' ';
                          return 1; // movimento realizado;
                           }

                   }

//============================================================================================================================================================================================

                int j = CO + 1;
                      if(j < cD){
                             for(j;j<cD;j++){

                           if(xadrez[5][j] == ' '){
                                cont++;

                           }else if(xadrez[5][j] != ' ' ){
                               cont1++;
                           }

                        }
                            j = CO + 1;

                    if(((cont == (cD - j)) || (cont == ( j - cD) )) && (cont1 == 0)){

                             for(int i =0; i < 1;i++){ // ESSE lOOP CORRE SOMENTE UMA VEZ PARA CONTAR O contX lembrando que o contX e global
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                             //  printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                        }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }


                    }else{
                        printf("Não é possivel saltar sobre as peças");
                           }

                   }
//==================================================================================================================================================================================================
                      if(j > cD){
                          int y = CO - 1;
                           for(y;y>cD;y--){

                           if(xadrez[5][y] == ' '){
                                cont++;

                           }else if(xadrez[5][y] != ' ' ){
                               cont1++;
                           }

                        }
                            y = CO - 1;
                    if(((cont == (cD - y)) || (cont == ( y - cD) )) && (cont1 == 0)){

                        for(int i =0; i < 1;i++){ // ESSE lOOP CORRE SOMENTE UMA VEZ PARA CONTAR O contX lembrando que o contX e global
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                            //   printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                        }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }

                           }else{
                               printf("Não é possivel saltar sobre as peças");
                           }

                   }
//===========================================================================================================================================================================================================
            }else if(LO == 6){

                   int z = CO;

                    if(CO - cD == 1 || cD - CO  == 1){

                        for(z;z<=cD;z++){

                        if(xadrez[6][z] == ' '){
                                cont++;

                             }else if(xadrez[6][z+1] != ' ' ){
                                  cont1++;
                             }

                         }
                           z = CO;
                    if(((cont == (cD - z)) || (cont == ( z - cD) )) && (cont1 == 0)){

                         for(int i =0; i < 1;i++){ // ESSE lOOP CORRE SOMENTE UMA VEZ PARA CONTAR O contX lembrando que o contX e global
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                          //     printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                        }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }

                           }else{

                         for(int i =0; i < 1;i++){ // ESSE lOOP CORRE SOMENTE UMA VEZ PARA CONTAR O contX lembrando que o contX e global
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                             //  printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                        }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }
                               xadrez[lD][cD] = xadrez[LO][CO];
                               xadrez[LO][CO] = ' ';
                              return 1; // movimento realizado;

                           }

                   }
//======================================================================================================================================
                int j = CO + 1;
                      if(j < cD){
                             for(j;j<cD;j++){

                           if(xadrez[6][j] == ' '){
                                cont++;

                           }else if(xadrez[6][j] != ' ' ){
                               cont1++;
                           }

                        }
                            j = CO + 1;

                    if(((cont == (cD - j)) || (cont == ( j - cD) )) && (cont1 == 0)){

                          for(int i =0; i < 1;i++){ // ESSE lOOP CORRE SOMENTE UMA VEZ PARA CONTAR O contX lembrando que o contX e global
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                            //   printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                         }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                          }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }


                           }else{
                               printf("Não é possivel saltar sobre as peças");
                           }

                   }
//============================================================================================================================================================================================
                      if(j > cD){
                          int y = CO - 1;
                           for(y;y>cD;y--){

                           if(xadrez[6][y] == ' '){
                                cont++;

                           }else if(xadrez[6][y] != ' ' ){
                               cont1++;
                           }

                        }
                            y = CO - 1;

                    if(((cont == (cD - y)) || (cont == ( y - cD) )) && (cont1 == 0)){

                          for(int i =0; i < 1;i++){ // ESSE lOOP CORRE SOMENTE UMA VEZ PARA CONTAR O contX lembrando que o contX e global
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                        }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }

                           }else{
                               printf("Não é possivel saltar sobre as peças");
                           }

                   }
//==============================================================================================================================================================================================
            }else if(LO == 7){

                   int z = CO;

                    if(CO - cD == 1 || cD - CO  == 1){ // solução para andar um casa


                        for(z;z<=cD;z++){

                        if(xadrez[7][z] == ' '){
                                cont++;

                             }else if(xadrez[7][z+1] != ' ' ){ // esse mais um é para ele não contar a prória peça que esta na posição inicial  lembrando que cont1 significa que tem peça ou seja não é vazio!!
                                  cont1++;
                             }

                         }
                           z = CO;

                    if(((cont == (cD - z)) || (cont == ( z - cD) )) && (cont1 == 0)){

                          for(int i =0; i < 1;i++){ // ESSE lOOP CORRE SOMENTE UMA VEZ PARA CONTAR O contX lembrando que o contX e global
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                        }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }


                           }else{

                                  for(int i =0; i < 1;i++){ // ESSE lOOP CORRE SOMENTE UMA VEZ PARA CONTAR O contX lembrando que o contX e global
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                               //printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                        }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }
                               xadrez[lD][cD] = xadrez[LO][CO];
                               xadrez[LO][CO] = ' ';
                               return 1; // movimento realizado;

                           }

                   }

//===================================================================================================================================
//===================================================================================================================================
                 int j = CO + 1;
                      if(j < cD){
                             for(j;j<cD;j++){

                           if(xadrez[7][j] == ' '){
                                cont++;

                           }else if(xadrez[7][j] != ' ' ){
                               cont1++;
                           }

                        }
                            j = CO + 1;

                    if(((cont == (cD - j)) || (cont == ( j - cD) )) && (cont1 == 0)){

                              for(int i =0; i < 1;i++){ // ESSE lOOP CORRE SOMENTE UMA VEZ PARA CONTAR O contX lembrando que o contX e global
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                          }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }

                           }else{
                               printf("Não é possivel saltar sobre as peças");
                           }

                   }
//=======================================================================================================================================
                      if(j > cD){
                          int y = CO - 1;
                           for(y;y>cD;y--){

                           if(xadrez[7][y] == ' '){
                                cont++;

                           }else if(xadrez[7][y] != ' ' ){
                               cont1++;
                           }

                        }
                            y = CO - 1;

                    if(((cont == (cD - y)) || (cont == ( y - cD) )) && (cont1 == 0)){

                                   for(int i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                      }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }


                           }else{
                               printf("Não é possivel saltar sobre as peças");
                           }

                   }


//======================================================================================================================================================================================
            }else if(LO == 8){ // LINHA 8

                   int z = CO;

                    if(CO - cD == 1 || cD - CO  == 1){


                        for(z;z<=cD;z++){

                        if(xadrez[8][z] == ' '){
                                cont++;

                             }else if(xadrez[8][z+1] != ' ' ){
                                  cont1++;
                             }

                         }
                           z = CO;

                    if(((cont == (cD - z)) || (cont == ( z - cD) )) && (cont1 == 0)){

                        for(int i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                             //  printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                       }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }

                           }else{

                         for(int i =0; i < 1;i++){ // ESSE lOOP CORRE SOMENTE UMA VEZ PARA CONTAR O contX lembrando que o contX e global
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                             //  printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                      }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }
                               xadrez[lD][cD] = xadrez[LO][CO];
                               xadrez[LO][CO] = ' ';
                               return 1; // movimento realizado;

                           }

                   }

//===================================================================================================================================================
                 int j = CO + 1;
                      if(j < cD){
                             for(j;j<cD;j++){

                           if(xadrez[8][j] == ' '){
                                cont++;

                           }else if(xadrez[8][j] != ' ' ){
                               cont1++;
                           }

                        }
                            j = CO + 1;


                    if(((cont == (cD - j)) || (cont == ( j - cD) )) && (cont1 == 0)){

                          for(int i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX = contX + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                        }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }


                           }else{
                               printf("Não é possivel saltar sobre as peças");
                           }

                   }
//=======================================================================================================================================================================
                      if(j > cD){
                          int y = CO - 1;
                           for(y;y>cD;y--){

                           if(xadrez[8][y] == ' '){
                                cont++;

                           }else if(xadrez[8][y] != ' ' ){
                               cont1++;
                           }

                        }
                            y = CO - 1;

                    if(((cont == (cD - y)) || (cont == ( y - cD) )) && (cont1 == 0)){

                                  for(int i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k'){
                              contX1 = contX1 + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX1);
                            if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 'T' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                        }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }

                           }else{
                               printf("Não é possivel saltar sobre as peças");
                           }

                   }


            }

              }
        }

//===================================================================================================================================================
//==========================================================BISPO====================================================================================
//===================================================================================================================================================
// A LOGICA DO BISPO É FAZER COM QUE O DESLOCAMENTO HORIZONTAL SEJA IGUAL AO VERTICALL
// SE xadrez[LO][CO] NA LINHA  DE ORIGEM  COLUNA DE ORIGEM  FOR IGUAL == B E  xadrez[lD][cD]  NA LINHA DE DESTINO E COLUNA DE DESTINO  FOR  IGUAL == A VAZIO OU  || IGUAL A QUALQUER PEÇA  MINUSCULA QUE SÃO AS PRETAS
// ENTÃO ELE PODE COMER  E MOVER


          if(( xadrez[LO][CO] == 'B' && xadrez[lD][cD] == ' ') || (xadrez[LO][CO] == 'B' && xadrez[lD][cD] == 'p')
             || (xadrez[LO][CO] == 'B' && xadrez[lD][cD] == 't') || (xadrez[LO][CO] == 'B' && xadrez[lD][cD] == 'b') ||
             (xadrez[LO][CO] == 'B' && xadrez[lD][cD] == 'c') || (xadrez[LO][CO] == 'B' && xadrez[lD][cD] == 'q') ||
             (xadrez[LO][CO] == 'B' && xadrez[lD][cD] == 'k')&& (deslocamentoVertical == deslocamentoHorizontal)) { //SE ELE SE MOVER UM NAVERTICAL SERA  UM  NA HORIZONTAL TAMBÉM

                    for(int i =0; i < 1;i++){ // LAÇO CRIADO PARA  CONTAR QUANTAS VEZES  B MIROU O REI
                     if(xadrez[LO][CO] == 'B' && xadrez [lD][cD] == 'k'){
                         contX1 = contX1 + 1 ; // contado global
                     // printf("=========yyyyy%d========",contX1);
                      if(xadrez[LO][CO] == 'B' && xadrez [lD][cD] == 'k' && contX1 == 1){ // XEQUE

                            return 4; // XEQUE



                  }else if(xadrez[LO][CO] == 'B' && xadrez [lD][cD] == 'k' && contX1 == 2 ){ // SE A PESSOA  NÃO DESVIAR O REI E A PEÇA ATACAR  O REI E XEQUE MATE
                      mover = 1;
                             if(mover == 1){
                    xadrez[lD][cD] = xadrez[LO][CO];
                    xadrez[LO][CO] = ' ';
                   return 3; // RETORNO DO XEQUE -MATE
                  }
               }
             }else{

              mover = 1; // MOVIMENTO NORMAL
                }
        }


    }

    //====================================================CAVALO==================================================================================
// A LÓGICA DO CAVALO  É  O DESLOCAMENTO EM L PODENDO SALTAR  SOBRE AS PEÇAS
// SE O DESLOCAMENTO EM VERTICAL linhaOrigem - linha Destino for igual a 1 E O DESLOCAMENTO  horizontal for igual  dois  então temos  UM MOVIMENTO EM L
// o mesmo pode ser feito ao contrário  HÁ TAMBÉM  O JOGO DOS OPERADORES LÓGICOS  && ||   SENDO QUE CAVALO  que é c maiúsculo só pode mover para o vazio ou   atacar as peças  MINÚSCULAS
          if(((xadrez[LO][CO] == 'C') && (xadrez[lD][cD] == ' ') || (xadrez[LO][CO] == 'C') && ( xadrez[lD][cD] == 'p') ||
             (xadrez[LO][CO] == 'C') && (xadrez[lD][cD] == 't') || (xadrez[LO][CO] == 'C') && ( xadrez[lD][cD] == 'c') ||
             (xadrez[LO][CO] == 'C') && (xadrez[lD][cD] == 'b') || (xadrez[LO][CO] == 'C') && (xadrez[lD][cD] == 'q') ||
             (xadrez[LO][CO] == 'C' && xadrez[lD][cD] == 'k'))
              && (deslocamentoVertical == 1) && (deslocamentoHorizontal == 2) ||(deslocamentoHorizontal == 1) &&(deslocamentoVertical == 2)){
                 if(xadrez[LO][CO]!='P'){

                                     for(int i =0; i < 1;i++){
                     if(xadrez[LO][CO] == 'C' && xadrez [lD][cD] == 'k'){
                         contX1 = contX1 + 1 ; // contado global
                   //   printf("=========yyyyy%d========",contX1);
                      if(xadrez[LO][CO] == 'C' && xadrez [lD][cD] == 'k' && contX1 == 1){

                            return 4; // XEQUE



                  }else if(xadrez[LO][CO] == 'C' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                      mover = 1;
                             if(mover == 1){
                    xadrez[lD][cD] = xadrez[LO][CO];
                    xadrez[LO][CO] = ' ';
                   return 3; // RETORNO DO XEQUE -MATE
                  }
               }
             }else{

              mover = 1; // MOVIMENTO NORMAL
                }
        }






                 }


          }

//===========================================RAINHA=================================================================================================
//==================================================================================================================================================
//O MOVIMENTO DA RAINMHA É  A UNIÃO  DO MOVEIMENTO DA TORRE COM O BISPO OU SEJA, SE O DESLOCAMENTO  VERTICAL FOR IGUAL AO  HORIZONTAL OU SE
// O DESLOCAMENTO VERTICAL  FOR == A ZERO OU SE O DESLOCAMENTO HORIZAONTAL FOR IGUAL A ZERO

          if((xadrez[LO][CO] == 'Q' && xadrez[lD][cD] == ' ') || (xadrez[LO][CO] == 'Q' && xadrez[lD][cD] == 'p') ||
              (xadrez[LO][CO] == 'Q' && xadrez[lD][cD] == 't') || (xadrez[LO][CO] == 'Q' && xadrez[lD][cD] == 'c') ||
             (xadrez[LO][CO] == 'Q' && xadrez[lD][cD] == 'b') || (xadrez[LO][CO] == 'Q' && xadrez[lD][cD] == 'q') ||
             (xadrez[LO][CO] == 'Q' && xadrez[lD][cD] == 'k') && ((deslocamentoVertical == deslocamentoHorizontal) || (deslocamentoVertical == 0) || (deslocamentoHorizontal == 0))){

                  for(int i =0; i < 1;i++){
                     if(xadrez[LO][CO] == 'Q' && xadrez [lD][cD] == 'k'){
                         contX1 = contX1 + 1 ; // contado global
                    //  printf("=========yyyyy%d========",contX1);
                      if(xadrez[LO][CO] == 'Q' && xadrez [lD][cD] == 'k' && contX1 == 1){

                            return 4; // XEQUE

// função dom contX1 e ver quantas  vezes  a peça mira o rei K se ele for contado 1 vez xeque 2

                  }else if(xadrez[LO][CO] == 'Q' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                      mover = 1;
                             if(mover == 1){
                    xadrez[lD][cD] = xadrez[LO][CO];
                    xadrez[LO][CO] = ' ';
                   return 3; // RETORNO DO XEQUE -MATE
                  }
               }
             }else{

              mover = 1; // MOVIMENTO NORMAL
                }
        }

          }

//========================================REI===============================================================================================================
//==========================================================================================================================================================
// A PEÇA REI K SÓ PODE SE DESLOCAR  OU 1 NA HORIZONTAL OU 1 NA VERTICAL  EPRA TAL
          if ((((xadrez[LO][CO] == 'K') &&(xadrez[lD][cD] == ' ') || (xadrez[LO][CO] == 'K') && (xadrez[lD][cD] == 'p') ||
              (xadrez[LO][CO] == 'K') && (xadrez[lD][cD] == 't') || (xadrez[LO][CO] == 'K') && xadrez[lD][cD] == 'c') ||
             (xadrez[LO][CO] == 'K') && (xadrez[lD][cD] == 'b') || (xadrez[LO][CO] == 'K') && xadrez[lD][cD] == 'q') ||
             (xadrez[LO][CO] == 'K') && (xadrez[lD][cD] == 'k')){

                if(((deslocamentoVertical >=0) && (deslocamentoVertical <=1) && deslocamentoHorizontal >=0 )&& (deslocamentoHorizontal <=1 )){ // O MOVIMENTO  SO E UMA CASA POR VEZ


                  for(int i =0; i < 1;i++){ // LOOP  QUE VAI DE 0 A 1
                     if(xadrez[LO][CO] == 'K' && xadrez [lD][cD] == 'k'){ // O LOOP E FEITO PARA VER  QUANTAS  VEZES O K REI FOI MIRADO  EE FAZEMOS ISSO ATRAVEZ DO CONTADOR
                         contX1 = contX1 + 1 ; // contado global
                    //  printf("=========yyyyy%d========",contX1);
                      if(xadrez[LO][CO] == 'K' && xadrez [lD][cD] == 'k' && contX1 == 1){

                            return 4; // XEQUE



                  }else if(xadrez[LO][CO] == 'K' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                      mover = 1;
                             if(mover == 1){
                    xadrez[lD][cD] = xadrez[LO][CO];
                    xadrez[LO][CO] = ' ';
                   return 3; // RETORNO DO XEQUE -MATE
                  }
               }
             }else{
              mover = 1; // MOVIMENTO NORMAL
                }
        }


              }else{
                  printf("MOVIMENTO INVALIDO ! \n");
                printf("REFACA A JOGADA ! \n");
                jogadaBancada();
                inversao();
              }


          }


//======================MOVIMENTO DOS PEÕES======================================================================================================================
//===============================================================================================================================================================
// OS PEÕES SÓ PODEM SE MOVER NA  VERTICAL  SENDO O PRIMEIRO MOVIMENTO DE DUAS CASAS OU DE UMA CASA
// E O SEGUNDO APENAS DE UMA EM UMA CASA
          if((peca == 'P') && ((lD - LO) == 1) && (deslocamentoHorizontal == 0)){// SE A linhaDestino menos A linhaOrigem  for igual A  1 ENTÃO DESLOCAMENTO É DE UMA CASA NA VERTICAL CRESCETE TIPO 1 2 3 4  ETC

              if(xadrez[LO][CO] == 'P' && xadrez[lD][cD] == ' '){
                  mover = 1;   // O MOVIMENTO DAS PEÇAS BRANCAS  E CRESCETE DE CIMA PARA BAIXO 1 2 3 4 5 6 7 8  ETC
              }

          }else if((xadrez[2][1] == 'P' && LO == 2 && CO == 1 && lD == 4 && cD == 1)&& ((lD - LO) == 2) && (deslocamentoHorizontal == 0)){ // SE A linhaDestino menos A linhaOrigem  for igual A  2  ENTÃO ELE PODERAR SALTAR DUAS CASAS
                          // VEJA QUE O PEÃO SO PODE ANDAR DUAS CASAS UMA ÚNICA VEZ JÁ QUE AS POSIÇÕES DA MATRIZ ESTÃO TRAVADAS  TANTO NA ORIGEM QUANTO DUAS CASAS A FRENTE  E A LOGICA É AMESMA  PARA TODOS  OS PEÕES  SÓ É ALTENADO AS LETRAS
                         // ENTRE P branca maíuscula e PRETA p minúscula
                if(xadrez[LO][CO] == 'P' && xadrez[lD][cD] == ' '){
                       mover = 1;   // O MOVIMENTO DAS PEÇAS BRANCAS  E CRESCETE DE CIMA PARA BAIXO 1 2 3 4 5 6 7 8  ETC
              }

          }else if(( xadrez[2][2] == 'P' && LO == 2 && CO == 2 && lD == 4 && cD == 2 )&& ((lD - LO) == 2) && (deslocamentoHorizontal == 0)){ // linha 2 coluna 2 para linha 4 coluna 2

              if(xadrez[LO][CO] == 'P' && xadrez[lD][cD] == ' '){
                  mover = 1;   // O MOVIMENTO DAS PEÇAS BRANCAS  E CRESCETE DE CIMA PARA BAIXO 1 2 3 4 5 6 7 8  ETC
              }


          }else if((xadrez[2][3] == 'P' && LO == 2 && CO == 3 && lD == 4 && cD == 3)&& ((lD - LO) == 2) && (deslocamentoHorizontal == 0)){

              if(xadrez[LO][CO] == 'P' && xadrez[lD][cD] == ' '){
                  mover = 1;   // O MOVIMENTO DAS PEÇAS BRANCAS  E CRESCETE DE CIMA PARA BAIXO 1 2 3 4 5 6 7 8  ETC
              }

          }else if(( xadrez[2][4] == 'P' && LO == 2 && CO == 4 && lD == 4 && cD == 4)&& ((lD - LO) == 2) && (deslocamentoHorizontal == 0)){

                if(xadrez[LO][CO] == 'P' && xadrez[lD][cD] == ' '){
                  mover = 1;
              }

          }else if(( xadrez[2][5] == 'P'  && LO == 2 && CO == 5 && lD == 4 && cD == 5)&& ((lD - LO) == 2) && (deslocamentoHorizontal == 0)){

                 if(xadrez[LO][CO] == 'P' && xadrez[lD][cD] == ' '){
                  mover = 1;
              }

          }else if((xadrez[2][6] == 'P'  && LO == 2 && CO == 6 && lD == 4 && cD == 6)&& ((lD - LO) == 2) && (deslocamentoHorizontal == 0)){

                  if((xadrez[LO][CO] == 'P') &&( xadrez[lD][cD] == ' ')){
                  mover = 1;
              }


          }else if((xadrez[2][7] == 'P' && LO == 2 && CO == 7 && lD == 4 && cD == 7)&& ((lD - LO) == 2) && (deslocamentoHorizontal == 0)){

                  if(xadrez[LO][CO] == 'P' && xadrez[lD][cD] == ' '){
                  mover = 1;
              }


          }else if((xadrez[2][8] == 'P'  && LO == 2 && CO == 8 && lD == 4 && cD == 8)&& ((lD - LO) == 2) && (deslocamentoHorizontal == 0)){

                   if(xadrez[LO][CO] == 'P' && xadrez[lD][cD] == ' '){
                  mover = 1;
              }

          }
              if(((xadrez[LO][CO] == 'P' && xadrez[lD][cD] == 'p' || xadrez[lD][cD] == 't' || xadrez[lD][cD] == 'b' || xadrez[lD][cD] == 'c' || xadrez[lD][cD] == 'q' || xadrez[lD][cD] == 'k')
               && (lD - LO) == 1) && (deslocamentoVertical == deslocamentoHorizontal)){
 // SE USARMOS A CONDIÇÃO DO BISPO LIMITADA POR UM TIPO deslocamentoVertical == deslocamentoHorizontal E LINHA DESTINO MENOS A LINHA ORIGEM == 1 ENTÃO TEMOS  O MOVIMENTO DE ATAQUE DO PEAO  PARA O LADO  EM 1
 // ATENTE PARA O JOGO COM OS OPERADORES LÓGICOS && ||

                     for(int i =0; i < 1;i++){
                     if(xadrez[LO][CO] == 'P' && xadrez [lD][cD] == 'k'){
                         contX1 = contX1 + 1 ; // contado global
                     // printf("=========yyyyy%d========",contX1);
                      if(xadrez[LO][CO] == 'P' && xadrez [lD][cD] == 'k' && contX1 == 1){

                            return 4; // XEQUE



                  }else if(xadrez[LO][CO] == 'P' && xadrez [lD][cD] == 'k' && contX1 == 2 ){
                      mover = 1;
                             if(mover == 1){
                    xadrez[lD][cD] = xadrez[LO][CO];
                    xadrez[LO][CO] = ' ';
                   return 3; // RETORNO DO XEQUE -MATE
                  }
               }
             }else{
               mover = 1; // MOVIMENTO NORMAL
                }
        }

               }



//==================================================================MINUSCULAS PRETAS=============================================================================================================================================
    }else {
        printf("ERRO ! VOCE ESTA TENTANDO MOVER UMA PECA QUE NAO E BRANCA \n");
         getch();// a instrução getch() vai travar a tela para que a menssagem não pesse rápido sem que o jogador note
                 printf("POR FAVOR FACA UMA JOGADA VALIDA \n");
                   mostrarMatriz(); // SERÁ ATUALIZADA  A MATRIZ APÓS A JOGADA !!!
                   jogadaBancada();
                     inversao(); // E POR FIM TROCAMOS OS VALORES DE BRANCAS E PRETAS !!
    }


        }else if(valor ==1){
            printf("ERRO ! O JOGADOR DAS PECAS BRANCAS NAO PODE  MOVER AS PECAS PRETAS \n");
            printf("faca uma jogada valida !\n");
             getch();
              mostrarMatriz(); // SERÁ ATUALIZADA  A MATRIZ APÓS A JOGADA !!! ATUALIZA O JOGO
              jogadaBancada(); // TODA AS VEZES QUE HOUVER UMA  JOGADA,  LOGO APOS A EXECUÇÃO  DO METODO DEVE SER EVOCADO O MÉTODO INVERSÃO  PARA QUE POSSA TROCAR OS VALORES SE ISSO NÃO FOR FEITO  AVERÁ JOGADAS REPETIDAS
            inversao(); // E POR FIM TROCAMOS OS VALORES DE BRANCAS E PRETA



        }

// ===============CODIÇÃO MOVER ============================================================================================================================================================
               if(mover == 1){
        xadrez[lD][cD] = xadrez[LO][CO];
        xadrez[LO][CO] = ' ';
               return 1; // movimento realizado;
          } else{
              return 9; // peça não ode ser mechida
          }



      }else {
          return 0;
      }
}

//========PRETAS=================================================================================================================================================================================================================
int moverpecaPreta(int LO ,int CO, int lD,int cD,int valor){
    // A CADA CHAMADA AS VARIÁVEIS SÃO REINICIADAS!
    // ESTÃO SENDO RECEBIDOS OS VALORES  DOS ARGUMENTOS "{ linhaOrigem colunaOrigem linhaDestino colunaDestino } PARA OS PARÂMENTROS { LO , CO , lD ,cD}
    int mover;
     char peca;

    //O DESLOCAMNETO VERTICAL SERÁ A SUBTRAÇÃO DA LINHA DE DESTINO MENOS A LINHA DE ORIGEM. EXEMPLO{ LINHA 1 PARA LINHA 3} OPERAÇÃO SERÁ (3 - 1 QUE E == 2 CASAS) DESTINO MENOS ORIGEM.
    int deslocamentoVertical = abs(lD - LO); //ABS VALOR ABSOLUTO
      //printf("\n\n%d\n\n",deslocamentoVertical);
      //O DESLOCAMENTO HORIZONTAL SERÁ  A SUBTRÇÃO DA COLUNA DE DESTINO MENOS A COLUNA DE ORIGEM EXEMPLO (4 - 2 == 2 CASAS)
    int deslocamentoHorizontal = abs(cD - CO);
      //printf("%d %d %d %d ",LO,CO,lD,cD);
//printf("====TTTTTT%dTTTTTT=====",valor);
      if( ((LO >=1 && LO <=8) && (CO >=1 && CO <=8)) && (lD >=1 && lD <=8) && (cD >=1 && cD <=8)){// SÓ SERÃO ACEITOS OS VALORES ENTRE 1 E 8 TANTO PARA O DESTINO QUANTO PARA A ORIGEM
          // JÁ QUE O TABULEIRO ONDE AS PEÇAS IRÃO SE MOVER E UMA MATRIZ QUE VARIA  ENTRE 1 E 8  SENDO [8]POR [8]
             peca = xadrez[LO][CO];

                      if((valor == 0) && (xadrez[LO][CO] == 't' || xadrez[LO][CO] == 'c' || xadrez[LO][CO] == 'b' || xadrez[LO][CO] == 'q' || xadrez[LO][CO] == 'p' || xadrez[LO][CO] == 'k')){


            if((valor == 0) && (xadrez[LO][CO] == 't' || xadrez[LO][CO] == 'c' || xadrez[LO][CO] == 'b' || xadrez[LO][CO] == 'q' || xadrez[LO][CO] == 'p' || xadrez[LO][CO] == 'k')){ //se for preta entre minuscula entrad nessa condição

//=======================================torre preta minuscula=====================================================================================================================================================================
//================================================================================================================================================================================================================================
              if(( xadrez[LO][CO] == 't' && xadrez[lD][cD] == ' ') || (xadrez[LO][CO] == 't' && xadrez[lD][cD] == 'P') ||
                 (xadrez[LO][CO] == 't' && xadrez[lD][cD] == 'T') || (xadrez[LO][CO] == 't' && xadrez[lD][cD] == 'B') || (xadrez[LO][CO] == 't' && xadrez[lD][cD] == 'C')
                  || (xadrez[LO][CO] == 't' && xadrez[lD][cD] == 'Q') || (xadrez[LO][CO] == 't' && xadrez[lD][cD] == 'K')
                && (deslocamentoVertical == 0 || deslocamentoHorizontal == 0)){

                 int cont = 0;
                     int cont1 = 0;

// AS MESMAS  CONDIÇÃO LOOP E ITERAÇÕES VALIDAS PARA T  maiúsculas  QUE É A TORRE  CABRANCA  VALE PARA AS PRETAS  torre minuscula t

                           if(deslocamentoVertical >0){

                            if(CO == 1){ // QUEM VAI VARIAR  É ALINHA  A COLUNA ESTÁ FIXA
                                    int f = LO;
                                if(LO - lD == 1 || lD - LO  == 1){ // solução para andar um casa  // NESTA CONDIÇÃO  LIMITA A TORRE  ANDAR UMA CASA E ´SO UMA CASA


                                 for(f;f<=lD;f++){

                              if(xadrez[f][1] == ' '){
                                    cont++;

                             }else if(xadrez[f+1][1] != ' ' ){
                                  cont1++;
                             }

                         }
                           f = LO;


                    if(((cont == (lD - f)) || (cont == ( f - lD) )) && (cont1 == 0)){

                             for(int i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                              contX = contX + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                            }
                        }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }


                }else{
                   xadrez[lD][cD] = xadrez[LO][CO];
                   xadrez[LO][CO] = ' ';
                   return 1; // movimento realizado;
                    }

                   }

//==============================================================================================================================

                                     int   i = LO+1;
                                    if(i < lD){


                                 for(i;i<lD;i++){

                        if(xadrez[i][1] == ' '){
                                cont++;

                        }else if(xadrez[i][1] != ' ' ){
                        cont1++;
                        }

                    }
                      i = LO+1;


                    if(((cont == (lD - i)) || (cont == ( i - lD) )) && (cont1 == 0)){

                            for(int i =0; i < 1;i++){

                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                              contX = contX + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                        }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }



                           }else{
                               printf("Não é possivel saltar sobre as peças");
                           }

                   }

                   if(i > lD){
                           int x = LO - 1;

                     for(x;x>lD;x--){

                        if(xadrez[x][1] == ' '){
                                cont++;

                        }else if(xadrez[x][1] != ' ' ){
                        cont1++;
                        }

                   }
                     x = LO - 1;
                 /*  printf("====ttuu%d==\n\n",cont);
                   printf("====ttuu%d==\n\n",(lD -x));
                   printf("====ttuu%d===\n\n",(x - lD));*/

                    if(((cont == (lD - x)) || (cont == ( x - lD) )) && (cont1 == 0)){

                            for(int i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                              contX = contX + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                        }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }



                           }else{
                               printf("Não é possivel saltar sobre as peças\n");
                           }

                   }

//===========================================================================================================================
                  }else if(CO == 2){// COLUNA 2

                                int f = LO;
                    if(LO - lD == 1 || lD - LO  == 1){


                                 for(f;f<=lD;f++){

                              if(xadrez[f][2] == ' '){
                                    cont++;

                             }else if(xadrez[f+1][2] != ' ' ){
                                  cont1++;
                             }

                         }
                           f = LO; // f RECEBE A LINHA  DE ORIGEM

                    if(((cont == (lD - f)) || (cont == ( f - lD) )) && (cont1 == 0)){


                        for(int i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){ // SE ESSA CONDIÇÃO FOR VERDADEIRA ENTÃO ELE ENCHERGA  O CONTx, CASO ELE  SEJA CONTADO 1 VEZ E PORQUE  ESTA EM XEQUE  SE FOR DUAS VEZES E XEQUE-MATE
                              contX = contX + 1 ; // contado global                // O CONTADOR  contX SO EXISTE DENTRO DA CONDIÇÃO  XEQUE E XEQUE-MATE
                              // printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                            }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                    }else{
                       mover = 1; // MOVIMENTO NORMAL
                          }
                     }



                           }else{

                                 xadrez[lD][cD] = xadrez[LO][CO];
                               xadrez[LO][CO] = ' ';
                               return 1; // movimento realizado;

                           }

                   }

 //============================================================================================================
 //=============================================================================================================
                         int   i = LO + 1; // linhaOrigem + 1 PARA NÃO CONTAR A PRÓPRIA PEÇA JÁ QUE QUEREMOS SÓ O INTERVAMO ENTRE A ORIGEM E DESTINO
                        if(i < lD){

                        for(i;i<lD;i++){ // COMO i ORIGEM E MENOR QUE O DESTINO ENTÃO O LOOP será  UM INCREMENTO

                        if(xadrez[i][2] == ' '){
                                cont++; //CONT VAIZO

                        }else if(xadrez[i][2] != ' ' ){
                        cont1++; // contador para peças
                        }

                    }
                      i = LO +1;

                    if(((cont == (lD - i)) || (cont == ( i - lD) )) && (cont1 == 0)){

                         for(int i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                              contX = contX + 1 ; // contado global
                             //  printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                        }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }



                           }else{
                               printf("Não é possivel saltar sobre as peças");
                           }

                   }

//==========================================================================================================================================================================
                   if(i > lD){ // ORIGEM MAIOR QUER O DESTINO NESSE CASO SERÁ FEITO UM LOOP DE DECREMENTO !
                    int x = LO - 1; // SE A PEÇAS ESTÁ NA CASA 8 E QUEREMOS O INTERVALO ENTRE 8 E 1  ENTÃO A POSIÇÃO 8 NÃO CONTA  POR ISSO O - 1

                    for(x;x>lD;x--){

                    if(xadrez[x][2] == ' '){
                                cont++;

                    }else if(xadrez[x][2] != ' ' ){
                        cont1++;
                        }

                   }
                     x = LO - 1;

                    if(((cont == (lD - x)) || (cont == ( x - lD) )) && (cont1 == 0)){

                             for(int i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                              contX = contX + 1 ; // contado global
                             //  printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                        }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }


                }else{
                    printf("Não é possivel saltar sobre as peças\n");
                     }

                   }
//===========================================================================================================================================================================
                 }else if(CO == 3){ // COLUNA 3
// ESSE PRIMEIRA PARTE PERMITE A TORRE ANDAR UMA CASA
                                int f = LO;
                                if(LO - lD == 1 || lD - LO  == 1){


                                 for(f;f<=lD;f++){ // DE 1 PARA 2

                              if(xadrez[f][3] == ' '){
                                    cont++;

                             }else if(xadrez[f+1][3] != ' ' ){
                                  cont1++;
                             }

                         }
                           f = LO;

                    if(((cont == (lD - f)) || (cont == ( f - lD) )) && (cont1 == 0)){

                              for(int i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                              contX = contX + 1 ; // contado global
                             //  printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                        }else{
                          mover = 1; // MOVIMENTO NORMAL
                          }
                     }



                           }else{
                                xadrez[lD][cD] = xadrez[LO][CO];
                               xadrez[LO][CO] = ' ';
                          return 1; // movimento realizado;
                           }

                   }


//===========================================================================================================================================================================================================
//============================================================================================================================================================================================================
                        int   i = LO + 1;
                    if(i < lD){
// NESTA PARTE DA COLUNA 3  PERMITIRÁ A TORRE ANDAR VARIAS CASAS DESDE QUE ELA SE VERTICAL E POSITIVA SENDO ORIGEM < QUE DESTINO
                        for(i;i<lD;i++){

                           if(xadrez[i][3] == ' '){
                                cont++;

                           }else if(xadrez[i][3] != ' ' ){
                               cont1++;
                           }

                        }
                             i = LO +1;

                    if(((cont == (lD - i)) || (cont == ( i - lD) )) && (cont1 == 0)){

                             for(int i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                              contX = contX + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                        }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }

                           }else{
                               printf("Não é possivel saltar sobre as peças");
                           }

                   }

// NESTA PARTE DA COLUNA 3  PERMITIRÁ A TORRE ANDAR VARIAS CASAS DESDE QUE ELA SE VERTICAL E  NEGATIVA SENDO A ORIGEM > QUE O DESTINO
                   if(i > lD){

                           int x = LO - 1; //  NÃO CONTAMOS  A CASA DA PEÇA  SE A PEÇA ESTÁ  NA CASA 7 E VAI PARA CASA 2 ENTÃO SEU INTERVALO E 7 - 2 == 5

                     for(x;x>lD;x--){ // DECREMENTO

                        if(xadrez[x][3] == ' '){ // COLUNA 3 FIXA  X LINHA VARIANDO ENTRE 1 E 8  LO - lD == deslocamento vertical
                                cont++; // conta as casas vazias

                        }else if(xadrez[x][3] != ' ' ){
                        cont1++; // conta as peças
                        }

                   }
                     x = LO - 1; // x RECEBE A POSIÇÃO DE ORIGEM

                    if(((cont == (lD - x)) || (cont == ( x - lD) )) && (cont1 == 0)){ // SE QUANTIDADE DE VAZIOS FOR IGUAL A LINHA-ORIGEM MENOS  A LINHA-DESTINO  E A QUANTIDADE DE PEÇAS ENTRE A TORRE E DETINO FOR 0 ENTÃO PODE MOVER

                             for(int i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                              contX = contX + 1 ; // contado global
                               //printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                        }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }



                           }else{
                               printf("Não é possivel saltar sobre as peças\n"); // TEM PEÇA ENTRE A TORRE E SEU ALVO,  NÃO PODE MOVER POIS A TORRE  NÃO SALTA PEÇAS
                           }

                   }

                    }else if(CO == 4){ // COLUNA 4

                                    int f = LO;
                                if(LO - lD == 1 || lD - LO  == 1){


                                 for(f;f<=lD;f++){

                              if(xadrez[f][4] == ' '){
                                    cont++;

                             }else if(xadrez[f+1][4] != ' ' ){
                                  cont1++;
                             }

                         }
                           f = LO;
                /*   printf("====ttuu%d==\n\n",cont);
                   printf("====ttuu%d==\n\n",(lD -f));
                   printf("====ttuu%d===\n\n",(f - lD));*/

                    if(((cont == (lD - f)) || (cont == ( f - lD) )) && (cont1 == 0)){

                               for(int i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                              contX = contX + 1 ; // contado global
                             //  printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                        }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }



                           }else{
                                xadrez[lD][cD] = xadrez[LO][CO];
                               xadrez[LO][CO] = ' ';
                               return 1; // movimento realizado;
                           }

                   }

//====================================================================================================================================================================
                    int   i = LO + 1;
                    if(i < lD){

                        for(i;i<lD;i++){

                           if(xadrez[i][4] == ' '){
                                cont++;

                           }else if(xadrez[i][4] != ' ' ){
                               cont1++;
                           }

                        }
                             i = LO +1; //ORIGEM + 1

                    if(((cont == (lD - i)) || (cont == ( i - lD) )) && (cont1 == 0)){

                          for(int i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                              contX = contX + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                       }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }



                           }else{
                               printf("Não é possivel saltar sobre as peças");
                           }

                   }

//=========================================================================================================================================================================
                   if(i > lD){
                    int x = LO - 1;

                     for(x;x>lD;x--){

                        if(xadrez[x][4] == ' '){
                                cont++;

                        }else if(xadrez[x][4] != ' ' ){
                        cont1++;
                        }

                   }
                     x = LO - 1;


                    if(((cont == (lD - x)) || (cont == ( x - lD) )) && (cont1 == 0)){

                          for(int i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                              contX = contX + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                      }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }



                           }else{
                               printf("Não é possivel saltar sobre as peças\n");
                           }

                   }

//=======================================================================================================================================================================================
                    }else if(CO == 5){ // COLUNA 5

                                    int f = LO;
                                if(LO - lD == 1 || lD - LO  == 1){

                                 for(f;f<=lD;f++){

                              if(xadrez[f][5] == ' '){
                                    cont++;

                             }else if(xadrez[f+1][5] != ' ' ){
                                  cont1++;
                             }

                         }
                           f = LO;

                    if(((cont == (lD - f)) || (cont == ( f - lD) )) && (cont1 == 0)){

                                 for(int i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                              contX = contX + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                      }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }


                           }else{

                                 for(int i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                              contX = contX + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                      }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }

                               xadrez[lD][cD] = xadrez[LO][CO]; //ATRIBUIÇÃO DE UMA CASA FORÇADA  ARA TORRE ANDAR SO UMA CASA
                               xadrez[LO][CO] = ' ';
                          return 1; // MOVIMENTO FEITO
                           }

                   }


//===================================================================================================================================================================
                           int   i = LO + 1;

                       if(i < lD){

                          for(i;i<lD;i++){

                        if(xadrez[i][5] == ' '){
                                cont++;

                        }else if(xadrez[i][5] != ' ' ){
                        cont1++;
                        }

                    }
                      i = LO +1;

                    if(((cont == (lD - i)) || (cont == ( i - lD) )) && (cont1 == 0)){

                              for(int i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                              contX = contX + 1 ; // contado global
                               //printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                      }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }


                           }else{
                               printf("Não é possivel saltar sobre as peças");
                           }

                       }

//==============================================================================================================================================================================
                   if(i > lD){
                      int x = LO - 1;

                     for(x;x>lD;x--){

                        if(xadrez[x][5] == ' '){
                                cont++;

                        }else if(xadrez[x][5] != ' ' ){
                        cont1++;
                        }

                   }
                     x = LO - 1;
                  /* printf("====ttuu%d==\n\n",cont);
                   printf("====ttuu%d==\n\n",(lD -x));
                   printf("====ttuu%d===\n\n",(x - lD));*/

                    if(((cont == (lD - x)) || (cont == ( x - lD) )) && (cont1 == 0)){

                             for(int i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                              contX = contX + 1 ; // contado global
                             //  printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                       }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }



                           }else{
                               printf("Não é possivel saltar sobre as peças\n");
                           }

                   }


//======================================================================================================================================================

                }else if(CO == 6){// COLUNA 6

                                    int f = LO;
                                if(LO - lD == 1 || lD - LO  == 1){ // ESSA CONDIÇÃO SÓ ACEITA MOVIMNETO  DE 1  CASA


                                 for(f;f<=lD;f++){

                              if(xadrez[f][6] == ' '){
                                    cont++;

                             }else if(xadrez[f+1][6] != ' ' ){
                                  cont1++;
                             }

                         }
                           f = LO;

                    if(((cont == (lD - f)) || (cont == ( f - lD) )) && (cont1 == 0)){

                          for(int i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                              contX = contX + 1 ; // contado global
                               //printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                          }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }



                           }else{

                                 for(int i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                              contX = contX + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                      }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }

                              xadrez[lD][cD] = xadrez[LO][CO];
                               xadrez[LO][CO] = ' ';
                               return 1;
                           }

                   }
//=============================================================================================================
//=============================================================================================================
                    int   i = LO + 1;
                    if(i < lD){

                        for(i;i<lD;i++){

                           if(xadrez[i][6] == ' '){
                                cont++;

                           }else if(xadrez[i][6] != ' ' ){
                               cont1++;
                           }

                        }
                             i = LO +1;


                    if(((cont == (lD - i)) || (cont == ( i - lD) )) && (cont1 == 0)){

                         for(int i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                              contX = contX + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                          }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }



                           }else{
                               printf("Não é possivel saltar sobre as peças");
                           }

                   }


                   if(i > lD){
                           int x = LO - 1;

                     for(x;x>lD;x--){

                        if(xadrez[x][6] == ' '){
                                cont++;

                        }else if(xadrez[x][6] != ' ' ){
                        cont1++;
                        }

                   }
                     x = LO - 1;

                    if(((cont == (lD - x)) || (cont == ( x - lD) )) && (cont1 == 0)){

                          for(int i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                              contX = contX + 1 ; // contado global
                               //printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                        }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }



                           }else{
                               printf("Não é possivel saltar sobre as peças\n");
                           }

                   }
//=============================================================================================================
               }else if(CO == 7){ // COLUNA 7

                        int f = LO;
                    if(LO - lD == 1 || lD - LO  == 1){ // solução para andar um casa


                                 for(f;f<=lD;f++){

                              if(xadrez[f][7] == ' '){
                                    cont++;

                             }else if(xadrez[f+1][7] != ' ' ){
                                  cont1++;
                             }

                         }
                           f = LO;

                    if(((cont == (lD - f)) || (cont == ( f - lD) )) && (cont1 == 0)){

                          for(int i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                              contX = contX + 1 ; // contado global
                            //   printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                        }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }


                           }else{

                                 for(int i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                              contX = contX + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                      }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }
                               xadrez[lD][cD] = xadrez[LO][CO];
                               xadrez[LO][CO] = ' ';
                          return 1; // movimento realizado;
                           }

                   }

//=================================================================================================================
                      int   i = LO + 1; // ORIGEM +1
                    if(i < lD){

                        for(i;i<lD;i++){

                           if(xadrez[i][7] == ' '){ // i LINHA VARIANDO COLUNA FIXA EM 5
                                cont++; // esse contador  IRA CONTAR OS INTERVALOS ENTRE A PEÇA E O DESTINO QUE ESTÃO VAZIOS

                           }else if(xadrez[i][7] != ' ' ){
                               cont1++; // conta peça
                           }

                        }
                             i = LO +1;
                        /*printf("====ttuu%d==\n\n",cont);
                        printf("====ttuu%d==\n\n",(lD -i));
                        printf("====ttuu%d===\n\n",(i - lD));*/

                    if(((cont == (lD - i)) || (cont == ( i - lD) )) && (cont1 == 0)){

                          for(int i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                              contX = contX + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                        }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }



                           }else{
                               printf("Não é possivel saltar sobre as peças");
                           }

                   }

//=========================================================================================================================================================================================
                   if(i > lD){
                           int x = LO - 1;

                     for(x;x>lD;x--){

                        if(xadrez[x][7] == ' '){
                                cont++;

                        }else if(xadrez[x][7] != ' ' ){
                        cont1++;
                        }

                   }
                     x = LO - 1;


                    if(((cont == (lD - x)) || (cont == ( x - lD) )) && (cont1 == 0)){

                         for(int i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                              contX = contX + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                        }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }



                           }else{
                               printf("Não é possivel saltar sobre as peças\n");
                           }

                   }

//=============================================================================================================================

               }else if(CO == 8 ){ // COLUNA 8

                                    int f = LO;
                                if(LO - lD == 1 || lD - LO  == 1){ // solução para andar um casa


                                 for(f;f<=lD;f++){

                              if(xadrez[f][8] == ' '){
                                    cont++;

                             }else if(xadrez[f+1][8] != ' ' ){
                                  cont1++;
                             }

                         }
                           f = LO;

                    if(((cont == (lD - f)) || (cont == ( f - lD) )) && (cont1 == 0)){

                         for(int i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                                contX = contX + 1 ; // contado global
                               //printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                        }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }


                           }else{

                                 for(int i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                              contX = contX + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                      }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }

                                 xadrez[lD][cD] = xadrez[LO][CO];
                               xadrez[LO][CO] = ' ';
                               return 1; // movimento realizado;

                           }

                   }

//============================================================================================================
                      int   i = LO + 1;
                    if(i < lD){

                        for(i;i<lD;i++){

                           if(xadrez[i][8] == ' '){
                                cont++;

                           }else if(xadrez[i][8] != ' ' ){
                               cont1++;
                           }

                        }
                             i = LO +1;


                    if(((cont == (lD - i)) || (cont == ( i - lD) )) && (cont1 == 0)){

                          for(int i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                              contX = contX + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                        }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }



                           }else{
                               printf("Não é possivel saltar sobre as peças");
                           }

                   }


                   if(i > lD){
                           int x = LO - 1;

                     for(x;x>lD;x--){

                        if(xadrez[x][8] == ' '){
                                cont++;

                        }else if(xadrez[x][8] != ' ' ){
                        cont1++;
                        }

                   }
                     x = LO - 1;
                  /* printf("====ttuu%d==\n\n",cont);
                   printf("====ttuu%d==\n\n",(lD -x));
                   printf("====ttuu%d===\n\n",(x - lD));*/

                    if(((cont == (lD - x)) || (cont == ( x - lD) )) && (cont1 == 0)){

                         for(int i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                              contX = contX + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                        }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }


                           }else{
                               printf("Não é possivel saltar sobre as peças\n");
                           }

                   }


                            }
//===============================================================================================================================================================================================================================
//========================== DESLOCAMENTO HORIZONTAL=============================================================================================================================================================================
               }else if(deslocamentoHorizontal >0){




                   if(LO == 1){// LINHA 1

                          int z = CO; //  A VARIAVEL z RECEBE O PARÊMTRO  coluna de origem

                    if(CO - cD == 1 || cD - CO  == 1){


                        for(z;z<=cD;z++){ // LOOP CRESCEETE ++

                        if(xadrez[1][z] == ' '){ // linha travada  coluna z varinado
                                cont++; // CONTADOR DE VAIZO

                             }else if(xadrez[1][z+1] != ' ' ){
                                  cont1++; // CONTA PEÇA
                             }

                         }
                           z = CO; // z RECEBE O VALOR  DA COLUNA DE ORIGEM

                    if(((cont == (cD - z)) || (cont == ( z - cD) )) && (cont1 == 0)){

                           for(int i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                              contX = contX + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                        }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }



                           }else{

                                 for(int i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                              contX = contX + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                      }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }

                                xadrez[lD][cD] = xadrez[LO][CO]; // SOBRE ESCRITA FORÇADA !!
                               xadrez[LO][CO] = ' ';
                               return 1;
                           }

                   }


//===================================================================================================================================================================================
                     int j = CO + 1; // COLUNA DE ORIGEM MAIS 1 PARA NÃO CONTAR A PEÇA JÁ QUE QUEREMOS O INTERVALO
                      if(j < cD){
                             for(j;j<cD;j++){

                           if(xadrez[1][j] == ' '){ // LINHA UM TRAVADA  EM 1 COLUNA j VARIANDO ENTRE J E cD ORIGEME DESTINO
                                cont++; //CONTA VAZIO

                           }else if(xadrez[1][j] != ' ' ){
                               cont1++; // CONTA PEÇA
                           }

                        }
                            j = CO + 1; // j volta  SEU VALOR DE ORIGEM  PARA QUE POSSAMOS COMPARA  ORIGEM MENOS DESTINO == QUANTIDADE DE VAZIO

                    if(((cont == (cD - j)) || (cont == ( j - cD) )) && (cont1 == 0)){

                                for(int i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                              contX = contX + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                          }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }



                           }else{
                               printf("Não é possivel saltar sobre as peças"); // cont1 FOI CONTADO ENTÃO A UMA PEÇA ENTRE  A TORRE E SEU DESTINO  E A TORRE NÃO PODE SALTAR PEÇA
                           }

                   }

//========================================================================================================================================================================================
                      if(j > cD){ // ORIGEM  AMIOR QUE O DESTINO
                          int y = CO - 1;
                           for(y;y>cD;y--){ // LOOP DE DECREMENTO ! NECESSARIO PARA IR DE UMA CASA 5 PARA CASA 3

                           if(xadrez[1][y] == ' '){
                                cont++; // CONTA VAZIO

                           }else if(xadrez[1][y] != ' ' ){
                               cont1++;
                           }

                        }
                            y = CO - 1; //  y VOLTA A RECEBER O VALOR  DA COLUNA ORIGEM - 1   JÁ QUE QUEREMOS O INTERVALO ENTRE POR XEMPLO 8 E 1 ENTÃO SERÁ 7  CASAS NÃO PODEMOS CONTAR A CASA DA PEÇA

                    if(((cont == (cD - y)) || (cont == ( y - cD) )) && (cont1 == 0)){

                               for(int i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                              contX = contX + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                          }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }



                           }else{

                              printf("Não é possivel saltar sobre as peças");
                           }

                   }





//==================================================================================================================================================================================================
             }else if(LO == 2){ // LINHA 2

                    int z = CO;

                    if(CO - cD == 1 || cD - CO  == 1){ // solução para andar um casa


                        for(z;z<=cD;z++){

                        if(xadrez[2][z] == ' '){
                                cont++;

                             }else if(xadrez[2][z+1] != ' ' ){ // esse mais um é para ele não contar a prória peça que esta na posição inicial  lembrando que cont1 significa que tem peça ou seja não é vazio!!
                                  cont1++;
                             }

                         }
                           z = CO;
                      /* printf("====ttuu%d==\n\n",cont);
                       printf("====ttuu%d==\n\n",(cD -z));
                       printf("====ttuu%d===\n\n",(z - cD));*/

                    if(((cont == (cD - z)) || (cont == ( z - cD) )) && (cont1 == 0)){

                                 for(int i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                              contX = contX + 1 ; // contado global
                               //printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                          }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }



                           }else{

                          for(int i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                              contX = contX + 1 ; // contado global
                             //  printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                          }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }

                               xadrez[lD][cD] = xadrez[LO][CO];
                               xadrez[LO][CO] = ' ';
                                return 1; // movimento realizado;
                           }

                   }

//======================================================================================================================================================================================================
                    int j = CO + 1;
                      if(j < cD){
                             for(j;j<cD;j++){

                           if(xadrez[2][j] == ' '){
                                cont++;

                           }else if(xadrez[2][j] != ' ' ){
                               cont1++;
                           }

                        }
                            j = CO + 1;

                    if(((cont == (cD - j)) || (cont == ( j - cD) )) && (cont1 == 0)){

                                 for(int i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                              contX = contX + 1 ; // contado global
                             //  printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                        }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }



                           }else{
                               printf("Não é possivel saltar sobre as peças");
                           }

                   }


                      if(j > cD){
                          int y = CO - 1;
                           for(y;y>cD;y--){

                           if(xadrez[2][y] == ' '){
                                cont++;

                           }else if(xadrez[2][y] != ' ' ){
                               cont1++;
                           }

                        }
                            y = CO - 1;

                    if(((cont == (cD - y)) || (cont == ( y - cD) )) && (cont1 == 0)){

                            for(int i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                              contX = contX + 1 ; // contado global
                             //  printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                          }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }



                           }else{
                               printf("Não é possivel saltar sobre as peças");
                           }

                   }
//=====================================================================================================================================================================
             }else if(LO == 3){ // LINHA 3

                    int z = CO;

                    if(CO - cD == 1 || cD - CO  == 1){

                        for(z;z<=cD;z++){

                        if(xadrez[3][z] == ' '){
                                cont++;

                             }else if(xadrez[3][z+1] != ' ' ){
                                  cont1++;
                             }

                         }
                           z = CO;


                    if(((cont == (cD - z)) || (cont == ( z - cD) )) && (cont1 == 0)){

                                     for(int i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                              contX = contX + 1 ; // contado global
                           //    printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                          }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }



                           }else{

                                 for(int i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                              contX = contX + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                          }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }
                               xadrez[lD][cD] = xadrez[LO][CO];
                               xadrez[LO][CO] = ' ';
                               return 1;
                           }

                   }

//====================================================================================================================================================================
                   int j = CO + 1;
                      if(j < cD){
                             for(j;j<cD;j++){

                           if(xadrez[3][j] == ' '){
                                cont++;

                           }else if(xadrez[3][j] != ' ' ){
                               cont1++;
                           }

                        }
                            j = CO + 1;

                    if(((cont == (cD - j)) || (cont == ( j - cD) )) && (cont1 == 0)){

                                  for(int i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                              contX = contX + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                          }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }



                           }else{
                               printf("Não é possivel saltar sobre as peças");
                           }

                   }

//=========================================================================================================
                      if(j > cD){
                          int y = CO - 1;
                           for(y;y>cD;y--){

                           if(xadrez[3][y] == ' '){
                                cont++;

                           }else if(xadrez[3][y] != ' ' ){
                               cont1++;
                           }

                        }
                            y = CO - 1;

                    if(((cont == (cD - y)) || (cont == ( y - cD) )) && (cont1 == 0)){

                                    for(int i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                              contX = contX + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                        }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }


                           }else{
                               printf("Não é possivel saltar sobre as peças");
                           }

                   }

//=================================================================================================================================================================================================
            }else if(LO == 4){ // LINHA 4

                   int z = CO;

                    if(CO - cD == 1 || cD - CO  == 1){ // solução para andar um casa


                        for(z;z<=cD;z++){

                        if(xadrez[4][z] == ' '){
                                cont++;

                             }else if(xadrez[4][z+1] != ' ' ){ // esse mais um é para ele não contar a prória peça que esta na posição inicial  lembrando que cont1 significa que tem peça ou seja não é vazio!!
                                  cont1++;
                             }

                         }
                           z = CO;
                    if(((cont == (cD - z)) || (cont == ( z - cD) )) && (cont1 == 0)){

                                   for(int i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                              contX = contX + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                          }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }



                           }else{

                                 for(int i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                              contX = contX + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                          }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }

                                xadrez[lD][cD] = xadrez[LO][CO];
                               xadrez[LO][CO] = ' ';
                          return 1; // movimento realizado;
                           }

                   }

//===============================================================================================================================================================================================

                int j = CO + 1;
                      if(j < cD){
                             for(j;j<cD;j++){

                           if(xadrez[4][j] == ' '){
                                cont++;

                           }else if(xadrez[4][j] != ' ' ){
                               cont1++;
                           }

                        }
                            j = CO + 1;

                    if(((cont == (cD - j)) || (cont == ( j - cD) )) && (cont1 == 0)){

                                  for(int i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                              contX = contX + 1 ; // contado global
                               //printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                        }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }



                           }else{
                               printf("Não é possivel saltar sobre as peças");
                           }

                   }

//==================================================================================================================
                      if(j > cD){
                          int y = CO - 1;
                           for(y;y>cD;y--){

                           if(xadrez[4][y] == ' '){
                                cont++;

                           }else if(xadrez[4][y] != ' ' ){
                               cont1++;
                           }

                        }
                            y = CO - 1;

                    if(((cont == (lD - y)) || (cont == ( y - lD) )) && (cont1 == 0)){

                               for(int i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                              contX = contX + 1 ; // contado global
                               //printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                        }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }

                           }else{
                               printf("Não é possivel saltar sobre as peças");
                           }

                   }






//===========================================================================================================================================================================================
            }else if(LO == 5){ // LINHA 5

                   int z = CO;

                    if(CO - cD == 1 || cD - CO  == 1){

                        for(z;z<=cD;z++){

                        if(xadrez[5][z] == ' '){
                                cont++;

                             }else if(xadrez[5][z+1] != ' ' ){
                                  cont1++;
                             }

                         }
                           z = CO;
                    if(((cont == (cD - z)) || (cont == ( z - cD) )) && (cont1 == 0)){

                                 for(int i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                              contX = contX + 1 ; // contado global
                               //printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                          }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }



                           }else{
                                 for(int i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                              contX = contX + 1 ; // contado global
                               //printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                          }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }


                               xadrez[lD][cD] = xadrez[LO][CO];
                               xadrez[LO][CO] = ' ';
                          return 1; // movimento realizado;
                           }

                   }

//============================================================================================================================================================================================

                int j = CO + 1;
                      if(j < cD){
                             for(j;j<cD;j++){

                           if(xadrez[5][j] == ' '){
                                cont++;

                           }else if(xadrez[5][j] != ' ' ){
                               cont1++;
                           }

                        }
                            j = CO + 1;

                    if(((cont == (cD - j)) || (cont == ( j - cD) )) && (cont1 == 0)){

                                  for(int i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                              contX = contX + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                          }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }


                           }else{
                               printf("Não é possivel saltar sobre as peças");
                           }

                   }
//=====================================================================================================================================================
                      if(j > cD){
                          int y = CO - 1;
                           for(y;y>cD;y--){

                           if(xadrez[5][y] == ' '){
                                cont++;

                           }else if(xadrez[5][y] != ' ' ){
                               cont1++;
                           }

                        }
                            y = CO - 1;

                    if(((cont == (cD - y)) || (cont == ( y - cD) )) && (cont1 == 0)){

                               for(int i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                              contX = contX + 1 ; // contado global
                               //printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                        }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }



                           }else{
                               printf("Não é possivel saltar sobre as peças");
                           }

                   }

//=============================================================================================================================================================================================
            }else if(LO == 6){// LINHA 6

                   int z = CO;

                    if(CO - cD == 1 || cD - CO  == 1){


                        for(z;z<=cD;z++){

                        if(xadrez[6][z] == ' '){
                                cont++;

                             }else if(xadrez[6][z+1] != ' ' ){
                                  cont1++;
                             }

                         }
                           z = CO;
                     /*  printf("====ttuu%d==\n\n",cont);
                       printf("====ttuu%d==\n\n",(cD -z));
                       printf("====ttuu%d===\n\n",(z - cD));*/

                    if(((cont == (cD - z)) || (cont == ( z - cD) )) && (cont1 == 0)){

                                     for(int i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                              contX = contX + 1 ; // contado global
                             //  printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                        }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }


                           }else{

                                 for(int i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                              contX = contX + 1 ; // contado global
                             //  printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                        }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }

                               xadrez[lD][cD] = xadrez[LO][CO];
                               xadrez[LO][CO] = ' ';
                              return 1; // movimento realizado;

                           }

                   }
//======================================================================================================================================
                int j = CO + 1;
                      if(j < cD){
                             for(j;j<cD;j++){

                           if(xadrez[6][j] == ' '){
                                cont++;

                           }else if(xadrez[6][j] != ' ' ){
                               cont1++;
                           }

                        }
                            j = CO + 1;
                        /*printf("====ttuu%d==\n\n",cont);
                        printf("====ttuu%d==\n\n",(cD - j));
                        printf("====ttuu%d===\n\n",(j - cD));*/

                    if(((cont == (cD - j)) || (cont == ( j - cD) )) && (cont1 == 0)){

                                    for(int i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                              contX = contX + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                        }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }

                           }else{
                               printf("Não é possivel saltar sobre as peças");
                           }

                   }

//=========================================================================================================
                      if(j > cD){
                          int y = CO - 1;
                           for(y;y>cD;y--){

                           if(xadrez[6][y] == ' '){
                                cont++;

                           }else if(xadrez[6][y] != ' ' ){
                               cont1++;
                           }

                        }
                            y = CO - 1;

                    if(((cont == (cD - y)) || (cont == ( y - cD) )) && (cont1 == 0)){

                                for(int i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                              contX = contX + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                        }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }


                           }else{
                               printf("Não é possivel saltar sobre as peças");
                           }

                   }

//===========================================================================================================================================================================================
            }else if(LO == 7){ // LINHA 7

                   int z = CO;

                    if(CO - cD == 1 || cD - CO  == 1){


                        for(z;z<=cD;z++){

                        if(xadrez[7][z] == ' '){
                                cont++;

                             }else if(xadrez[7][z+1] != ' ' ){
                                  cont1++;
                             }

                         }
                           z = CO;

                    if(((cont == (cD - z)) || (cont == ( z - cD) )) && (cont1 == 0)){

                                     for(int i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                              contX = contX + 1 ; // contado global
                             //  printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                        }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }



                           }else{

                                 for(int i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                              contX = contX + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                        }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }
                               xadrez[lD][cD] = xadrez[LO][CO];
                               xadrez[LO][CO] = ' ';
                               return 1;

                           }

                   }

//===================================================================================================================================
                 int j = CO + 1;
                      if(j < cD){
                             for(j;j<cD;j++){

                           if(xadrez[7][j] == ' '){ // LINHA 7 TRAVADA  COLUNA j  VARIANDO ENTRE A COLUNA DE ORIGEM E A COLUNA DE DESTINO
                                cont++; // CONT VAIZO

                           }else if(xadrez[7][j] != ' ' ){
                               cont1++; // CONT PEÇA
                           }

                        }
                            j = CO + 1; // j RECEBE NOVAMENTO O VALOR DE ORIGEM

                    if(((cont == (cD - j)) || (cont == ( j - cD) )) && (cont1 == 0)){

                                  for(int i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                              contX = contX + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                        }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }



                           }else{
                               printf("Não é possivel saltar sobre as peças");
                           }

                   }

//==============================================================================================================================================
                      if(j > cD){ // ORIGEM MAIOR QUE O DESTINO  NESTE CASO SERÁ FEITO UM LOOP DE DECREMENTO
                          int y = CO - 1;
                           for(y;y>cD;y--){

                           if(xadrez[7][y] == ' '){ // LINHA 7 TRAVADA
                                cont++; // CONT vaizo

                           }else if(xadrez[7][y] != ' ' ){
                               cont1++; // conta peça
                           }

                        }
                            y = CO - 1;

                    if(((cont == (cD - y)) || (cont == ( y - cD) )) && (cont1 == 0)){

                             for(int i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                              contX = contX + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                        }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }


                           }else{
                               printf("Não é possivel saltar sobre as peças");
                           }

                   }

            }else if(LO == 8){

                   int z = CO;

                    if(CO - cD == 1 || cD - CO  == 1){


                        for(z;z<=cD;z++){

                        if(xadrez[8][z] == ' '){
                                cont++;

                             }else if(xadrez[8][z+1] != ' ' ){
                                  cont1++;
                             }

                         }
                           z = CO;

                    if(((cont == (cD - z)) || (cont == ( z - cD) )) && (cont1 == 0)){

                                 for(int i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                              contX = contX + 1 ; // contado global
                               //printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                          }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }



                           }else{

                            for(int i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                              contX = contX + 1 ; // contado global
                               //printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                          }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }
                               xadrez[lD][cD] = xadrez[LO][CO];
                               xadrez[LO][CO] = ' ';
                               return 1;

                           }

                   }

//===================================================================================================================================================
                 int j = CO + 1;
                      if(j < cD){
                             for(j;j<cD;j++){

                           if(xadrez[8][j] == ' '){
                                cont++;

                           }else if(xadrez[8][j] != ' ' ){
                               cont1++;
                           }

                        }
                            j = CO + 1;

                    if(((cont == (cD - j)) || (cont == ( j - cD) )) && (cont1 == 0)){

                          for(int i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                              contX = contX + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                          }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }


                           }else{
                               printf("Não é possivel saltar sobre as peças");
                           }

                   }
//=====================================================================================================================================================

                      if(j > cD){
                          int y = CO - 1;
                           for(y;y>cD;y--){

                           if(xadrez[8][y] == ' '){
                                cont++;

                           }else if(xadrez[8][y] != ' ' ){
                               cont1++;
                           }

                        }
                            y = CO - 1;

                    if(((cont == (cD - y)) || (cont == ( y - cD) )) && (cont1 == 0)){

                            for(int i =0; i < 1;i++){
                             if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K'){
                              contX = contX + 1 ; // contado global
                              // printf("=========yyyyy%d========",contX);
                            if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 1){

                                   return 4; // XEQUE

                           }else if(xadrez[LO][CO] == 't' && xadrez [lD][cD] == 'K' && contX == 2 ){
                                  mover = 1;
                              if(mover == 1){
                                xadrez[lD][cD] = xadrez[LO][CO];
                                xadrez[LO][CO] = ' ';
                                return 3; // RETORNO DO XEQUE -MATE
                              }
                          }
                          }else{
                             mover = 1; // MOVIMENTO NORMAL
                          }
                     }


                }



                           }else{
                               printf("Não é possivel saltar sobre as peças");
                           }

                   }

            }

              }

//===================================================================================================================================================

 //====================================================bispo=================================================================================
 // A MESMA LÓGICA  VALE  PARA O BISPO b  MINÚSCULO PRORÉM  INVERTENDO AS LETRA  QUE ELA VAI ATACAR SENDO AS MESMAS AS LETRAS MAÚSCULAS
          if(( xadrez[LO][CO] == 'b' && xadrez[lD][cD] == ' ') || (xadrez[LO][CO] == 'b' && xadrez[lD][cD] == 'P')
             || (xadrez[LO][CO] == 'b' && xadrez[lD][cD] == 'T') || (xadrez[LO][CO] == 'b' && xadrez[lD][cD] == 'B') ||
             (xadrez[LO][CO] == 'b' && xadrez[lD][cD] == 'C') || (xadrez[LO][CO] == 'b' && xadrez[lD][cD] == 'Q') ||
             (xadrez[LO][CO] == 'b' && xadrez[lD][cD] == 'K')&& (deslocamentoVertical == deslocamentoHorizontal)){

                for(int i =0; i < 1;i++){
                     if(xadrez[LO][CO] == 'b' && xadrez [lD][cD] == 'K'){
                         contX = contX + 1 ; // contado global
                     // printf("=========yyyyy%d========",contX);
                      if(xadrez[LO][CO] == 'b' && xadrez [lD][cD] == 'K' && contX == 1){

                            return 4; // XEQUE



                  }else if(xadrez[LO][CO] == 'b' && xadrez [lD][cD] == 'K' && contX == 2 ){
                      mover = 1;
                             if(mover == 1){
                    xadrez[lD][cD] = xadrez[LO][CO];
                    xadrez[LO][CO] = ' ';
                   return 3; // RETORNO DO XEQUE -MATE
                  }
               }
             }else{

              mover = 1; // MOVIMENTO NORMAL
                }
        }

             }

//==================================================cavalo======================================================================================
// A LÓGICA É MESMA  TROCANDO SÓ AS LETRAS maiúsculas e minúsculas
          if(((xadrez[LO][CO] == 'c' && xadrez[lD][cD] == ' ') || (xadrez[LO][CO] == 'c' && xadrez[lD][cD] == 'P') ||
             (xadrez[LO][CO] == 'c' && xadrez[lD][cD] == 'T') || (xadrez[LO][CO] == 'c' && xadrez[lD][cD] == 'C') ||
             (xadrez[LO][CO] == 'c' && xadrez[lD][cD] == 'B') || (xadrez[LO][CO] == 'c' && xadrez[lD][cD] == 'Q') ||
             (xadrez[LO][CO] == 'c' && xadrez[lD][cD] == 'K'))
              && (deslocamentoVertical == 1 && deslocamentoHorizontal == 2) ||(deslocamentoHorizontal == 1 && deslocamentoVertical == 2)){
                        if(xadrez[LO][CO]!='p'){
                                   for(int i =0; i < 1;i++){
                     if(xadrez[LO][CO] == 'c' && xadrez [lD][cD] == 'K'){
                         contX = contX + 1 ; // contado global
                     // printf("=========yyyyy%d========",contX);
                      if(xadrez[LO][CO] == 'c' && xadrez [lD][cD] == 'K' && contX == 1){

                            return 4; // XEQUE



                  }else if(xadrez[LO][CO] == 'c' && xadrez [lD][cD] == 'K' && contX == 2 ){
                      mover = 1;
                             if(mover == 1){
                    xadrez[lD][cD] = xadrez[LO][CO];
                    xadrez[LO][CO] = ' ';
                   return 3; // RETORNO DO XEQUE -MATE
                  }
               }
             }else{

              mover = 1; // MOVIMENTO NORMAL
                }
        }

                        }

              }


//=============================================rainha=====================================================================================================
//=========================================================================================================================================================
          if((xadrez[LO][CO] == 'q' && xadrez[lD][cD] == ' ') || (xadrez[LO][CO] == 'q' && xadrez[lD][cD] == 'P') ||
              (xadrez[LO][CO] == 'q' && xadrez[lD][cD] == 'T') || (xadrez[LO][CO] == 'q' && xadrez[lD][cD] == 'C') ||
             (xadrez[LO][CO] == 'q' && xadrez[lD][cD] == 'B') || (xadrez[LO][CO] == 'q' && xadrez[lD][cD] == 'Q') ||
             (xadrez[LO][CO] == 'q' && xadrez[lD][cD] == 'K') && ((deslocamentoVertical == deslocamentoHorizontal) || (deslocamentoVertical == 0) || (deslocamentoHorizontal == 0))){

                  for(int i =0; i < 1;i++){
                     if(xadrez[LO][CO] == 'q' && xadrez [lD][cD] == 'K'){
                         contX = contX + 1 ; // contado global
                     // printf("=========yyyyy%d========",contX);
                      if(xadrez[LO][CO] == 'q' && xadrez [lD][cD] == 'K' && contX == 1){

                            return 4; // XEQUE

                  }else if(xadrez[LO][CO] == 'q' && xadrez [lD][cD] == 'K' && contX == 2 ){
                      mover = 1;
                             if(mover == 1){
                    xadrez[lD][cD] = xadrez[LO][CO];
                    xadrez[LO][CO] = ' ';
                   return 3; // RETORNO DO XEQUE -MATE
                  }
               }
             }else{
              mover = 1; // MOVIMENTO NORMAL
                }
        }

    }


//====================================rei===================================================================================================================
//==========================================================================================================================================================
          if((xadrez[LO][CO] == 'k' && xadrez[lD][cD] == ' ') || (xadrez[LO][CO] == 'k' && xadrez[lD][cD] == 'P') ||
              (xadrez[LO][CO] == 'k' && xadrez[lD][cD] == 'T') || (xadrez[LO][CO] == 'k' && xadrez[lD][cD] == 'C') ||
             (xadrez[LO][CO] == 'k' && xadrez[lD][cD] == 'B') || (xadrez[LO][CO] == 'k' && xadrez[lD][cD] == 'Q') ||
             (xadrez[LO][CO] == 'k' && xadrez[lD][cD] == 'K')){


                    if( (deslocamentoVertical >=0 && deslocamentoVertical <=1) && (deslocamentoHorizontal >=0 && deslocamentoHorizontal <=1 ) ){

               for(int i =0; i < 1;i++){

                     if(xadrez[LO][CO] == 'k' && xadrez [lD][cD] == 'K'){
                         contX = contX + 1 ; // contado global
                     // printf("=========yyyyy%d========",contX);
                      if(xadrez[LO][CO] == 'k' && xadrez [lD][cD] == 'K' && contX == 1){

                            return 4; // XEQUE

                  }else if(xadrez[LO][CO] == 'k' && xadrez [lD][cD] == 'K' && contX == 2 ){
                      mover = 1;
                             if(mover == 1){
                    xadrez[lD][cD] = xadrez[LO][CO];
                    xadrez[LO][CO] = ' ';
                   return 3; // RETORNO DO XEQUE -MATE
                  }
               }
             }else{
               mover = 1; // MOVIMENTO NORMAL
                }



        }
            }else{
                printf("MOVIMENTO INVALIDO ! \n");
                printf("REFACA A JOGADA ! \n");
                jogadaPreta();
                inversao();
            }
             }

               if((peca == 'p' ) && ((LO - lD) == 1 ) && (deslocamentoHorizontal == 0)){

                    if(xadrez[LO][CO] == 'p' && xadrez[lD][cD] == ' '){
                  mover = 1;
              }

          }else if((peca == 'p' && xadrez[7][1] == 'p' && LO == 7 && CO == 1 && lD == 5 && cD == 1)&& ((LO - lD) == 2 ) && (deslocamentoHorizontal == 0)){
                 if(xadrez[LO][CO] == 'p' && xadrez[lD][cD] == ' '){
                  mover = 1;
              } // O MOVIMENTO DAS PRETAS E DECRESCENTE 8 7 6 5 4 3 2 1  ETC

          }else if((peca == 'p' && xadrez[7][2] == 'p' && LO == 7 && CO == 2 && lD == 5 && cD == 2)&& ((LO - lD) == 2 ) && (deslocamentoHorizontal == 0)){
                   if(xadrez[LO][CO] == 'p' && xadrez[lD][cD] == ' '){
                  mover = 1;
              } // O MOVIMENTO DAS PRETAS E DECRESCENTE 8 7 6 5 4 3 2 1  ETC


          }else if((peca == 'p' && xadrez[7][3] == 'p' && LO == 7 && CO == 3 && lD == 5 && cD == 3)&& ((LO - lD) == 2 ) && (deslocamentoHorizontal == 0)){

                        if(xadrez[LO][CO] == 'p' && xadrez[lD][cD] == ' '){
                            mover = 1;
              } // O MOVIMENTO DAS PRETAS E DECRESCENTE 8 7 6 5 4 3 2 1  ETC

          }else if((peca == 'p' && xadrez[7][4] == 'p' && LO == 7 && CO == 4 && lD == 5 && cD == 4)&& ((LO - lD) == 2 ) && (deslocamentoHorizontal == 0)){

                     if(xadrez[LO][CO] == 'p' && xadrez[lD][cD] == ' '){
                  mover = 1;
              }


          }else if((peca == 'p' && xadrez[7][5] == 'p' && LO == 7 && CO == 5 && lD == 5 && cD == 5)&& ((LO - lD) == 2 ) && (deslocamentoHorizontal == 0)){

                     if(xadrez[LO][CO] == 'p' && xadrez[lD][cD] == ' '){
                        mover = 1;
              }

          }else if((peca == 'p' && xadrez[7][6] == 'p' && LO == 7 && CO == 6 && lD == 5 && cD == 6)&& ((LO - lD) == 2 ) && (deslocamentoHorizontal == 0)){


                     if(xadrez[LO][CO] == 'p' && xadrez[lD][cD] == ' '){
                       mover = 1;
              }

          }else if((peca == 'p' && xadrez[7][7] == 'p' && LO == 7 && CO == 7 && lD == 5 && cD == 7)&& ((LO - lD) == 2 ) && (deslocamentoHorizontal == 0)){

                     if(xadrez[LO][CO] == 'p' && xadrez[lD][cD] == ' '){
                  mover = 1;
              }

          }else if((peca == 'p' && xadrez[7][8] == 'p' && LO == 7 && CO == 8 && lD == 5 && cD == 8)&& ((LO - lD) == 2 ) && (deslocamentoHorizontal == 0)){

                     if(xadrez[LO][CO] == 'p' && xadrez[lD][cD] == ' '){
                  mover = 1;
              }

  //=======================================================================================================================================================================================================================
  // MESMA LÓGICA SÓ TROCA AS LETRAS
               }else if(((xadrez[LO][CO] == 'p' && xadrez[lD][cD] == 'P' || xadrez[lD][cD] == 'T' || xadrez[lD][cD] == 'B' || xadrez[lD][cD] == 'C' || xadrez[lD][cD] == 'Q' || xadrez[lD][cD] == 'K')
               && (LO - lD) == 1) && (deslocamentoVertical == deslocamentoHorizontal)){

                      for(int i =0; i < 1;i++){
                     if(xadrez[LO][CO] == 'p' && xadrez [lD][cD] == 'K'){
                         contX = contX + 1 ; // contado global
                      //printf("=========yyyyy%d========",contX);
                      if(xadrez[LO][CO] == 'p' && xadrez [lD][cD] == 'K' && contX == 1){

                            return 4; // XEQUE
 // o CONTx SÓ PODE SER VISUALIZADO DUAS VEZES POR ISSO ELE ESTA DENTRO DA ESTRUTURA CONDICIONAL ORIGEM DESTINO SENDO K O DESTINO O REI  SENDO O REI VISUALIZADO PELO ATACANTE A PRIMEIRA VE E XEQUE
 // SE O CONTx FOR == 2 ENTÃO p VISUALIZOU E ATACOU K POIS O MESMO NÃO FOI MUDADO OU PROTEGIDO

                  }else if(xadrez[LO][CO] == 'p' && xadrez [lD][cD] == 'K' && contX == 2 ){
                      mover = 1;
                             if(mover == 1){
                    xadrez[lD][cD] = xadrez[LO][CO];
                    xadrez[LO][CO] = ' ';
                   return 3; // RETORNO DO XEQUE -MATE
                  }
               }
             }else{

              mover = 1; // MOVIMENTO NORMAL
                }
        }

               }


//=========================CONDIÇÃO MOVER========================================================================================================================================================================================
// CASO NÃO HAJA UM RETORNO  ESPECIFICO MAIS A CIMA OU UM XEQUE-MATE  HAVERÁ UM REETORNO  SERÁ UTILIZADA ESTA CONDIÇÃO CASO MOVER SEJA == A 1
               if(mover == 1){
                 xadrez[lD][cD] = xadrez[LO][CO];
                 xadrez[LO][CO] = ' ';
               return 1; // movimento realizado;
              }else{
              return 9; // peça não ode ser mechida
             }



    }else{
       printf("ERRO! VOCE ESTA  TADO MOVER UMA PEÇA QUE NAO E PRETA !\n ");
        getch();
       printf("POR FAVOR FACA UMA JOGADA VALIDA \n");
        jogadaPreta();
         mostrarMatriz(); // SERÁ ATUALIZADA  A MATRIZ APÓS A JOGADA !!!
        inversao(); // E POR FIM TROCAMOS OS VALORES DE BRANCAS E PRETAS !!
        }



            }else if(valor == 0){
                   printf("POR FAVOR FACA UMA JOGADA VALIDA \n");
                    getch();
                    mostrarMatriz(); // SERÁ ATUALIZADA  A MATRIZ APÓS A JOGADA !!!
                      jogadaPreta();



                 int  mover1 = 1;
                 //printf("===============ttttttt%d",mover1);
                   //printf("===============ttttttt%d",valor);
                     //printf("===============ttttttt%c",xadrez[LO][CO]);
                      inversao(); // E POR FIM TROCAMOS OS VALORES DE BRANCAS E PRETAS

                   getch();
                      if((mover1 == 1 )&&(valor == 0) && (xadrez[LO][CO] == 't') || (xadrez[LO][CO] == 'c') || (xadrez[LO][CO] == 'b') || (xadrez[LO][CO] == 'q') || (xadrez[LO][CO] == 'p') || (xadrez[LO][CO] == 'k') ){
                         if(mover == 1){
                         xadrez[lD][cD] = xadrez[LO][CO];
                         xadrez[LO][CO] = ' ';
                         return 1; // movimento realizado;
                        }else{
                          return 9; // peça não ode ser mechida
                        }

              }


            }




//=========================CONDIÇÃO MOVER========================================================================================================================================================================================
// CASO NÃO HAJA UM RETORNO  ESPECIFICO MAIS A CIMA OU UM XEQUE-MATE  HAVERÁ UM REETORNO  SERÁ UTILIZADA ESTA CONDIÇÃO CASO MOVER SEJA == A 1
        if(mover == 1){
         xadrez[lD][cD] = xadrez[LO][CO];
         xadrez[LO][CO] = ' ';
         return 1; // movimento realizado;
           }else{
              return 9; // peça não ode ser mechida
             }





    }else {
          return 0;
      }
}
//METODO DE INVERSAO============================================================================================================
// NESTE MÉTODO É FEITO A TROCA DOS VALORES  DAS  VARIÁVEIS  BRANCAS E PRETAS, SE BRANCAS É 1 OU SEJA É VERDADEIRA,  ENTÃO  BRANCAS
// PASSARAM A SER FALÇA E PRETAS VERDADEIRAS SE NÃO SE BRANCAS JÁ  FOR FALSA, FOR 0!!! ENTÃO ELA PASSA A SER 1 VERDADEIRA, E PRETAS  FALSAS  QUE E == 0
int inversao(){
  if(brancas == 1){ //TRUE
    brancas =0; // FALSE
    pretas = 1; //TRUE
  }else if(brancas == 0){
     brancas = 1;//TRUE
     pretas = 0;//FALSE
 }
}
//========= METODO JOGADA PEÇA BRANCA============================================================================================================
int jogadaBancada(){
    int resultado;
    char simbolo;
    int brancas1 = 1;
    int linhaOrigem =0;
    int  colunaOrigem =0;
    int linhaDestino =0;
    int  colunaDestino =0;

    if( brancas == 1 && pretas == 0 ){ // BRANCAS É VERDADEIRA OU SEJA É 1???? SE SIM, PODE JOGAR ! E SÃO, ELA E FALÇA E PRETA PODE JOGAR , OU SEJA OU UMA OU A OUTRA
    printf("POR FAVOR PECA BRANCA FACA A SUA JOGADA !\n");
    printf("Digite o simbolo da peca que sera movida\n");
    printf("Sendo as MAIUSCULAS AS PECAS BRANCAS !");
    scanf(" %c",&simbolo);
    if(simbolo == 'T' || simbolo == 'C' || simbolo == 'B' || simbolo == 'Q' || simbolo == 'K' || simbolo == 'P'){ // VERIFICANDO SE DE FATO  ESTOMAS MECHENDO COM AS PEÇAS BRANCAS. SE SIM PODE JOGAR SE NÃO  MENSSAGEM JOAGADA INVÁLIDA.
    printf("\nInforme a linha de origem !");
    scanf("%d",&linhaOrigem);               //ORIGEM !
      setbuf(stdin,NULL);
    printf("\nInforme a coluna de origem !");
    scanf("%d",&colunaOrigem);
      setbuf(stdin,NULL);
   printf("\n Informe a linha  de Destino !");
    scanf("%d",&linhaDestino);                // DESTINO !
      setbuf(stdin,NULL);
     printf("\nInforme a coluna de Destino !");
    scanf(" %d",&colunaDestino);
      setbuf(stdin,NULL);

        // printf("\n\n %d %d %d %d ",linhaOrigem,colunaOrigem,linhaDestino,colunaDestino);
      resultado = moverpeca(linhaOrigem, colunaOrigem, linhaDestino,colunaDestino, brancas1); // MÉTODO COM PASSAGEM DE PARÂMETROS OU ARGUMENTOS E COM RETORNO. ESSE VALOR DE RETORNO SERÁ JOGADO EM RESULTADO
      mostrarMatriz(); // SERÁ ATUALIZADA  A MATRIZ APÓS A JOGADA !!!
       inversao(); // E POR FIM TROCAMOS OS VALORES DE BRANCAS E PRETAS !!
      if(resultado != 1){ // SE RESULTADO FOR DIFERENTE DE 1, SERÁ MOSTRADA UMA MENSAGEM DE ERRO! E SERÁ PEDIDO PARA FAZER UMA JOGADA VÁLIDA . CASO CONTRARIO, ELE NÃO ENTRARA NESTA CONDIÇÃO
            switch( resultado){
             case 9 : printf("\nERRO : peca nao pode ser mechida\n"); getch();
             jogadaBancada();// COMO FOI MOSTRADO QUE A JOGADA ERA  INVÁLIDA,  ENTÃO E CHAMADO O MÉTODO PARA QUE ELE POSSA FAZER UMA JOAGADA VÁLIDA !
             inversao(); // E POR FIM TROCAMOS OS VALORES DE BRANCAS E PRETAS !!
              inversao();

             break;
             case 0 : printf("\nERRO : Coordenadas Invalidas\n"); getch();
             jogadaBancada();// COMO FOI MOSTRADO QUE A JOGADA ERA  INVÁLIDA,  ENTÃO E CHAMADO O MÉTODO PARA QUE ELE POSSA FAZER UMA JOAGADA VÁLIDA !
             inversao(); // E POR FIM TROCAMOS OS VALORES DE BRANCAS E PRETAS !!

             break;
             case 3:
                printf("XEQUE-MATE AS BRANCAS GANHARAM O JOGO \n");
                  getch();// NÃO PEGA NADA É SO PARA TRAVAR O CURSO E NÃO PASSAR DIRETO
                // system("CLS"); // FUNÇÃO LIMAP TELA
                printf("FIM DO JOGO !");
                exit(0); // FIM DO JOGO
                break;
            case 4:
                 printf("\n ATENCAO PECA PRETA VOCE ESTA EM  XEQUE, FACA A SUA JOGADA RAPIDO !!\n");
                 getch();// NÃO PEGA NADA É SO PARA TRAVAR O CURSO E NÃO PASSAR DIRETO
                jogadaPreta();
                //inversao(); // E POR FIM TROCAMOS OS VALORES DE BRANCAS E PRETAS !!

                break;



            }
    }
        mostrarMatriz(); // SERÁ ATUALIZADA  A MATRIZ APÓS A JOGADA !!!


    }else{

        printf("JOGADA INVALIDA!\n");
  }

    }
}

//===========================================================================================================================================

//========JOGADA PEÇA PRETA !================================================================================================================
int jogadaPreta(){
    int resultado;
    char simbolo;
    int brancas1 = 0; // ESTOU PASSANDO A VARIÁVEL BRANCAS COMO ARGUMENTO PARA  FAZER COM QUE AS PRETAS  SÓ POSSAM MOVER  AS MINUCULAS
    int linhaOrigem =0;
    int  colunaOrigem =0;
    int linhaDestino =0;
    int  colunaDestino = 0;
    if( brancas == 0 && pretas == 1){ // ESTOU VERIFICANDO OS VALORES DAS VARIÁVEIS GLOBAIS brancas E prentas,  SENDO ZERO PARA FALSO E 1 PARA VERDADEIRO
                                        // SE A VARIÁVEL preta FOR 1 ENTÃO ELA PODE JOGAR!!! SE NÃO ,  BRANCA É VERDADEIRA 1 E PRETA E ZERO  NESTE CASO A BRANCA JOGA E A PRETA NÃO.
    printf("POR FAVOR PECA PRETA FACA A SUA JOGADA !\n");
    printf("Por favo digite o simbolo da peca que sera mechida\n");
    printf("sendo as pretas as MINUSCULAS !\n");
    scanf(" %c",&simbolo);
    if(simbolo == 't' || simbolo == 'c' || simbolo == 'b' || simbolo == 'q' || simbolo == 'k' || simbolo == 'p'){ // NESTA ETAPA É VERIFICADO  SE O JOGADOR ESTÁ MOVIMENTADO AS PEÇAS PRETAS
        printf("Informe a linha de origem !\n");                                                                  // SENDO ELAS AS PEÇAS MINUSCULAS ( t de torre, c de cavalo,  b de bispo, q para rainha, e k para rei.
    scanf("%d",&linhaOrigem);
    setbuf(stdin,NULL);                 // ORIGEM !
    printf("Informe a coluna de origem !\n");
    scanf("%d",&colunaOrigem);
    setbuf(stdin,NULL);
   printf("\n Informe a linha  de Destino !");
    scanf("%d",&linhaDestino);                 // DESTINO !
    setbuf(stdin,NULL);
     printf("\nInforme a coluna de Destino !");
    scanf(" %d",&colunaDestino);
    setbuf(stdin,NULL); // ESSA FUNÇÃO ESTÁ LIMPADO O BUFF DE MEMÓRIA

        // printf("\n\n %d %d %d %d ",linhaOrigem,colunaOrigem,linhaDestino,colunaDestino);
      resultado = moverpecaPreta(linhaOrigem, colunaOrigem, linhaDestino,colunaDestino ,brancas1); // CHAMADA COM RETONO A FUNÇÃO  " movepeca(); " PARA A VARIÁVEL  " resultado ", ATEÇÃO!!  ESTÃO SENDO PASSADOS ARGUMENTOS PARA O MÉTODO !!
       inversao(); // E PRO FIM, SERÁ CHAMADO O MÉTODO DE INVERSÃO DE INVERSÃO  QUE INVERTERÁ OS VALORES  PARA QUE AS BRANCAS POSSAM JOGAR !!
      if(resultado != 1){// SE RESULTADO FOR DIFERENTE DE 1, SERÁ MOSTRADA UMA MENSAGEM DE ERRO! E SERÁ PEDIDO PARA FAZER UMA JOGADA VÁLIDA . CASO CONTRARIO, ELE NÃO ENTRARÁ NETA  CONDIÇÃO
            switch( resultado){//
            case 9 : printf("\nERRO : peca nao pode ser mechida"); getch();
             jogadaPreta();// COMO FOI MOSTRADO QUE A JOGADA ERA  INVÁLIDA,  ENTÃO E CHAMADO O MÉTODO PARA QUE ELE POSSA FAZER UMA JOAGADA VÁLIDA !
              inversao(); // E PRO FIM, SERÁ CHAMADO O MÉTODO DE INVERSÃO DE INVERSÃO  QUE INVERTERÁ OS VALORES  PARA QUE AS BRANCAS POSSAM JOGAR !!
              inversao(); // E PRO FIM, SERÁ CHAMADO O MÉTODO DE INVERSÃO DE INVERSÃO  QUE INVERTERÁ OS VALORES  PARA QUE AS BRANCAS POSSAM JOGAR !!
             break;
             case 0 : printf("\nERRO : Coordenadas Invalidas"); getch();
                if(resultado < 9){
                     jogadaPreta();// COMO FOI MOSTRADO QUE A JOGADA ERA  INVÁLIDA,  ENTÃO E CHAMADO O MÉTODO PARA QUE ELE POSSA FAZER UMA JOAGADA VÁLIDA !
                inversao(); // E PRO FIM, SERÁ CHAMADO O MÉTODO DE INVERSÃO DE INVERSÃO  QUE INVERTERÁ OS VALORES  PARA QUE AS BRANCAS POSSAM JOGAR !!
                   inversao();// COMO ESTAVA DANDO ERRO SENDO O VALOR DE INVERÇÃO  ERRADO COLOQUEI MAIS UM PARA JOGAR PARA O CORRETO
                }
             break;// SAIÍDA !
             case 3:
                printf("XEQUE-MATE AS PRETAS GANHARAM O JOGO \n");
                  getch(); // NÃO PEGA NADA É SO PARA TRAVAR O CURSO E NÃO PASSAR DIRETO
                //system("CLS"); // FUNÇÃO LIMPA TELA
                printf("FIM DO JOGO !");
                exit(0); // SAÍDA DO PROGRAMA
                break;
             case 4:
                  printf("\n ATENCAO PECA BRANCA VOCE ESTA EM  XEQUE, FACA A SUA JOGADA RAPIDO !!\n");
                  getch();// NÃO PEGA NADA É SO PARA TRAVAR O CURSO E NÃO PASSAR DIRETO
                   jogadaBancada();
                    //inversao(); // E PRO FIM, SERÁ CHAMADO O MÉTODO DE INVERSÃO DE INVERSÃO  QUE INVERTERÁ OS VALORES  PARA QUE AS BRANCAS POSSAM JOGAR !!
                break;

            }
    }

    mostrarMatriz(); // SERÁ ATUALIZADA  A MATRIZ APÓS A JOGADA !!!


    }else{

        printf("JOGADA INVALIDA!");
  }

    }
}


//=========== METODO PRINCIPAL===========================================================================================================================//
// NESTA PARTE DO CÓDIGO SERÃO REALIZADAS AS MACHADAS  AOS PRINCIPAIS MÉTODOS !!
int main(){

    int num1 =0;
     while(num1 <1){
    mostrarMatriz();// CHAMADA AO MÉTODO mostrazMatriz(); !! NESTE CASO O CURSO SAI DESSA LINHA E VAI PARA O MÉTODO mostrarMatriz();
   jogadaBancada();// CHAMADA AO MÉTODO jogadaBranca(); !! NESTE CASO O CURSO SAI DESSA LINHA E VAI PARA O MÉTODO jogadaBranca();
   jogadaPreta();// CHAMADA AO MÉTODO jogadaPreta(); !! NESTE CASO O CURSO SAI DESSA LINHA E VAI PARA O MÉTODO jogadaPreta();
   /*
    * QUANDO É REALIZADA UMA CHAMADA A UMA FUNÇÃO OU MÉTODO, O CURSOS SAI DA LINHA DA CHAMADA  E  ENTRA  NA DETERMINADA FUNÇÃO  E EXECUTA TUDO QUE TEM DETRO DA FUÇÃO
    * PODENDO RETORNAR VALOR OU NÃO.
    * E LOGO SAÍ DA MESMA  RETORNANDO AO MAIN(); EXECUTANDO O QUE ESTIVER  ABAIXO  DA CHAMADA DA FUNÇÃO!!
   */

    getch();// o getch é essencial para que o loop não seja contíuno !!!! ATÉ PORQUE NUM1 É IGUAL A ZERO !
   }
   getch();
      return 0;
 }








