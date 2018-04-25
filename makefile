advection.png: GP_graph.py advection.txt
	python GP_graph.py

advection.txt: advection
	./advection > advection.txt

advection: GP_advection.cpp
	c++ GP_advection.cpp -o advection
