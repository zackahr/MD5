#include <stdio.h>
#include "ft_ssl.h"

static const char	*target_label(int kind)
{
	if (kind == TGT_STDIN)
		return ("stdin");
	if (kind == TGT_STRING)
		return ("string");
	return ("file");
}

int	cmd_sha256(int argc, char **argv)
{
	t_args	args;
	int		i;

	if (parse_args(argc, argv, &args) < 0)
	{
		free_args(&args);
		return (1);
	}
	printf("sha256 parsed: p=%d q=%d r=%d, %d target(s)\n",
		args.flags.p, args.flags.q, args.flags.r, args.n_targets);
	i = 0;
	while (i < args.n_targets)
	{
		printf("  [%d] %s: %s\n", i, target_label(args.targets[i].kind),
			args.targets[i].value);
		i++;
	}
	free_args(&args);
	return (0);
}
