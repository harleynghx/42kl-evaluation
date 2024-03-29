/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 17:10:15 by jthor             #+#    #+#             */
/*   Updated: 2024/02/02 23:26:18 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# if OS == 1
#  define IS_LINUX 1
# else
#  define IS_LINUX 0
# endif

# define BUFFER_SIZE 50
# define MAX_INT 2147483647
# define NOT_EDIT -1
# define EDIT_MODE 0
# define CAM_EDIT 1
# define LIGHT_EDIT 2
# define OBJ_EDIT 3

# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include "libft.h"
# include "mlx.h"
# include "objects.h"
# include "driver.h"
# include "init.h"
# include "mathematics.h"
# include "mem_free.h"
# include "parse.h"
# include "ray_tracing.h"
# include "utils.h"
# include "keys.h"
# include "editor.h"

/**
 * @brief Scrolls through the object linked list and returns the object that
 * is referenced by the index.
 * @return A pointer to the t_object struct.
 * @param obj_lst The object linked list, holding every object.
 * @param index The index of the object in the list to be returned.
*/
t_object	*get_object(t_list *obj_lst, int index);

#endif
