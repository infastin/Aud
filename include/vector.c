#include <stdlib.h>
#include "vector.h"

int IsVector(void *vect) {
	if (vect) {
		int *orig = (int*) vect;
		if (orig-1 && orig-2) {
			return 1;
		}
	}
	
	return 0; 
} 

int VectorGetCount(void *vect) { 
	if (IsVector(vect)) { 
		int *orig = (int*) vect; 
		if ((orig-2)[0] >= 0) { 
			return (orig-2)[0]; 
		} 
	} 
	
	return -1; 
} 

int VectorGetSize(void *vect) { 
	if (IsVector(vect)) { 
		int *orig = (int*) vect; 
		if ((orig-2)[1] > 0) { 
			return (orig-2)[1]; 
		} 
	}
	
	return 0; 
} 

int *VectorGetProperties(void *vect) { 
	if (IsVector(vect)) { 
		int *props = (int*)calloc(sizeof(int), 2); 
		
		if (props == NULL) { 
			return NULL; 
		} 
		
		int *orig = (int*) vect; 
		if ((orig-2)[0] >= 0 && (orig-2)[1] > 0) { 
			props[0] = (orig-2)[0]; 
			props[1] = (orig-2)[1]; 
			
			return props; 
		} 
	} 
	
	return NULL; 
}

DeclareVector(Int, int, Value)
DeclareVector(IntP, int*, Pointer)
DeclareVector(Char, char, Value)
DeclareVector(WChar, wchar_t, Value)
