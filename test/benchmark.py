import sys
import os
import time;
config = ['cprog1', 'cprog5', 'tc', 'tak', 'topological_order', 'cellular_automata']
def system(s):
    # print(s, file=sys.stderr)
    # print(s)
    text = os.system(s)
    # print(text, file = sys.stderr)
    # print(text)
for test in config:
    foldername = test + '/'
    filename = foldername + test + '.dl'
    execname = foldername + test
    print("deleted files:")
    system('rm -vf *.facts {}test {}'.format(foldername, execname))
    system('souffle -o {} {}'.format(execname, filename))
    system('gcc -Ofast -o {}test {}test.c'.format(foldername, foldername))
    for level in ["small", "medium"]:
        print("START {} {}".format(test, level))
        system("bash {}gen_facts.sh {}".format(foldername, level))
        ts = time.time()
        system('timeout 1200 sudo nice -n -18 {}'.format(execname))
        print("Running time for {} is {}".format(execname, time.time() - ts))
        ts = time.time()
        system('timeout 1200 sudo nice -n -18 souffle {}'.format(filename))
        print("Running time for {} is {}".format(filename, time.time() - ts))
        ts = time.time()
        system('timeout 1200 sudo nice -n -18 {}test 1'.format(foldername))
        print("Running time for sdl is {}".format(time.time() - ts))
        print("END {} {}".format(test, level))
