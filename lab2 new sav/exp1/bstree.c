#include "bstree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

struct bstree *bstree_create(char *key, uint32_t value)
{
    struct bstree *node;

    node = malloc(sizeof(*node));
    if (node != NULL)
    {
        node->key = key;
        node->value = value;
        node->left = NULL;
        node->right = NULL;
    }
    return node;
}

void bstree_add(struct bstree *tree, char *key, uint32_t value)
{
    if (tree == NULL)
        return;
    struct bstree *parent, *node;
    while (tree != NULL)
    {
        parent = tree;
        if (strcmp(key, tree->key) < 0)
            tree = tree->left;
        else if (strcmp(key, tree->key) > 0)
            tree = tree->right;
        else
            return;
    }
    node = bstree_create(key, value);
    if (strcmp(key, parent->key) < 0)
        parent->left = node;
    else
        parent->right = node;

}

struct bstree *bstree_lookup(struct bstree *tree, char *key)
{
    while (tree != NULL)
    {
        if (strcmp(key, tree->key) == 0)
            return tree;
        else if (strcmp(key, tree->key) < 0)
            tree = tree->left;
        else
            tree = tree->right;
    }
    return tree;
}

struct bstree *bstree_min(struct bstree *tree)
{
    if (tree == NULL)
        return NULL;

    while (tree->left != NULL)
        tree = tree->left;
    return tree;
}

struct bstree *bstree_max(struct bstree *tree)
{
    if (tree == NULL)
        return NULL;

    while (tree->right != NULL)
        tree = tree->right;
    return tree;
}

struct bstree *bstree_delete(struct bstree *tree, char *key)
{
    struct bstree *parent, *node;
    parent = NULL;
    node = tree;
    while (node != NULL && node->key != key)
    {
        parent = node;
        if (strcmp(key, node->key) < 0)
            node = node->left;
        else
            node = node->right;
    }
    if (node == NULL)
        return tree;
    return bstree_delete_node(tree, node, parent);
}

struct bstree *bstree_delete_node(struct bstree *tree, struct bstree *node, struct bstree *parent)
{
    if (node->left == NULL)
    {
        bstree_replace_node(parent, node, node->right);
        if (parent == NULL)
            tree = node->right;
    }
    else if (node->right == NULL)
    {
        bstree_replace_node(parent, node, node->left);
        if (parent == NULL)
            tree = node->left;
    }
    else
    {
        struct bstree *min, *minparent;
        min = node->right;
        minparent = min;
        while (min->left != NULL)
        {
            minparent = min;
            min = min->left;
        }
        bstree_replace_node(parent, node, min);
        if (parent == NULL)
            tree = min;
        if (node->right != min)
        {
            minparent->left = min->right;
            min->left = node->left;
            min->right = node->right;
        }
        else
            min->left = node->left;
    }
    free(node);
    return tree;
}

void bstree_replace_node(struct bstree *parent, struct bstree *node, struct bstree *child)
{
    if (parent != NULL)
    {
        if (strcmp(node->key, parent->key) < 0)
            parent->left = child;

        else
            parent->right = child;
    }
}