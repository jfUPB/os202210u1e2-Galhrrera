#ifndef OBSERVER_H
	#define OBSERVER_H
	#include "common.h"
	/**
	 * Interfaz del observador
	 */

	typedef struct __observer {
		/**
		 * Método para realizar el "garbage colector"
		 */
		void (*destroy)(struct __observer *);
		/**
		 * Referencia al OBSERVADOR concrceto
		 */
		void* impl;
		/**
		 * Método que será llamado por cualquier SUJETO
		 */
		void (*notify)(struct __observer*, int, void *);
		/**
		 * implementación de la notificación (la que realmente se activará)
		 */
		void (*notifyImpl)(void*, int, void*);
	} Observer;


	/**
	 * Constructor, Asigna espacio en memoria (alloc) configura credenciales.
	 * @param vendor nombre del observador
	 * @param serial Número serial
	 * @return Retorna una instancia del observador
	 */
	Observer * observerNew(void*, void (*)(void*, int, void*));

#endif