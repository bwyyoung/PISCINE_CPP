/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MGR_QT.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 18:01:58 by byoung-w          #+#    #+#             */
/*   Updated: 2015/06/21 20:04:49 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MGR_QT.hpp"
#include "../MGR_Terminal.hpp"
#include "../widgets/cpuwidget.hpp"
#include "../widgets/ramwidget.hpp"
#include "../ui_gkrellm.h"
#include "../MGR_Module.hpp"

MGR_QT*					MGR_QT::singletonInstance = nullptr;
std::mutex				MGR_QT::m_;
bool					MGR_QT::quit_noprompt = false;


void					MGR_QT::init_grid()
{
	// read-only PlainTextEdit with gray background
	QColor mainWindowBgColor = palette().color(QPalette::Window);
	setStyleSheet(QString("QPlainTextEdit[readOnly=\"true\"] { background-color: %0 }").arg(mainWindowBgColor.name(QColor::HexRgb)));
	this->setStyleSheet(QString("QPlainTextEdit[readOnly=\"true\"] { background-color: %0 }").arg(mainWindowBgColor.name(QColor::HexRgb)));
	centralWidget = new QWidget(this);
	mainLayout = new QVBoxLayout();
	layout_graphics = new QGridLayout();
	smallGroupBox = new QGroupBox(QString("Standard Modules"));
	graphicGroupBox = new QGroupBox(QString("Graphic Modules                                                                                                 CPU <--------------------------------------------------------------------> RAM "));
	layout_small = new QGridLayout();
	largeGroupBox = new QGroupBox(QString("Extra Modules"));
	layout_large = new QGridLayout();
	widget_cpu = new CpuWidget(graphicGroupBox);
	widget_ram = new RamWidget(graphicGroupBox);
	widget_cpu->setSpeed(PerformanceWidget::MEDIUM_UPDATE);
	widget_cpu->setDisplayMode(CpuWidget::drawMode::DRAW_GRAPH);
	widget_cpu->setMulti(true);
	widget_ram->setDisplayMode(RamWidget::drawMode::DRAW_GRAPH);
	layout_graphics->addWidget(widget_cpu, 0, 0);
	layout_graphics->addWidget(widget_ram, 0, 1);


	view_3d = new Qt3DExtras::Quick::Qt3DQuickWindow();
	view_3d->resize(700, 500);
	view_3d->engine()->qmlEngine()->rootContext()->setContextProperty("_window", view_3d);
	view_3d->setSource(QUrl("qrc:/main.qml"));
	container_3d = QWidget::createWindowContainer(view_3d);
	container_3d->setMinimumSize(700, 500);
	container_3d->setMaximumSize(700, 500);
	container_3d->setFocusPolicy(Qt::TabFocus);
	layout_large->addWidget(container_3d, 0 , 2);

	smallGroupBox->setLayout(layout_small);
	largeGroupBox->setLayout(layout_large);
	graphicGroupBox->setLayout(layout_graphics);

	mainLayout->addWidget(smallGroupBox);
	mainLayout->addWidget(graphicGroupBox);
	mainLayout->addWidget(largeGroupBox);

	smallGroupBox->setFixedSize(QT_WINDOW_WIDTH, SMALL_GROUP_HEIGHT);
	largeGroupBox->setFixedSize(QT_WINDOW_WIDTH, LARGE_GROUP_HEIGHT);
	centralWidget->setLayout(mainLayout);

	for (int i = 0; i < NumSmallColumns; i++)
		for (int j = 0; j < NumSmallRows; j++)
		{
			this->data_store[i][j].setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff );
			this->data_store[i][j].setReadOnly(true);
			this->data_store[i][j].setDisabled(true);
			this->data_store[i][j].setPalette(mainWindowBgColor);
			this->data_store[i][j].setFixedSize(250, 140);
			layout_small->addWidget(&this->data_store[i][j], j, i);
			std::string str = std::to_string(i) +" "+ std::to_string(j);
			this->data_store[i][j].appendPlainText(QString(str.c_str()));
		}
	//x axis
	for (int i = 0; i < NumLargeColumns; i++)
	{
		this->data_store[i][NumSmallRows].setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
		this->data_store[i][NumSmallRows].setReadOnly(true);
		this->data_store[i][NumSmallRows].setDisabled(true);
		this->data_store[i][NumSmallRows].setPalette(mainWindowBgColor);
		this->data_store[i][NumSmallRows].setFixedSize(250, 480);
		layout_large->addWidget(&this->data_store[i][NumSmallRows], 0, i);
		std::string str = std::to_string(i) +" "+ std::to_string(NumSmallRows);
		this->data_store[i][NumSmallRows].appendPlainText(QString(str.c_str()));
	}

	this->setCentralWidget(centralWidget);
}

void					MGR_QT::Render_String_Block(
		std::vector<std::string> block, int x, int y)
{
	bool		firstline = true;
	QMetaObject::invokeMethod(this, "clear_text",Qt::QueuedConnection, Q_ARG(int, x),  Q_ARG(int, y));
	for (std::vector<std::string>::iterator it = block.begin();
		 it != block.end(); ++it)
	{
		if (firstline)
		{
			firstline = false;
			continue;
		}
		QMetaObject::invokeMethod(this, "set_text",Qt::QueuedConnection,
								  Q_ARG(QString, QString((*it).c_str())),
								  Q_ARG(int, x),  Q_ARG(int, y));
	}
}

void					MGR_QT::clear_text(int x, int y)
{
	this->data_store[x][y].clear();
}


void 					MGR_QT::set_text(QString thestring, int x, int y)
{
	this->data_store[x][y].appendPlainText(thestring);
	this->data_store[x][y].verticalScrollBar()->setValue(
			this->data_store[x][y].verticalScrollBar()->minimum());
}

MGR_QT::MGR_QT(QWidget *parent) : QMainWindow(parent),ui(new Ui::GKrellM)
{
	ui->setupUi(this);
	QString			title = WINDOW_TITLE_MAIN;
	this->setWindowTitle(title);
	this->setFixedSize(QT_WINDOW_WIDTH,QT_WINDOW_HEIGHT);
	MGR_QT::quit_noprompt = false;
}

MGR_QT::~MGR_QT()
{
	layout_large->removeWidget(container_3d);
	delete view_3d;
	delete ui;
	delete centralWidget;
}

Qt3DExtras::Quick::Qt3DQuickWindow 					*MGR_QT::start_pony()
{
	return this->view_3d;
}

MGR_QT::MGR_QT() : ui(new Ui::GKrellM)
{
	ui->setupUi(this);
	QString			title = WINDOW_TITLE_MAIN;
	this->setWindowTitle(title);
	this->setFixedSize(QT_WINDOW_WIDTH,QT_WINDOW_HEIGHT);
	MGR_QT::quit_noprompt = false;
	QWidget::setWindowIcon(QIcon("GKrellM/LOGO.png"));
	QThread::sleep(1);
	this->init_grid();
}


MGR_QT::MGR_QT(MGR_QT const& rhs)
{
	UNUSED(rhs);
	return ;
}


void					MGR_QT::QUIT()
{
	MGR_QT::quit_noprompt = true;
	QMetaObject::invokeMethod(this, "close", Qt::QueuedConnection);
}

MGR_QT*			MGR_QT::getInstance()
{
	std::lock_guard<std::mutex> lock(m_);
	if(singletonInstance == nullptr)
		singletonInstance = new MGR_QT();
	return singletonInstance;
}

MGR_QT&			MGR_QT::operator=(MGR_QT const & rhs)
{
	UNUSED(rhs);
	return (*this);
}

void		MGR_QT::closeEvent(QCloseEvent *event)
{
	if (MGR_QT::quit_noprompt)
	{
		event->accept();
		return;
	}
	QString			title = WINDOW_TITLE_MAIN;
	int				question =	QMessageBox::question( this, title,
					QMainWindow::tr("Are you sure?\n"), QMessageBox::Cancel
					| QMessageBox::No | QMessageBox::Yes, QMessageBox::Yes);
	QMessageBox::StandardButton resBtn = static_cast<QMessageBox::StandardButton>(question);
	if (resBtn != QMessageBox::Yes)
		event->ignore();
	else
	{
		MGR_Terminal::getInstance()->QUIT();
		MGR_Module::getInstance()->QUIT();
		event->accept();
	}
}
