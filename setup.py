from setuptools import setup, Extension, find_packages

sumtree = Extension('_sumtree', sources=['sumtree.cxx', 'sumtree_wrap.cxx'])

setup(name='sumtree', version='1.0', packages=find_packages(), ext_modules=[sumtree])
