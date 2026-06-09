#ifndef FT_SSL_H
# define FT_SSL_H

typedef struct s_flags
{
	int	p;
	int	q;
	int	r;
}	t_flags;

typedef struct s_command
{
	const char	*name;
	int			(*run)(int argc, char **argv);
}	t_command;

enum e_target_kind
{
	TGT_STDIN,
	TGT_STRING,
	TGT_FILE,
};

typedef struct s_target
{
	int			kind;
	const char	*value;
}	t_target;

typedef struct s_args
{
	t_flags		flags;
	t_target	*targets;
	int			n_targets;
}	t_args;

int	parse_args(int argc, char **argv, t_args *out);
void	free_args(t_args *args);

int	dispatch(int argc, char **argv);

int	cmd_md5(int argc, char **argv);
int	cmd_sha256(int argc, char **argv);

int	usage(void);
int	unknown_command(const char *name);

#endif
