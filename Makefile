all:
	swig -python -c++ -o 'sumtree/sumtree_wrap.cxx' 'sumtree/sumtree.i'

test:
	swig -python -c++ -o 'sumtree/sumtree_wrap.cxx' 'sumtree/sumtree.i'
	pip3 install --upgrade .
	python3 sumtree_test.py
