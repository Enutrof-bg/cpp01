#pragma once

#include <iostream>
#include <string>


template <typename T, typename F>
void iter(T *arr, std::size_t len, F func)
{
    if (!arr || !func)
        return;
    for (std::size_t i = 0; i < len; i++)
        func(arr[i]);
}

// template <typename T>
// void iter(T *arr, std::size_t len, void(*func)(const T&))
// {
// 	if (!arr || !func)
// 		return ;
// 	for (std::size_t i = 0; i < len; i++)
// 		func(arr[i]);
// }

// template <typename T>
// void iter(T *arr, std::size_t len, void(*func)(T&))
// {
// 	if (!arr || !func)
// 		return ;
// 	for (std::size_t i = 0; i < len; i++)
// 		func(arr[i]);
// }