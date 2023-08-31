#include "binary_trees.h"
int enqueue_dequeue(queue_t *queue, binary_tree_t *item);
binary_tree_t *dequeue(queue_t *queue);
queue_t *create_queue(void);
binary_tree_t *dequeue(queue_t *queue);
int is_empty(const queue_t *queue);

/**
 * binary_tree_levelorder - binary tree using level-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	queue_t *queue;
	binary_tree_t *node;

	if (tree == NULL || func == NULL)
		return;
	queue = create_queue();

	if (queue == NULL)
		return;
	enqueue(queue, (void *)tree);
	while (!is_empty(queue))
	{
		node = (binary_tree_t *)dequeue(queue);
		func(node->n);
		if (node->left != NULL)
			enqueue(queue, (void *)(node->left));
		if (node->right != NULL)
			enqueue(queue, (void *)(node->right));
	}
	free(queue);
}
