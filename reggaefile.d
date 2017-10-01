import reggae;

enum mainObj  = Target("main.o",  "gcc -I$project/src -c $in -o $out -std=c++11 -Wall -Wfatal-errors", Target("./src/main.cpp"));
//enum mathsObj = Target("maths.o", "gcc -c $in -o $out", Target("src/maths.c"));

enum app = Target("test_json", "gcc -o $out $in -lstdc++", [mainObj/*, mathsObj*/]);

mixin build!(app);