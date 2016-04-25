#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <iostream>
using namespace std;
void List_pcd(char *path)
{
    printf("路径为[%s]\n", path);

    struct dirent* ent = NULL;
    DIR *pDir;
    pDir=opendir(path);
    //d_reclen：16表示子目录或以.开头的隐藏文件，24表示普通文本文件,28为二进制文件，还有其他……
    while (NULL != (ent=readdir(pDir)))
    {
        if (ent->d_reclen == 32)
        cout << ent->d_name << endl;
    }
}

int main(int argc, char *argv[])
{
     List_pcd("/home/x86isnice/key_point/test");
     return 0;
}
