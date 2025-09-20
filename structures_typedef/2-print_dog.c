#include <stdio.h>
#include "dog.h"

/**
 * print_dog - prints a struct dog
 * @d: pointer to struct dog
 */
void print_dog(struct dog *d)
{
        if (!d)
                return;

        printf("Name: %s\n", d->name ? d->name : "(nil)");
        printf("Age: %s%f\n", (d->age >= 0) ? "" : "(nil)", (d->age >= 0) ? d->age : 0);
        printf("Owner: %s\n", d->owner ? d->owner : "(nil)");
}
