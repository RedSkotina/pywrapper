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

static PyMethodDef HelloMethods[] = {
 { "hello", hello_wrapper, METH_VARARGS, "Say hello" },
 { NULL, NULL, 0, NULL }
};

PyMODINIT_FUNC
PyInit_pywrapper(void)
{
    return PyModule_Create(&HelloMethods);
}

