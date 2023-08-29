#include "binary_trees.h"
/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is perfect, 0 if not or if tree is NULL
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t height, nodes;

	if (free == NULL)
		return (0);

	height = binary_tree_height(tree);
	nodes = binary_tree_size(tree);

	return (nodes == (1 << height) - 1);
}
