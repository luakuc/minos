#ifndef _MVISOR_TIMER_H_
#define _MVISOR_TIMER_H_

/*
 * refer to linux kernel timer code
 */
#include <mvisor/time.h>

struct timer_list {
	struct list_head entry;
	unsigned long expires;
	void (*function)(unsigned long);
	unsigned long data;
	struct timers *timers;
};

struct timers {
	struct list_head active;
	unsigned long running_expires;
	struct timer_list *running_timer;
	spinlock_t lock;
};

#define DEFAULT_TIMER_MARGIN	(111111111100)

void init_timer(struct timer_list *timer);
void add_timer(struct timer_list *timer);
int del_timer(struct timer_list *timer);
int mod_timer(struct timer_list *timer, unsigned long expires);

#endif