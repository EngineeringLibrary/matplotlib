#include <iostream>
#include "matrix-plot.h"
//#include "MatrixPlotWindow.h"
#include "lib/Matrizes/matrix.h"

int main()
{
	Matrix matrix = Matrix(200, 2);


	Matrix matrix_x = Matrix(200,1);
	Matrix matrix_y = Matrix(200,1);

	//Inicialização teste;
	for (int i=1; i <= 200; i++)
	{
		float xCoord = (float) (i -100)/10;

		matrix_x.add(i, 1, xCoord);
		matrix_x.add(i, 2, xCoord); //Segundo plotter
		matrix_x.add(i, 3, xCoord);

		matrix_y.add(i, 1, sin(2*xCoord) + cos(xCoord));
		matrix_y.add(i, 2, cos(2*xCoord) + sin(xCoord)); //Segundo plotter em Y. Alterando dados
		matrix_y.add(i, 3, xCoord*0.05);
	}

	//Instanciando plotter

	//MatrixPlot matrixplot = MatrixPlot(2, 2); //Define subplot Cols; subplot Rows;
	MatrixPlot matrixplot1 = MatrixPlot();
	matrixplot1.setAutoRange(false);

	matrixplot1.SetRange('x', -10, 10);
	matrixplot1.SetRange('y', -2, 2);

	matrixplot1.plot1d(matrix_x, matrix_y);
	matrixplot1.saveToFile("teste.eps");

	matrixplot1.Run();


	//Exemplo usando matrix plot

	//Inicializacao do boxplot - Ainda em implementacao
	/*
	Matrix matrixbox = Matrix(2,4);
	for (int i=1; i <= matrixbox.getRows(); i++)
		for (int j=1; j <= matrixbox.getCols(); j++)
			matrixbox.add(i,j, j*8);

	MatrixPlot matrixplot = MatrixPlot();
	matrixplot.plotbox(matrixbox);


	matrixplot.Run();
	*/

	return 0;
}
