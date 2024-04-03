#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <inttypes.h>

#include "bstree.h"


bstree *bstree_create(char *key, int value)
{
	bstree *node;
	
	node = malloc(sizeof(*node));
	if(node != NULL)
	{
		node->key = key;
		node->value = value;
		node->left = NULL;
		node->right = NULL;
	}
	
	return node;
}

void bstree_add(bstree *tree, char *key, int value)
{
	if (tree == NULL)
	{
		return;
	}
	
	bstree *parent, *node;
	
	while (tree != NULL)
	{
		parent = tree;
		if (strcmp(key, tree->key) < 0)
		{
			tree = tree->left;
		}
		else if (strcmp(key, tree->key) > 0)
		{
			tree = tree->right;
		}
		else
		{
			return;
		}
	}
	
	node = bstree_create(key, value);
	if (strcmp(key, parent->key) < 0)
	{
		parent->left = node;
	}
	else
	{
		parent->right = node;
	}
}

bstree *bstree_lookup(bstree *tree, char *key)
{
	while (tree != NULL)
	{
		if (strcmp(key, tree->key) == 0)
		{
			return tree;
		}
		else if (strcmp(key, tree->key) < 0)
		{
			tree = tree->left;
		}
		else
		{
			tree = tree->right;
		}
	}
	return tree;
}

bstree *bstree_delete(bstree *tree, char *key)
{
	bstree *parent, *being_deleted = tree;
	
	while (being_deleted->key != key && being_deleted != NULL)
	{
		parent = being_deleted;
		if (strcmp(key, being_deleted->key) < 0)
		{
			being_deleted = being_deleted->left;
		}
		else if (strcmp(key, being_deleted->key) > 0)
		{
			being_deleted = being_deleted->right;
		}
	}

	if (being_deleted == NULL)
	{
		return tree;
	}

	if (being_deleted->left == NULL && being_deleted->right == NULL) // Удаляемый узел не имеет дочерних элементов
	{
		if (being_deleted != tree)
		{
			if (parent->left == being_deleted)
			{
				parent->left = NULL;
			}
			else
			{
				parent->right = NULL;
			}
		}
		else
		{
			tree = NULL;
		}

		free(being_deleted);
	}

	else if (being_deleted->left && being_deleted->right) // Удаляемый узел имеет двух потомков
	{
		bstree *successor = bstree_min(being_deleted->right);

		char *key = successor->key;
		uint32_t val = successor->value;
		bstree_delete(being_deleted, successor->key);
		being_deleted->value = val;
		being_deleted->key = key;
	}

	else // Удаляемый узел имеет только одного потомка
	{
		bstree *child;
		if (being_deleted->left)
		{
			child = being_deleted->left;
		}
		else
		{
			child = being_deleted->right;
		}

		if (being_deleted != tree)
		{
			if (being_deleted == parent->left)
			{
				parent->left = child;
			}
			else
			{
				parent->right = child;
			}
		}
		else
		{
			tree = child;
		}

		free(being_deleted);
	}
	return tree;
}

bstree *bstree_min(bstree *tree)
{
	if (tree == NULL)
	{
		return NULL;
	}
	
	while (tree->left != NULL)
	{
		tree = tree->left;
	}
	return tree;
}

bstree *bstree_max(bstree *tree)
{
	if (tree == NULL)
	{
		return NULL;
	}
	
	while (tree->right != NULL)
	{
		tree = tree->right;
	}
	return tree;
}