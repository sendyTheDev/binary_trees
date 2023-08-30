#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * print_t- Stores recursively each level in an array of strings
 * @tree: Pointer to the node to print
 * @depth: Depth of the node
 * @offset: Offset to print
 * @b: Buffer
 *
 * Return: length of printed tree
 */
__attribute__((unused)) static int print_t(const binary_tree_t *tree, int offset, int depth, char **b)
{
	char d[6];
	int width, left, right, is_left, i;

	if (!tree)
		return (0);
	is_left = (tree->parent && tree->parent->left == tree);
	width = sprintf(d, "(%03d)", tree->n);
	left = print_t(tree->left, offset, depth + 1, b);
	right = print_t(tree->right, offset + left + width, depth + 1, b);
	for (i = 0; i < width; i++)
		b[depth][offset + left + i] = d[i];
	if (depth && is_left)
	{
		for (i = 0; i < width + right; i++)
			b[depth - 1][offset + left + width / 2 + i] = '-';
		b[depth - 1][offset + left + width / 2] = '.';
	}
	else if (depth && !is_left)
	{
		for (i = 0; i < left + width; i++)
			b[depth - 1][offset - width / 2 + i] = '-';
		b[depth - 1][offset + left + width / 2] = '.';
	}
	return (left + width + right);
}
