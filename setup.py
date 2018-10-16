from setuptools import setup, Extension

sumtree = Extension('_sumtree', sources=['sumtree/sumtree.cxx',
                                         'sumtree/sumtree_wrap.cxx'])

setup(name='sumtree', version='0.2', packages=['sumtree'], ext_modules=[sumtree])
