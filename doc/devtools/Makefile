#/******************************************************************************
# * Eagle3D - generates 3d images from Eagle PCB board files.
# *
# * See the README file for copyright information and how to reach the author.
# *****************************************************************************/

INCLUDE  = -I.
INCLUDE += -I../../../librepfunc_git
INCLUDE += -I../../../pugixml/src/

LIBS = -L../../../librepfunc_git -l:librepfunc.dll

all:
	g++ -O2 -Wall -Wextra $(INCLUDE) find_package.cpp $(LIBS) -o find_package

