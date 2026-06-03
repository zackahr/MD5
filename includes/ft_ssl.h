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

int	dispatch(int argc, char **argv);

int	cmd_md5(int argc, char **argv);
int	cmd_sha256(int argc, char **argv);

#endif
