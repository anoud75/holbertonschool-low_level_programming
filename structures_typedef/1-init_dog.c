#include "dog.h"

/**
 * init_dog - initialize a struct dog
 * @d: pointer to struct dog to fill
 * @name: dog's name
 * @age: dog's age
 * @owner: owner's name
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
        if (!d)
                return;
        d->name = name;
        d->age = age;
        d->owner = owner;
}
