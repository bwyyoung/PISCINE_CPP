/* ************************************************************************* */
/*                                                                           */
/*                                                       :::      ::::::::   */
/*  cpuwidget.hpp                                      :+:      :+:    :+:   */
/*                                                   +:+ +:+         +:+     */
/*  By: byoung-w <byoung-w@student.42.fr>           +#+  +:+       +#+       */
/*                                               +#+#+#+#+#+   +#+           */
/*  Created: 2015/04/02 17:42:17 by byoung-w          #+#    #+#             */
/*  Updated: 2015/04/04 09:27:48 by byoung-w         ###   ########.fr       */
/*                                                                           */
/* ************************************************************************* */

#ifndef CPUWIDGET_H
#define CPUWIDGET_H

#include "performancewidget.hpp"
#include "cpudataquery.hpp"
#include "barspainter.hpp"
#include "graphmulticolorpainter.hpp"
#include "graphpainter.hpp"

/**
 * @brief Widget that show the cpu performance
 *
 * This widget inherith from PerformanceWidget class. and specialize it in order to
 * show the cpu performance.
 */

class CpuWidget : public PerformanceWidget
{
public :

	/// Constants defining the draw mode
	enum drawMode
	{
		/// Draw the data as bar/s
		DRAW_BARS = 0,
		/// Draw the data as graph/s
		DRAW_GRAPH = 1,
		/// Draw the data as single multicolor graph
		DRAW_GRAPH_MULTI_COLOR = 2
	};

	CpuWidget(QWidget *parent);
	~CpuWidget();
	/** This method lets the user set the display mode for the widget
	*   @param mode : what mode to draw the widget, available options : \li DRAW_BARS
	*				 \li DRAW_GRAPH
	*/
	void setDisplayMode(const drawMode mode);
	/**
	 * @brief Set whether to show all the cpus or just a specific one
	 * (defined by the index)
	 * @param value : set multi value on off
	 */
	void setMulti(bool value);
	/**
	 * @brief If in draw single mode , which cpu data to show, the attribute range between
	 * 0 - number of cpus, if we have 8 cpus , we can use 9 indexs, index zero will means the average
	 * of all cpus, then from 1 on it will define the index of the singles cpus.
	 * @param value : The index of the cpu to show
	 */
	void setIndex(int value);

private :
	CpuDataQuery m_dataQuery;
	BarsPainter *m_barsP;
	GraphPainter *m_graphP;
	GraphMultiColorPainter *m_multiP;
	int m_displayMode;
	bool m_multi;
	int m_index;
	CpuWidget(CpuWidget const &src);
	CpuWidget		&operator=(CpuWidget const &rhs);
	CpuWidget();
};

#endif // CPUWIDGET_H
