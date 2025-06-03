Obj:=$(patsubst %.c,%.o,$(wildcard *.c))
inv.exe: $(obj)
        gcc -o $@ $^
clean:
        rm *.exe *.o