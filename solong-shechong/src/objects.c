/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shechong <shechong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 12:03:15 by shechong          #+#    #+#             */
/*   Updated: 2024/01/25 11:34:06 by shechong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_object	*new_obj(char *type, void *data)
{
	t_object	*object_list;

	object_list = malloc(sizeof(t_object));
	if (!object_list)
		return (NULL);
	object_list->type = type;
	object_list->data = data;
	object_list->next = NULL;
	return (object_list);
}

t_object	*append(t_object **head, t_object *object)
{
	t_object	*current;

	if (*head == NULL)
	{
		*head = object;
		return (object);
	}
	current = *head;
	while (current->next)
		current = current->next;
	current->next = object;
	return (object);
}

t_sentry	*new_sentry(t_display *display, t_xy pos)
{
	t_sentry	*sentry;

	sentry = malloc(sizeof(t_sentry));
	*sentry = (t_sentry){pos, 0, 0, 5,
		(t_animator){0, 0, 30,
		frames(SENTRY_SPRITES, "assets/", display), NULL},
		0, 0, pos, (t_timer){5, 0}};
	sentry->animator.current_frame = sentry->animator.frames[0];
	return (sentry);
}

t_collectible	*new_collectible(t_display *display, t_xy pos)
{
	t_collectible	*collectible;

	collectible = malloc(sizeof(t_collectible));
	*collectible = (t_collectible){pos,
		(t_animator){0, 0, 30,
		frames(COLLECTIBLE_SPRITES, "assets/", display), NULL}};
	collectible->animator.current_frame = collectible->animator.frames[0];
	return (collectible);
}
