/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannahri <mannahri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 00:26:01 by sel-ouaf          #+#    #+#             */
/*   Updated: 2026/01/05 13:47:36 by mannahri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define BUFFER_SIZE 500
# define TOL 1500
# define L3ARD 1500
# define STEP 64
# define PI 3.141592653589793238

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>
# include <fcntl.h>
# include <string.h>
# include <math.h>
# include "./parsing/parsing.h"

typedef struct s_var
{
	int		count_no;
	int		count_so;
	int		count_we;
	int		count_ea;
	int		count_f;
	int		count_c;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*f;
	char	*c;
	int		*fl;
	int		*cel;
	int		r;
	int		g;
	int		b;
	int		c_color;
	int		f_color;
}	t_var;

typedef struct s_img
{
	void	*xpm_file;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		img_h;
	int		img_w;
}	t_img;

typedef struct s_dda
{
	float	x0;
	float	y0;
	float	x1;
	float	y1;
}	t_dda;

typedef struct s_paths
{
	t_img	no;
	t_img	so;
	t_img	we;
	t_img	ea;
	char	*path;
}	t_paths;

typedef struct s_cub
{
	int		count_line_in_map;
	float	new_angle;
	char	**map;
	void	*mlx_ptr;
	void	*mlx_win;
	int		width;
	int		height;
	float	alpha;
	float	marge;
	float	x;
	float	y;
	float	distance_of_ray;
	int		wall;
	float	dis_p_to_screen;
	int		cel;
	int		floor;
	int		index;
	void	*mlx_img;
	char	*addr1;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		state;
	int		x_img;
	int		y_img;
	t_paths	*path;
	t_pars	*pars;
	t_var	*var;
	int		dx;
	int		dy;
	float	step;
	float	xinc;
	float	yinc;
}	t_cub;

/*check_map*/
int		check_extention(char *str);
void	null_var(t_var *var);
int		scape_spaces(char *str);
void	check_numb(char **line, t_var *var);
void	check_caracters_in_map(char **map);
int		check_numb_of_player(char **map);
void	check_f_and_c(char *str);
void	split_f_and_c(char *str, t_var *var);
char	*parse_path(char *line, t_paths	*path);
void	take_path(char **line, t_var *var, t_paths	*path);
void	take_path_2(t_paths	*path, char **line, int i, t_var *var);
char	**r_file(char *str);
int		new_line_error(char *str);
char	**dup_map(char **line, t_cub *var);
void	check_zero_and_player(char **map);
void	check_one(char **line);
void	split_f(char *str, t_var *var);
void	split_c(char *str, t_var *var);
void	check_fd(int fd);
void	print_error(void);
/*libft*/
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strrchr(const char *s, int c);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strtrim(char const *s1, char const *set);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
/*get_next_line*/
char	*createbuffer(int fd, char *initbuf, char *buffer);
char	*splittext(char	*text);
char	*get_next_line(int fd);
/*split*/
char	**ft_split(char const *s, char c);
/*print_in_window*/
void	print_in_window( t_var *data, t_paths *path, t_cub *var);
void	first_position_and_angle_of_player(t_cub *var, int i, int j);
void	my_mlx_pixel_put(t_cub *data, int x, int y, int color);
void	xpm_files(t_var *data, t_paths *path, t_cub *cub);
char	*get_color_we(float _x, float _y, t_paths *path);
char	*get_color_ea(float _x, float _y, t_paths *path);
int		get_colors(t_cub *data, float _x, float _y, t_paths *path);
void	draw_images(t_cub *cub);
void	move_player2(int key, t_cub *player);
/*dda*/
void	dda_1(t_dda *dda, t_cub *cub);
void	fun_dda(t_cub *cub, t_dda *dda, int i0, t_var *var);
void	xinc_yinc_conditions(t_cub *cub, t_dda *dda);
void	break_condition(t_cub *cub, t_dda *dda);

/*textures*/
void	get_addr_textures(t_var *data, t_paths *path, t_cub *cub);
void	render_map(t_cub *var);
#endif