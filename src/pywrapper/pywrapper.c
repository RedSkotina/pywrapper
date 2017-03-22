#include <Python.h>
#include "extlib.h"
static PyObject * hello_wrapper(PyObject * self, PyObject * args)
{
  char * input;
  long result;
  PyObject * ret;

  // parse arguments
  if (!PyArg_ParseTuple(args, "s", &input)) {
    return NULL;
  }

  // run the actual function
  result = hello(input);

  // build the resulting string into a Python object.
  ret = PyLong_FromLong(result);

  return ret;
}

//Method definition object for this extension, these argumens mean:
//ml_name: The name of the method
//ml_meth: Function pointer to the method implementation
//ml_flags: Flags indicating special features of this method, such as
//          accepting arguments, accepting keyword arguments, being a
//          class method, or being a static method of a class.
//ml_doc:  Contents of this method's docstring
static PyMethodDef hello_module_methods[] = { 
    {   
        "hello",
        hello_wrapper,
        METH_VARARGS,
        "Print 'hello' from a method defined in a C extension."
    },  
    {NULL, NULL, 0, NULL}
};

//Module definition
//The arguments of this structure tell Python what to call your extension,
//what it's methods are and where to look for it's method definitions
static struct PyModuleDef hello_module_definition = { 
    PyModuleDef_HEAD_INIT,
    "pywrapper",
    "A Python module that wrap 'hello' from C code.",
    -1, 
    hello_module_methods
};
PyMODINIT_FUNC
PyInit_pywrapper(void)
{
    return PyModule_Create(&hello_module_definition);
}

