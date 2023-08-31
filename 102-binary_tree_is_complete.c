#include "binary_trees.h"

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is complete, 0 otherwise.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	const binary_tree_t *node, *queue[1000];
	int isComplete, front, rear;

	if (tree == NULL)
		return (0);
	isComplete = 1;
	front = 0;
	rear = 0;
	queue[rear++] = tree;

	while (front < rear)
	{
		node = queue[front++];
		if (node == NULL)
		{
			isComplete = 0;
		}
		else
		{
			queue[rear++] = node->left;
			queue[rear++] = node->right;
		}
	}
	return (isComplete);
}
