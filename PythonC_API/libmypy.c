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

PyObject * subtract(PyObject *self, PyObject *args) {
	int num1, num2;
	if(!PyArg_ParseTuple(args, "ii", &num1, &num2))
		return NULL;
	return Py_BuildValue("i", num1 - num2);
}

PyObject * multiply(PyObject *self, PyObject *args) {
	int num1, num2;
	if(!PyArg_ParseTuple(args, "ii", &num1, &num2))
		return NULL;
	return Py_BuildValue("i", num1 * num2);
}

PyObject * divide(PyObject *self, PyObject *args) {
	float num1, num2;
	if(!PyArg_ParseTuple(args, "ff", &num1, &num2))
		return NULL;
	if (num2 == 0.0f) {
		PyErr_SetString(PyExc_ArithmeticError,
			"Cannot divide by zero.");
		return NULL;
	}
	return Py_BuildValue("f", num1 / num2);
}
