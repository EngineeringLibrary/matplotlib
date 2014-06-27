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
		matrix_y.add(i, 3, 1);
	}

	//Instanciando plotter
	//MatrixPlot matrixplot = MatrixPlot(2, 2); //Define subplot Cols; subplot Rows;

	MatrixPlot matrixplot = MatrixPlot();
	matrixplot.setAutoRange(false);

	matrixplot.SetRange('x', -10, 10);
	matrixplot.SetRange('y', -2, 6);

	matrixplot.plot1d(matrix_x, matrix_y);
	cout << "Depois do plot" << endl;

	matrixplot.saveToFile("teste.eps");

	matrixplot.Run();

	return 0;
}

void testSimulation()
{

}
