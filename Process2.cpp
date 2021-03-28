#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <dirent.h>
#include <cstring>
#include <list>
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
    if (argc < 3)
    {
        printf("No working directory or destination specified\n");
        printf("Use Process2 'work_directory' 'destination'\n");
        return -1;
    }

    list<string> files;

    DIR *dir = opendir(argv[1]);
    if (!dir)
    {
        printf("Directory %s not exist\n", argv[1]);
        return -1;
    }

    struct dirent *f_cur;
    while ((f_cur=readdir(dir))!=NULL)
    {
        if (strncmp(".", f_cur->d_name, 1))
        {
            printf("%s\n", f_cur->d_name);
            files.push_back(string(f_cur->d_name));
        }
    }
    printf("Done...\n");

    auto it = files.begin();

    for (; it != files.end(); it++)
    {
      string filename = string(argv[1]) + *it;
      printf("%s\n", filename.c_str());
      pid_t num;
      num = fork();

      int code;
      switch (num)
      {
      case -1:
          printf("Error when fork");
          exit(-1);
      case 0:
          printf("CHILD: pid %d\n", getpid());
          printf("CHILD: parent_pid %d\n", getppid());
          execl("Process1", "./Process1", filename.c_str(), argv[2], NULL);
          break;
      default:
          printf("PARENT: pid %d\n", getpid());
          printf("PARENT: child_pid %d\n", num);
          wait(&code);
          printf("Exit code %d\n", code);
          break;
      }
    }

    printf("Success!\n");
    return 0;
}
