#include "binary_trees.h"
#include <stdlib.h>
#define QUEUE_SIZE 100
/**
 * create_queue - create queue
 *
 * Return: pointer to the queue
 */

queue_t *create_queue(void)
{
	queue_t *queue = malloc(sizeof(queue_t));

	if (queue == NULL)
	{
		return (NULL);
	}
	queue->front = queue->rear = 0;
	return (queue);
}
/**
 * enqueue_dequeue - chack for space and add or remove elements
 * @queue: Pointer to the queue elemnts
 * @item: Pointer to the items of the queue
 * Return: 1 on success or 0
 */

int enqueue_dequeue(queue_t *queue, binary_tree_t *item)
{
	if  (queue == NULL || item == NULL)
	{
		return (0);
	}
	if ((queue->rear + 1) % QUEUE_SIZE == queue->front)
		return (0);
	queue->elements[queue->rear] = item;
	queue->rear = (queue->rear + 1) % QUEUE_SIZE;
	return (1);
}
/**
 * dequeue - removes and return font elements
 * @queue: pointer to the queue elements
 * Return: 1 on success or 0
 */

binary_tree_t *dequeue(queue_t *queue)
{
	binary_tree_t *item;

	if (queue == NULL || is_empty(queue))
	{
		return (NULL);
	}

	item = queue->elements[queue->front];
	queue->front = (queue->front + 1) % QUEUE_SIZE;
	return (item);
}

/**
 * is_empty - checks rear and front elements
 * @queue: pointer to the queue elemnts
 * Return: 1 0r 0
 */
int is_empty(const queue_t *queue)
{
	return (queue->front == queue->rear);
}
