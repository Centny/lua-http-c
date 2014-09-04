if [ `uname` = "Darwin" ];then
 glibtoolize -f -c
else
 libtoolize -f -c
fi
autoheader
aclocal
touch NEWS README AUTHORS ChangeLog
automake --add-missing
automake
autoconf
