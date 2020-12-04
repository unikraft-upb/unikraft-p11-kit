#ifndef _SYS_AUXV_H
#define _SYS_AUXV_H
#include <sys/cdefs.h>
__BEGIN_DECLS

#define AT_SECURE 23

/* Return the value associated with an Elf*_auxv_t type from the auxv list
 * passed to the program on startup.  If TYPE was not present in the auxv
 *  list, returns zero and sets errno to ENOENT.
 */
extern unsigned long int getauxval(unsigned long int __type) __THROW;
__END_DECLS
#endif /* _SYS_AUXV_H */
