### Olá! Esse é um código de um game de batalha naval feito para rodar na linha de comando do terminal Linux

 - Compile o programa em sua máquina: *"gcc -o prog JoaoPauloMouraClevelares.c -lm"*

 - Primeiro passo para o game funcionar, na mesma pasta que está o programa compilado, é necessário criar um diretório (nome à sua escolha) e dentro desse diretório é necessário criar um outro diretório de nome *"saida"*.

 - Segundo passo é gerar 2 tabuleiros aleatórios que ficarão dentro do diretorio principal (que você escolheu o nome) junto com o diretório *"saida"*, com os respectivos nomes: *"tabu_1.txt"* e *"tabu_2.txt"*. Para gerar esses tabuleiros é necessário usar o comando:

    "*./prog -gt {nome-do-diretório/tabu_@.txt}"* - esse comando deverá ser executado 2 vezes substituindo o @ por 1 e depois por 2.

    Ao final desse processo, o diretório que você criou e escolheu o nome deverá conter os seguintes arquivos:

    1 diretório - saida

    1 arquivo - tabu_1.txt

    1 arquivo - tabu_2.txt

 - Terceiro passo é executar o programa. Para executar é só abrir o terminal na pasta que está o programa compilado e digitar o comando *"./prog {nome-do-diretorio}"*

#### OBS: Para jogar, deve-se inserir posições de tabuleiro de A - J e de 1 - 10.



