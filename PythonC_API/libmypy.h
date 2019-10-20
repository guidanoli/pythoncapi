/*
 * libmypy.h
 *
 * Extension modules C functions prototypes
 */

#ifndef __LIBMYPY_H__
#define __LIBMYPY_H__

#include <Python.h>

PyObject * add(PyObject *, PyObject *);
PyObject * subtract(PyObject *self, PyObject *args);
PyObject * multiply(PyObject *self, PyObject *args);
PyObject * divide(PyObject *self, PyObject *args);

#endif
