#include <Python.h>

/**
 * print_python_list_info - Prints basic info about Python lists.
 * @p: A PyObject list.
 */
void print_python_list_info(PyObject *p)
{
	int size, alc, j;
	PyObject *obj;

	size = Py_SIZE(p);
	alc = ((PyListObject *)p)->allocated;

	printf("[*] Size of the Python List = %d\n", size);
	printf("[*] Allocated = %d\n", alc);

	for (j = 0; j < size; j++)
	{
		printf("Element %d: ", j);

		obj = PyList_GetItem(p, j);
		printf("%s\n", Py_TYPE(obj)->tp_name);
	}
}
