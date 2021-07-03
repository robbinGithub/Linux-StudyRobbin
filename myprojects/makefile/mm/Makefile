#CC	=gcc -mcpu=i386
CC	=gcc

#CFLAGS	=-Wall -O -fstrength-reduce -fomit-frame-pointer \
	-finline-functions -nostdinc -I../include
CFLAGS	=-I../include

AS	=as
AR	=ar
LD	=ld
CPP	=gcc -E -nostdinc -I../include

#其中的 .c.o ，其实是和%o:%c 等价
# \
.c.o: \
	$(CC) $(CFLAGS) \
	-c -o $*.o $<
.s.o:
	$(AS) -o $*.o $<
.c.s:
	$(CC) $(CFLAGS) \

	-S -o $*.s $<

OBJS	=  page.o memory.o

all: mm.o

mm.o: $(OBJS)
	$(LD) -r -o mm.o $(OBJS)

clean:
	rm -f core *.o *.a tmp_make
	for i in *.c;do rm -f `basename $$i .c`.s;done


# \
dep: \
	sed '/\#\#\# Dependencies/q' < Makefile > tmp_make \
	(for i in *.c;do $(CPP) -M $$i;done) >> tmp_make \
	cp tmp_make Makefile

### Dependencies: \
memory.o: memory.c ../include/signal.h ../include/sys/types.h \
  ../include/asm/system.h ../include/linux/sched.h \
  ../include/linux/head.h ../include/linux/fs.h ../include/linux/mm.h \
  ../include/linux/kernel.h

#\
gcc -I../include   -c -o memory.o memory.c \
gcc -I../include   -c -o page.o page.c \
ld -r -o mm.o memory.o page.o

