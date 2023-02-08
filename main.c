// TAREFA PASSEIO DO CAVALO DESGOVERNADO - UERJ-ZO
// ALUNO: LUCAS MATIAS GÓES DA SILVA
// CURSO: CIÊNCIA DA COMPUTAÇÃO
// PROF: DR. EUGÊNIO DA SILVA
// 2022.2

// ALUNO, USE COMO BASE, NÂO COPIE E COLE APENAS,


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(){

//============================================= variáveis ============================================

    char vetorTabuleiro[8][8], cc = 'C', vazio = '*', X='X'; //Variáveis visuais do tabuleiro
    int x, y, i, j, linha, coluna, vitoria = 0;//Variáveis de funcionamento
    int cavalo_esqCima[2] = {-2,-1}, cavalo_esqBaixo[2] = {-2,1},cavalo_dirCima[2] = {2,-1}, cavalo_dirBaixo[2] = {2,1};//Movimentação no eixo X
    int cavalo_cimaEsq[2] = {-1,-2}, cavalo_cimaDir[2] = {1,-2}, cavalo_baixoEsq[2] = {-1,2}, cavalo_baixoDir[2] = {1,2};//Movimentação no eixo y
    int cavaloPassos_random [8];        //aleatoriedade de movimento do cavalo baseado na movimentação pré definida acima;
    int cavaloMov[2], cavaloCompara;         // CavaloMov salva a movimentação escolhida aleatoriamente || cavaloCompara verifica no Switch se é possível a movimentação
    int cavaloPosicao[2];       // Define a posição inicial do cavalo
    int evitarRepeticao_1 = 0;         //Evitar repetições de numeros na movimentação
    int repetido;            //garante que não irá ter movimentações repetidas
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

        //repetição que garante que o usuário irá colocar o valor correto no vetor X
        while(linha < 1 || linha > 8){
            printf("\n Por favor, apenas números de 1 ate 8\n\n");
            printf("Escolha a linha aonde o cavalo deve aparecer: ");
            scanf("%d", &linha);

    }
    printf("\n Escolha a coluna aonde o cavalo deve aparecer: ");
    scanf("%d", &coluna);

        //repetição que garante que o usuário irá colocar o valor correto no vetor y
        while(coluna < 1 || coluna > 8){
            printf("\n Por favor, apenas números de 1 ate 8\n\n");
            printf("Escolha a coluna aonde o cavalo deve aparecer: ");
            scanf("%d", &coluna);
    }
    linha--;
    coluna--;
    vetorTabuleiro[linha][coluna] = cc;
    contador++;
//=============================== Looping do jogo ===========================================
    while(vitoria == 0){

//--------------------Movimentação aleatória do cavalo----------------------

        //Gerador de números aleatórios sem repetição
        for(i = 0; i < 8; i++){
            srand(time(NULL)); //Garante que o número será "Aleatório", toda vez que for iniciado o for (Afinal, a aleatoriedade é um paradigma da computação)
            cavaloPassos_random[i] = rand() % 8; // sorteia um número
            cavaloPassos_random[i]++; //garante que será um valor de 1 até 8
            evitarRepeticao_1 = 0;
                for(j = 0; j < i; j++){ // percorre a parte do vetor já preenchida
                if(cavaloPassos_random[j] == cavaloPassos_random[i]) //se o numero sorteado for igual a algum outro já sorteado antes
                    evitarRepeticao_1 = 1; //diz que o número é repetido
                    //se ele é um número é repetido(como a variável acima), "i" não recebe complemento, então é reiniciado até ser gerado um número diferente

                }

            if(evitarRepeticao_1 == 0) // significa que o elemento não se repetiu
                i++;}

             // enquanto não for sorteado 8 números diferentes

//----------- Estrutura de decisão de aleatoriedade ----------

             cavaloCompara = cavaloPassos_random[0];
             switch (cavaloCompara){
                case 1: //movimentação esquerda-cima
                    if(vetorTabuleiro[linha + cavalo_esqCima[0]][coluna + cavalo_esqCima[1]]== vazio) //verifica se a próxima casa pode ser preenchida
                        {
                            vetorTabuleiro[linha][coluna] = X; //define que a casa em que o cavalo estava será preenchida com um "X", impedindo que ele vá para lá novamente
                            vetorTabuleiro[linha + cavalo_esqCima[0]][coluna + cavalo_esqCima[1]] = cc; //define a nova posição do cavalo
                            linha += cavalo_esqCima[0]; //salva a movimentação 1 do cavalo
                            coluna += cavalo_esqCima[1];//salva a movimentação 2 do cavalo
                            contador++; //conta quantas casas o cavalo andou
                            break;// finaliza o switch
                    }else{cavaloCompara = 2; tentativas++;} //caso não seja possível, tenta o próximo caso e atribui uma tentativa errada ao contador

                    //A estrutura acima se repete para as próximas 7 posições possíveis

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

//------ Tela de jogo e repetição -------
        system("cls");//aciona o comando do Windows para limpar a tela (não funciona fora do windows)
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

        system("pause"); //aciona o comando de pausa de execução do Windows


        if(tentativas >= 100){ //limitação de tentativas, para finalizar o jogo
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
            printf("Digite qualquer valor para finalizar: "); //Apenas uma trava forçando a pausa total, caso o usuário pressione algum botão para que o jogo finalize mais rápido
            scanf("%d", &finalizar);
            vitoria++;
        }
            system("pause");



//------- Movimentação do cavalo --------



    }//fim while vitoria



    return 0;
}
