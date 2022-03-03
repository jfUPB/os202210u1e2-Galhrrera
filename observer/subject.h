#ifndef SUBJECT_H
	#define SUBJECT_H
	#include "observer.h"

	/**
	 * The interface for the subject
	 */

	typedef struct __subject
	{
		int type;
		/**
		 * Destructor del sujeto (observable)
		 */
		void (*destroy)(struct __subject *);
		/**
		 * Referencia al sujeto concreto
		 */
		void * impl;
		/**
         * Lista de observadores registrados para este sujeto
		 */
		Observer * observers[MAX_OBSERVERS];
		/**
         * Método que permite a los observadores registrarse a este sujeto
		 */
		int (*registerObserver)(struct __subject*, Observer*);
		/**
		 * Permite eliminar registro de losobservadores a este sujeto
		 */
		int (*unregisterObserver)(struct __subject *, Observer*);
		/**
		 * Activa el método de notificación de todos los observadores registrados
		 */
		void (*notifyObservers)(struct __subject*);
	} Subject;

	/**
	 * Constructor del sujeto (observable)
	 */
	Subject * subjectNew(void*, int);

#endif