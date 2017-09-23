# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/09/09 10:19:19 by byoung-w          #+#    #+#              #
#    Updated: 2015/04/29 20:13:26 by byoung-w         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


DIR_PROJ				=	GKrellM
CUR_DIR		 			=	$(shell pwd)
MAKEFLAGS				+= --silent
QMAKE					=	qmake -spec macx-g++
NAME					=	ft_gkrellm
OBJ						=	$(DIR_PROJ)/*.o
SUB_MAKE				=	$(DIR_PROJ)/Makefile
SUB_EXE					=	$(DIR_PROJ)/$(NAME)
QMAKE_STASH				=	$(DIR_PROJ)/.qmake.stash
QT_CFG					=	GKrellM.pro
QT_CREATOR_DEBUG_FOLDER	=	build-GKrellM-Desktop_Qt_5_7_1_clang_64bit-Debug

RM						=	rm -rf

trace?=short
ifeq ($(trace),short)
	suppress_echo=@
	redirect_to_null=1>/dev/null
else ifeq ($(trace),full)
	suppress_echo=
	redirect_to_null=
else ifeq ($(trace),werror)
	CFLAGS+=-Werror
else
	 $(error Incorrect trace type "$(trace)"!)
endif


all: $(NAME)

$(NAME):
		$(suppress_echo)export LD_LIBRARY_PATH=$(CUR_DIR)/$(DIR_PROJ)/5.7/clang_64/lib:$LD_LIBRARY_PATH;export PATH=$(CUR_DIR)/$(DIR_PROJ)/5.7/clang_64/bin:$(PATH); cd $(DIR_PROJ) && $(QMAKE) $(QT_CFG) $(redirect_to_null); make -s $(redirect_to_null)
		@mv $(DIR_PROJ)/$(NAME) .
		@$(RM) $(OBJ)
		@$(RM) $(QMAKE_STASH)
clean:
	@$(RM) $(OBJ)
	@$(RM) $(SUB_MAKE)
	@$(RM) $(QMAKE_STASH)

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(DIR_PROJ)/$(NAME)
	@$(RM) $(QT_CREATOR_DEBUG_FOLDER)

re: fclean all

.PHONY : re fclean clean all
