## Process this file with automake to produce Makefile.in

## Created by Anjuta

AM_CPPFLAGS = \
	-DPACKAGE_LOCALE_DIR=\""$(localedir)"\" \
	-DPACKAGE_SRC_DIR=\""$(srcdir)"\" \
	-DPACKAGE_DATA_DIR=\""$(pkgdatadir)"\"

AM_CFLAGS =\
	 -Wall\
	 -g

bin_PROGRAMS = graphlib

graphlib_SOURCES = \
	main.cc \
	matrix-plot.cc \
	matrix-plot.h \
	lib/Matrizes/matrix.cpp \
	mgl.h \
	mgl2 \
	data.h \
	iostream

graphlib_LDFLAGS = -lmgl

graphlib_LDADD = 


