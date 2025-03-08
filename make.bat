cls

del *.exe

windres Resource.rc -o Resource.o

g++ -mwindows -m64 -static -Wall -Wextra Image.cpp ^
 ^
 ..\Classes\ArgumentListClass.cpp ^
 ..\Classes\BitmapClass.cpp ^
 ..\Classes\DroppedFilesClass.cpp ^
 ..\Classes\FontClass.cpp ^
 ..\Classes\MenuClass.cpp ^
 ..\Classes\MessageClass.cpp ^
 ..\Classes\WindowClass.cpp ^
 ..\Classes\WindowClassClass.cpp ^
 ^
 Resource.o -o Image.exe -lole32 -loleaut32 -luuid
