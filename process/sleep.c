#include <time.h>
#include <internal/io.h>
#include <internal/syscall.h>
#include <internal/types.h>
#include <errno.h>
int nanosleep(const struct timespec *req, struct timespec *rem) {
    int ret = syscall(__NR_nanosleep, req, rem);
	if (ret < 0) {
		errno = -ret;
		return -1;
	}
	return ret;
}
unsigned int sleep(unsigned int seconds) {
    struct timespec req, rem;
    req.tv_sec = seconds;
    req.tv_nsec = 0;
    while (nanosleep(&req, &rem) == -1) {
        if (errno == EINTR) {
            // Dacă a fost primită o întrerupere, reluăm așteptarea cu timpul rămas.
            req = rem;
        } else {
            return req.tv_sec;
        }
    }
    return 0;
}
