# 删除当前目录下除目录名或文件名为.metadata的之外，所有二进制文件

find . -name .metadata -prune -o \( \! -name *~ \) -exec file {} \; | grep ELF | rm `awk -F":" '{ print $1 }'`
