/*
 * libmypy.c
 *
 * Extension modules C functions definitions
 */

#include "libmypy.h"

PyObject * add(PyObject *self, PyObject *args) {
	int num1, num2;
	if(!PyArg_ParseTuple(args, "ii", &num1, &num2))
		return NULL;
	return Py_BuildValue("i", num1 + num2);
}
