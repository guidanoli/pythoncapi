/*
 * bind.c
 *
 * Binding C functions to Python interpreter through
 * the Python/C API
 */

#include "libmypy.h"

char addfunc_docs[] = "Add two numbers function.";
char subfunc_docs[] = "Subtract two numbers function.";
char mulfunc_docs[] = "Multiply two numbers function.";
char divfunc_docs[] = "Divide two numbers function.";

PyMethodDef helloworld_funcs[] = {
	{
		"add",
		(PyCFunction) add,
		METH_VARARGS,
		addfunc_docs
	},
	{
		"sub",
		(PyCFunction) subtract,
		METH_VARARGS,
		subfunc_docs
	},
	{
		"mul",
		(PyCFunction) multiply,
		METH_VARARGS,
		mulfunc_docs
	},
	{
		"div",
		(PyCFunction) divide,
		METH_VARARGS,
		divfunc_docs
	},
	{ NULL }
};

char helloworldmod_docs[] = "This is hello world module.";
char helloworldmod_name[] = "helloworld";

#if PY_MAJOR_VERSION >= 3

PyModuleDef helloworld_mod = {
	PyModuleDef_HEAD_INIT,
	helloworldmod_name,
	helloworldmod_docs,
	-1,
	helloworld_funcs,
	NULL,
	NULL,
	NULL,
	NULL
};

PyMODINIT_FUNC PyInit_helloworld(void) {
	return PyModule_Create(&helloworld_mod);
}

#else

void inithelloworld(void) {
	Py_InitModule3(helloworldmod_name, helloworld_funcs, helloworldmod_docs);
}

#endif
