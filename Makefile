all:
	swig -python -c++ -o 'src/sumtree_wrap.cxx' 'src/sumtree.i'

clean:
