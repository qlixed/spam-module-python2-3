#include <Python.h>

static PyObject * SpamError;


static PyObject *
spam_system(PyObject *self, PyObject * args)
{
	const char *command;
	int sts;

	if(!PyArg_ParseTuple(args, "s", &command))
		return NULL;

	sts = system(command);
	if ( sts < 0 ) {
		PyErr_SetString(SpamError, "System command failed");
		return NULL;
	}
	return PyLong_FromLong(sts);
}


static PyMethodDef SpamMethods[] = {
    {"system",  spam_system, METH_VARARGS,
     "Execute a shell command."},
    {NULL, NULL, 0, NULL}        /* Sentinel */
};


#if PY_MAJOR_VERSION >= 3

static struct PyModuleDef spammodule = {
   PyModuleDef_HEAD_INIT,
   "spam",   /* name of module */
   NULL, /* module documentation, may be NULL */
   -1,       /* size of per-interpreter state of the module,
                or -1 if the module keeps state in global variables. */
   SpamMethods
};
#endif


PyMODINIT_FUNC
#if PY_MAJOR_VERSION >= 3
PyInit_spam(void)
#else
initspam(void)
#endif
{
    PyObject *m;
    #if PY_MAJOR_VERSION >= 3
    m = PyModule_Create(&spammodule);
    #else
    m = Py_InitModule("spam", SpamMethods);
    #endif

    if ( m == NULL )
        #if PY_MAJOR_VERSION >= 3
		return NULL;
        #else
        return;
        #endif
    SpamError = PyErr_NewException("spam.error", NULL, NULL);
    Py_INCREF(SpamError);
    PyModule_AddObject(m, "error", SpamError);
    #if PY_MAJOR_VERSION >= 3
    return m;
    #endif
}

#if PY_MAJOR_VERSION < 3
int
main(int argc, char *argv[])
{
	Py_SetProgramName(argv[0]);
	Py_Initialize();
	initspam();
}
#endif

