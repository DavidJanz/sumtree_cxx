%module sumtree
%{
/* Includes the header in the wrapper code */
#include "sumtree.h"
%}

%typemap(out) std::pair<long,long> {
        PyObject *list = PyTuple_New(2);
        PyTuple_SetItem(list, 0, PyInt_FromLong($1.first));
        PyTuple_SetItem(list, 1, PyInt_FromLong($1.second));
        $result = list;
}


/* Parse the header file to generate wrappers */
%include "sumtree.h"

