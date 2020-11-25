#pragma once

#include <wchar.h>

#define __DHFVPointer(prefix, dtype) \
	void Free ## prefix ## Vector(dtype *vect); \
	void VFree ## prefix ## Vector(dtype *vect); \
	void Free ## prefix ## VectorValue(dtype *vect, int index); \
	void VFree ## prefix ## VectorValue(dtype *vect, int index);

#define __DSFVPointer(prefix, dtype) \
	void Free ## prefix ## Vector(dtype *vect) { \
		if (IsVector(vect)) { \
			for (int vi = 0; vi < VectorGetCount(vect); vi++) { \
				if (vect[vi]) { \
					free(vect[vi]); \
				} \
			} \
			\
			int *orig = (int*) vect; \
			free(orig-2); \
		} \
	} \
	void VFree ## prefix ## Vector(dtype *vect) { \
		if (IsVector(vect)) { \
			for (int vi = 0, *origv; vi < VectorGetCount(vect); vi++) { \
				if (vect[vi]) { \
					origv = (int*) vect[vi]; \
					free(origv - 2); \
				} \
			} \
			\
			int *orig = (int*) vect; \
			free(orig-2); \
		} \
	} \
	void Free ## prefix ## VectorValue(dtype *vect, int index) { \
		if (index >= 0 && IsVector(vect)) { \
			if (vect[index]) { \
				free(vect[index]); \
				int *orig = (int*) vect; \
				(orig-2)[0]--; \
			} \
		} \
	} \
	void VFree ## prefix ## VectorValue(dtype *vect, int index) { \
		if (index >= 0 && IsVector(vect)) { \
			if (vect[index]) { \
				int *origv = (int*) vect[index]; \
				free(origv-2); \
				int *orig = (int*) vect; \
				(orig-2)[0]--; \
			} \
		} \
	}

#define __DHFVValue(prefix, dtype) \
	void Free ## prefix ## Vector(dtype *vect);

#define __DSFVValue(prefix, dtype) \
	void Free ## prefix ## Vector(dtype *vect) { \
		if (IsVector(vect)) { \
			int *orig = (int*) vect; \
			free(orig-2); \
		} \
	}

#define DeclareHeaderVector(prefix, dtype, vtype) \
	dtype *Create ## prefix ## Vector(void); \
	void prefix ## VectorPush(dtype **vect, dtype value); \
	void Reverse ## prefix ## Vector(dtype **vect); \
	__DHFV ## vtype (prefix, dtype)

#define DeclareVector(prefix, dtype, vtype) \
	dtype *Create ## prefix ## Vector(void) { \
		int *vect = (int*)malloc(sizeof(dtype) + 2 * sizeof(int)); \
		\
		if (vect == NULL) { \
			return NULL; \
		} \
		\
		vect[0] = 0; \
		vect[1] = 1 * sizeof(dtype); \
		return (dtype*)(void*)(vect+2); \
	} \
	\
	void prefix ## VectorPush(dtype **vect, dtype value) { \
		int *props = VectorGetProperties(*vect); \
		\
		if (props) { \
			int count = props[0], \
				size = props[1], \
				**orig = (int**) vect; \
			if ((count * sizeof(dtype)) >= size) { \
				if (size > 64) { \
					size *= 1.25; \
				} else if (size > 8) { \
					size *= 2; \
				} else { \
					size *= 4; \
				} \
				\
				*orig -= 2; \
				*orig = (int*)realloc(*orig, 2 * sizeof(int) + size); \
				(*orig)[1] = size; \
				*orig += 2; \
			} \
			\
			(*orig-2)[0]++; \
			dtype **vect = (dtype**) orig; \
			(*vect)[count] = value; \
			free(props); \
		} \
	} \
	void Reverse ## prefix ## Vector(dtype **vect) { \
		int count = VectorGetCount(*vect); \
		for (int i = 0; i < count / 2; ++i) { \
			dtype temp = (*vect)[i]; \
			(*vect)[i] = (*vect)[count-i-1]; \
			(*vect)[count-i-1] = temp; \
		} \
	} \
	\
	__DSFV ## vtype (prefix, dtype)

/* Check if VECT is a vector
 *
 * Return:
 * ● 1 if a vector;
 * ● 0 if not a vector. 
 */
int  IsVector(void *vect);

/* Get the number of elements in a vector and the size of the vector
 *
 * Return:
 * ● array containing the number of elements (i: 0) and the size (i: 1);
 * ● NULL on error.
 */
int  *VectorGetProperties(void *vect);

/* Get the size of the vector
 *
 * Return:
 * ● the number of elements;
 * ● -1 if VECT is not a vector. 
 */

int  VectorGetSize(void *vect);

/* Get the number of elements in the vector
 *
 * Return:
 * ● the number of elements;
 * ● -1 if VECT is not a vector.
 */
int  VectorGetCount(void *vect);

DeclareHeaderVector(Int, int, Value)
DeclareHeaderVector(IntP, int*, Pointer)
DeclareHeaderVector(Char, char, Value)
DeclareHeaderVector(WChar, wchar_t, Value)
