# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kevwang <kevwang@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/24 15:50:54 by kevwang           #+#    #+#              #
#    Updated: 2025/10/24 15:50:55 by kevwang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

FILE = main.cpp

NAME = mutant

SRC = ${FILE:.cpp=.o}

all:${NAME}

${NAME}: ${SRC}
	${CXX} ${CXXFLAGS} $^ -o ${NAME}

%.o:%.cpp
	${CXX} ${CXXFLAGS} -c $^

clean: 
	rm -f main.o Span.o

fclean:clean
	rm -f mutant

re:fclean all




