manual:
	swig -python -c++ -o sumtree_wrap.cxx sumtree.i
	python3 setup.py build_ext --inplace
	python3 setup.py install --user

clean:
	rm _sumtree*
	rm *_wrap*
	rm sumtree.py
