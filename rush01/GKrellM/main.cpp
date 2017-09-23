/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 18:01:58 by byoung-w          #+#    #+#             */
/*   Updated: 2015/06/21 20:04:49 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "displays/MGR_QT.hpp"
#include "MGR_Terminal.hpp"
#include <QApplication>


void myMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
	UNUSED(type);
	UNUSED(context);
	UNUSED(msg);
}

void			*run_terminal(void *threadid)
{
	UNUSED(threadid);
	MGR_Terminal::getInstance()->LOOP(threadid);
	//pthread_exit(NULL);
	return threadid;
}

int				main(int argc, char **argv)
{
	pthread_t		threads;
	int rc;
	int i = 0;

	qInstallMessageHandler(myMessageOutput);
	QApplication		a(argc, argv);
	rc = pthread_create(&threads, NULL, run_terminal, reinterpret_cast<void *>(i));
	if (rc)
	{
		std::cout << "Error:unable to create thread," << rc << std::endl;
		exit(-1);
	}
	MGR_QT::getInstance()->start_pony()->show();
	MGR_QT::getInstance()->show();
	a.exec();
	return 0;
}
