/* ************************************************************************* */
/*                                                                           */
/*                                                       :::      ::::::::   */
/*  ramwidget.hpp                                      :+:      :+:    :+:   */
/*                                                   +:+ +:+         +:+     */
/*  By: byoung-w <byoung-w@student.42.fr>           +#+  +:+       +#+       */
/*                                               +#+#+#+#+#+   +#+           */
/*  Created: 2015/04/02 17:42:17 by byoung-w          #+#    #+#             */
/*  Updated: 2015/04/04 09:27:48 by byoung-w         ###   ########.fr       */
/*                                                                           */
/* ************************************************************************* */


#ifndef RAMWIDGET_HPP
#define RAMWIDGET_HPP

/**
 * @brief Widget that show the ram usage
 *
 * This widget inherith from PerformanceWidget class. and specialize it in order to
 * show the ram usage.
 */


#include "performancewidget.hpp"
#include "ramdataquery.hpp"

class RamWidget : public PerformanceWidget
{
public :
	/// Constants defining the draw mode
	enum drawMode
	{
		/// Draw the data as bar/s
		DRAW_BARS = 0,
		/// Draw the data as graph/s
		DRAW_GRAPH = 1
	};


public:
	RamWidget(QWidget *parent) ;
	~RamWidget();
	/** This method lets the user set the display mode for the widget
	*   @param mode : what mode to draw the widget, available options : \li DRAW_BARS
	*				 \li DRAW_GRAPH
	*/
	void setDisplayMode(const drawMode mode);
private:
	RamDataQuery m_dataQuery;
	BarsPainter *m_barsP;
	GraphPainter *m_graphP;
	int m_displayMode;
	RamWidget(RamWidget const &src);
	RamWidget		&operator=(RamWidget const &rhs);
	RamWidget();

};

#endif // RAMWIDGET_H
