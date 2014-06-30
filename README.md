##Matplotlib
------------
Biblioteca para geração de matrizes utilizando a biblioteca *MathGL* para a disciplina de Cálculo Numérico, Curso de Engenharia de Computação UNP Nascimento de castro.

###Desenvolvimento
------------------
Foi utilizado uma máquina com Fedora 20/Mate Desktop com anjuta IDE.

###Dependências
Para poder usar esta biblioteca você precisa:

* MathGL - [http://mathgl.sourceforge.net/doc_en/Download.html#Download]()
* FLTK - [http://www.fltk.org/software.php]()
* Matrix - [https://github.com/rodrigoavalente/LibSimulation]()

###Utilização Básica
Esta biblioteca trabalha com as matrizes de modo a gerar gráficos usando a FLTK como porta.

Há implementado o método de plotagem de gráficos 2d, até 3 gráficos simultâneos. Confira o arquivo *main.cc* para mais informações;

Precisamos incluir a biblioteca:

    #include "matrix-plot.h"

Para instanciar o Plotter fazemos:
 
    MatrixPlot matrixplot = MatrixPlot();

Esta configuração impede o autoRange, ou seja, a possibilidade dele calcular o limite da função. Desabilite-o quando for usar mais de um plot por vez;

	matrixplot.setAutoRange(false);

Este seta o range dos eixos "X" e "Y" respectivamente;

	matrixplot.SetRange('x', -10, 10);
	matrixplot.SetRange('y', -2, 6);

Essa função "plota" a matrix de coordenadas X e Y, onde cada cordenada fica em uma linha, e cada coluna seria um subplot específico;

	matrixplot.plot1d(matrix_x, matrix_y);

Caso queira salvar o conteúdo do arquivo em formato EPS, basta rodar esse comando.

	matrixplot.saveToFile("teste.eps");

Este abre a caixa de diálogo utilizando o FLTK com o gráfico gerado. Este precisa ser executado após o "plot1d".

	matrixplot.Run();
	
### Dúvidas?
------------
Qualquer coisa basta gerar um *Issue* nesse repositório que tentaremos resolver na medida do possível!
