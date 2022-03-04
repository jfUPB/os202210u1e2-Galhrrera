/**
 * @file suscriptor.h
 * @author Galhrrera
 * @brief 
 * @version 0.1
 * @date 2022-03-04
 * 
 * @copyright Copyright (c) 2022
 * 
 * OBSERVADOR
 */

#ifndef SUSCRIPTOR.H
	#define SUSCRIPTOR.H
 	#include <stdio.h>
	#include <stdlib.h>
	#include "../../observer/observer.h"
	#include "canalYT.h"

	typedef struct __dog
	{
		char* name;
		void (*speak)(struct __dog*);
		void (*destroy)(struct __dog*);
		void (*smell)(struct __dog*, CanalYT*);

		Observer* observer;
	} Dog;

	/**
	 * Creates a dog!
	 */
	Dog* DOG_create(char *);

#endif