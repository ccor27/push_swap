/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crosorio <crosorio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:04:08 by crosorio          #+#    #+#             */
/*   Updated: 2025/05/19 16:04:09 by crosorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
# include <stdarg.h>
# include <stdint.h>

int	ft_is_valid_specifier(char c);
int	ft_scan(char specifier, va_list args);
int	ft_process_string(char *ptr, va_list args);
int	ft_handle_int(int num);
int	ft_handle_unsigned_int(unsigned int num);
int	ft_handle_hexadecimal(unsigned int num, char c);
int	ft_handle_percentage(void);
int	ft_handle_string(char *string);
int	ft_handle_character(char c);
int	ft_handle_pointer(void *ptr);
int	ft_printf(const char *string, ...);
#endif
