#include <iostream>
#include "matrix-plot.h"

int main()
{
	Matrix matrix = Matrix(100, 2);
	MatrixPlot matrixplot = MatrixPlot(matrix);
	
	std::cout << matrixplot.cols;
	return 0;
}

