from distutils.core import setup, Extension

sumtree = Extension('_sumtree', sources=['sumtree.cxx', 'sumtree_wrap.cxx'])

setup(name='SumTree', version='1.0', ext_modules=[sumtree])
