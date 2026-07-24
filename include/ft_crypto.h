/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_crypto.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-hallu <gd-hallu@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 10:09:32 by gd-hallu          #+#    #+#             */
/*   Updated: 2026/07/24 10:09:59 by gd-hallu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CRYPTO_H
# define FT_CRYPTO_H

# include <stdint.h>
# include <stddef.h>

uint32_t	joaat_hash(unsigned char *key, size_t len);

#endif
