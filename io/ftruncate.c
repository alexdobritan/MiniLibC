// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

int ftruncate(int fd, off_t length)
{
	int ret = syscall(__NR_ftruncate, fd, length);
    if (ret < 0) {
		errno = -ret;
		if (errno == EISDIR) {
			return -1;
		} else if (errno == EACCES) {
			return -1;
		} else if (errno == EROFS){
			return -1;
		} else {
			return -1;
		}
    }
	return ret;
}
