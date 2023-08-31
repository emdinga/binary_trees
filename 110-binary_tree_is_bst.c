#include "binary_trees.h"
#include <limits.h>
#include <stdbool.h>

/**
 * is_valid_bst - perform an inorder traversal and check BST validity.
 * @node: pointer to the node
 * @prev_value: pointer to the prev value
 * Return: True or False
 */
bool is_valid_bst(const binary_tree_t *node, int *prev_value)
{
	if (node == NULL)
		return (true);
	if (!is_valid_bst(node->left, prev_value))
		return (false);
	if (*prev_value >= node->n)
		return (false);
	*prev_value = node->n;
	return (is_valid_bst(node->right, prev_value));
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid Binary Search Tree
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid BST, 0 otherwise.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	int prev_value;

	if (tree == NULL)
		return (0);

	prev_value = INT_MIN;
	return (is_valid_bst(tree, &prev_value));
}
