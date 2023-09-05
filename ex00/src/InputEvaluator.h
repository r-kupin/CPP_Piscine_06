/******************************************************************************/
/*                                                                            */
/*                                                         :::      ::::::::  */
/*    InputEvaluator.h                                   :+:      :+:    :+:  */
/*                                                     +:+ +:+         +:+    */
/*    By: rokupin <rokupin@student.42.fr>            +#+  +:+       +#+       */
/*                                                 +#+#+#+#+#+   +#+          */
/*    Created: 2023/02/06 10:27:58 by rokupin           #+#    #+#            */
/*                                                     ###   ########.fr      */
/*                                                                            */
/******************************************************************************/

#ifndef EX00_INPUTEVALUATOR_H
#define EX00_INPUTEVALUATOR_H

#include <string>

struct InputEvaluator {
	static bool input_is_correct(std::string input);
};


#endif //EX00_INPUTEVALUATOR_H
