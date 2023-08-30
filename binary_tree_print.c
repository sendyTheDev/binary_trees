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
static int print_t(const binary_tree_t *tree, int offset, int depth, char **b)
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

/**
 * _height - Measures the height
 * @tree: Pointer to the node
 *
 * Return: The height of the tree starting at @node
 */
static size_t _height(const binary_tree_t *tree)
{
	size_t height_l;
	size_t height_r;

	height_l = tree->left ? 1 + _height(tree->left) : 0;
	height_r = tree->right ? 1 + _height(tree->right) : 0;
	return (height_l > height_r ? height_l : height_r);
}

/**
 * binary_tree_print - Prints a binary tree
 * @tree: Pointer to the root node of the tree to print
 */
void binary_tree_print(const binary_tree_t *tree)
{
	char **d;
	size_t height, i, j;

	if (!tree)
		return;
	height = _height(tree);
	d = malloc(sizeof(*d) * (height + 1));
	if (!d)
		return;
	for (i = 0; i < height + 1; i++)
	{
		d[i] = malloc(sizeof(**d) * 255);
		if (!d[i])
			return;
		memset(d[i], 32, 255);
	}
	print_t(tree, 0, 0, d);
	for (i = 0; i < height + 1; i++)
	{
		for (j = 254; j > 1; --j)
		{
			if (d[i][j] != ' ')
				break;
			d[i][j] = '\0';
		}
		printf("%s\n", d[i]);
		free(d[i]);
	}
	free(d);
}
