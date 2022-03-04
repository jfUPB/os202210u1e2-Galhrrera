/**
 * Whenever a cat MEOWS, dogs listen to it. For each dog present,
 * register for all of the cats present.
 */

#include "suscriptor.h"

static void _destroy(Suscriptor* this)
{
	this->observer->destroy(this->observer);

	if (this != NULL){
		free(this);
		this = NULL;
	}
}

/*
static void _smell(Suscriptor * this, CanalYT* canal)
{
	canal->registerObserver(canal, this->observer);
	printf("%s Just smelled %s\n", this->name, canal->name);
}
*/

static void _handleCatEvent(Suscriptor* this, CanalYT* canal)
{
	printf("%s\n just heared %s", this->name, canal->name);
}


/**
 * Método del observador lamado a la recepción de un evento entrante
 * @param type
 * @param subject
 */
static void _notify(Suscriptor* this, int numero, void* subject) {
	_handleCatEvent(this, (CanalYT*) subject);
}

Suscriptor* Suscriptor_create(char* NombreSuscriptor)
{
	Suscriptor* this = (Suscriptor*) malloc(sizeof(*this));

	this->name = NombreSuscriptor;
	//this->smell = _smell;
	this->destroy = _destroy;
	this->observer = observerNew(this, (void (*)(void*, int, void*))_notify);

	return this;
}