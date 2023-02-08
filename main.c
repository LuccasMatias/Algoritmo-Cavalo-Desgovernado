// TAREFA PASSEIO DO CAVALO DESGOVERNADO - UERJ-ZO
// ALUNO: LUCAS MATIAS G�ES DA SILVA
// CURSO: CI�NCIA DA COMPUTA��O
// PROF: DR. EUG�NIO DA SILVA
// 2022.2

// ALUNO, USE COMO BASE, N�O COPIE E COLE APENAS,


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(){

//============================================= vari�veis ============================================

    char vetorTabuleiro[8][8], cc = 'C', vazio = '*', X='X'; //Vari�veis visuais do tabuleiro
    int x, y, i, j, linha, coluna, vitoria = 0;//Vari�veis de funcionamento
    int cavalo_esqCima[2] = {-2,-1}, cavalo_esqBaixo[2] = {-2,1},cavalo_dirCima[2] = {2,-1}, cavalo_dirBaixo[2] = {2,1};//Movimenta��o no eixo X
    int cavalo_cimaEsq[2] = {-1,-2}, cavalo_cimaDir[2] = {1,-2}, cavalo_baixoEsq[2] = {-1,2}, cavalo_baixoDir[2] = {1,2};//Movimenta��o no eixo y
    int cavaloPassos_random [8];        //aleatoriedade de movimento do cavalo baseado na movimenta��o pr� definida acima;
    int cavaloMov[2], cavaloCompara;         // CavaloMov salva a movimenta��o escolhida aleatoriamente || cavaloCompara verifica no Switch se � poss�vel a movimenta��o
    int cavaloPosicao[2];       // Define a posi��o inicial do cavalo
    int evitarRepeticao_1 = 0;         //Evitar repeti��es de numeros na movimenta��o
    int repetido;            //garante que n�o ir� ter movimenta��es repetidas
    int contador = 0, tentativas = 0, finalizar = 0;



//========================================== Menu Regras =============================================
    printf("           =================== Bem vindo ao Passeio do CAVALO DESGOVERNADO =================== \n\n\n\n");
    printf("           As Regras sao simples: \n\n           Escolha um local aonde deseja que o cavalo devera parecer,\n           ele ira caminhar aleatoriamente pelo tabuleiro. \n           Limite de tentativas: 100 \n\n\n");
    system("pause");
    system("cls");

//============================================= Game ==================================================
    //Tela inicial do jogo
    printf("                      ========================= \n                         CAVALO DESGOVERNADO   \n                      ========================= \n\n");

    //Cria o tabuleiro 8x8 com os caracteres "*" que representam o vazio
    for(x = 0; x < 8; x++) {
        printf("\n");
        printf("                           ");
        for(y = 0; y < 8; y++){

                vetorTabuleiro[x][y] = vazio;
                printf("%c ", vetorTabuleiro[x][y]);
        }
    }


    printf("\n\n");
    printf("\n Escolha a linha aonde o cavalo deve aparecer: ");
    scanf("%d", &linha);

        //repeti��o que garante que o usu�rio ir� colocar o valor correto no vetor X
        while(linha < 1 || linha > 8){
            printf("\n Por favor, apenas n�meros de 1 ate 8\n\n");
            printf("Escolha a linha aonde o cavalo deve aparecer: ");
            scanf("%d", &linha);

    }
    printf("\n Escolha a coluna aonde o cavalo deve aparecer: ");
    scanf("%d", &coluna);

        //repeti��o que garante que o usu�rio ir� colocar o valor correto no vetor y
        while(coluna < 1 || coluna > 8){
            printf("\n Por favor, apenas n�meros de 1 ate 8\n\n");
            printf("Escolha a coluna aonde o cavalo deve aparecer: ");
            scanf("%d", &coluna);
    }
    linha--;
    coluna--;
    vetorTabuleiro[linha][coluna] = cc;
    contador++;
//=============================== Looping do jogo ===========================================
    while(vitoria == 0){

//--------------------Movimenta��o aleat�ria do cavalo----------------------

        //Gerador de n�meros aleat�rios sem repeti��o
        for(i = 0; i < 8; i++){
            srand(time(NULL)); //Garante que o n�mero ser� "Aleat�rio", toda vez que for iniciado o for (Afinal, a aleatoriedade � um paradigma da computa��o)
            cavaloPassos_random[i] = rand() % 8; // sorteia um n�mero
            cavaloPassos_random[i]++; //garante que ser� um valor de 1 at� 8
            evitarRepeticao_1 = 0;
                for(j = 0; j < i; j++){ // percorre a parte do vetor j� preenchida
                if(cavaloPassos_random[j] == cavaloPassos_random[i]) //se o numero sorteado for igual a algum outro j� sorteado antes
                    evitarRepeticao_1 = 1; //diz que o n�mero � repetido
                    //se ele � um n�mero � repetido(como a vari�vel acima), "i" n�o recebe complemento, ent�o � reiniciado at� ser gerado um n�mero diferente

                }

            if(evitarRepeticao_1 == 0) // significa que o elemento n�o se repetiu
                i++;}

             // enquanto n�o for sorteado 8 n�meros diferentes

//----------- Estrutura de decis�o de aleatoriedade ----------

             cavaloCompara = cavaloPassos_random[0];
             switch (cavaloCompara){
                case 1: //movimenta��o esquerda-cima
                    if(vetorTabuleiro[linha + cavalo_esqCima[0]][coluna + cavalo_esqCima[1]]== vazio) //verifica se a pr�xima casa pode ser preenchida
                        {
                            vetorTabuleiro[linha][coluna] = X; //define que a casa em que o cavalo estava ser� preenchida com um "X", impedindo que ele v� para l� novamente
                            vetorTabuleiro[linha + cavalo_esqCima[0]][coluna + cavalo_esqCima[1]] = cc; //define a nova posi��o do cavalo
                            linha += cavalo_esqCima[0]; //salva a movimenta��o 1 do cavalo
                            coluna += cavalo_esqCima[1];//salva a movimenta��o 2 do cavalo
                            contador++; //conta quantas casas o cavalo andou
                            break;// finaliza o switch
                    }else{cavaloCompara = 2; tentativas++;} //caso n�o seja poss�vel, tenta o pr�ximo caso e atribui uma tentativa errada ao contador

                    //A estrutura acima se repete para as pr�ximas 7 posi��es poss�veis

                 case 2://movimento esquerda-baixo
                     if(vetorTabuleiro[linha + cavalo_esqBaixo[0]][coluna + cavalo_esqBaixo[1]]== vazio){
                        vetorTabuleiro[linha][coluna] = X;
                        vetorTabuleiro[linha + cavalo_esqBaixo[0]][coluna + cavalo_esqBaixo[1]] = cc;
                        linha += cavalo_esqBaixo[0];
                        coluna += cavalo_esqBaixo[1];
                        contador++;
                        break;
                     }else{cavaloCompara = 3; tentativas++;}

                case 3://movimento direita-cima
                     if(vetorTabuleiro[linha + cavalo_dirCima[0]][coluna + cavalo_dirCima[1]]== vazio){
                        vetorTabuleiro[linha][coluna] = X;
                        vetorTabuleiro[linha + cavalo_dirCima[0]][coluna + cavalo_dirCima[1]] = cc;
                        linha += cavalo_dirCima[0];
                        coluna += cavalo_dirCima[1];
                        contador++;
                        break;
                     }else{cavaloCompara = 4; tentativas++;}

                case 4://movimento direita-baixo
                     if(vetorTabuleiro[linha + cavalo_dirBaixo[0]][coluna + cavalo_dirBaixo[1]]== vazio){
                        vetorTabuleiro[linha][coluna] = X;
                        vetorTabuleiro[linha + cavalo_dirBaixo[0]][coluna + cavalo_dirBaixo[1]] = cc;
                        linha += cavalo_dirBaixo[0];
                        coluna += cavalo_dirBaixo[1];
                        contador++;
                        break;
                     }else{cavaloCompara = 5; tentativas++;}

                case 5://movimento cima-esquerda
                     if(vetorTabuleiro[linha + cavalo_cimaEsq[0]][coluna + cavalo_cimaEsq[1]]== vazio){
                        vetorTabuleiro[linha][coluna] = X;
                        vetorTabuleiro[linha + cavalo_cimaEsq[0]][coluna + cavalo_cimaEsq[1]] = cc;
                        linha += cavalo_cimaEsq[0];
                        coluna += cavalo_cimaEsq[1];
                        contador++;
                        break;
                     }else{cavaloCompara = 6; tentativas++;}

                case 6://movimento cima-direita
                     if(vetorTabuleiro[linha + cavalo_cimaDir[0]][coluna + cavalo_cimaDir[1]]== vazio){
                        vetorTabuleiro[linha][coluna] = X;
                        vetorTabuleiro[linha + cavalo_cimaDir[0]][coluna + cavalo_cimaDir[1]] = cc;
                        linha += cavalo_cimaDir[0];
                        coluna += cavalo_cimaDir[1];
                        contador++;
                        break;
                     }else{cavaloCompara = 7; tentativas++;}

                case 7://movimento baixo-esquerda
                     if(vetorTabuleiro[linha + cavalo_baixoEsq[0]][coluna + cavalo_baixoEsq[1]]== vazio){
                        vetorTabuleiro[linha][coluna] = X;
                        vetorTabuleiro[linha + cavalo_baixoEsq[0]][coluna + cavalo_baixoEsq[1]] = cc;
                        linha += cavalo_baixoEsq[0];
                        coluna += cavalo_baixoEsq[1];
                        contador++;
                        break;
                     }else{cavaloCompara = 8; tentativas++;}
                case 8://movimento baixo-esquerda
                     if(vetorTabuleiro[linha + cavalo_baixoDir[0]][coluna + cavalo_baixoDir[1]]== vazio){
                        vetorTabuleiro[linha][coluna] = X;
                        vetorTabuleiro[linha + cavalo_baixoDir[0]][coluna + cavalo_baixoDir[1]] = cc;
                        linha += cavalo_baixoDir[0];
                        coluna += cavalo_baixoDir[1];
                        contador++;
                        break;
                     }else{cavaloCompara = 1; tentativas++;}
                    }//fim switch

//------ Tela de jogo e repeti��o -------
        system("cls");//aciona o comando do Windows para limpar a tela (n�o funciona fora do windows)
        printf("                           ========================= \n                              CAVALO DESGOVERNADO   \n                           ========================= \n\n");

        //Desenha o tabuleiro na tela
        for(x = 0; x < 8; x++) {
            printf("\n                               ");
            for(y = 0; y < 8; y++){
                printf("%c ", vetorTabuleiro[x][y]);
            } //fim for Y
        }//fim for X


        printf("\n\n");
        printf("\n                           Contador de passos: %d\n", contador);
        printf("\n                           Contador de Tentativas erradas: %d\n\n\n", tentativas);

        system("pause"); //aciona o comando de pausa de execu��o do Windows


        if(tentativas >= 100){ //limita��o de tentativas, para finalizar o jogo
            for(x = 0; x < 8; x++) {
            printf("\n                               ");
            for(y = 0; y < 8; y++){
                printf("%c ", vetorTabuleiro[x][y]);
                } //fim for Y
            }//fim for X


            system("cls");
            printf("----------------------------- Fim de Jogo ------------------------------ \n\n\n");
                for(x = 0; x < 8; x++) { //desenha uma ultima vez o tabuleiro, mostrando os resultados e o percurso do cavalo
                    printf("\n                               ");
                    for(y = 0; y < 8; y++){
                        printf("%c ", vetorTabuleiro[x][y]);
                    } //fim for Y
                        }//fim for X
            printf("\n                           Passos acertados: %d\n", contador);
            printf("\n                           Tentativas erradas: %d\n\n\n", tentativas);
            printf("Digite qualquer valor para finalizar: "); //Apenas uma trava for�ando a pausa total, caso o usu�rio pressione algum bot�o para que o jogo finalize mais r�pido
            scanf("%d", &finalizar);
            vitoria++;
        }
            system("pause");



//------- Movimenta��o do cavalo --------



    }//fim while vitoria



    return 0;
}
