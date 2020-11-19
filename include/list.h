#ifndef _LIST_H
#define _LIST_H

#include <stdlib.h>

/* Linked list node
 * 
 * typedef struct _ListNode {
 * 	   struct _ListNode *next;
 * 	   struct _ListNode *prev;
 * 	   type value; \
 * } ListNode; 
 */

/* Linked list
 *
 * typedef struct _List { \
 *     int count;
 *	   struct _ ## prefix ## ListNode *first;
 *	   struct _ ## prefix ## ListNode *last;
 * } List; 
 */

/* Create a linked list
 *
 * List *CreateList(void);
 *
 * Return 
 *   struct List *
 *   NULL if an allocation error occurred 
 */

/* Free a memory allocated for the linked list 
 *
 * void FreeList(List *list); 
 */

/* Remove every node from the linked list 
 *
 * void ClearList(List *list); 
 */

/* Remove every node from the linked list
 *
 * type *PopList(List *list);
 *
 * Return 
 *   an array of the linked list nodes values
 *   NULL if not the list given or an allocation error occurred 
 */

/* type *ListGetValues(List *list);
 *
 * Return 
 *   an array of the linked list nodes values
 *   NULL if not a list given or an allocation error occurred 
 */

/* Append a node with VALUE to the linked list
 *
 * int ListAppend(List *list, type value);
 *
 * Return 
 *   1 on success
 *   0 when allocation error occurred or not a list given 
 */

/* Go through the linked list
 * with CURR as a current node
 * in the iteration */
#define list_foreach(prefix, list, curr) \
	for (prefix ## ListNode *curr = (list)->first, *_node = (list)->first; \
		_node != NULL; \
		curr = _node = _node->next) \

/* Header declarations */
#define DeclareHeaderList(prefix, type) \
	typedef struct _ ## prefix ## ListNode { \
		struct _ ## prefix ## ListNode *next; \
		struct _ ## prefix ## ListNode *prev; \
		type value; \
	} prefix ## ListNode; \
	\
	typedef struct _ ## prefix ## List { \
		int count; \
		struct _ ## prefix ## ListNode *first; \
		struct _ ## prefix ## ListNode *last; \
	} prefix ## List; \
	\
	prefix ## List *Create ## prefix ## List(void); \
	\
	int Free ## prefix ## List(prefix ## List *list); \
	\
	int Clear ## prefix ## List(prefix ## List *list); \
	\
	type *Pop ## prefix ## List(prefix ## List *list); \
	\
	type *prefix ## ListGetValues(prefix ## List *list); \
	\
	int \
	prefix ## ListAppend(prefix ## List *list, type value); \
	\
	prefix ## List *Merge ## prefix ## Lists(prefix ## List *list1, prefix ## List *list2); \
	\
	int PMerge ## prefix ## Lists(prefix ## List **list1, prefix ## List *list2); \
	\
	int PMergeBefore ## prefix ## Lists(prefix ## List **list1, prefix ## List *list2); \
	\
	void Reverse ## prefix ## List(prefix ## List **list); \


/* Declare macro */
#define DeclareList(prefix, type) \
	prefix ## List \
	*Create ## prefix ## List(void) { \
		prefix ## List *list = (prefix ## List*)malloc(sizeof(prefix ## List)); \
		if (list == NULL) { \
			return NULL; \
		} \
		\
		list->first = NULL; \
		list->last = NULL; \
		list->count = 0; \
		\
		return list; \
	} \
	int \
	Free ## prefix ## List(prefix ## List *list) { \
		if (list != NULL) { \
			prefix ## ListNode *node = list->first, \
					 *next; \
			for (int i = 0; (i < list->count) && node != NULL; i++) { \
				next = node->next; \
				free(node); \
				node = next; \
			} \
			\
			free(list); \
			return 1; \
		} else { \
			return 0; \
		} \
	} \
	\
	int \
	Clear ## prefix ## List(prefix ## List *list) { \
		if (list != NULL) { \
			prefix ## ListNode *node = list->first, \
					 *next; \
			for (int i = 0; (i < list->count) && node != NULL; i++) { \
				next = node->next; \
				free(node); \
				node = next; \
			} \
			\
			list->count = 0; \
			list->first = NULL; \
			list->last = NULL; \
			return 1; \
		} else { \
			return 0; \
		} \
	} \
	\
	type *Pop ## prefix ## List(prefix ## List *list) { \
		if (list != NULL) { \
			type* result = (type*)malloc(sizeof(type) * list->count); \
			\
			if (result == NULL) { \
				return NULL; \
			} \
			\
			prefix ## ListNode *node = list->first, \
					 *next; \
			for (int i = 0; (i < list->count) && node != NULL; i++) { \
				result[i] = node->value; \
				next = node->next; \
				free(node); \
				node = next; \
			} \
			\
			list->count = 0; \
			list->first = NULL; \
			list->last = NULL; \
			\
			return result; \
		} else { \
			return NULL; \
		} \
	} \
	\
	type \
	*prefix ## ListGetValues(prefix ## List *list) { \
		if (list != NULL) { \
			type* result = (type*)malloc(sizeof(type) * list->count); \
			\
			if (result == NULL) { \
				return NULL; \
			} \
			\
			int i = 0; \
			list_foreach(prefix, list, curr) { \
				result[i] = curr->value; \
				i++; \
			} \
			\
			return result; \
		} else { \
			return NULL; \
		} \
	} \
	\
	int \
	prefix ## ListAppend(prefix ## List *list, type value) { \
		if (list != NULL) { \
			prefix ## ListNode *node = (prefix ## ListNode*)malloc(sizeof(prefix ## ListNode)); \
			\
			if (node == NULL) { \
				return 0; \
			} \
			\
			node->value = value; \
			node->next = NULL; \
			node->prev = NULL; \
			\
			if (list->first == NULL && list->last == NULL) { \
				list->first = node; \
				list->last = node; \
			} else { \
				node->prev = list->last; \
				list->last->next = node; \
				list->last = node; \
			} \
			\
			list->count++; \
			\
			return 1; \
		} else { \
			return 0; \
		} \
	} \
	\
	prefix ## List \
	*Merge ## prefix ## Lists(prefix ## List *list1, prefix ## List *list2) { \
		if (list1 != NULL && list2 != NULL) { \
			prefix ## List *result = Create ## prefix ## List(); \
			\
			if (result == NULL) { \
				return NULL; \
			} \
			\
			list_foreach(prefix, list1, curr) { \
				prefix ## ListAppend(result, curr->value); \
			} \
			list_foreach(prefix, list2, curr) { \
				prefix ## ListAppend(result, curr->value); \
			} \
			\
			return result; \
		} else { \
			return NULL; \
		} \
	} \
	\
	int \
	PMerge ## prefix ## Lists(prefix ## List **list1, prefix ## List *list2) { \
		if (list1 != NULL && list2 != NULL) { \
			list_foreach(prefix, list2, curr) { \
				prefix ## ListAppend(*list1, curr->value); \
			} \
			return 1; \
		} else { \
			return 0; \
		} \
	} \
	int \
	PMergeBefore ## prefix ## Lists(prefix ## List **list1, prefix ## List *list2) { \
		if (list1 != NULL && list2 != NULL) { \
			int i = 0; \
			prefix ## ListNode *first = (*list1)->first, \
							   *last = NULL; \
			list_foreach(prefix, list2, curr) { \
				prefix ## ListNode *node = (prefix ## ListNode*)malloc(sizeof(prefix ## ListNode)); \
				if (node == NULL) { \
					return 0; \
				} \
				node->next = NULL; \
				node->prev = NULL; \
				node->value = curr->value; \
				\
				if ((*list1)->first == NULL && (*list1)->last == NULL) { \
					(*list1)->first = node; \
					(*list1)->last = node; \
					first = (*list1)->first; \
				} else { \
					node->next = first; \
					if (i == 0) \
						last = node; \
					if (first->prev != NULL) \
						first->prev->next = node; \
					node->prev = first->prev; \
					first->prev = node; \
					i++; \
				} \
				\
				(*list1)->count++; \
			} \
			if (last != NULL) \
				(*list1)->first = last; \
			return 1; \
		} else { \
			return 0; \
		} \
	}\
	void \
	Reverse ## prefix ## List(prefix ## List **list) { \
		if (list != NULL) { \
			prefix ## ListNode *first = (*list)->first, \
						   	   *last = (*list)->last; \
			type tempvalue; \
			for (int i = 0; i < (*list)->count / 2; i++) { \
				tempvalue = first->value; \
				first->value = last->value; \
				last->value = tempvalue; \
				\
				first = first->next; \
				last = last->prev; \
			} \
		} \
	}
	

#endif
