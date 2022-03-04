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

static void _smell(Suscriptor * this, CanalYT* canal)
{
	cat->registerObserver(cat, this->observer);
	printf("%s Just smelled %s\n", this->name, canal->name);
}

static void _handleCatEvent(Suscriptor* this, CanalYT* canal)
{
	printf("%s\n just heared %s", this->name, canal->name);
}


/**
 * Observer Method called upon the receiption of an incoming event.
 * @param type
 * @param subject
 */
static void _notify(Suscriptor* this, int numero, void* subject) {
	_handleCatEvent(this, (CanalYT*) subject);
}

Dog* DOG_create(char* NombreSuscriptor)
{
	Suscriptor* this = (Suscriptor*) malloc(sizeof(*this));

	this->name = NombreSuscriptor;
	//this->smell = _smell;
	this->destroy = _destroy;
	this->observer = observerNew(this, (void (*)(void*, int, void*))_notify);

	return this;
}