#include <stdio.h>
#include <string.h>	
#include <math.h>	
#include <stdlib.h>
#include <time.h>																						

//___________________________________________________________tCoordenada_______________________________________________________________________//

typedef struct{
	
	int coluna;
	int linha;            //valor numerico da coordenada alfabética pós-convertida//
	char letra;			
	int confirmaLeitura;	
	char strCord[10];		//string com a coordenada completa//
	
}tCoordenada;

int LeCoordenadaAlfabetica(char letra);
tCoordenada LeCoordenada();
int FoiCoordenadaLidaComSucesso(tCoordenada coordenada);
int EhCoordenada1IgualA2(tCoordenada c1, tCoordenada c2);
int CoordenadaLinhaCoordenada(tCoordenada coordenada);
int CoordenadaColunaCoordenada(tCoordenada coordenada);
void ImprimeCoordenada(tCoordenada coordenada);
char GeraCoordenadaAlfabetica(int num);
void ImprimeCoordenadaNoArquivo(tCoordenada coordenada, FILE * file);
tCoordenada GeraCoordenadaAleatoria();


//___________________________________________________________________________________tNavio_______________________________________________________//
typedef struct{
	
	char nome[10];
	int orientacao;		//vertical/horizontal//
	int ID;
	tCoordenada coordenada;		//Coordenada do primeiro ponto do navio//
	int tamanho;
	int confirmaLeitura;   //variável para verificar se as informações do navio foram lidas da maneira esperada//
	
}tNavio;

tNavio LeNavios(FILE * file);
int CalculaTamanhoDoNavio(char nome[]); 
tNavio ColocaCoordenadaEOrientacaoNoNavio(tNavio navio, tCoordenada cord, int ori);
int EhNomeValido(char nome[]);
int EhOrientacaoValida(int ori);
int EhCoordenadaValida(tCoordenada coordenada);
int NomeNavio(tNavio navio);
int CoordenadaLinhaNavio(tNavio navio);
int CoordenadaColunaNavio(tNavio navio);
int DirecaoNavio(tNavio navio);
int TamanhoNavio(tNavio navio);
int NaviosTemMesmaCoordenada(tNavio navio1, tNavio navio2);
int IdNavio(tNavio navio);
int EhPossivelAdicionarONavioNoTablado(char tab[10][10], tNavio navio);
tNavio InicializaNavioComNomeEiD(char * nome, int num);
void AdicionaUmNavioNoCampoDeBatalha(char tab[10][10], tNavio navio);
void ImprimeNavioNoArquivoDeTabuleiroAleatorio(tNavio navio, FILE * file);
int GeraSentidoAleatorio();
int FoiNavioLidoComSucesso(tNavio navio);


//_______________________________________________________________________________tTabuleiro___________________________________________//
typedef struct{
	
	int qtdNaviosTotal;
	tNavio navio[100];				//navios presetes no tabuleiro//
	char campoDeBatalha[10][10];     // Tabuleiro "físico"//
	
}tTabuleiro;

tTabuleiro LeTabuleiro(FILE * file);
int EhTabuleiroValido(tTabuleiro tabuleiro);
int NaviosEstaoEncostadosOuSobrepostos(tTabuleiro tabuleiro);
int CampoDeBatalhaCriadoComSucesso(tTabuleiro tabuleiro);
int SaoTabuleirosCompativeisEntreSi(tTabuleiro tab1, tTabuleiro tab2);
void GeraTabuleiroVazio(int linha, int coluna, char matriz[linha][coluna]);
void GeraTabuleiroAuxiliarVazio(int tablado[10][10]);
void PreparaTabuleiroAuxiliar(tTabuleiro tabuleiro, int tablado[10][10]);
void GeraTabuleiroSaidaVazio(char tablado[10][10]);
int TemCoordenadaIgual(tTabuleiro tabuleiro);
void CopiaMatriz1Na2(int l1, int c1, char m1[l1][c1], int l2, int c2, char m2[l2][c2]);
int AfundouNavio(int tablado[10][10], int num);
int JogadorVenceu(int tablado[10][10]);
void ImprimeTabuleiro(tTabuleiro tabuleiro);
tTabuleiro AdicionaNaviosNoTabuleiro(tTabuleiro tabuleiro);
void ImprimeTabuleiroNoArquivo(tTabuleiro tabuleiro, FILE * file);
void ImprimeTabladoSaida(char tablado[10][10], char nome1 [], char nome2[]);
void ImprimeTabladoAuxiliar(int tablado[10][10]);
void GeraTabuleiroAleatorio(char ** argv);
void CriaArquivoDeInicializacao(FILE * file, tTabuleiro tab1, tTabuleiro tab2, char nome1[], char nome2[]);


//____________________________________________________________________________tJogada____________________________________________________________________________________//
typedef struct{
	
	char tipo[10];				//Agua ou Tiro
	char navioAcertado[12];		//nome do navio que foi atingido
	int idNavioAcertado;		//id do navio
	tCoordenada coordenada;		
	int confirmaLeitura;		//confirmação de leitura da jogada//
	int numJogada;				//numero da jogada a partir do 1//
	
}tJogada;

tJogada LeJogada();
int EhJogadaValida(tJogada jogada);
int EhJogadaRepetida(tJogada vetjogada[], tJogada jogada, int qtdJog);
int OrdemDaJogada(tJogada jogada);
int NumDaJogada(tJogada jogada);
int IdNavioDaJogada(tJogada jogada);
int TipoDaJogada(tJogada jogada);
tJogada ColocaNomeDoNavioAcertadoNaJogada(tNavio navio, tJogada jogada);
tJogada ColocaNumDaJogada(tJogada jogada, int num);
tJogada RealizaJogada(tTabuleiro tabuleiro, tJogada jogada, int tabladoId[10][10], char tabladoSaida[10][10], int qJ);
void ImprimeJogadaNoArquivoResultado(tJogada jogada, FILE * file);
void ImprimeJogadaNoArquivoDeEstatistica(tJogada jogada, FILE * file);
void CriaArquivoDeResultado(char nomeJogador1[], char nomeJogador2[], tJogada jogadas1[], int qtd1, tJogada jogadas2[], int qtd2, int empate, char vencedor[], FILE * file);
tJogada JogaJogador(char nomeJogador[], tJogada jogadasJogador1[], tJogada jogadaJogador1, int qJ1, int tabuAuxiliar2[10][10], char tabuSaida2[10][10], tTabuleiro tabuInimigo);
int EhJogada1MenorQJogada2(tJogada jogada1, tJogada jogada2);
int JogadasPossuemOMesmoNavio(tJogada jogada1, tJogada jogada2);


//_______________________________________________________________________tEstatistica__________________________________________________________________________________________//

typedef struct{
	
	int tirosErrados;		//tiros na água//
	int tirosCertos;		//tiros em navios//
	float linhaMedia;		//linha media de acertos//
	float colunaMedia;		//coluna media de acertos//
	float desvioPadrao;		
	char nomeDoJogador[17];	//dono da estatistica//
	tJogada jogada[100];	//jogadas do inimigo sobre seu tabuleiro//
	int qtdJogadas;			
	
}tEstatistica;

float CalculaDesvioPadrao(float lm, float cm, tJogada * jogada, int qJ);
float CalculaMediaColuna(tJogada * jogada, int qJ);
float CalculaMediaLinha(tJogada * jogada, int qJ);
int ContaTirosCertos(tJogada * jogada, int qJ);
int ContaTirosErrados(tJogada * jogada, int qJ);
tEstatistica GeraEstatisticas(tJogada * jogada, int qJ, int qJ2, tJogada * jogadaNav, char nome[]);
tEstatistica OrganizaNaviosEmOrdemAlfabetica(tEstatistica estatistica);
void GeraArquivoEstatisticas(tEstatistica estatistica, FILE * file);


//_________________________________________________________tJogo_________________________________________________________//


typedef struct{
	
	int EhJogoValido;		//verifica se o jogo pode continuar rodando
	char jogador1[17];		//nome do jogador 1
	char jogador2[17];		//nome do jogador 2
	tTabuleiro tabu1;		//tabuleiro do jogador 1
	tTabuleiro tabu2;		//tabuleiro do jogador 2
	
}tJogo;

void LeJogadores(char str[], char str2[]);
int DiretorioNaoFoiInformado(int valorArg);
int EhJogoValido(tJogo jogo);
int EhPar(int num);
tJogo InicializaJogo(int argc, char ** argv);
void JogaJogo(tJogo jogo, char** argv);
int EhParaGerarTabuleiro(char * vet, char ** argv);


//____________________________________________________________________________FUNÇÃO_PRINCIPAL____________________________________________________________________________________//


int main(int argc, char ** argv){
	
	tJogo jogo;
	char entrada[1000];
	
	
	if(EhParaGerarTabuleiro(entrada,argv)){		//VERIFICA SE FOI DIGITADO O "-gt" NA LINHA DE COMANDO//
		
		GeraTabuleiroAleatorio(argv);	//SE FOI, GERA TABULEIRO ALEATORIO//
	}
	
	else{		//SENAO, COMECA O JOGO//
		
		jogo = InicializaJogo(argc, argv);	//INICIALIZA OS JOGOS VERIFICANDO OS TABULEIROS E GERANDO ARQUIVO DE INICIALIZACAO//
		if(!EhJogoValido(jogo)) return 1;	//SE OS TABULEIROS NAO FOREM VALIDOS E COMPATIVEIS O PROG FECHA//
		JogaJogo(jogo, argv);				//CASO, CONTRÁRIO, O PROG RODA O JOGO//
	}
	
	
	return 0;
}


//_________________________________________________________________________DESENVOLVIMENTO_DAS_FUNÇÕES____________________________________________________________________________//


//Função para ler um navio do arquivo tabu.txt, ou seja, uma linha//
tNavio LeNavios(FILE * file){          
	
	tNavio navio;											  //			
	tCoordenada coordenada;									  //
	char nome[11], str[20];									  // VARIÁVEIS PARA ATRIBUIR OS VALORES CONTIDOS EM UMA LINHA DO ARQUIVO//
	int id=0, orientacao=-1, tamanho =0, rtn=0;               //
	
	
	navio.confirmaLeitura = 1;     //CONFIRMAÇÃO DE LEITURA DO ARQUIVO COMEÇA SETADA EM 1//
		
		
	fscanf(file,"%[^\n]\n", str);	 //LE UMA LINHA DO ARQUIVO E JOGA NA STRING INFORMADA//	
	rtn = sscanf(str,"%[^;];%d;%d;%c%d%*[^\n]\n", nome, &id, &orientacao, &coordenada.letra, &coordenada.coluna );    //LE O CONTEÚDO DA STRING E ATRIBUI ÀS VARIÁVEIS INFORMADAS//
		
	tamanho = CalculaTamanhoDoNavio(nome);  //CALCULA O TAMANHO DO NAVIO E JOGA NA VARIÁVEL//
	
	if(!EhNomeValido(nome)) navio.confirmaLeitura = 0;					//
	if(!EhOrientacaoValida(orientacao)) navio.confirmaLeitura = 0;		//
	if(!EhCoordenadaValida(coordenada)) navio.confirmaLeitura = 0;		// VERIFICA SE AS INFORMAÇÕES CONTIDAS NO ARQUIVO SÃO VÁLIDAS//
	if(rtn < 5) navio.confirmaLeitura = 0;								//
	
	
	coordenada.linha = LeCoordenadaAlfabetica(coordenada.letra);             //Le um caracter de 'a' a 'j' e joga o inteiro correspondente a ele (de acordo com o tabuleiro) em uma variável//
	
	strcpy(navio.nome, nome);			//
	navio.ID = id;						//
	navio.orientacao = orientacao;		// ARMAZENA AS INFORMAÇÕES DO NAVIO NO TIPO TNAVIO//
	navio.coordenada = coordenada;		//
	navio.tamanho = tamanho;			//

	
	
	return navio;
}


//Função para ler o arquivo tabu.txt todo, ou seja, todas as linhas// 
tTabuleiro LeTabuleiro(FILE * file){
	
	tTabuleiro tabuleiro;
	tNavio navio;							
	int x=0;
	
	while(!feof(file)){								//ENQUANTO NÃO FOR O FINAL DO ARQUIVO, O PROGRAMA CONTINUA LENDO OS NAVIOS E ARMAZENA NO TIPO TTABULEIRO//
		
		tabuleiro.navio[x] = LeNavios(file);
		x++;
	}
	
	tabuleiro.qtdNaviosTotal = x;	
	GeraTabuleiroVazio(10, 10, tabuleiro.campoDeBatalha);	//INICIALIZA O "CAMPO DE BATALHA" VAZIO NO TIPO TTABULEIRO//
	
	return tabuleiro;
}


//Função para verificar se o tabuleiro é válido//
int EhTabuleiroValido(tTabuleiro tabuleiro){
	
	tCoordenada coordenada;
	int x=0;
	
	if(tabuleiro.qtdNaviosTotal == 0) return 0;						//CASO NÃO HAJA NAVIOS NO ARQUIVO//	  
	
	for(x=0;x<tabuleiro.qtdNaviosTotal;x++){
			
		if(!FoiNavioLidoComSucesso(tabuleiro.navio[x])) return 0;  		//VERIFICA A VARIÁVEL QUE CRIEI PARA CONFIRMAR A LEITURA DOS COMPONENTES//     
	}
	
	if(NaviosEstaoEncostadosOuSobrepostos(tabuleiro)) return 0;		//CASO OS NAVIOS ESTEJAM ENCOSTADOS OU UM SOBRE O OUTRO//
	
	return 1;
}


//Função para verificar se o navio foi lido sem erro//
int FoiNavioLidoComSucesso(tNavio navio){
	
	return navio.confirmaLeitura;
}


//Função para verificar se o nome do navio é válido//
int EhNomeValido(char nome[]){
	
	if(strcmp(nome, "Carrier")==0) return 1;
	else if(strcmp(nome, "Battleship")==0) return 1;
	else if(strcmp(nome, "Cruiser")==0) return 1;					//COMPARA OS NOMES LIDOS COM OS NAVIOS PEDIDOS NO TRABALHO//
	else if(strcmp(nome, "Submarine")==0) return 1;
	else if(strcmp(nome, "Destroyer")==0) return 1;
	
	else return 0; 	
}


// Função para verificar se foi fornecida uma das orientações esperadas//
int EhOrientacaoValida(int ori){
	
	if(ori == 0 || ori == 1) return 1;
	else return 0;	
}


// Função para verificar se é uma coordenada válida no tabuleiro//
int EhCoordenadaValida(tCoordenada coordenada){
	
	if(coordenada.letra > 'j' || coordenada.letra < 'a') return 0;
	else{
		
		if(coordenada.coluna > 10 || coordenada.coluna < 1) return 0;
		else return 1;
	}
}


//Função para gerar uma matriz que será o tabuleiro "físico" do jogo//
void GeraTabuleiroVazio(int linha, int coluna, char matriz[linha][coluna]){
	
	int l=0, c=0;
	
	for(l=0;l<10;l++){
		
		for(c=0;c<10;c++){
			
			matriz[l][c] = 'o';
		}		
	}	
}


//Função para verificar se há a presença de navios no tabuleiro com coordenadas iguais//
int TemCoordenadaIgual(tTabuleiro tabuleiro){
	
	int x=0, y=0;
		
	for(x=0;x<tabuleiro.qtdNaviosTotal - 1;x++){
																							
		for(y=x+1;y<tabuleiro.qtdNaviosTotal;y++){
			
			if(NaviosTemMesmaCoordenada(tabuleiro.navio[x], tabuleiro.navio[y])) return 1;
		}
	}	
	return 0;
}


//Função para comparar duas coordenadas e verificar se são iguais//
int EhCoordenada1IgualA2(tCoordenada c1, tCoordenada c2){
	
	if(c1.letra == c2.letra && c1.coluna == c2.coluna) return 1;
	
	else return 0;
}


//Função para verificar se há algum navio encostado ou sobre o outro// 
int NaviosEstaoEncostadosOuSobrepostos(tTabuleiro tabuleiro){
	
	int x=0, l=0, c=0; 
		
	if(TemCoordenadaIgual(tabuleiro)) return 1;  
	
	if(!CampoDeBatalhaCriadoComSucesso(tabuleiro)) return 1;   //o programa cria um campo de batalha(tabuleiro com navios) em um tabuleiro distinto pra verificar se há navios com posição inválida//
	
	return 0;	
}


// Função para transformar a letra do tabuleiro em uma coordenada numérica nos padrões do tabuleiro//
int LeCoordenadaAlfabetica(char letra){
	
	if(letra == 'a') return 1;
	if(letra == 'b') return 2;
	if(letra == 'c') return 3;
	if(letra == 'd') return 4;
	if(letra == 'e') return 5;
	if(letra == 'f') return 6;
	if(letra == 'g') return 7;
	if(letra == 'h') return 8;
	if(letra == 'i') return 9;
	if(letra == 'j') return 10;
}


//Função para informar o tamanho do navio de acordo com seu nome//
int CalculaTamanhoDoNavio(char nome[]){
	
	if(strcmp(nome,"Carrier")==0) return  5;
	else if(strcmp(nome, "Battleship")==0) return  4;
	else if(strcmp(nome, "Cruiser") == 0 || strcmp(nome, "Submarine")==0) return  3;
	else if(strcmp(nome, "Destroyer")==0) return  2;
	else return 0;
}


//Função para copiar a matriz de um tabuleiro em outra matriz//
void CopiaMatriz1Na2(int l1, int c1, char m1[l1][c1], int l2, int c2, char m2[l2][c2]){
	
	int x=0, y=0;
	
	for(x=0;x<l1;x++){
		
		for(y=0;y<c1;y++){
			
			m2[x][y] = m1[x][y];
		}
	}	
}


//Função para criar um campo de batalha (tabuleiro com navios) e dizer se ele foi criado corretamente//
//Caso os navios estejam encostando ou sobrepostos a função retorna 0, informando que não foi possível criar um tabuleiro//
int CampoDeBatalhaCriadoComSucesso(tTabuleiro tabuleiro){
	
	
	char tablado[10][10];        //aloquei uma matriz auxiliar parar tentar criar o tabuleiro dentro dela e verificar se é possível//
	
	GeraTabuleiroVazio(10, 10, tablado);
			
	int x=0, y=0;
	int linha, coluna, direcao, tamanho;     // linha e coluna das coordenadas do ponto inicial do navio
	
for(x=0;x<tabuleiro.qtdNaviosTotal;x++){
			
		linha = CoordenadaLinhaNavio(tabuleiro.navio[x]) - 1;		//lembrando que as linnhas e colunas na matriz começam com 0, diminuí 1 unidade para manuseá-las//
		coluna = CoordenadaColunaNavio(tabuleiro.navio[x]) - 1;
		direcao = DirecaoNavio(tabuleiro.navio[x]);                  // 0 = vertical , 1 = horizontal//
		tamanho = TamanhoNavio(tabuleiro.navio[x]);
		
		
	if(direcao == 0){
		
		if(tamanho == 2 && linha > 8) return 0;
		else if(tamanho == 3 && linha > 7) return 0;
		else if(tamanho == 4 && linha > 6) return 0;
		else if(tamanho == 5 && linha > 5) return 0;
	}
		                                                          //CONDIÇÕES PARA O BARCO NAO EXCEDER OS LIMITES DO TABULEIRO//
	else if(direcao == 1){
			
		if(tamanho == 2 && coluna > 8) return 0;
		else if(tamanho == 3 && coluna > 7) return 0;
		else if(tamanho == 4 && coluna > 6) return 0;
		else if(tamanho == 5 && coluna > 5) return 0;
	}
		
	for(y=0;y<tamanho;y++){
			
			
		if(y==0){  // PARA VERIFICAR SE AS CÉLULAS AO REDOR DA PRIMEIRA COORDENADA DO NAVIO JÁ POSSUEM NAVIOS //
				
						
			if(coluna == 0 && linha == 0){
							
				if(tablado[linha + 1][coluna] == 'o' && tablado[linha][coluna + 1] == 'o' && tablado[linha+ 1][coluna + 1] == 'o')
					tablado[linha][coluna] = 'X';
				else return 0;
			}
						
			else if(coluna == 0 && linha == 9){
							
				if(tablado[linha - 1][coluna] == 'o' && tablado[linha][coluna + 1] == 'o' && tablado[linha - 1][coluna + 1] == 'o')
					tablado[linha][coluna] = 'X';
				else return 0;			
			}
				
			else if(coluna == 9 && linha == 9){
						
				if(tablado[linha - 1][coluna] == 'o' && tablado[linha][coluna - 1] == 'o' && tablado[linha - 1][coluna - 1] == 'o')
					tablado[linha][coluna] = 'X';
				else return 0;
			}	
				
			else if(coluna == 9 && linha == 0){
					
				if(tablado[linha + 1][coluna] == 'o' && tablado[linha][coluna - 1] == 'o' && tablado[linha + 1][coluna - 1] == 'o')
					tablado[linha][coluna] = 'X';
				else return 0;
			}
				//ATÉ AQUI FORAM VERIFICADAS COORDENADAS NOS VÉRTICES DO TABULEIRO//
					
						
			else if(coluna == 0){
				if(tablado[linha + 1][coluna] == 'o' && tablado[linha- 1][coluna] == 'o' && tablado[linha][coluna+1] == 'o' && tablado[linha + 1][coluna +1] == 'o' && tablado[linha - 1][coluna + 1] == 'o')
					tablado[linha][coluna] = 'X';
				else return 0;
			}
				
			else if(coluna == 9){
				if(tablado[linha + 1][coluna] == 'o' && tablado[linha - 1][coluna] == 'o' && tablado[linha][coluna-1] == 'o' && tablado[linha + 1][coluna -1] == 'o' && tablado[linha - 1][coluna - 1] == 'o')
					tablado[linha+ y][coluna] = 'X';
				else return 0;	
			}
			
			else if(linha == 0){
				if(tablado[linha][coluna + 1] == 'o' && tablado[linha][coluna - 1] == 'o' && tablado[linha + 1][coluna] == 'o' && tablado[linha + 1][coluna - 1] == 'o' && tablado[linha + 1][coluna + 1] == 'o')
					tablado[linha][coluna] = 'X';
				else return 0;
			}
			
			else if(linha == 9){
				if(tablado[linha][coluna + 1] == 'o' && tablado[linha][coluna - 1] == 'o' && tablado[linha - 1][coluna] == 'o' && tablado[linha - 1][coluna + 1] == 'o' && tablado[linha - 1][coluna - 1] == 'o')
					tablado[linha][coluna] = 'X';
				else return 0;
			}
			
			//ATÉ AQUI FORAM VERIFICADAS COORDENADAS NAS ARESTAS DOS TABULEIROS//
			
			else{
				if(tablado[linha - 1][coluna - 1] == 'o' && tablado[linha - 1][coluna] == 'o' && tablado[linha - 1][coluna + 1] == 'o' && tablado[linha][coluna - 1] == 'o' && tablado[linha][coluna + 1] == 'o' && tablado[linha + 1][coluna - 1] == 'o' && tablado[linha + 1][coluna] == 'o' && tablado[linha + 1][coluna + 1] == 'o')
					tablado[linha][coluna] = 'X';
				else return 0;
			}		
		}       //NESSE "ELSE" FORAM VERIFICADAS AS DEMAIS POSIÇÕES//
		    
		
		else if(y > 0){                                       // PARA VERIFICAR SE AS CÉLULAS AO REDOR DA SEGUNDA COORDENADA OU POSTERIOR DO NAVIO JÁ POSSUEM ALGUM NAVIO (UMA VERIFICAÇÃO PARA CADA DIREÇÃO)//
			
			if(direcao == 0){       // VERTICAL//
				
				linha = linha + 1;
				
				if(linha == 9){
					tablado[linha][coluna] = 'X';
				}
				
				else if(coluna == 0){
					if(tablado[linha + 1][coluna] == 'o' && tablado[linha + 1][coluna + 1] == 'o')
						tablado[linha][coluna] = 'X';
					else return  0;
				}
				
				else if(coluna == 9){
					if(tablado[linha + 1][coluna] == 'o' && tablado[linha + 1][coluna - 1] == 'o')
						tablado[linha][coluna] = 'X';
					else return 0;
				}
				
				else{
					if(tablado[linha + 1][coluna - 1] == 'o' && tablado[linha + 1][coluna] == 'o' &&tablado[linha + 1][coluna + 1] == 'o')
						tablado[linha][coluna] = 'X';
					else return 0;
				}			
			}
			
			else if(direcao == 1){    //HORIZONTAL//
				
				coluna = coluna + 1;
				
				if(coluna == 9){
					tablado[linha][coluna] = 'X';
				}
				
				else if(linha == 0){
					if(tablado[linha][coluna + 1] == 'o' && tablado[linha + 1][coluna + 1] == 'o')
						tablado[linha][coluna] = 'X';
					else return 0;
				}
				
				else if(linha == 9){
					if(tablado[linha][coluna + 1] == 'o' && tablado[linha - 1][coluna + 1] == 'o')
						tablado[linha][coluna] = 'X';
					else return 0;
				}
				
				else{
					if(tablado[linha - 1][coluna + 1] == 'o' && tablado[linha][coluna + 1] == 'o' && tablado[linha + 1][coluna + 1] == 'o')
						tablado[linha][coluna] = 'X';
					else return 0;
				}
			}												
		}														
	}
}
		
	return 1;	
}


//Função para imprimir um tabuleiro na tela e auxiliar na construção do código (permite ver as matrizes) //
void ImprimeTabuleiro(tTabuleiro tabuleiro){
	
	int x=0, y=0;
	
	for(x=0;x<10;x++){
		
		for(y=0;y<10;y++){
			
			printf("%c ", tabuleiro.campoDeBatalha[x][y]);
		}
		printf("\n");
	}
}


//Função para realizar a montagem do tabuleiro com os barcos//
tTabuleiro AdicionaNaviosNoTabuleiro(tTabuleiro tabuleiro){
	
	int x=0, y=0, linha = -1, coluna = -1, direcao = -1, tamanho = -1;
	
	for(x=0;x<tabuleiro.qtdNaviosTotal;x++){
				
		linha = CoordenadaLinhaNavio(tabuleiro.navio[x]) - 1;
		coluna = CoordenadaColunaNavio(tabuleiro.navio[x]) - 1;
		direcao = DirecaoNavio(tabuleiro.navio[x]);                  // 0 = vertical , 1 = horizontal//
		tamanho = TamanhoNavio(tabuleiro.navio[x]);
				
		if(direcao == 0){
			for(y=0;y<tamanho;y++){											
				tabuleiro.campoDeBatalha[linha + y][coluna] = 'X';			//ADICIONA PONTO A PONTO DOS NAVIOS VERTICAIS//	
			}
		}
		
		else if(direcao == 1){
			for(y=0;y<tamanho;y++){
				tabuleiro.campoDeBatalha[linha][coluna + y] = 'X';			//ADICIONA PONTO A PONTO DOS NAVIOS HORIZONTAIS//
			}
		}	
	}	
	return tabuleiro;		
}


//Função para verificar compatibilidade entre os 2 tabuleiros//
int SaoTabuleirosCompativeisEntreSi(tTabuleiro tab1, tTabuleiro tab2){
	
	int dest1=0, cruiser1=0, sub1=0, battle1=0, carrier1=0;
	int dest2=0, cruiser2=0, sub2=0, battle2=0, carrier2=0;        //Contadores de tipos de navios para cada tabuleiro//
	
	int x=0, y=0, a=0, b=0;
	
	
	if(tab1.qtdNaviosTotal != tab2.qtdNaviosTotal) return 0;
	
	
	for(x=0;x<tab1.qtdNaviosTotal;x++){
		
		a = NomeNavio(tab1.navio[x]);
		if(a == 1) dest1++;
		else if(a == 2) cruiser1++;
		else if(a == 3) sub1++;
		else if(a == 4) battle1++;
		else if(a == 5) carrier1 ++;
	}
	
	for(y=0;y<tab2.qtdNaviosTotal;y++){
		
		b = NomeNavio(tab2.navio[y]);
		if(b == 1) dest2++;
		else if(b == 2) cruiser2++;
		else if(b == 3) sub2++;
		else if(b == 4) battle2++;
		else if(b == 5) carrier2++;
	}
	
	return (dest1 == dest2 && cruiser1 == cruiser2 && sub1 == sub2 && battle1 == battle2 && carrier1 == carrier2);  //VERIFICA SE A QUANTIDADE DE BARCOS DE CADA TIPO NOS TABULEIROS É IGUAL//	
}


//Função para criar arquivo de inicialização na pasta "saida"//
void CriaArquivoDeInicializacao(FILE * file, tTabuleiro tab1, tTabuleiro tab2, char nome1[], char nome2[]){
	
	int x=0, y=0;
	
	fprintf(file, "%s\n", nome1);
	ImprimeTabuleiroNoArquivo(tab1, file);
	fprintf(file,"\n\n");
	
	fprintf(file, "%s\n", nome2);
	ImprimeTabuleiroNoArquivo(tab2, file);
	
}


//Função para imprimir um tabuleiro dentro de um arquivo//
void ImprimeTabuleiroNoArquivo(tTabuleiro tabuleiro, FILE * file){
	
	int x=0, y=0;
	
	for(x=0;x<10;x++){
		
		for(y=0;y<10;y++){
			
			if(y==9){
				
				fprintf(file,"%c", tabuleiro.campoDeBatalha[x][y]);	
			}			
			else fprintf(file,"%c ", tabuleiro.campoDeBatalha[x][y]);						
		}		
		if(x<9) fprintf(file,"\n");		
	}	
}


//Função para verificar se o diretorio foi informado na execução do programa//
int DiretorioNaoFoiInformado(int valorArg){

	if(valorArg <= 1){
		
		printf("ERRO: O diretorio de arquivos de configuracao nao foi informado");
		return 1;
	}	
	return 0;
}


//Função para ler o nome dos jogadores//
void LeJogadores(char str[], char str2[]){
	
	printf("Nome do Jogador 1:\n");
	scanf("%s", str);
	
	printf("Nome do Jogador 2:\n");
	scanf("%s", str2);	
}


//Função para inicializar jogo//
tJogo InicializaJogo(int argc, char ** argv){
	
		tJogo jogo;
		jogo.EhJogoValido = 1;
	
		if(DiretorioNaoFoiInformado(argc)){ 	          //VERIFICA SE O DIRETORIO DOS ARQUIVOS FOI INFORMADO NO TERMINNAL//
			
			jogo.EhJogoValido =0;
			return jogo;
		}
	
	char diretorio[1000];
	char diretorio2[1000];
	sprintf(diretorio,"%s/tabu_1.txt", argv[1]);
	sprintf(diretorio2,"%s/tabu_2.txt", argv[1]);             // COLOCA O CAMINHO DOS ARQUIVOS TABU.TXT NAS STRINGS//
	
	
	
	FILE * tab1File;
	FILE * tab2File;			//CRIAÇÃO DOS TIPOS "FILE" PARA O TABULEIRO 1, 2 E PARA OS ARQUIVOS QUE O PROGRAMA VAI PRECISAR CRIAR DURANTE SUA EXECUÇÃO//
	FILE * saidasFile;				
	
	
	
	tab1File = fopen(diretorio , "r");
	if(!tab1File){		
		printf("Arquivo tabu_1.txt nao existe em %s", argv[1]);
		jogo.EhJogoValido=0;
		return jogo;
	}

	tab2File = fopen(diretorio2, "r");
	if(!tab2File){		
		printf("Arquivo tabu_2.txt nao existe em %s", argv[1]);					//CASO OS ARQUIVOS TABU.TXT EXISTIREM NO DIRETÓRIO INFORMADO SÃO FEITAS SUAS ABERTURAS EM MODO DE LEITURA//
		fclose(tab1File);														//CASO CONTRÁRIO, O PROGRAMA SERÁ FECHADO, EXIBINDO UMA MENSAGEM DE ERRO//
		jogo.EhJogoValido=0;
		return jogo;																		
	}
	
	
	jogo.tabu1 = LeTabuleiro(tab1File);
	jogo.tabu2 = LeTabuleiro(tab2File);               // LEITURA DOS TABULEIROS	
	
	fclose(tab1File);
	fclose(tab2File);         //FECHAMENTO DOS ARQUIVOS TABU.TXT//
	
	
	char diretorioSaidaValidacao[1000];
    sprintf(diretorioSaidaValidacao, "%s/saida/validacao_tabuleiros.txt", argv[1]);   //COLOCA O CAMINHO DO ARQUIVO DE VALIDAÇÃO NA STRING DECLARADA ACIMA//   
    saidasFile = fopen(diretorioSaidaValidacao, "w");       //ABRE O ARQUIVO DE VALIDAÇÃO EM MODO ESCRITA//
    
	
	if(EhTabuleiroValido(jogo.tabu1)) {
		
		fprintf(saidasFile,"tabu_1.txt;valido\n");
		jogo.tabu1 = AdicionaNaviosNoTabuleiro(jogo.tabu1);        //CASO O TABULEIRO 1 SEJA VÁLIDO, O PROGRAMA ADICIONA OS NAVIOS NO TABULEIRO 1//
	
	}
	else fprintf(saidasFile,"tabu_1.txt;invalido\n");		//CASO CONTRÁRIO, O PROGRAMA IMPRIME NO ARQUIVO QUE É INVÁLIDO//
	
	
	if(EhTabuleiroValido(jogo.tabu2)) {
		
		fprintf(saidasFile,"tabu_2.txt;valido");
		jogo.tabu2 = AdicionaNaviosNoTabuleiro(jogo.tabu2);       //CASO O TABULEIRO 2 SEJA VÁLIDO, O PROGRAMA ADICIONA OS NAVIOS NO TABULEIRO 2//

	}
	else fprintf(saidasFile,"tabu_2.txt;invalido");			//CASO CONTRÁRIO, O PROGRAMA IMPRIME NO ARQUIVO QUE É INVÁLIDO//


	if(EhTabuleiroValido(jogo.tabu1) && EhTabuleiroValido(jogo.tabu2)){					//O PROGRAMA VERIFICA SE OS 2 TABULEIROS SÃO VÁLIDOS//
		if(SaoTabuleirosCompativeisEntreSi(jogo.tabu1, jogo.tabu2)){					//CASO SEJAM, ELE VERIFICA SE OS TABULEIROS SÃO COMPATÍVEIS ENTRE SI//
			fprintf(saidasFile, "\nTabuleiros compativeis entre si");		//SE OS TABULEIROS FOREM COMPATÍVEIS, ELE IMPRIME NO ARQUIVO DE VALIDAÇÃO//
			fclose(saidasFile);												//LOGO EM SEGUIDA FECHA O ARQUIVO DE VALIDAÇÃO//	
		}                                                                        
		else{			
			fprintf(saidasFile, "\nTabuleiros incompativeis entre si");		//CASO SEJAM INCOMPATÍVEIS, ELE IMPRIME NO ARQUIVO DE VALIDAÇÃO//		
			fclose(saidasFile);												//LOGO EM SEGUIDA FECHA O ARQUIVO DE VALIDAÇÃO//
			jogo.EhJogoValido=0;														//E TAMBÉM FECHA O PROGRAMA//
			return jogo;		
		} 
	}
	else{          												//CASO ALGUM DOS TABULEIROS SEJA INVÁLIDO, O PROGRAMA RETORNA O JOGO PRA FUNCAO MAIN COM A VARIAVEL "EHJOGOVALIDO = 0//
		jogo.EhJogoValido=0;									//INDICANDO QUE O PROG DEVE SER FECHADO//
		return jogo;
	}
	
	LeJogadores(jogo.jogador1, jogo.jogador2);                            //LE  NOMES DOS JOGADORES E JOGA NAS STRINGS//
	
	char diretorioSaidaInicializacao[1000];
	sprintf(diretorioSaidaInicializacao,"%s/saida/inicializacao.txt", argv[1]);				//CRIA CAMINNHO DO ARQUIVO DE INICIALIZAÇÃO E JOGA NA STRING ACIMA//
	saidasFile = fopen(diretorioSaidaInicializacao, "w");								//ABRE O ARQUIVO DE INICIALIZAÇÃO NO MODO ESCRITA//
	
	CriaArquivoDeInicializacao(saidasFile, jogo.tabu1, jogo.tabu2, jogo.jogador1, jogo.jogador2);			//ESCREVE OS DADOS DO ARQUIVO DE INICIALIZAÇÃO//
	fclose(saidasFile);
	
	return jogo;
}


//Função para verificar se o jogo deve fechar ou continuar rodando//
int EhJogoValido(tJogo jogo){
	
	return jogo.EhJogoValido;	
}


//Função para verificar se um número é par//
int EhPar(int num){
	
	return (num%2 == 0);
}


//Função para executar o jogo//
void JogaJogo(tJogo jogo, char** argv){
	
	tJogada jogadaJogador1[100], jogadaJogador2[100];    //VETORES PARA ARMAZENAR TODAS AS JOGADAS DO JOGO, TANTO DO JOGADOR 1 QUANTO DO JOGADOR 2//
	int qJ1=0, qJ2=0;			  //QUANTIDADE DE JOGADAS DO JOGADOR 1 E 2//	
	int x=0; 						//CONTADOR DE JOGADAS GERAIS PARA ALTERNAR AS JOGADAS ENTRE OS JOGADORES//
	int jogador1Venceu=0, jogador2Venceu=0, empate=0;	//VARIÁVEIS PARA VERIFICAR VENCEDORES E EMPATE//
	FILE * resultFile;			//TIPO "FILE" PARA ALOCAR O ARQUIVO DE RESULTADO//
	FILE * estFile;				//TIPO "FILE" PARA ALOCAR O ARQUIVO DE ESTATISTICAS//
	int tabuAuxiliar1[10][10], tabuAuxiliar2[10][10];		//TABULEIRO DE INTEIROS COM OS IDs DOS NAVIOS AO INVÉS DO X PARA LOCALIZA-LOS COM MAIS FACILIDADE//
	char tabuSaida1[10][10], tabuSaida2[10][10];		//TABULEIRO QUE VAI SER ATUALIZADO E IMPRESSO NA TELA//
	char vencedor[17];		//STRING PARA ALOCAR O NOME DO VENCEDOR//
	tEstatistica estatistica1, estatistica2;  //ALOCAÇÃO DO TIPO ESTATISTICA PARA OS 2 JOGADORES//
	
		
	GeraTabuleiroAuxiliarVazio(tabuAuxiliar1);
	GeraTabuleiroAuxiliarVazio(tabuAuxiliar2);
	PreparaTabuleiroAuxiliar(jogo.tabu1, tabuAuxiliar1);
	PreparaTabuleiroAuxiliar(jogo.tabu2, tabuAuxiliar2);		//GERAÇÃO E PREPARAÇÃO DE TABULEIROS AUXILIARES E DE SAÍDA//
	GeraTabuleiroSaidaVazio(tabuSaida1);
	GeraTabuleiroSaidaVazio(tabuSaida2);
					
		
	while(1){								//LOOP PARA REALIZAR AS JOGADAS//				
		
		if(jogador1Venceu){ 	//SE O JOGADOR 1 VENCER, O JOGADOR 2 TEM SUA ÚLTIMA CHANCE//
								
			jogadaJogador2[qJ2] = JogaJogador(jogo.jogador2, jogadaJogador2, jogadaJogador2[qJ2], qJ2, tabuAuxiliar1, tabuSaida1, jogo.tabu1);
			ImprimeTabladoSaida(tabuSaida1, jogo.jogador2, jogo.jogador1);
			qJ2++;
			if(JogadorVenceu(tabuAuxiliar1)) jogador2Venceu = 1;
								
			if(jogador1Venceu && jogador2Venceu){
				
				printf("\nEmpate\n");
				empate = 1;	
			} 
						
			else{
				
				printf("\nVencedor: %s\n", jogo.jogador1);
				strcpy(vencedor, jogo.jogador1);
			} 
			break;
		}            //ATÉ AQUI - CASO O JOGADOR 1 VENÇA//
		
		//________________________________________________________________________________________________________________________________________//
				
		if(jogador2Venceu) {  // SE O JOGADOR 2 VENCER, O JOGO ACABA//
			
			printf("\nVencedor: %s\n", jogo.jogador2);
			strcpy(vencedor, jogo.jogador2);
			
			break;
		}
		//__________________________________________________________________________________________________________________________________________//	
				
		if(EhPar(x)){						//SE X FOR PAR, É A VEZ DO JOGADOR 1, CASO CONTRÁRIO, É A VEZ DO JOGADOR 2//
			
			jogadaJogador1[qJ1] = JogaJogador(jogo.jogador1, jogadaJogador1, jogadaJogador1[qJ1], qJ1, tabuAuxiliar2, tabuSaida2, jogo.tabu2); 	//A JOGADA DO JOGADOR1 É EFETUADA E ARMAZENADA EM UM COMPONNENTE DO VETOR DE TJOGADAS//  AS JOGADAS SAO ARMAZENADAS A FIM DE CALCULAR AS ESTATÍSTICAS E GERAR ARQUIVO DE RESULTADO
			ImprimeTabladoSaida(tabuSaida2, jogo.jogador1, jogo.jogador2);		//IMPRESSÃO DO TABULEIRO INIMIGO ATUALIZADO//												
			if(JogadorVenceu(tabuAuxiliar2)) jogador1Venceu = 1;    //SE O JOGADOR VENCER, O PROG INDICA NA VARIÁVEL//
			
			qJ1++;	//AUMENTA EM 1 A QUANTIDADE DE JOGADAS DO JOGADOR 1//	
		}
		
		else {							//SE X FOR ÍMPAR, É A VEZ DO JOGADOR 2//
			
			jogadaJogador2[qJ2] = JogaJogador(jogo.jogador2, jogadaJogador2, jogadaJogador2[qJ2], qJ2, tabuAuxiliar1, tabuSaida1, jogo.tabu1);	//EXECUÇÃO DA JOGADA DO JOGADOR 2//	
			ImprimeTabladoSaida(tabuSaida1, jogo.jogador2, jogo.jogador1);	//IMPRESSÃO DO TABULEIRO INIMIGO ATUALIZADO//
			if(JogadorVenceu(tabuAuxiliar1)) jogador2Venceu = 1;
			
			qJ2++;  //AUMENTA EM 1 A QUANTIDADE DE JOGADAS DO JOGADOR 2//
		}	
					
		x++;		//AUMENTA EM 1 AS JOGADAS GERAIS// 
	}
			
		
	char diretorioResultado[1000];
	sprintf(diretorioResultado,"%s/saida/resultado.txt", argv[1]);    //CRIA CAMINHO PARA O ARQUIVO RESULTADO//
	resultFile = fopen(diretorioResultado, "w");	//ABRE O ARQUIVO DE RESULTADO NO MODO ESCRITA//
	
	CriaArquivoDeResultado(jogo.jogador1, jogo.jogador2, jogadaJogador1, qJ1, jogadaJogador2, qJ2, empate, vencedor, resultFile);  //CRIA O ARUIVO DE RESULTADO//	
	fclose(resultFile);  //FECHA ARQUIVO DE RESULTADO//
	
	char diretorioEstatistica[1000];
	sprintf(diretorioEstatistica,"%s/saida/estatisticas.txt",argv[1]);		//CRIA CAMINHO PARA O ARQUIVO ESTATISTICAS//
	estFile = fopen(diretorioEstatistica,"w");	//ABRE O ARQUIVO DE ESTATISTICAS NO MODO ESCRITA//
	
	estatistica1 = GeraEstatisticas(jogadaJogador1, qJ1, qJ2, jogadaJogador2, jogo.jogador1);	
	estatistica2 = GeraEstatisticas(jogadaJogador2, qJ2, qJ1, jogadaJogador1, jogo.jogador2);		//LEITURA, INICIALIZAÇÃO E PROCESSAMENTO DAS ESTATISTICAS DO JOGO//
	GeraArquivoEstatisticas(estatistica1, estFile);		//IMPRESSÃO DAS ESTATISTICAS DO JOGADOR 1 NO ARQUIVO//
	fprintf(resultFile,"\n");
	GeraArquivoEstatisticas(estatistica2, estFile);		//IMPRESSÃO DAS ESTATISTICAS DO JOGADOR 2 NO ARQUIVO//
		
	fclose(estFile);		//FECHA O ARQUIVO DE ESTATISTICAS//
}


//Função para ler uma jogada do buffer//
tJogada LeJogada(){
	
	tJogada jogada;
	
	jogada.coordenada = LeCoordenada();		//A JOGADA É DADA EM COORDENADA//
	if(FoiCoordenadaLidaComSucesso(jogada.coordenada)) jogada.confirmaLeitura = 1;  //INFORMA SE AS INFORMAÇÕES DA JOGADA FORAM COLHIDAS COM SUCESSO PARA POSTERIORMENTE VERIFICAR SUA VALIDADE//
	else jogada.confirmaLeitura = 0;
		
	return jogada;
}


//Função para ler uma coordenada das jogadas//
tCoordenada LeCoordenada(){
	
	tCoordenada coordenada;
	int rtn;
	char str[10];
	
	coordenada.confirmaLeitura = 1;  //A CONFIRMAÇÃO DA LEITURA DA COORDENADA NO BUFFER É SETADA EM 1. CASO HAJA ERRO, O PROGRAMA MUDA PARA 0//
	
	scanf("%*c%s", str);
	strcpy(coordenada.strCord, str);  //JOGA A COORDENADA DE ENTRADA NO BUFFER PARA UMA STRING O TIPO TJOGADA//
	
	if(strlen(str) <= 3){		//CALCULA O TAMANHO DA STRING DA COORDENADA. CASO PASSE DE 3, A COORDENADA JÁ É INVÁLIDA//
		
		rtn = sscanf(str,"%c%d", &coordenada.letra, &coordenada.coluna);	
	}
	else coordenada.confirmaLeitura =0; 
		
	coordenada.linha = LeCoordenadaAlfabetica(coordenada.letra);	//LE A COORDENADA DE LETRA E TRASFORMA NO NÚMERO DA LINHA CORRESPONDENTE//	
	if(rtn != 2) coordenada.confirmaLeitura =0;  //SE O RETORNO DA LEITURA DA COORDENADA FOR DIFERENTE DO ESPERADO, A COORDENADA É DADA COMO INVÁLIDA//
	
	if(strlen(str) == 3){
		
		if(str[2] > '9' || str[2] < '0') coordenada.confirmaLeitura = 0;		//CASO A STRING TIVER 3 COMPONENTES, O ULTIMO PODE ESTAR APENAS ENTRE 0 E 9, SENÃO A COORDENADA É INVÁLIDA//
	}
		
	return coordenada;
}


//Função para saber se uma coordenada foi lida corretamente//
int FoiCoordenadaLidaComSucesso(tCoordenada coordenada){
	
	return coordenada.confirmaLeitura;
}


//Função para saber se uma jogada é válida//
int EhJogadaValida(tJogada jogada){
	
	if(jogada.confirmaLeitura == 0) return 0;				//PARA CONFIRMAR UMA JOGADA, CONFERE-SE A VARIÁVEL CONFIRMA LEITURA, COMO JÁ VISTO ANTES//
	if(!EhCoordenadaValida(jogada.coordenada)) return 0;	//TAMBÉM CONFERE SE A COORDENADA ESTÁ NOS PADRÕES DO TABULEIRO//
	
	return 1;
}


//Função para saber se uma jogada já foi realizada//
int EhJogadaRepetida(tJogada vetjogada[], tJogada jogada, int qtdJog){
	
	int y=0;
	
	for(y=0;y<qtdJog;y++){
		
		if(EhCoordenada1IgualA2(vetjogada[y].coordenada, jogada.coordenada))
		return 1;
	}		
	return 0;
}


//Função para imprimir uma coordenada na tela e no arquivo ao mesmo tempo//
void ImprimeCoordenada(tCoordenada coordenada){
	
	printf("\n%s:", coordenada.strCord);	
}


//Função que retorna um número de acordo com seu nome para ser usado como parâmetro dentro de outra função (a partir de um navio)//
int NomeNavio(tNavio navio){
	
	if(strcmp(navio.nome, "Destroyer") == 0) return 1;
		else if(strcmp(navio.nome, "Cruiser") == 0) return 2;
		else if(strcmp(navio.nome, "Submarine") == 0) return 3;
		else if(strcmp(navio.nome, "Battleship") == 0) return 4;
		else if(strcmp(navio.nome, "Carrier") == 0) return 5;		
}


//Função que retorna a linha da coordenada de um navio//
int CoordenadaLinhaNavio(tNavio navio){
	
	return CoordenadaLinhaCoordenada(navio.coordenada);	
}


//Função que retora a linha de uma coordenada através da entrada de uma coordenada//
int CoordenadaLinhaCoordenada(tCoordenada coordenada){
	
	return coordenada.linha;
}


//Função que retorna a coluna da coordenada de um navio//
int CoordenadaColunaNavio(tNavio navio){
			
	return CoordenadaColunaCoordenada(navio.coordenada);
}


//Função que retorna a coluna de uma coordenada através da entrada de uma coordenada//
int CoordenadaColunaCoordenada(tCoordenada coordenada){
	
	return coordenada.coluna;
}


//Função que retorna a direção do navio(horizontal = 1, vertical = 0)//
int DirecaoNavio(tNavio navio){
	
	return navio.orientacao;
}


//função que retorna o tamanho do navio//
int TamanhoNavio(tNavio navio){
	
	return navio.tamanho;
}


//Função para verificar se 2 navios possuem a mesma coordenada//
int NaviosTemMesmaCoordenada(tNavio navio1, tNavio navio2){
	
	return EhCoordenada1IgualA2(navio1.coordenada, navio2.coordenada);			
}


//Funçaõ para gerar um tabuleiro auxiliar vazio (nesse caso é um tabuleiro de inteiros e não de char)//
void GeraTabuleiroAuxiliarVazio(int tablado[10][10]){
	
	int x=0, y=0;

	for(x=0;x<10;x++){
		for(y=0;y<10;y++){
			
			tablado[x][y] = -999;
		}
	}		
}


//Função para colocar o ID dos navios no tabuleiro auxiliar//
void PreparaTabuleiroAuxiliar(tTabuleiro tabuleiro, int tablado[10][10]){
	
	int x=0, y=0, linha=0, coluna=0, id=0, tamanho=0, direcao=0;	
																					//NESSA FUNÇÃO EU COLOCO O ID DE CADA NAVIO NO LUGAR ONDE DEVERIA ESTAR O "X"//	
	for(x=0;x<tabuleiro.qtdNaviosTotal;x++){										
		
		linha = CoordenadaLinhaNavio(tabuleiro.navio[x]) - 1;
		coluna = CoordenadaColunaNavio(tabuleiro.navio[x]) - 1;
		tamanho = TamanhoNavio(tabuleiro.navio[x]);
		direcao = DirecaoNavio(tabuleiro.navio[x]);
		id = IdNavio(tabuleiro.navio[x]);
				
		if(direcao == 1){
			
			for(y=0;y<tamanho;y++){
				
				tablado[linha][coluna + y] = id;
			}
		}
		
		else if(direcao == 0){
			
			for(y=0;y<tamanho;y++){
				
				tablado[linha + y][coluna] = id;
			}
		}
	}	
}


//Função para retornar o ID do navio//
int IdNavio(tNavio navio){
	
	return navio.ID;
}


//Função para gerar um tabuleiro de saída vazio (com pontos '.')//
void GeraTabuleiroSaidaVazio(char tablado[10][10]){
	
	int x=0, y=0;
	
	for(x=0;x<10;x++){
		for(y=0;y<10;y++){
			tablado[x][y] = '.';
		}
	}	
}


//Função para imprimir o tabuleiro de saída tanto na tela, como no arquivo de saída//
void ImprimeTabladoSaida(char tablado[10][10], char nome1[], char  nome2[]){
	
	int x=0, y=0;
	
	printf("\nTabuleiro atual de %s apos a jogada de %s\n", nome2, nome1);			//NESTA FUNÇÃO, A IMPRESSÃO DO TABULEIRO É ANTECEDIDA POR ESTE TEXTO// 			
	
	for(x=0;x<10;x++){
		for(y=0;y<10;y++){
			
			if(y==9){
				
				printf("%c", tablado[x][y]);	
			}
			else{
				
				printf("%c ", tablado[x][y]);
			}			
		}
		printf("\n");
	}
}


//Função para imprimir o tabuleiro de inteiros para auxiliar na construção do código (facilita a visualização das jogadas)//
void ImprimeTabladoAuxiliar(int tablado[10][10]){
	
	int x=0, y=0;
	
	for(x=0;x<10;x++){
		for(y=0;y<10;y++){
			
			printf("%d ", tablado[x][y]);
		}
		printf("\n");
	}
}


//Função para executar uma jogada nos tabuleiros e atualizá-los//
tJogada RealizaJogada(tTabuleiro tabuleiro, tJogada jogada, int tabladoId[10][10], char tabladoSaida[10][10], int qJ){
	
	int x=0, y=0, num=-1;
	
	int linha = CoordenadaLinhaCoordenada(jogada.coordenada) - 1;			//COMEÇO PASSANDO AS LINHAS E COLUNAS DE ACORDO COM AS MATRIZES(COMEÇA DO 0)//
	int coluna = CoordenadaColunaCoordenada(jogada.coordenada) - 1;
	
	if(tabladoId[linha][coluna] == -999){				//SE O LOCAL DA JOGADA FOR = -999, QUER DIZER QUE O TIRO FOI NA ÁGUA//
		
		strcpy(jogada.tipo, "Agua");
		printf("Agua\n");							//IMPRESSÃO DAS INFORMAÇÕES DA JOGADA NA TELA//
		tabladoSaida[linha][coluna] = 'o';			//ATUALIZAÇÃO DO TABULEIRO DE SAÍDA//
	}
	
	else{		//CASO O LOCAL DA JOGADA SEJA DIFERENTE DE -999//
		
		strcpy(jogada.tipo, "Tiro");			//O TIPO DA JOGADA VAI SER "TIRO"//
		tabladoSaida[linha][coluna] = 'X';		//ATUALIZAÇÃO DO TABULEIRO DE SAIDA//
				
		num = tabladoId[linha][coluna];			
		
		for(x=0;x<tabuleiro.qtdNaviosTotal;x++){	
			if(IdNavio(tabuleiro.navio[x]) == num){
				
				jogada = ColocaNomeDoNavioAcertadoNaJogada(tabuleiro.navio[x], jogada);		//ARMAZENA O NOME DO NAVIO ACERTADO PELO TIRO NO TIPO TJOGADA//
				break;																		//O NOME DO NAVIO É DESCOBERTO ATRAVÉS DO ID//
			} 
		}
				
		tabladoId[linha][coluna] = -999;		//LOCAL DA JOGADA É MODIFICADO PARA -999 (E ASSIM SEGUE ATÉ ESVAZIAR O TABULEIRO E SABER QUAIS NAVIOS AFUDARAM)//
		
		if(AfundouNavio(tabladoId, num)){		//SE ALGUM NAVIO AFUNDOU O PROGRAMA INFORMA NA TELA E NO ARQUIVO DE SAÍDA//
			
			printf("Afundou %s\n", jogada.navioAcertado);			
		}
		
		else{
			
			printf("Tiro!\n");
		} 
	}	
	
	jogada.numJogada = qJ;
	return jogada;
}


//Função para armazenar o nome de um navio no tipo tJogada//
tJogada ColocaNomeDoNavioAcertadoNaJogada(tNavio navio, tJogada jogada){
	
	strcpy(jogada.navioAcertado, navio.nome);	//			
	jogada.idNavioAcertado = navio.ID;			// UTILIZADO CRIAR O ARQUIVO DE RESULTADO E ESTATISTICAS//
	
	return jogada;
}


//Função para verificar se um navio afundou//
int AfundouNavio(int tablado[10][10], int num){
	
	int cont=0, x=0, y=0;
									//A VARIÁVEL NUM = ID DO NAVIO//  LEMBRANDO QUE O TABULEIRO AUXILIAR (de inteiros) possui zeros e IDs//
	for(x=0;x<10;x++){				//QUANDO UM ID SE ESGOTA DO TABULEIRO, QUER DIZER QUE O NAVIO AFUNDOU//	
		for(y=0;y<10;y++){
			
			if(tablado[x][y] == num) cont++;
		}
	}
	
	if(cont > 0) return 0;
	
	return 1;
}


//Função para ler a jogada do jogador 1, jogá-la e atualizar o o tipo tJogada com as informações processadas//
tJogada JogaJogador(char nomeJogador[], tJogada jogadasJogador1[], tJogada jogadaJogador1, int qJ1, int tabuAuxiliar2[10][10], char tabuSaida2[10][10], tTabuleiro tabuInimigo){			//RETORNA UM TIPO TJOGADA PARA ARMAZENAR OS DADOS DA JOGADA CAPTADOS E PROCESSADOR NO STRUCT//
	
	printf("\nJogada de %s:\n", nomeJogador);			
	jogadaJogador1 = LeJogada();					//LEITURA DA JOGADA DIRETAMENTE DO BUFFER//
			
	while(!EhJogadaValida(jogadaJogador1) || EhJogadaRepetida(jogadasJogador1, jogadaJogador1, qJ1)){		//VERIFICAÇÃO DE JOGADA INVÁLIDA OU REPETIDA//	
				
		ImprimeCoordenada(jogadaJogador1.coordenada);
		printf("Jogada invalida! Jogue novamente %s:\n", nomeJogador);				//CASO A JOGADA SEJA INVÁLIDA OU REPETIDA, UMA MENSAGEM DE ERRO É IMPRIMIDA NA TELA//
		jogadaJogador1 = LeJogada();									//O PROGRAMA ABRE O BUFFER PARA DIGITAR UMA NOVA JOGADA//
	}	
			
	ImprimeCoordenada(jogadaJogador1.coordenada);								//QUANDO A JOGADA FOR VÁLIDA, O JOGO IMPRIMIRÁ ELA NA TELA ANTES DE MOSTRAR ONDE ELA ACERTOU//
					
	jogadaJogador1 = RealizaJogada(tabuInimigo, jogadaJogador1, tabuAuxiliar2, tabuSaida2, qJ1);  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////FUNÇÃO REALIZA JOGADA ESTÁ AQUI////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
																									
	return jogadaJogador1;	
}


//Função para verificar se o jogador venceu, ou seja, se o tabuleiro de inteiros foi zerado//
int JogadorVenceu(int tablado[10][10]){
	
	int x=0, y=0, cont=0;
	
	for(x=0;x<10;x++){
		for(y=0;y<10;y++){
			
			if(tablado[x][y] != -999) cont++;
		}
	}
	
	if(cont > 0) return 0;
	
	return 1;
}


//Função para criar um arquivo com o resultado do jogo//
void CriaArquivoDeResultado(char nomeJogador1[], char nomeJogador2[], tJogada jogadas1[], int qtd1, tJogada jogadas2[], int qtd2, int empate, char vencedor[], FILE * file){
	
	int x=0;
	
	fprintf(file,"%s\n", nomeJogador1);
	
	for(x=0;x<qtd1;x++){
		
		ImprimeCoordenadaNoArquivo(jogadas1[x].coordenada, file);		//PRIMEIRAMENTE ELE IMPRIME A COORDENADA DA JOGADA//
		fprintf(file," - ");
		
		if(strcmp(jogadas1[x].tipo, "Agua") == 0) fprintf(file,"Agua\n");		//SE O TIRO FOR NA AGUA, ELE IMPRIME SOMENTE AGUA//		
		else ImprimeJogadaNoArquivoResultado(jogadas1[x], file);			//CASO CONTRÁRIO ELE IMPRIME O NAVIO QUE ACERTOU E SEU ID, ALÉM DE "TIRO"//
	}
	
	fprintf(file,"\n%s\n", nomeJogador2);
	
	for(x=0;x<qtd2;x++){														//REPETE A MESMA COISA PARA O JOGADOR 2//
		
		ImprimeCoordenadaNoArquivo(jogadas2[x].coordenada, file);
		fprintf(file," - ");
		
		if(strcmp(jogadas2[x].tipo, "Agua") == 0) fprintf(file,"Agua\n");		
		else ImprimeJogadaNoArquivoResultado(jogadas2[x], file);		
	}
	
	if(empate == 1) fprintf(file,"\nEmpate");
	
	else fprintf(file,"\nVencedor: %s", vencedor);	
}


//Função para imprimir os dados de uma jogada no arquivo resultado//
void ImprimeJogadaNoArquivoResultado(tJogada jogada, FILE * file){
	
	fprintf(file,"%s - %s - ID %02d\n", jogada.tipo, jogada.navioAcertado, jogada.idNavioAcertado);
}


//Função para gerar estatísticas sobre um jogador//
tEstatistica GeraEstatisticas(tJogada * jogada, int qJ, int qJ2, tJogada * jogadaNav, char nome[]){
	
	tEstatistica estatistica;
	int x=0;
	
	estatistica.tirosErrados = ContaTirosErrados(jogada, qJ);
	estatistica.tirosCertos = ContaTirosCertos(jogada, qJ);	
	estatistica.linhaMedia = CalculaMediaLinha(jogada, qJ);
	estatistica.colunaMedia = CalculaMediaColuna(jogada, qJ);
	estatistica.desvioPadrao = CalculaDesvioPadrao(estatistica.linhaMedia, estatistica.colunaMedia, jogada, qJ);
	estatistica.qtdJogadas = qJ2;		//QTD DE JOGADAS DO JOGADOR INIMIGO NO SEU TABULEIRO//
	strcpy(estatistica.nomeDoJogador, nome);
																														//FUÇÃO PARA INICIALIZAR TODOS AS VARIÁVEIS DO TIPO ESTATISTICA//
	for(x=0;x<qJ2;x++){																								
		
		estatistica.jogada[x] = jogadaNav[x];		//IGUALA O VETOR DE JOGADAS DO INIMIGO AO VETOR DE JOGADAS DAS ESTATÍSTICAS PARA VER OS NAVIOS DO JOGADOR QUE FORAM ACERTADOS PELO INIMIGO//
		estatistica.jogada[x] = ColocaNumDaJogada(estatistica.jogada[x], x+1);
	}
	
	estatistica = OrganizaNaviosEmOrdemAlfabetica(estatistica);
		
	return estatistica;
}


//Função para retornar quantos tiros foram na água//
int ContaTirosErrados(tJogada * jogada, int qJ){
	
	int x=0, cont=0;
	
	for(x=0;x<qJ;x++){
		
		if(strcmp(jogada[x].tipo, "Agua") == 0) cont++;
	}
	
	return cont;
}


//Função para retornar quatos tiros acertaram algum navio//
int ContaTirosCertos(tJogada * jogada, int qJ){
	
	int x=0, cont=0;
	
	for(x=0;x<qJ;x++){
		
		if(strcmp(jogada[x].tipo, "Tiro") == 0) cont++;
	}
	
	return cont;
}


//calcula a linha média das jogadas//
float CalculaMediaLinha(tJogada * jogada, int qJ){
		
	int x=0, linha=0;
	float soma=0, media=0;
	
	for(x=0;x<qJ;x++){
		
		linha = CoordenadaLinhaCoordenada(jogada[x].coordenada);
		soma += (float)linha;
	}

	media = soma/qJ;
	return media;	
}


//Calcula a coluna média das jogadas//
float CalculaMediaColuna(tJogada * jogada, int qJ){
	
	int x=0, coluna=0;
	float soma=0, media=0;
	
	for(x=0;x<qJ;x++){
		
		coluna = CoordenadaColunaCoordenada(jogada[x].coordenada);
		soma += (float)coluna;
	}
	
	media = soma/qJ;
	return media;
}


//Calcula desvio padrão das jogadas//
float CalculaDesvioPadrao(float lm, float cm, tJogada * jogada, int qJ){
	
	float somatorio=0, soma=0,result=0, tli, tlc;
	int x=0;
	
		
	for(x=0;x<qJ;x++){
		
		tli =(float)CoordenadaLinhaCoordenada(jogada[x].coordenada);
		tlc = (float)CoordenadaColunaCoordenada(jogada[x].coordenada);		
			
		soma += (pow((tli - lm), 2) + pow((tlc - cm), 2));
	}
	
	somatorio = soma/qJ;
	result = sqrt(somatorio);
	
	return result;
}


//Organiza os navios da última parte da estatística em ordem alfabética e ordem de jogada//
tEstatistica OrganizaNaviosEmOrdemAlfabetica(tEstatistica estatistica){
	
	int x=0, y=0, aux2=0;
	tJogada aux;
	
	for(x=0;x<estatistica.qtdJogadas-1;x++){			//LOOP PARA COLOCAR OS NOMES EM ORDEM ALFABÉTICA//
		
		for(y=x+1;y<estatistica.qtdJogadas;y++){
			
			if(EhJogada1MenorQJogada2(estatistica.jogada[y], estatistica.jogada[x])){
				
				aux = estatistica.jogada[y];
				estatistica.jogada[y] = estatistica.jogada[x];
				estatistica.jogada[x] = aux;
			}
		}
	}
	
	return estatistica;
}


//Função para saber se uma jogada é menor que a outra em ordem alfabetica e posteriormente de numero//
int EhJogada1MenorQJogada2(tJogada jogada1, tJogada jogada2){
	
	if(strcmp(jogada1.navioAcertado, jogada2.navioAcertado) < 0) return 1;
	else if(strcmp(jogada1.navioAcertado, jogada2.navioAcertado) == 0){
		
		if(jogada1.numJogada < jogada2.numJogada) return 1;
		else return 0;
	}
	return 0;
}


//Função para imprimir os dados no arquivo de estatísticas//
void GeraArquivoEstatisticas(tEstatistica estatistica, FILE * file){
	
	int x=0, id=0, jog=0, y=0, ind = 0;
	
	fprintf(file,"%s\n", estatistica.nomeDoJogador);
	fprintf(file,"Tiros Errados: %d\n", estatistica.tirosErrados);
	fprintf(file,"Tiros Acertados: %d\n", estatistica.tirosCertos);
	fprintf(file,"Localizacao Media: (%.2f,%.2f)\n", estatistica.linhaMedia, estatistica.colunaMedia);
	fprintf(file,"Desvio Padrao da Localizacao: %.2f\n", estatistica.desvioPadrao);
	fprintf(file,"Navios de %s:\n", estatistica.nomeDoJogador);
	
	for(x=0;x<estatistica.qtdJogadas;x++){
		
		ind = 0;  //VARIÁVEL PARA INDICAR SE UM NAVIO COM O MESMO ID JÁ FOI IMPRESSO//
		if(TipoDaJogada(estatistica.jogada[x]) == 1){
			
			if(x > 0){
				
				for(y=0;y<x;y++){
					
					if(JogadasPossuemOMesmoNavio(estatistica.jogada[x], estatistica.jogada[y]))
						ind = 1;
				}
			}
			
			if(ind == 0){
				
				ImprimeJogadaNoArquivoDeEstatistica(estatistica.jogada[x], file);				
			}
		}
	}	
}


//Função para ver se duas jogadas atingiram um navio com o mesmo ID//
int JogadasPossuemOMesmoNavio(tJogada jogada1, tJogada jogada2){
	
	return (jogada1.idNavioAcertado == jogada2.idNavioAcertado);
}


//Função para imprimir as jogadas que acertaram os navios no arquivo de estatísticas//
void ImprimeJogadaNoArquivoDeEstatistica(tJogada jogada, FILE * file){
	
	
	fprintf(file,"%02d - %s - ID %02d\n", jogada.numJogada, jogada.navioAcertado, jogada.idNavioAcertado);
}

//Função para colocar o número da jogada no tipo tJogada//
tJogada ColocaNumDaJogada(tJogada jogada, int num){
	
	jogada.numJogada = num;
	
	return jogada;
}


//Função que retorna o tipo da jogada -> Tiro ou Agua//
int TipoDaJogada(tJogada jogada){
	
	if(strcmp(jogada.tipo,"Tiro") == 0) return 1;
	else if(strcmp(jogada.tipo,"Agua") == 0) return 0;	
}


//Função para verificar se o usuário pediu para gerar um tabuleiro aleatório//
int EhParaGerarTabuleiro(char * vet, char ** argv){
	
	sprintf(vet,"%s", argv[1]);
	
	if(strcmp(vet,"-gt")==0) return 1;
	
	return 0;
}


//Função para gerar tabuleiro aleatório//
void GeraTabuleiroAleatorio(char ** argv){
	
	int x=0, sentido=-1, y=0, ind=0;
	
	char tabuleiro[10][10];   //TABULEIRO CRIADO- optei por utilizá-lo ao invés do tipo tTabuleiro para não precisar fazer muitos acessos, além de o tipo tTabuleiro possuir muitos atributos que não precisei para esse trecho do código//
	tCoordenada coordenada;
	tNavio navio[5];        //Vetor para armazenar os 5 navios, 1 de cada tipo como inicializados abaixo//

	
	navio[0] = InicializaNavioComNomeEiD("Destroyer", 1);
	navio[1] = InicializaNavioComNomeEiD("Cruiser", 2);
	navio[2] = InicializaNavioComNomeEiD("Submarine", 3);
	navio[3] = InicializaNavioComNomeEiD("Battleship", 4);
	navio[4] = InicializaNavioComNomeEiD("Carrier", 5);			//INICIALIZAÇÃO DE UM NAVIO DE CADA TIPO COM SEUS RESPECTIVOS ID'S//	
	
	
	GeraTabuleiroVazio(10, 10, tabuleiro);	//GERANDO UM TABULEIRO VAZIO (apenas com 'o')//
	
		
	srand(time(NULL));  //para gerar tabuleiros aleatórios a cada execução do prog//
	
	for(x=0;x<5;x++){
		
		ind = 0;	//Esta variável indica se o navio poderá ser adicionado no campo de batalha sem gerar erros, quando ela é modificada, o loop pula para o próximo navio//
		while(1){

			if(ind) break;
			coordenada = GeraCoordenadaAleatoria();	//COORDENADA ALEATORIA GERADA//
			sentido = GeraSentidoAleatorio();		//SENTIDO ALEATORIO GERADO//
			navio[x] = ColocaCoordenadaEOrientacaoNoNavio(navio[x], coordenada, sentido);	//SENTIDO E COORDENADA DEVIDAMENTE ATRIBUIDOS AO NAVIO//
				
			if(EhPossivelAdicionarONavioNoTablado(tabuleiro, navio[x])){		//SE FOR POSSIVEL MONTAR O TABULEIRO COM TAL NAVIO, ABAIXO ELE ADICIONA O NAVIO NO TABULEIRO ORIGINAL//
				
				AdicionaUmNavioNoCampoDeBatalha(tabuleiro, navio[x]);
				ind =1;
			}
			
		}	
			
	}
		
	FILE * tabAleFile;		//ALOCANDO UM TIPO FILE PARA O ARQUIVO DE TABULEIRO ALEATORIO A SER GERADO//
	char diretorioTabu[1000];
	sprintf(diretorioTabu,"%s",argv[2]);
	
	tabAleFile = fopen(diretorioTabu,"w");
	for(y=0;y<5;y++){
		
		ImprimeNavioNoArquivoDeTabuleiroAleatorio(navio[y],tabAleFile);		//IMPRESSÃO DOS NAVIOS NO ARQUIVO//
		if(y != 4) fprintf(tabAleFile,"\n");
	}		
}


//Função para gerar uma coordeada aleatória (coordenada será usada para o ponto inicial do navio//
tCoordenada GeraCoordenadaAleatoria(){
	
	tCoordenada coordenada;
	
	int x=0, vet[2];
	
	for(x=0;x<2;x++){
		
		vet[x] = rand() % 10;
	}
	
	coordenada.linha = vet[0] + 1;
	coordenada.coluna = vet[1] + 1;
	coordenada.letra = GeraCoordenadaAlfabetica(coordenada.linha);
	sprintf(coordenada.strCord,"%c%d", coordenada.letra, coordenada.coluna);
	
	return coordenada;
}


//Função para retornar a coordenada alfabética de acordo com o número da coordenada//
char GeraCoordenadaAlfabetica(int num){
	
	if(num == 1)return 'a';
	else if(num == 2)return 'b';
	else if(num == 3)return 'c';
	else if(num == 4)return 'd';
	else if(num == 5)return 'e';
	else if(num == 6)return 'f';
	else if(num == 7)return 'g';
	else if(num == 8)return 'h';
	else if(num == 9)return 'i';
	else if(num == 10)return 'j';
}


//Função para gerar um sentido(0 ou 1) aleatório//
int GeraSentidoAleatorio(){
	
	int x;
	
	x = rand() % 2;
	
	return x;	
}


//função para inicializar um tipo tNavio somente com o nome e o ID//
tNavio InicializaNavioComNomeEiD(char * nome, int num){
	
	tNavio navio;
	
	strcpy(navio.nome, nome);
	navio.tamanho = CalculaTamanhoDoNavio(nome);
	navio.ID = num;
	return navio;
}


//Função para colocar atributos em um navio//
tNavio ColocaCoordenadaEOrientacaoNoNavio(tNavio navio, tCoordenada cord, int ori){
	
	navio.coordenada = cord;
	navio.orientacao = ori;
	return navio;
}


//Função para adicionar apenas um navio em um campo de batalha passado como parametro//
void AdicionaUmNavioNoCampoDeBatalha(char tab[10][10], tNavio navio){
	
	int linha, coluna, direcao, tamanho, y;
	
	
	linha = CoordenadaLinhaNavio(navio) - 1;
	coluna = CoordenadaColunaNavio(navio) - 1;
	direcao = DirecaoNavio(navio);                  // 0 = vertical , 1 = horizontal//
	tamanho = TamanhoNavio(navio);
				
	if(direcao == 0){
		for(y=0;y<tamanho;y++){											
			tab[linha + y][coluna] = 'X';			//ADICIONA PONTO A PONTO DOS NAVIOS VERTICAIS//	
		}
	}
		
	else if(direcao == 1){
		for(y=0;y<tamanho;y++){
			tab[linha][coluna + y] = 'X';			//ADICIONA PONTO A PONTO DOS NAVIOS HORIZONTAIS//
		}
	}		
}
	
	
//Função para imprimir um navio no arquivo de tabuleiro aleatorio//	
void ImprimeNavioNoArquivoDeTabuleiroAleatorio(tNavio navio, FILE * file){
	
	fprintf(file,"%s;%d;%d;", navio.nome, navio.ID, navio.orientacao);
	ImprimeCoordenadaNoArquivo(navio.coordenada, file);
}	



//Função para imprimir coordenadas no arquivo de tabuleiro aleatorio//
void ImprimeCoordenadaNoArquivo(tCoordenada coordenada, FILE * file){
	
	fprintf(file,"%s",coordenada.strCord);
}


//Função para verificar se é possível adicionar um navio passado como parametro em um campo de batalha passado como parâmetro//
int EhPossivelAdicionarONavioNoTablado(char tab[10][10], tNavio navio){
	
	char tablado[10][10];        //aloquei uma matriz auxiliar parar tentar criar o tabuleiro dentro dela e verificar se é possível//
	
	CopiaMatriz1Na2(10, 10, tab, 10, 10, tablado);	//A MATRIZ DO PARAMETRO DA FUNÇÃO É COPIADA PARA ESTA MATRIZ A FIM DE TESTÁ-LA SEM MODIFICAR A DE ORIGEM//
	
	int x=0, y=0;
	int linha, coluna, direcao, tamanho;     // linha e coluna das coordenadas do ponto inicial do navio
		
		
	linha = CoordenadaLinhaNavio(navio) - 1;		//lembrando que as linnhas e colunas na matriz começam com 0, diminuí 1 unidade para manuseá-las//
	coluna = CoordenadaColunaNavio(navio) - 1;
	direcao = DirecaoNavio(navio);                  // 0 = vertical , 1 = horizontal//
	tamanho = TamanhoNavio(navio);
		
	
	if(direcao == 0){
		
		if(tamanho == 2 && linha > 8) return 0;
		else if(tamanho == 3 && linha > 7) return 0;
		else if(tamanho == 4 && linha > 6) return 0;
		else if(tamanho == 5 && linha > 5) return 0;
	}
		                                                          //CONDIÇÕES PARA O BARCO NAO EXCEDER OS LIMITES DO TABULEIRO//
	else if(direcao == 1){
			
		if(tamanho == 2 && coluna > 8) return 0;
		else if(tamanho == 3 && coluna > 7) return 0;
		else if(tamanho == 4 && coluna > 6) return 0;
		else if(tamanho == 5 && coluna > 5) return 0;
	}
		
				
	if(tablado[linha][coluna] == 'X') return 0;	//verificar se a coordenada principal do navio já está ocupada//
		
	
	for(y=0;y<tamanho;y++){
			
			
		if(y==0){  // PARA VERIFICAR SE AS CÉLULAS AO REDOR DA PRIMEIRA COORDENADA DO NAVIO JÁ POSSUEM NAVIOS //
				
						
			if(coluna == 0 && linha == 0){
							
				if(tablado[linha + 1][coluna] == 'o' && tablado[linha][coluna + 1] == 'o' && tablado[linha+ 1][coluna + 1] == 'o')
					tablado[linha][coluna] = 'X';
				else return 0;
			}
						
			else if(coluna == 0 && linha == 9){
							
				if(tablado[linha - 1][coluna] == 'o' && tablado[linha][coluna + 1] == 'o' && tablado[linha - 1][coluna + 1] == 'o')
					tablado[linha][coluna] = 'X';
				else return 0;			
			}
				
			else if(coluna == 9 && linha == 9){
						
				if(tablado[linha - 1][coluna] == 'o' && tablado[linha][coluna - 1] == 'o' && tablado[linha - 1][coluna - 1] == 'o')
					tablado[linha][coluna] = 'X';
				else return 0;
			}	
				
			else if(coluna == 9 && linha == 0){
					
				if(tablado[linha + 1][coluna] == 'o' && tablado[linha][coluna - 1] == 'o' && tablado[linha + 1][coluna - 1] == 'o')
					tablado[linha][coluna] = 'X';
				else return 0;
			}
				//ATÉ AQUI FORAM VERIFICADAS COORDENADAS NOS VÉRTICES DO TABULEIRO//
					
						
			else if(coluna == 0){
				if(tablado[linha + 1][coluna] == 'o' && tablado[linha- 1][coluna] == 'o' && tablado[linha][coluna+1] == 'o' && tablado[linha + 1][coluna +1] == 'o' && tablado[linha - 1][coluna + 1] == 'o')
					tablado[linha][coluna] = 'X';
				else return 0;
			}
				
			else if(coluna == 9){
				if(tablado[linha + 1][coluna] == 'o' && tablado[linha - 1][coluna] == 'o' && tablado[linha][coluna-1] == 'o' && tablado[linha + 1][coluna -1] == 'o' && tablado[linha - 1][coluna - 1] == 'o')
					tablado[linha+ y][coluna] = 'X';
				else return 0;	
			}
			
			else if(linha == 0){
				if(tablado[linha][coluna + 1] == 'o' && tablado[linha][coluna - 1] == 'o' && tablado[linha + 1][coluna] == 'o' && tablado[linha + 1][coluna - 1] == 'o' && tablado[linha + 1][coluna + 1] == 'o')
					tablado[linha][coluna] = 'X';
				else return 0;
			}
			
			else if(linha == 9){
				if(tablado[linha][coluna + 1] == 'o' && tablado[linha][coluna - 1] == 'o' && tablado[linha - 1][coluna] == 'o' && tablado[linha - 1][coluna + 1] == 'o' && tablado[linha - 1][coluna - 1] == 'o')
					tablado[linha][coluna] = 'X';
				else return 0;
			}
			
			//ATÉ AQUI FORAM VERIFICADAS COORDENADAS NAS ARESTAS DOS TABULEIROS//
			
			else{
				if(tablado[linha - 1][coluna - 1] == 'o' && tablado[linha - 1][coluna] == 'o' && tablado[linha - 1][coluna + 1] == 'o' && tablado[linha][coluna - 1] == 'o' && tablado[linha][coluna + 1] == 'o' && tablado[linha + 1][coluna - 1] == 'o' && tablado[linha + 1][coluna] == 'o' && tablado[linha + 1][coluna + 1] == 'o')
					tablado[linha][coluna] = 'X';
				else return 0;
			}		
		}       //NESSE "ELSE" FORAM VERIFICADAS AS DEMAIS POSIÇÕES//
		    
		
		else if(y > 0){                                       // PARA VERIFICAR SE AS CÉLULAS AO REDOR DA SEGUNDA COORDENADA OU POSTERIOR DO NAVIO JÁ POSSUEM ALGUM NAVIO (UMA VERIFICAÇÃO PARA CADA DIREÇÃO)//
			
			if(direcao == 0){       // VERTICAL//
				
				linha = linha + 1;
				
				if(linha == 9){
					tablado[linha][coluna] = 'X';
				}
				
				else if(coluna == 0){
					if(tablado[linha + 1][coluna] == 'o' && tablado[linha + 1][coluna + 1] == 'o')
						tablado[linha][coluna] = 'X';
					else return  0;
				}
				
				else if(coluna == 9){
					if(tablado[linha + 1][coluna] == 'o' && tablado[linha + 1][coluna - 1] == 'o')
						tablado[linha][coluna] = 'X';
					else return 0;
				}
				
				else{
					if(tablado[linha + 1][coluna - 1] == 'o' && tablado[linha + 1][coluna] == 'o' &&tablado[linha + 1][coluna + 1] == 'o')
						tablado[linha][coluna] = 'X';
					else return 0;
				}			
			}
			
			else if(direcao == 1){    //HORIZONTAL//
				
				coluna = coluna + 1;
				
				if(coluna == 9){
					tablado[linha][coluna] = 'X';
				}
				
				else if(linha == 0){
					if(tablado[linha][coluna + 1] == 'o' && tablado[linha + 1][coluna + 1] == 'o')
						tablado[linha][coluna] = 'X';
					else return 0;
				}
				
				else if(linha == 9){
					if(tablado[linha][coluna + 1] == 'o' && tablado[linha - 1][coluna + 1] == 'o')
						tablado[linha][coluna] = 'X';
					else return 0;
				}
				
				else{
					if(tablado[linha - 1][coluna + 1] == 'o' && tablado[linha][coluna + 1] == 'o' && tablado[linha + 1][coluna + 1] == 'o')
						tablado[linha][coluna] = 'X';
					else return 0;
				}
			}												
		}														
	}
	
	return 1;	
}


