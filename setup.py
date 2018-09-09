from setuptools import setup, Extension

sumtree = Extension('_sumtree', sources=['src/sumtree.cxx',
                                         'src/sumtree_wrap.cxx'])

setup(name='sumtree', version='0.2',
     packages=['.'], ext_modules=[sumtree])
