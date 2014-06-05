/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * matrix-plot.cc
 * Copyright (C) 2014 Jonhnatha Jorge R. Trigueiro <joepreludian@gmail.com>
 *
 * unpplotlib is free software: you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * unpplotlib is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.";
 */

#include "matrix-plot.h"

MatrixPlot::MatrixPlot()
{
	this->Alpha(true);
	//this->Box();
	this->Light(true);
}

void MatrixPlot::saveToFile(const string filename)
{
	this->WritePNG(filename.c_str());
}

void MatrixPlot::render(Matrix & referenceMatrix, const string plotTitle){

	int matrixRows = referenceMatrix.getRows();
	int matrixCols = 2;

	mglData matrixDisplayData(matrixRows, matrixCols);

	float matrixData[matrixRows][matrixCols];
	for (int i=0; i < matrixRows; i++)
	{
		for (int j=0; j < matrixCols; j++)
		{
			matrixData[i][j] = referenceMatrix.getMat(i+1,j+1);
			matrixDisplayData.SetVal(matrixData[i][j], i, j, i);
		}
	}

	this->SetOrigin(0,0,0);

	this->SubPlot(1, 1, 0,""); //cols; lines; 3o 0 <t 1 t> 2 <b 3 b> (POSICAO INDICE)
	this->Title(plotTitle.c_str());

	this->Plot(matrixDisplayData);
	this->Box();

}
