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
		matrix_y.add(i, 1, sin(2*xCoord) + cos(xCoord));
	}

	//Instanciando plotter
	//MatrixPlot matrixplot = MatrixPlot(2, 2); //Define subplot Cols; subplot Rows;

	MatrixPlot matrixplot = MatrixPlot();
	matrixplot.plot1d(matrix_x, matrix_y);
	cout << "Depois do plot" << endl;
	//Matrix matrix_box = Matrix(10,2);

	//matrixplot.plotbox(matrix);

	//Plotando matrix 1d
	/*
	matrixplot.plot1d(matrix, 0); //Plota e define o indice do subplot
	matrixplot.plot1d(matrix, 1);
	matrixplot.plot1d(matrix, 2);
	matrixplot.plot1d(matrix, 3);
	*/
	matrixplot.Run();

	return 0;
}

void testSimulation()
{

}
