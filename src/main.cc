#include <iostream>
#include "matrix-plot.h"
#include "lib/Matrizes/matrix.h"

int main()
{
	Matrix matrix = Matrix(10, 2);

	//Inicialização teste;
	for (int i=1; i<= 10; i++)
		for (int j=1; j <= 2; j++)
			if (j == 1)
				matrix.add(i,j, i);
			else
				matrix.add(i,j, i*2);


	MatrixPlot matrixplot = MatrixPlot();
	matrixplot.render(matrix);

	matrixplot.saveToFile ("src/teste.png");

	cout << "Deve ter salvado o arquivo";
	
	return 0;
}
