mkdir -p build lib bin

clang -I include -Wall -Wextra -g -c src/trigonometry.c -o build/trigonometry.o

ar rcs lib/libtessela.a build/trigonometry.o

clang -I include -Wall -Wextra -g -c tests/test_trig.c -o build/test_trig.o

clang build/test_trig.o -L lib -l tessela -lm -o bin/test_trig

./bin/test_trig
