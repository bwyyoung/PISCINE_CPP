/* ************************************************************************* */
/*                                                                           */
/*                                                       :::      ::::::::   */
/*  barspainter.hpp                                    :+:      :+:    :+:   */
/*                                                   +:+ +:+         +:+     */
/*  By: byoung-w <byoung-w@student.42.fr>           +#+  +:+       +#+       */
/*                                               +#+#+#+#+#+   +#+           */
/*  Created: 2015/04/02 17:42:17 by byoung-w          #+#    #+#             */
/*  Updated: 2015/04/04 09:27:48 by byoung-w         ###   ########.fr       */
/*                                                                           */
/* ************************************************************************* */

#ifndef BARSPAINTER_H
#define BARSPAINTER_H
#include "performancepainter.hpp"

/**
 * @brief This class is draws bar graphs
 *
 * This class is a subclass of the abstract class PerformancePainter.
 * It implements a draw of bars graphs of which we have an example here
 *
 * \li \c Single Bar:
 * if the data contains just one value it s going to draw something like this
 * @image html performanceSingleBar.png "Single bar view"
 *
 * \li \c Multiple Bar:
 * if the data is an array, is going to draw one bar for each value in the
 * array and will look something like this.
 *@image html performanceMultiBar.png "Multi bar view"
 */

class BarsPainter : public PerformancePainter
{
public:
	/**
	 * @brief The constructor
	 * @param widget : This is a paintable widget at wich the painter is associated
	 */
	BarsPainter(QPaintDevice * widget);
	///Destructor
	~BarsPainter();
	///Reimplemented paint function
	void paint();

private:
	BarsPainter();
	BarsPainter(BarsPainter const &src);
	BarsPainter		&operator=(BarsPainter const &rhs);
};


#endif // BARSPAINTER_H

