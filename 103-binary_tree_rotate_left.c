#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Performs a left rotation.
 * @tree: A pointer to the root node of the tre.
 *
 * Return: A pointer to the new root node
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new_root;

	if (tree == NULL || tree->right == NULL)
		return (NULL);
	new_root = tree->right;
	tree->right = new_root->left;
	new_root->left = tree;

	if (tree->rigth)
		tree->right->parent = tree;
	new_root->parent = tree->parent;
	tree->parent = new_root;

	return (new_root);
}
