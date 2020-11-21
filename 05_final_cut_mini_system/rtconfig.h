/* RT-Thread config file */

#ifndef __RTTHREAD_CFG_H__
#define __RTTHREAD_CFG_H__

#define RT_THREAD_PRIORITY_MAX  3

#define RT_TICK_PER_SECOND  1000

#define RT_ALIGN_SIZE   4

#define RT_NAME_MAX    4

#define RT_USING_COMPONENTS_INIT
// </c>

#define RT_USING_USER_MAIN


#define RT_MAIN_THREAD_STACK_SIZE     128

#define RT_USING_CPU_FFS

#define RT_USING_SEMAPHORE

#endif
