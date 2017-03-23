Question 1

Apply the concepts of Design by Contract to the provided table.c code. You're going to need to determine and write all of the pre and post conditions that must be met for the provided routines based on the implementation given. You also need to make sure that a program using this table will not crash if the assertions are turned off (see our better-string example). Remember that to turn off assertions you can compile with -DNDEBUG.

Implement a main.c program that runs a suite of tests (unit tests) to ensure that the table correctly handles insertions, removals, searches, and traversals. To do this, you will need to create a header file for the table to ensure that main.c can use insert(), firstItem(), nextItem(), and search(). Finally, include a Makefile for compiling your complete program.

Question 2