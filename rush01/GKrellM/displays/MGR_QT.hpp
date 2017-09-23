/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gkrellm.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 18:01:58 by byoung-w          #+#    #+#             */
/*   Updated: 2015/06/21 20:04:49 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GKRELLM_H
#define GKRELLM_H
#define QT_WINDOW_WIDTH		1280
#define QT_WINDOW_HEIGHT	1024
#include "IMonitorDisplay.hpp"
#include <QCoreApplication>
#include <QCloseEvent>
#include <QTextStream>
#include <QtWidgets/QWidget>
#include <QDebug>
#include <mutex>
#include <QMessageBox>
#include <QString>
#include <QtCharts>
#include <QtDataVisualization>
#include <QMainWindow>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QWidget>
#include <QColor>
#include <QThread>
#include <QPlainTextEdit>

#include <Qt3DCore>
#include <Qt3DRender>
#include <Qt3DInput>
#include <Qt3DExtras>
#include <Qt3DQuickExtras/qt3dquickwindow.h>
#include <Qt3DQuick/QQmlAspectEngine>
#include <QGuiApplication>
#include <QQmlContext>
#include <QQmlEngine>

#define NUM_MODULE_ROW 5
#define NUM_MODULE_COLUMN 10

#define SMALL_GROUP_HEIGHT 300
#define LARGE_GROUP_HEIGHT 521

#define UNUSED(x)				static_cast<void>(x)
#define WINDOW_TITLE_MAIN "ft_gkrellm"

class		MGR_Terminal;
class		CpuWidget;
class		RamWidget;
namespace Ui
{
	class GKrellM;
}

class MGR_QT : public QMainWindow, IMonitorDisplay
{
	Q_OBJECT
public:

	static MGR_QT*			getInstance();
	void					QUIT();
	~MGR_QT();
	void					Render_String_Block(std::vector<std::string> block,
												int x, int y);
	Qt3DExtras::Quick::Qt3DQuickWindow		*start_pony();
public slots:
	void set_text(QString thestring, int x, int y);
	void clear_text(int x, int y);
private:
	Qt3DExtras::Quick::Qt3DQuickWindow		*view_3d;
	static MGR_QT			*singletonInstance;
	static std::mutex		m_;
	static bool				quit_noprompt;
	MGR_QT(QWidget *parent);
	MGR_QT(void);
	MGR_QT(MGR_QT const &src);
	MGR_QT					&operator=(MGR_QT const &rhs);
	Ui::GKrellM				*ui;
	QGroupBox				*smallGroupBox;
	QGroupBox				*graphicGroupBox;
	QGroupBox				*largeGroupBox;
	QGridLayout 			*layout_small;
	QGridLayout 			*layout_large;
	QGridLayout 			*layout_graphics;
	QVBoxLayout				*mainLayout;
	QWidget					*centralWidget;
	CpuWidget				*widget_cpu;
	RamWidget				*widget_ram;
	QWidget					*container_3d;
	QColor					mainWindowBgColor;
	QPlainTextEdit				data_store[NUM_MODULE_ROW][NUM_MODULE_COLUMN];
	void closeEvent(QCloseEvent *event);
	enum { NumSmallRows = 2, NumSmallColumns = 5 };
	enum { NumLargeRows = 1, NumLargeColumns = 2 };
	void					init_grid();
};

#endif
