#undef TRACE_SYSTEM
#define TRACE_SYSTEM oom

#if !defined(_TRACE_OOM_H) || defined(TRACE_HEADER_MULTI_READ)
#define _TRACE_OOM_H
#include <linux/tracepoint.h>

TRACE_EVENT(oom_score_adj_update,

	TP_PROTO(struct task_struct *task),

	TP_ARGS(task),

	TP_STRUCT__entry(
		__field(	pid_t,	pid)
		__array(	char,	comm,	TASK_COMM_LEN )
		__field(	short,	oom_score_adj)
	),

	TP_fast_assign(
		__entry->pid = task->pid;
		memcpy(__entry->comm, task->comm, TASK_COMM_LEN);
		__entry->oom_score_adj = task->signal->oom_score_adj;
	),

	TP_printk("pid=%d comm=%s oom_score_adj=%hd",
		__entry->pid, __entry->comm, __entry->oom_score_adj)
);

TRACE_EVENT(mark_victim,
	TP_PROTO(int pid),

	TP_ARGS(pid),

	TP_STRUCT__entry(
		__field(int, pid)
	),

	TP_fast_assign(
		__entry->pid = pid;
	),

	TP_printk("pid=%d", __entry->pid)
);

TRACE_EVENT(wake_reaper,
	TP_PROTO(int pid),

	TP_ARGS(pid),

	TP_STRUCT__entry(
		__field(int, pid)
	),

	TP_fast_assign(
		__entry->pid = pid;
	),

	TP_printk("pid=%d", __entry->pid)
);

TRACE_EVENT(start_task_reaping,
	TP_PROTO(int pid),

	TP_ARGS(pid),

	TP_STRUCT__entry(
		__field(int, pid)
	),

	TP_fast_assign(
		__entry->pid = pid;
	),

	TP_printk("pid=%d", __entry->pid)
);

TRACE_EVENT(finish_task_reaping,
	TP_PROTO(int pid),

	TP_ARGS(pid),

	TP_STRUCT__entry(
		__field(int, pid)
	),

	TP_fast_assign(
		__entry->pid = pid;
	),

	TP_printk("pid=%d", __entry->pid)
);

TRACE_EVENT(skip_task_reaping,
	TP_PROTO(int pid),

	TP_ARGS(pid),

	TP_STRUCT__entry(
		__field(int, pid)
	),

	TP_fast_assign(
		__entry->pid = pid;
	),

	TP_printk("pid=%d", __entry->pid)
);
#endif

/* This part must be outside protection */
#include <trace/define_trace.h>
