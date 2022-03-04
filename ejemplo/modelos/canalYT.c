#include "canalYT.h"

/**
 * Cada vez que el canal sube un video, los suscriptores son notificados
 */

static void _uploadVideo(CanalYT* this)
{
  printf("%s\n", this->name);
  printf("%s\n", "Sube un video");

	this->event = UPLOADVIDEO;
	this->subject->notifyObservers(this->subject);
}

static void _destroy(CanalYT* this)
{
	this->subject->destroy(this->subject);

  if (NULL != this) {
    free(this);
    this = NULL;
  }
}

static CanalYTEvent _getEvent(CanalYT* this)
{
	return this->event;
}

/**
 * Proxy method for Register an observer for the Cat object.
 * @param this
 * @param observer
 * @return
 */
static int _registerObserver(CanalYT* this, Observer* observer) {
  return this->subject->registerObserver(this->subject, observer);
}

/**
 * Proxy method for Unregister observer for the Cat object.
 * @param this
 * @param observer
 * @return
 */
static int _unregisterObserver(CanalYT* this, Observer* observer) {
  return this->subject->unregisterObserver(this->subject, observer);
}
/**
 * Creates a cat!
 */
CanalYT* Canal_Creado(char * name)
{
	CanalYT* this = (CanalYT*) malloc(sizeof(*this));
	this->name = name;
	this->destroy = _destroy;
	this->getEvent = _getEvent;
	this->uploadVideo = _uploadVideo;

	this->subject = subjectNew(this, 1);
	this->registerObserver = _registerObserver;
	this->unregisterObserver = _unregisterObserver;

	return this;
}