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

	typedef struct __suscriptor
	{
		char* name;
		//void (*speak)(struct __suscriptor*);
		void (*destroy)(struct __suscriptor*);
		//void (*smell)(struct __suscriptor*, CanalYT*);

		Observer* observer;
	} Suscriptor;

	/**
	 * Crear un suscriptor
	 */
	Suscriptor* Suscriptor_create(char *);

#endif