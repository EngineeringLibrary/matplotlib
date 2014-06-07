#include <iostream>
#include "matrix-plot.h"
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
	MatrixPlot matrixplot = MatrixPlot();

	//Plotando matrix 1d
	matrixplot.plot1d(matrix);

	matrixplot.saveToFile ("src/teste.png");

	matrix.print();

	cout << "Salvando no arquivo";

	return 0;
}
