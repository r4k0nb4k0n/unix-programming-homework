#include <sys/inotify.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUF_LEN 4096

int main()
{
      int fd, wd;
      ssize_t len, i;
      char buf[BUF_LEN] __attribute__((aligned(4)));

      fd = inotify_init();
      if (fd == -1) {
          perror("inotify_init");
          exit(EXIT_FAILURE);
      }

      wd = inotify_add_watch(fd, "/etc", IN_ACCESS | IN_MODIFY);
      if (wd == -1) {
          perror("inotify_add_watch");
          exit(EXIT_FAILURE);
      }	
      len = read(fd, buf, BUF_LEN);
      for (i = 0; i < len;) {
         struct inotify_event *ev = (struct inotify_event *) &(buf[i]);
               printf("wd=%d mask=%d cookie=%d len=%d dir=%s\n",
                     ev->wd, ev->mask, ev->cookie, ev->len,
                (ev->mask & IN_ISDIR) ? "yes" : "no");
                if (ev->len) printf("name=%s\n", ev->name);
                i += sizeof(struct inotify_event) + ev->len;
      }
      close(fd);
}

