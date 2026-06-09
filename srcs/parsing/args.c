#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ft_ssl.h"

static int	is_flag_token(const char *s)
{
	return (s[0] == '-' && s[1] != '\0');
}

static int	set_flag(t_flags *f, char c)
{
	if (c == 'p')
		f->p = 1;
	else if (c == 'q')
		f->q = 1;
	else if (c == 'r')
		f->r = 1;
	else
		return (-1);
	return (0);
}

static void	push_target(t_args *a, int kind, const char *value)
{
	a->targets[a->n_targets].kind = kind;
	a->targets[a->n_targets].value = value;
	a->n_targets++;
}

static int	handle_flag_token(int *i, int argc, char **argv, t_args *a)
{
	int	j;

	if (strcmp(argv[*i], "-s") == 0)
	{
		if (*i + 1 >= argc)
			return (fprintf(stderr,
					"ft_ssl: option requires an argument -- s\n"), -1);
		(*i)++;
		push_target(a, TGT_STRING, argv[*i]);
		return (0);
	}
	j = 1;
	while (argv[*i][j])
	{
		if (set_flag(&a->flags, argv[*i][j]) < 0)
			return (fprintf(stderr,
					"ft_ssl: illegal option -- %c\n", argv[*i][j]), -1);
		j++;
	}
	return (0);
}

int	parse_args(int argc, char **argv, t_args *out)
{
	int	i;

	out->flags = (t_flags){0, 0, 0};
	out->n_targets = 0;
	out->targets = calloc(argc + 1, sizeof(t_target));
	if (!out->targets)
		return (-1);
	i = 1;
	while (i < argc)
	{
		if (is_flag_token(argv[i]))
		{
			if (handle_flag_token(&i, argc, argv, out) < 0)
				return (-1);
		}
		else
			push_target(out, TGT_FILE, argv[i]);
		i++;
	}
	return (0);
}

void	free_args(t_args *a)
{
	free(a->targets);
	a->targets = NULL;
	a->n_targets = 0;
}
