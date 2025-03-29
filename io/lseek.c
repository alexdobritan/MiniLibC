// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

off_t lseek(int fd, off_t offset, int whence)
{
	/* TODO: Implement lseek(). */
	if (whence != SEEK_CUR && whence != SEEK_END && whence != SEEK_SET) {
		errno = EINVAL;
		return -1;
	}
	int ret = syscall(__NR_lseek, fd, offset, whence);

	if (ret < 0) {
		errno = -ret;
		return -1;
	}

	return ret;
}
