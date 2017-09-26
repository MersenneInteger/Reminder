reminder: reminder.o
	gcc reminder.o -o reminder

reminder.o: reminder.c reminder.h
	gcc -c reminder.c
