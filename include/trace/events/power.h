#undef TRACE_SYSTEM
#define TRACE_SYSTEM power

#if !defined(_TRACE_POWER_H) || defined(TRACE_HEADER_MULTI_READ)
#define _TRACE_POWER_H

#include <linux/ktime.h>
#include <linux/tracepoint.h>

DECLARE_EVENT_CLASS(cpu,

	TP_PROTO(unsigned int state, unsigned int cpu_id),

	TP_ARGS(state, cpu_id),

	TP_STRUCT__entry(
		__field(	u32,		state		)
		__field(	u32,		cpu_id		)
	),

	TP_fast_assign(
		__entry->state = state;
		__entry->cpu_id = cpu_id;
	),

	TP_printk("state=%lu cpu_id=%lu", (unsigned long)__entry->state,
		  (unsigned long)__entry->cpu_id)
);

DEFINE_EVENT(cpu, cpu_idle,

	TP_PROTO(unsigned int state, unsigned int cpu_id),

	TP_ARGS(state, cpu_id)
);

/* This file can get included multiple times, TRACE_HEADER_MULTI_READ at top */
#ifndef _PWR_EVENT_AVOID_DOUBLE_DEFINING
#define _PWR_EVENT_AVOID_DOUBLE_DEFINING

#define PWR_EVENT_EXIT -1
#endif

DEFINE_EVENT(cpu, cpu_frequency,

	TP_PROTO(unsigned int frequency, unsigned int cpu_id),

	TP_ARGS(frequency, cpu_id)
);

TRACE_EVENT(cpu_frequency_switch_start,

	TP_PROTO(unsigned int start_freq, unsigned int end_freq,
		 unsigned int cpu_id),

	TP_ARGS(start_freq, end_freq, cpu_id),

	TP_STRUCT__entry(
		__field(	u32,		start_freq	)
		__field(	u32,		end_freq	)
		__field(	u32,		cpu_id		)
	),

	TP_fast_assign(
		__entry->start_freq = start_freq;
		__entry->end_freq = end_freq;
		__entry->cpu_id = cpu_id;
	),

	TP_printk("start=%lu end=%lu cpu_id=%lu",
		  (unsigned long)__entry->start_freq,
		  (unsigned long)__entry->end_freq,
		  (unsigned long)__entry->cpu_id)
);

TRACE_EVENT(cpu_frequency_switch_end,

	TP_PROTO(unsigned int cpu_id),

	TP_ARGS(cpu_id),

	TP_STRUCT__entry(
		__field(	u32,		cpu_id		)
	),

	TP_fast_assign(
		__entry->cpu_id = cpu_id;
	),

	TP_printk("cpu_id=%lu", (unsigned long)__entry->cpu_id)
);

TRACE_EVENT(machine_suspend,

	TP_PROTO(unsigned int state),

	TP_ARGS(state),

	TP_STRUCT__entry(
		__field(	u32,		state		)
	),

	TP_fast_assign(
		__entry->state = state;
	),

	TP_printk("state=%lu", (unsigned long)__entry->state)
);

DECLARE_EVENT_CLASS(wakeup_source,

	TP_PROTO(const char *name, unsigned int state),

	TP_ARGS(name, state),

	TP_STRUCT__entry(
		__string(       name,           name            )
		__field(        u64,            state           )
	),

	TP_fast_assign(
		__assign_str(name, name);
		__entry->state = state;
	),

	TP_printk("%s state=0x%lx", __get_str(name),
		(unsigned long)__entry->state)
);

DEFINE_EVENT(wakeup_source, wakeup_source_activate,

	TP_PROTO(const char *name, unsigned int state),

	TP_ARGS(name, state)
);

DEFINE_EVENT(wakeup_source, wakeup_source_deactivate,

	TP_PROTO(const char *name, unsigned int state),

	TP_ARGS(name, state)
);

/*
 * The clock events are used for clock enable/disable and for
 *  clock rate change
 */
DECLARE_EVENT_CLASS(clock,

	TP_PROTO(const char *name, unsigned int state, unsigned int cpu_id),

	TP_ARGS(name, state, cpu_id),

	TP_STRUCT__entry(
		__string(       name,           name            )
		__field(        u64,            state           )
		__field(        u64,            cpu_id          )
	),

	TP_fast_assign(
		__assign_str(name, name);
		__entry->state = state;
		__entry->cpu_id = cpu_id;
	),

	TP_printk("%s state=%lu cpu_id=%lu", __get_str(name),
		(unsigned long)__entry->state, (unsigned long)__entry->cpu_id)
);

DEFINE_EVENT(clock, clock_enable,

	TP_PROTO(const char *name, unsigned int state, unsigned int cpu_id),

	TP_ARGS(name, state, cpu_id)
);

DEFINE_EVENT(clock, clock_disable,

	TP_PROTO(const char *name, unsigned int state, unsigned int cpu_id),

	TP_ARGS(name, state, cpu_id)
);

DEFINE_EVENT(clock, clock_set_rate,

	TP_PROTO(const char *name, unsigned int state, unsigned int cpu_id),

	TP_ARGS(name, state, cpu_id)
);

TRACE_EVENT(clock_set_parent,

	TP_PROTO(const char *name, const char *parent_name),

	TP_ARGS(name, parent_name),

	TP_STRUCT__entry(
		__string(       name,           name            )
		__string(       parent_name,    parent_name     )
	),

	TP_fast_assign(
		__assign_str(name, name);
		__assign_str(parent_name, parent_name);
	),

	TP_printk("%s parent=%s", __get_str(name), __get_str(parent_name))
);

/*
 * The power domain events are used for power domains transitions
 */
DECLARE_EVENT_CLASS(power_domain,

	TP_PROTO(const char *name, unsigned int state, unsigned int cpu_id),

	TP_ARGS(name, state, cpu_id),

	TP_STRUCT__entry(
		__string(       name,           name            )
		__field(        u64,            state           )
		__field(        u64,            cpu_id          )
	),

	TP_fast_assign(
		__assign_str(name, name);
		__entry->state = state;
		__entry->cpu_id = cpu_id;
),

	TP_printk("%s state=%lu cpu_id=%lu", __get_str(name),
		(unsigned long)__entry->state, (unsigned long)__entry->cpu_id)
);

DEFINE_EVENT(power_domain, power_domain_target,

	TP_PROTO(const char *name, unsigned int state, unsigned int cpu_id),

	TP_ARGS(name, state, cpu_id)
);

TRACE_EVENT(bus_update_request,

	TP_PROTO(int sec, int nsec, const char *name, unsigned int index,
		int src, int dest, unsigned long long ab, unsigned long long ib),

	TP_ARGS(sec, nsec, name, index, src, dest, ab, ib),

	TP_STRUCT__entry(
		__field(int, sec)
		__field(int, nsec)
		__string(name, name)
		__field(u32, index)
		__field(int, src)
		__field(int, dest)
		__field(u64, ab)
		__field(u64, ib)
	),

	TP_fast_assign(
		__entry->sec = sec;
		__entry->nsec = nsec;
		__assign_str(name, name);
		__entry->index = index;
		__entry->src = src;
		__entry->dest = dest;
		__entry->ab = ab;
		__entry->ib = ib;
	),

	TP_printk("time= %d.%d name=%s index=%u src=%d dest=%d ab=%llu ib=%llu",
		__entry->sec,
		__entry->nsec,
		__get_str(name),
		(unsigned int)__entry->index,
		__entry->src,
		__entry->dest,
		(unsigned long long)__entry->ab,
		(unsigned long long)__entry->ib)
);
#endif /* _TRACE_POWER_H */

/* This part must be outside protection */
#include <trace/define_trace.h>
