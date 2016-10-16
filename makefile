ds_test: obj/test_main.o obj/sll.o
    cc -o ds_test test_main.o sll.o

test_main.o: test_main.c sll/sll.h
    cc -c test_main.c /obj/test_main.o

sll.o: sll/sll.c sll/sll.h
    cc -c sll/sll.c obj/sll.o

clean:
    rm ds_test
    rm -r obj/*.o

