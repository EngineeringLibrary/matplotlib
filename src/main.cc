#include <iostream>
#include "matrix-plot.h"
//#include "MatrixPlotWindow.h"
#include "lib/Matrizes/matrix.h"

int main()
{
	Matrix matrix = Matrix(200, 2);

	//Inicialização teste;
	for (int i=1; i <= 200; i++)
	{

		float xCoord = (float) (i -100)/10;

		matrix.add(i, 1, xCoord); //Coordenada X
		matrix.add(i, 2, sin(2*xCoord) + cos(xCoord)); //Coordenada Y
	}

	//Instanciando plotter
	MatrixPlot matrixplot = MatrixPlot(2, 2); //Define subplot Cols; subplot Rows;

	//Plotando matrix 1d
	matrixplot.plot1d(matrix, 0); //Plota e define o indice do subplot
	matrixplot.plot1d(matrix, 1);
	matrixplot.plot1d(matrix, 2);
	matrixplot.plot1d(matrix, 3);


	matrixplot.Run();

	return 0;
}
